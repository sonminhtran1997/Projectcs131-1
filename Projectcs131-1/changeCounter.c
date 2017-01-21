//----------------------------------------------------------------------------
// File:			changeCounter.c
//
// Functions:		main(void)	
//
//----------------------------------------------------------------------------
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
// Function:		main(void)		
//
// Title:			Change Counter
//
// Description:		The program will takes in a specific amount of dollars
//					and the amount of tender. After that it will give the
//					list amount of change in different type of bills
//									
// Programmer:		Son Minh Tran
// 
// Date:			01/17/2017

// Version:			1.0
//
// Environment:		HP Elitebook 8570P 
//					Hardware: 8GB
//							  Intel(R) Core(TM) i5-3320M 
//					Software: OS: MS Windows 10 Professional 64-bit
//
// Input:			The amount of dollar for a purchase
//					The amount of money tendered
// Output:			Give out the amount of change 
//					Amount of twenty dollars
//					Amount of ten dollars
//					Amount of five dollars
//					Amount of one dollar
//					Amount of quarters
//					Amount of dimes
//					Amount of nickels
//					Amount of pennies
//
// Parameters:		void
// 
//
// Returns:			EXIT_SUCCESS for successful completion
// 
// 
// Called By:		None
// 
// Calls:			None
//
// History Log:		Commit github on 05/01/2017: Initialize the project
//					Commit github on 07/01/2017: Finished finding change
//					Commit github on 17/01/2017: Change to deal with 
//					big number
//----------------------------------------------------------------------------


int main(void)
{
	//Declare and initialize all the variable
	long double purchaseAmount = 0.0L;
	long double moneyTendered = 0.0L;
	long double change = 0.0;
	_Bool invalidPur = false;
	_Bool invalidTend = false;
	int scanPur = 0;
	int scanTend = 0;
	int roundNumber = 100;
	double numberForRounding = 0.5;
	unsigned long long twentyBill = 0llu;
	int tenBill = 0;
	int fiveBill = 0;
	int oneBill = 0;
	int quarterCoin = 0;
	int dimeCoin = 0;
	int nickleCoin = 0;
	int pennyCoin = 0;
	unsigned long long tempChangeInCent = 0ll;
	//Print out to command line and ask for input of purchase and tender
	printf("Welcome to Change Counter by Son Tran!\n");
	printf("Please enter the total amount of purchase: $");
	//read in amount of purchase
	scanPur = scanf("%Lf", &purchaseAmount);
	//check for the input type
	invalidPur = scanPur != ONE;
	//Continue ask to enter input until it get correct type
	while (getchar() != '\n');
	while (invalidPur)
	{
		printf("Invalid purchase amount, input should be number, "
			"please enter again: $");
		scanPur = scanf("%Lf", &purchaseAmount);
		while (getchar() != '\n');
		invalidPur = scanPur != ONE;
	}
	//round up to two number after the point of purchase amount
	purchaseAmount = floor(purchaseAmount * roundNumber + numberForRounding)
		/ roundNumber;
	printf("$%.2Lf\n", purchaseAmount);
	//ask and read in tender amount
	printf("Please enter amount of money tendered: $");
	scanTend = scanf("%Lf", &moneyTendered);
	//check for input type
	invalidTend = scanTend != ONE;
	//Continue ask to enter input until it get correct type
	while (getchar() != '\n');
	while (invalidTend)
	{
		printf("Invalid tender amount, input should be number, "
			"please enter again: $");
		scanTend = scanf("%Lf", &moneyTendered);
		while (getchar() != '\n');
		invalidTend = scanTend != ONE;
	}
	//round of to two number after the point of purchase amount
	moneyTendered = floor(moneyTendered * roundNumber + numberForRounding)
		/ roundNumber;
	printf("$%.2Lf\n", moneyTendered);
	printf("\n");
	//calculate change amount
	change = moneyTendered - purchaseAmount;
	tempChangeInCent = fabs(tempChangeInCent);
	tempChangeInCent = floor(change * roundNumber + numberForRounding);
	printf("Your change is: $%.2Lf\n", change);
	printf("\n");
	//check if the user is still owing or not
	if (change < ZERO)
	{
		printf("Change still owing\n");
	}
	//calculate amount of all types of bills
	twentyBill = tempChangeInCent / CENTS_IN_TWENTYDOLLARS;
	tempChangeInCent %= CENTS_IN_TWENTYDOLLARS;
	tenBill = tempChangeInCent / CENTS_IN_TENDOLLARS;
	tempChangeInCent %= CENTS_IN_TENDOLLARS;
	fiveBill = tempChangeInCent / CENTS_IN_FIVEDOLLARS;
	tempChangeInCent %= CENTS_IN_FIVEDOLLARS;
	oneBill = tempChangeInCent / CENTS_IN_ONEDOLLARS;
	tempChangeInCent %= CENTS_IN_ONEDOLLARS;
	quarterCoin = tempChangeInCent / CENTS_IN_QUARTER;
	tempChangeInCent %= CENTS_IN_QUARTER;
	dimeCoin = tempChangeInCent / CENTS_IN_DIME;
	tempChangeInCent %= CENTS_IN_DIME;
	nickleCoin = tempChangeInCent / CENTS_IN_NICKLE;
	tempChangeInCent %= CENTS_IN_NICKLE;
	pennyCoin = tempChangeInCent / CENTS_IN_PENNY;
	//print out amounts of all type of bills
	printf("Twenties : %llu\n", twentyBill);
	printf("Tens     : %d\n", tenBill);
	printf("Fives    : %d\n", fiveBill);
	printf("Ones     : %d\n", oneBill);
	printf("Quarters : %d\n", quarterCoin);
	printf("Dimes    : %d\n", dimeCoin);
	printf("Nickles  : %d\n", nickleCoin);
	printf("Pennies  : %d\n", pennyCoin);
	printf("-------------------------------------------------\n");
	printf("Thank you for using Change Counter.\nHave a nice day!\n");
	//clean out all the buffer
	while (getchar() != '\n');
	//return successful message to the program
	return EXIT_SUCCESS;
}
