/**************************************************************************************
* @file        : BatteryParameter_DataHandler.cpp
* @brief       : Provides Functionality to Handle each Parameters Data
*
**************************************************************************************/

#include "BatteryParameter_DataHandler.h"

/**
 * Description     : Constructor
 *
 */
ParameterData_Handler::ParameterData_Handler(unsigned int bufferSize)
: ParameterData_Statistics(bufferSize)
{

}

/**
 * Description     : Destructor
 *
 */
ParameterData_Handler::~ParameterData_Handler()
{

}

/**
 * Description     : Method to insert data to handle Parameter Statistics
 *
 */
void ParameterData_Handler::insert(float inputValue)
{
	ParameterData_Statistics::insert(inputValue);
}


