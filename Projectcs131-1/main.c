//-------------------------------------------------------------------------------------------
//	File: 
//
// Functions:
//
//-------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define CENTS_IN_TWENTYDOLLARS 2000
#define CENTS_IN_TENDOLLARS 1000
#define CENTS_IN_FIVEDOLLARS 500
#define CENTS_IN_ONEDOLLARS 100
#define ZERO 0;
#define ONE 1;
#define TOOBIG 9999999999; 
//-------------------------------------------------------------------------------------------
//	Function:
//
// Title:
//
//	Description: 
// 
//
// Programmer: 
// 
// Date:
// Version: 
//
//	Environment:
//                     Hardware:
//
//                      Software:
//
//	Input:
//
//	Output: 
//
//	Parameters:
// 
//
// Returns:
// 
// 
//	Called By:
// 
//	Calls: 
//
//	History Log:
//
// 
//----------------------------------------------------------------------------


int main(void)
{
	double purchaseAmount = 0;
	double moneyTendered = 0;
	double change = 0;
	_Bool invalidPur = false;
	_Bool invaliddTend = true;
	int scanPur = 0;
	printf("Welcome to Change Counter by Son Tran!\n");
	printf("Please enter the total amount of purchase: $");
	scanPur = scanf("%lf", &purchaseAmount);
	while (getchar() != '\n');
	while (invalidPur)
	{
		//printf("Invalid t, total amount of purchase should be number from 0 to 9999999999, please enter the ")
	}
	invalidPur = scanPur != ONE & purchaseAmount > TOOBIG;
	printf("$%.2lf\n", purchaseAmount);
	printf("Please enter amount of money tendered: $");
	scanf("%lf", &moneyTendered);
	printf("$%.2lf\n", moneyTendered);
	change = moneyTendered - purchaseAmount;
	printf("Your change is: $%.2lf\n", change);
	getchar();
	getchar();
	return EXIT_SUCCESS;
}
