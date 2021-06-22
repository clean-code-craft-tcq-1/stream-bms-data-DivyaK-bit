/**************************************************************************************
* @file        : BMS_Receiver_Test_Main.cpp
* @brief       : Provides Test Functionality for BMS Receiver Core
*
**************************************************************************************/
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include <iostream>

#include "catch.hpp"
#include "../BMS_Receiver_Core/JsonFormat_Utils.h"
#include "../BMS_Receiver_Core/BMS_Receiver_Core.h"

TEST_CASE("data Acceptance test - INVALID FORMART - EMPTY INPUT")
{
	BMSReceiver receiverTestObj;

	std::string inputStr = "";
	REQUIRE(receiverTestObj.insertParamsData_JSON_String(inputStr) == false);

}

TEST_CASE("data Acceptance test - INVALID FORMART - INVALID INPUT")
{
	BMSReceiver receiverTestObj;

	std::string inputStr = "abc";
	REQUIRE(receiverTestObj.insertParamsData_JSON_String(inputStr) == false);

}

TEST_CASE("data Acceptance test - VALID FORMART - SINGLE INPUT with 1 Parameter")
{
	BMSReceiver receiverTestObj;

	std::string inputStr = "{\"Charge_rate\": 0.80}";

	REQUIRE(receiverTestObj.insertParamsData_JSON_String(inputStr) == true);

}

TEST_CASE("data Acceptance test - VALID FORMART - SINGLE INPUT with 2 Parameters")
{
	BMSReceiver receiverTestObj;

	std::string inputStr = "{\"Charge_rate\": 0.80, \"Temperature\": 80}";

	REQUIRE(receiverTestObj.insertParamsData_JSON_String(inputStr) == true);

}

TEST_CASE("data Acceptance test - VALID FORMART - SINGLE INPUT with 3 Parameters")
{
	BMSReceiver receiverTestObj;

	std::string inputStr = "{\"Charge_rate\": 0.80, \"Temperature\": 80, \"Voltage\": 5}";

	REQUIRE(receiverTestObj.insertParamsData_JSON_String(inputStr) == true);

}



TEST_CASE("data validation test - VALID DATA OUTPUT - SINGLE INPUT with 2 Parameters")
{
	BMSReceiver receiverTestObj;

	std::string inputStr = "{\"Charge_rate\": 0.80, \"Temperature\": 80}";

	REQUIRE(receiverTestObj.insertParamsData_JSON_String(inputStr) == true);

	std::string paramsStats_Str = receiverTestObj.get_ParamsDataStats_String();

	REQUIRE( paramsStats_Str.empty() != true);

}

TEST_CASE("data validation test - VALID DATA OUTPUT - MULTIPLE INPUTS with 2 Parameters")
{
	BMSReceiver receiverTestObj;

	std::string inputStr = "{\"Charge_rate\": 0.80, \"Temperature\": 40}";
	REQUIRE(receiverTestObj.insertParamsData_JSON_String(inputStr) == true);

	inputStr = "{\"Charge_rate\": 0.60, \"Temperature\": 30}";
	REQUIRE(receiverTestObj.insertParamsData_JSON_String(inputStr) == true);

	std::string paramsStats_Str = receiverTestObj.get_ParamsDataStats_String();

	REQUIRE( paramsStats_Str.empty() != true);

}

TEST_CASE("data validation test - CHECK FOR STATS - SINGLE INPUTS with 1 Parameters")
{
	BMSReceiver receiverTestObj;

	std::string inputStr = "{\"Temperature\": 80}";
	REQUIRE(receiverTestObj.insertParamsData_JSON_String(inputStr) == true);

	std::string paramsStats_Str = receiverTestObj.get_ParamsDataStats_String();
	unsigned int delimiter_pos = paramsStats_Str.find('}');
	std::string param_Charge_rate_str = paramsStats_Str.substr(0,delimiter_pos+1);

	boost::property_tree::ptree Jsondata = get_Json_From_String(param_Charge_rate_str);

	REQUIRE(Jsondata.get<std::string>("ParameterName").compare("Temperature") == 0);
	REQUIRE(Jsondata.get<std::string>("Current").compare("80") == 0);
	REQUIRE(Jsondata.get<std::string>("Min").compare("80") == 0);
	REQUIRE(Jsondata.get<std::string>("Max").compare("80") == 0);
	REQUIRE(Jsondata.get<std::string>("Avg").compare("80") == 0);

}

TEST_CASE("data validation test - CHECK FOR STATS - 1 INPUT with 2 Parameters")
{
	BMSReceiver receiverTestObj;

	std::string inputStr = "{\"Charge_rate\": 1, \"Temperature\": 50}";
	REQUIRE(receiverTestObj.insertParamsData_JSON_String(inputStr) == true);

	std::string paramsStats_Str = receiverTestObj.get_ParamsDataStats_String();
	unsigned int delimiter_pos = paramsStats_Str.find('}');
	std::string param_str = paramsStats_Str.substr(0,delimiter_pos+1);

	boost::property_tree::ptree Jsondata = get_Json_From_String(param_str);

	REQUIRE(Jsondata.get<std::string>("ParameterName").compare("Temperature") == 0);
	REQUIRE(Jsondata.get<std::string>("Current").compare("50") == 0);
	REQUIRE(Jsondata.get<std::string>("Min").compare("50") == 0);
	REQUIRE(Jsondata.get<std::string>("Max").compare("50") == 0);
	REQUIRE(Jsondata.get<std::string>("Avg").compare("50") == 0);

	unsigned int delimiter_pos_new = paramsStats_Str.find('{',delimiter_pos);
	unsigned int delimiter_pos_end = paramsStats_Str.find('}',delimiter_pos+1);
	param_str = paramsStats_Str.substr(delimiter_pos_new,delimiter_pos_end);

	Jsondata = get_Json_From_String(param_str);

	REQUIRE(Jsondata.get<std::string>("ParameterName").compare("Charge_rate") == 0);
	REQUIRE(Jsondata.get<std::string>("Current").compare("1") == 0);
	REQUIRE(Jsondata.get<std::string>("Min").compare("1") == 0);
	REQUIRE(Jsondata.get<std::string>("Max").compare("1") == 0);
	REQUIRE(Jsondata.get<std::string>("Avg").compare("1") == 0);

}

TEST_CASE("data validation test - CHECK FOR STATS - 2 INPUTS with 2 Parameters")
{
	BMSReceiver receiverTestObj;

	std::string inputStr = "{\"Charge_rate\": 1, \"Temperature\": 50}";
	REQUIRE(receiverTestObj.insertParamsData_JSON_String(inputStr) == true);

	inputStr = "{\"Charge_rate\": 0, \"Temperature\": 60}";
	REQUIRE(receiverTestObj.insertParamsData_JSON_String(inputStr) == true);


	std::string paramsStats_Str = receiverTestObj.get_ParamsDataStats_String();
	unsigned int delimiter_pos = paramsStats_Str.find('}');
	std::string param_str = paramsStats_Str.substr(0,delimiter_pos+1);

	boost::property_tree::ptree Jsondata = get_Json_From_String(param_str);

	REQUIRE(Jsondata.get<std::string>("ParameterName").compare("Temperature") == 0);
	REQUIRE(Jsondata.get<std::string>("Min").compare("50") == 0);
	REQUIRE(Jsondata.get<std::string>("Max").compare("60") == 0);
	REQUIRE(Jsondata.get<std::string>("Avg").compare("55") == 0);

	unsigned int delimiter_pos_new = paramsStats_Str.find('{',delimiter_pos);
	unsigned int delimiter_pos_end = paramsStats_Str.find('}',delimiter_pos+1);
	param_str = paramsStats_Str.substr(delimiter_pos_new,delimiter_pos_end);

	Jsondata = get_Json_From_String(param_str);

	REQUIRE(Jsondata.get<std::string>("ParameterName").compare("Charge_rate") == 0);
	REQUIRE(Jsondata.get<std::string>("Min").compare("0") == 0);
	REQUIRE(Jsondata.get<std::string>("Max").compare("1") == 0);
	REQUIRE(Jsondata.get<std::string>("Avg").compare("0.5") == 0);

}
