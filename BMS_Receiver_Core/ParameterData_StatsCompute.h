/**************************************************************************************
* @file        : ParameterData_StatsCompute.h
* @brief       : Provides Functionality to compute various statistics of Parameter Data
*
**************************************************************************************/

#ifndef RECEIVER_PARAMETERDATA_STATSCOMPUTE_H_
#define RECEIVER_PARAMETERDATA_STATSCOMPUTE_H_

#include <iostream>
#include <queue>

class ParameterData_Statistics
{
public :
	ParameterData_Statistics(unsigned int bufferSize);
	virtual ~ParameterData_Statistics();

	virtual void insert(float inputValue);
	float getCurrentValue();
	float getRunningAvg();
	float getMaxVal();
	float getMinVal();

private :

	void updateMin(float inputValue);
	void updateMax(float inputValue);
	void updateRunningTotal(float inputValue);
	void updateBuffer(float inputValue);

	unsigned int windowSize;
	float runningTotal;
	float maxVal;
	float minVal;
	std::queue<float> buffer;
};



#endif /* RECEIVER_PARAMETERDATA_STATSCOMPUTE_H_ */
