#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "hotel.h"
#define MAX 10

int main(){
	Earnings *earnHead = NULL;
	Expen *expenHead = NULL;

	int go = 1, choice;

	while(go != 0){

	printf("\n\t**********WELCOME**********\t\n");

	printf("\n\t1) Book Room");
	printf("\n\t2) View Earnings");
	printf("\n\t3) Add Expenditures");
	printf("\n\t4) View Expenditures");
	printf("\n\t5) View Total Revenue");

		printf("\n\tEnter a choice: ");
		scanf("%d%*c", &choice);

		switch(choice){
			case 1:
				system("cls");
				printf("\n\t**********BOOKING**********\t\n");
				Customer *cust = getCustDetails();
				earnHead = insertEarnigs(earnHead, cust);
				break;
			case 2:
				system("cls");
				printf("\n\t**********EARNINGS DETAILS**********\t\n");
				displayEarnSum(earnHead);
				break;
			case 3:
				system("cls");
				printf("\n\t**********ADDING EXPENDITURE VALUES**********\t\n");
				Expenditure *expenditure = getExpenDetails();
				expenHead = insertExpen(expenHead, expenditure);

				break;

			case 4:
				system("cls");
				printf("\n\t**********EXPENDITURE DETAILS**********\t\n");
				displaySpendSum(expenHead);
				break;

			case 5:
				system("cls");
				printf("\n\t**********REVENUE**********\t\n");
				displayRevenue(earnHead, expenHead);
				break;
            default:
                printf("Invalid Choice");
                exit(0);

		}
	}

	return 0;
}

