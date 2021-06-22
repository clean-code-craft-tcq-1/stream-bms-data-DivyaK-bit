/**************************************************************************************
* @file        : JsonFormat_Utils.cpp
* @brief       : Provides Utility Functionals for handling JSON data
*
**************************************************************************************/

#include <iostream>

#include "JsonFormat_Utils.h"

/**
 * Description     : Method check if input argument is in JSON format
 *                   Returns true if in JSON format. False otherwise
 *
 */
bool isInput_in_JSONFormat(std::string input)
{
	try
	{
		std::stringstream inputStream;
		inputStream.str(input);
		boost::property_tree::ptree Jsondata;
		boost::property_tree::json_parser::read_json(inputStream,Jsondata);
	}
	catch (const boost::property_tree::ptree_error &e)
	{
		return false;
	}
	return true;
}

/**
 * Description     : Method to create and return a JSON object from input string
 *
 */
boost::property_tree::ptree get_Json_From_String(std::string data)
{
	std::stringstream input;
	input.str(data);
	boost::property_tree::ptree Jsondata;
	boost::property_tree::json_parser::read_json(input,Jsondata);

	return Jsondata;
}
