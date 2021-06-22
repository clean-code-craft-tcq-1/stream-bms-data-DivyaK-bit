/**************************************************************************************
* @file        : BMS_Receiver_Main.cpp
* @brief       : Provides Main for Receiver and Operates the Receiver object based on console Input
*
**************************************************************************************/

#include <iostream>
#include <unistd.h>
#include <thread>
#include <chrono>

#include "../BMS_Receiver_Core/BMS_Receiver_Core.h"

using namespace std;

#define START_CONDITION "START"
#define STOP_CONDITION  "STOP"

#define SUCCESS 0

/**
 * Description     : Method to check and handle console input
 *                   Condition to start                  : console input as "START"
 *
 */
bool checkFor_Start()
{
	std::string input;

	while(true)
	{
		std::getline(cin,input);
		if( input.compare(START_CONDITION) == SUCCESS )
		{
			return true;
		}
	}
}

/**
 * Description     : Method to print data to console
 *
 */
void printToConsole(std::string data)
{
	std::cout<<data;
}

/**
 * Description     : Method to read and update and print stats for the Parameters data from console
 *                   Also checks for Condition to Receiver Thread : console input as "STOP"
 *
 */
void receiveParametersData()
{
	std::string input;
	BMSReceiver receiverObj;

	while(true)
	{
		std::getline(cin,input);
		if( input.compare(STOP_CONDITION) == SUCCESS )
		{
			return ;
		}

		receiverObj.insertParamsData_JSON_String(input);
		printToConsole(receiverObj.get_ParamsDataStats_String());
	}
}

/**
 * Description     : Main Method
 *                   Starts Receiver Thread Once Start Condition is Satisfied
 *                   Process Received Parameters data
 *                   Stops  Receiver Thread Once Stop Condition is Satisfied
 *
 */
int main()
{
	bool startReceiver = checkFor_Start();
	if(startReceiver)
	{
		std::thread inp(receiveParametersData);

		inp.join();
	}

	return 0;

}
