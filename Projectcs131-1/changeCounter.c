//-------------------------------------------------------------------------------------------
//	File:		changeCounter.c
//
// Functions:	main(void)	
//
//-------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define CENTS_IN_TWENTYDOLLARS 2000
#define CENTS_IN_TENDOLLARS 1000
#define CENTS_IN_FIVEDOLLARS 500
#define CENTS_IN_ONEDOLLARS 100
#define CENTS_IN_QUARTER 25
#define CENTS_IN_DIME 10
#define CENTS_IN_NICKLE 5
#define CENTS_IN_PENNY 1
#define ZERO 0
#define ONE 1
#define TOOBIG 9999999999 
//----------------------------------------------------------------------------
//	Function:		main(void)		
//
// Title:			Change Counter
//
//	Description:	The program will takes in a specific amount of dollars
//										
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
	long double purchaseAmount = 0;
	long double moneyTendered = 0;
	long double change = 0;
	_Bool invalidPur = false;
	_Bool invalidTend = true;
	int scanPur = 0;
	int scanTend = 0;
	int roundNumber = 100;
	int numberForRounding = 0.5;
	unsigned long long twentyBill = 0;
	int tenBill = 0;
	int fiveBill = 0;
	int oneBill = 0;
	int quarterCoin = 0;
	int dimeCoin = 0;
	int nickleCoin = 0;
	int pennyCoin = 0;
	long long tempChangeInCent = 0;
	printf("Welcome to Change Counter by Son Tran!\n");
	printf("Please enter the total amount of purchase: $");
	scanPur = scanf("%lf", &purchaseAmount);
	invalidPur = scanPur != ONE;
	while (getchar() != '\n');
	while (invalidPur)
	{
		printf("Invalid purchase amount, input should be number, " 
			"please enter again: $");
		scanPur = scanf("%lf", &purchaseAmount);
		while (getchar() != '\n');
		invalidPur = scanPur != ONE;
	}
	purchaseAmount = floor(purchaseAmount * roundNumber + numberForRounding)
		/ roundNumber;
	printf("$%.2lf\n", purchaseAmount);

	printf("Please enter amount of money tendered: $");
	scanTend = scanf("%lf", &moneyTendered);
	invalidTend = scanTend != ONE;
	while (getchar() != '\n');
	while (invalidTend)
	{
		printf("Invalid tender amount, input should be number, "
			"please enter again: $");
		scanTend = scanf("%lf", &moneyTendered);
		while (getchar() != '\n');
		invalidTend = scanTend != ONE;
	}
	moneyTendered = floor(moneyTendered * roundNumber + numberForRounding)
		/ roundNumber;
	printf("$%.2lf\n", moneyTendered);
	printf("\n");
	change = moneyTendered - purchaseAmount;
	printf("Your change is: $%.2lf\n", change);
	printf("\n");
	if (change < ZERO)
	{
		printf("Change still owing\n");
	}
	tempChangeInCent = fabs(change) * roundNumber;
	twentyBill = tempChangeInCent / CENTS_IN_TWENTYDOLLARS;
	tempChangeInCent -= twentyBill * CENTS_IN_TWENTYDOLLARS;
	tenBill = tempChangeInCent / CENTS_IN_TENDOLLARS;
	tempChangeInCent -= tenBill * CENTS_IN_TENDOLLARS;
	fiveBill = tempChangeInCent / CENTS_IN_FIVEDOLLARS;
	tempChangeInCent -= fiveBill * CENTS_IN_FIVEDOLLARS;
	oneBill = tempChangeInCent / CENTS_IN_ONEDOLLARS;
	tempChangeInCent -= oneBill * CENTS_IN_ONEDOLLARS;
	quarterCoin = tempChangeInCent / CENTS_IN_QUARTER;
	tempChangeInCent -= quarterCoin * CENTS_IN_QUARTER;
	dimeCoin = tempChangeInCent / CENTS_IN_DIME;
	tempChangeInCent -= dimeCoin * CENTS_IN_DIME;
	nickleCoin = tempChangeInCent / CENTS_IN_NICKLE;
	tempChangeInCent -= nickleCoin * CENTS_IN_NICKLE;
	pennyCoin = tempChangeInCent / CENTS_IN_PENNY;
	printf("Twenties : %d\n", twentyBill);
	printf("Tens     : %d\n", tenBill);
	printf("Fives    : %d\n", fiveBill);
	printf("Ones     : %d\n", oneBill);
	printf("Quarters : %d\n", quarterCoin);
	printf("Dimes    : %d\n", dimeCoin);
	printf("Nickles  : %d\n", nickleCoin);
	printf("Pennies  : %d\n", pennyCoin);
	printf("-------------------------------------------------\n");
	printf("Thank you for using Change Counter.\nHave a nice day!\n");
	while (getchar() != '\n');
	return EXIT_SUCCESS;
}
