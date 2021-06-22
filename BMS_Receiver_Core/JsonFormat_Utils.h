/**************************************************************************************
* @file        : JsonFormat_Utils.h
* @brief       : Provides Utility Functionals for handling JSON data
*
**************************************************************************************/

#ifndef BMS_RECEIVER_CORE_JSONFORMAT_UTILS_H_
#define BMS_RECEIVER_CORE_JSONFORMAT_UTILS_H_

#include "boost/property_tree/json_parser.hpp"

bool isInput_in_JSONFormat(std::string data);
boost::property_tree::ptree convert_String_To_JSon(std::string data);
boost::property_tree::ptree get_Json_From_String(std::string data);


#endif /* BMS_RECEIVER_CORE_JSONFORMAT_UTILS_H_ */
