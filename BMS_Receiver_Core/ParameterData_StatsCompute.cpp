/**************************************************************************************
* @file        : ParameterData_StatsCompute.cpp
* @brief       : Provides Functionality to compute various statistics of Parameter Data
*
**************************************************************************************/
#include "ParameterData_StatsCompute.h"

/**
 * Description     : Constructor
 *
 */
ParameterData_Statistics::ParameterData_Statistics(unsigned int bufferSize)
: windowSize(bufferSize)
, runningTotal(0.0)
, maxVal(0.0)
, minVal(-1)
{

}

/**
 * Description     : Destructor
 *
 */
ParameterData_Statistics::~ParameterData_Statistics()
{
}

/**
 * Description     : Method to insert data to buffer and update different stats
 *
 */
void ParameterData_Statistics::insert(float inputValue)
{
	updateBuffer(inputValue);
	updateMin(inputValue);
	updateMax(inputValue);
	updateRunningTotal(inputValue);
}

/**
 * Description     : Method to insert data to buffer
 *                   If the buffer is Full , pop oldest element from Back and insert new element to Front
 *
 */
void ParameterData_Statistics::updateBuffer(float inputValue)
{
	/*check if buffer is full*/
	if (buffer.size() == windowSize)
	{
		runningTotal -= buffer.front(); /*subtract front value from running total*/
		buffer.pop();                   /*delete value from front of std::queue*/
	}

	buffer.push(inputValue);    /*add new value*/
}

/**
 * Description     : Method to update Min Value
 *
 */
void ParameterData_Statistics::updateMin(float inputValue)
{
	if(inputValue < minVal || minVal == -1)
	{
		minVal = inputValue;   /*update min value*/
	}
}

/**
 * Description     : Method to update Max Value
 *
 */
void ParameterData_Statistics::updateMax(float inputValue)
{
	if(inputValue > maxVal)
	{
		maxVal = inputValue;   /*update max value*/
	}
}

/**
 * Description     : Method to update Running Total of Buffer
 *
 */
void ParameterData_Statistics::updateRunningTotal(float inputValue)
{
	runningTotal += inputValue; /*update running total*/
}

/**
 * Description     : Method to get Current Parameter Value
 *
 */
float ParameterData_Statistics::getCurrentValue()
{
	return buffer.back();
}

/**
 * Description     : Method to get Current Running Average
 *
 */
float ParameterData_Statistics::getRunningAvg()
{
	return static_cast<float>(runningTotal / buffer.size());
}

/**
 * Description     : Method to get Max Value attained
 *
 */
float ParameterData_Statistics::getMaxVal()
{
	return maxVal;
}

/**
 * Description     : Method to get Min Value attained
 *
 */
float ParameterData_Statistics::getMinVal()
{
	return minVal;
}



