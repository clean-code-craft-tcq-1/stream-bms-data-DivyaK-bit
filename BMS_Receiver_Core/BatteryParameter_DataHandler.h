/**************************************************************************************
* @file        : BatteryParameter_DataHandler.h
* @brief       : Provides Functionality to Handle each Parameters Data
*
**************************************************************************************/

#ifndef BATTERYPARAMETER_DATAHANDLER_H_
#define BATTERYPARAMETER_DATAHANDLER_H_

#include "ParameterData_StatsCompute.h"

class ParameterData_Handler : public ParameterData_Statistics
{
public :
	ParameterData_Handler(unsigned int bufferSize);
	virtual ~ParameterData_Handler();

	virtual void insert(float inputValue);
};



#endif /* BATTERYPARAMETER_DATAHANDLER_H_ */
