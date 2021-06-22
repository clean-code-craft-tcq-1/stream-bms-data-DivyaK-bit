/*
 * BMS_Receiver_Core.cpp
 *
 *  Created on: Jun 20, 2021
 *      Author: ahk7kor
 */

#include <sstream>
#include "boost/property_tree/ptree.hpp"

#include "JsonFormat_Utils.h"
#include "BMS_Receiver_Core.h"

using namespace std;

#define CONFIG_DATA_BUFFER_SIZE 5

/**
 * Description     : Constructor
 *
 */
BMSReceiver::BMSReceiver()
{

}

/**
 * Description     : Destructor
 *
 */
BMSReceiver::~BMSReceiver()
{

}

/**
 * Description     : Method to insert and process Values of parameters received from Sender
 *                   Accepted Format : JSON String : {"Parameter1" : "Data1" , "Parameter2" : "Data2" . ...}
 *                   Accepted Number of Parameters : Any
 *                   Accepted Number of value for each parameter : One
 *
 *                   Return False if input is not in JSON String format
 *
 */
bool BMSReceiver::insertParamsData_JSON_String(std::string paramsData)
{
	if(isInput_in_JSONFormat(paramsData))
	{
	 boost::property_tree::ptree Jsondata = get_Json_From_String(paramsData);
	 updateParametersMap_withData(Jsondata);
	 return true;
	}
	return false;
}


/**
 * Description     : Method to update received values of various parameters
 *                   Expects Same Parameters to be updated each time
 *
 */
void BMSReceiver::updateParametersMap_withData(boost::property_tree::ptree paramsData)
{
	if(parametersMap.empty())
	{
		initializeParametersMap(paramsData);
	}

	for (boost::property_tree::ptree::const_iterator it = paramsData.begin(); it != paramsData.end(); ++it)
	{
		double value = std::stod((it->second).get_value<std::string>());
		parametersMap[it->first]->insert(value);
	}
}

/**
 * Description     : Method to initialize parameter map
 *                   Each input parameter will be assigned with ParameterData_Handler object to provide storage and computation
 *
 */
void BMSReceiver::initializeParametersMap(boost::property_tree::ptree paramsData)
{
	for (boost::property_tree::ptree::const_iterator it = paramsData.begin(); it != paramsData.end(); ++it)
	{
		parametersMap[it->first] = new ParameterData_Handler(CONFIG_DATA_BUFFER_SIZE);
	}
}


/**
 * Description     : Method to get All Parameters Stats in Sring Format
 *                   Return Format : String containing JSON Formatted stats of All Parameters
 *                                 : {"ParameterName" : "Parameter1" , "Current" : CurrentValue , "Min" : minValue , "Max" : maxValue , "Avg" : runningAvg }
 *                                   {"ParameterName" : "Parameter2" , "Current" : CurrentValue , "Min" : minValue , "Max" : maxValue , "Avg" : runningAvg }
 *                                   ...
 *                   Returns Empty String if No Data Available
 *
 */
std::string BMSReceiver::get_ParamsDataStats_String()
{
	std::string outputStr;
	std::unordered_map<std::string,ParameterData_Handler*>::iterator it = parametersMap.begin();
	for( ; it != parametersMap.end(); ++it)
	{
		boost::property_tree::ptree Jsondata;

		Jsondata.put("ParameterName", it->first);
		Jsondata.put("Current", it->second->getCurrentValue());
		Jsondata.put("Min", it->second->getMinVal());
		Jsondata.put("Max", it->second->getMaxVal());
		Jsondata.put("Avg", it->second->getRunningAvg());

		stringstream output;
		boost::property_tree::json_parser::write_json(output, Jsondata, false);

		outputStr = outputStr + output.str();
	}
	return outputStr;
}






