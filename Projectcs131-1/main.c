//-------------------------------------------------------------------------------------------
//	File: 
//
// Functions:
//
//-------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#define CENTS_IN_TWENTYDOLLARS 2000
#define CENTS_IN_TENDOLLARS 1000
#define CENTS_IN_FIVEDOLLARS 500
#define CENTS_IN_ONEDOLLARS 100
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
	printf("Welcome to Change Counter by Son Tran!\n");
	printf("Please enter the total amount of purchase: ");
	scanf("%lf", &purchaseAmount);
	printf("%.2lf\n", purchaseAmount);
	getchar();
	getchar();
	return EXIT_SUCCESS;
}