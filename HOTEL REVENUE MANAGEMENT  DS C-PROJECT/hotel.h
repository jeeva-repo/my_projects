#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

typedef struct customerDetails {
    char name[MAX];
    int room_no;
    char month[MAX];
    int amt;
    char address[MAX];
    char room_type[MAX];
    char arrival_date[MAX];
    int days_stay;
} Customer;

typedef struct earnings {
	Customer *customer;
	struct earnings *next;
} Earnings;

typedef struct expenditure {
	char month[MAX];
	int electricity_bill;
	int maintenance_bill;
	int employee_salary;
} Expenditure;

typedef struct expen {
	Expenditure *expenditure;
	struct expen *next;
} Expen;

Customer *createCust(char *name, int room_no, char *month, int amt,char *address,char *room_type, char *arrival_date, int days_stay){
    Customer *newCust = (Customer *)malloc(sizeof(Customer));

    strcpy(newCust->name, name);
    newCust->room_no = room_no;
    strcpy(newCust->month, month);
    newCust->amt = amt;
    strcpy(newCust->address, address);
    strcpy(newCust->room_type, room_type);
    strcpy(newCust->arrival_date, arrival_date);
    newCust->days_stay = days_stay;

    return newCust;
}

Customer *getCustDetails(){
    char name[MAX], month[MAX],address[MAX], room_type[MAX], arrival_date[MAX];
    int room_no, amt, days_stay;

    printf("\n\tEnter customer name: ");
    scanf("%[^\n]%*c", name);

    printf("\n\tEnter customer room no: ");
    scanf("%d%*c", &room_no);

    printf("\n\tEnter customer'S address: ");
    scanf("%[^\n]%*c", address );

    printf("\n\tEnter room type: ");
    scanf("%[^\n]%*c", room_type);

    printf("\n\tEnter Arrival Date: ");
    scanf("%[^\n]%*c", arrival_date);

    printf("\n\tEnter no. of days of Stay: ");
    scanf("%d%*c", &days_stay);

    printf("\n\tEnter Month: ");
    scanf("%[^\n]%*c", month);

    printf("\n\tEnter the Amount: ");
    scanf("%d%*c", &amt);


    Customer *cust = createCust(name, room_no, month, amt, address, room_type, arrival_date, days_stay);

    return cust;
}

void displayCust(Customer *cust){
	printf("\n\t**********CUSTOMER DETAILS**********\t\n");

	printf("\n\tName: %s", cust->name);
	printf("\n\tAddress: %s", cust->address);
	printf("\n\tRoom No: %d", cust->room_no);
	printf("\n\tRoom Type: %s", cust->room_type);
	printf("\n\tMonth: %s", cust->month);
	printf("\n\tArrival Date: %s", cust->arrival_date);
	printf("\n\tDays Stayed: %d", cust->days_stay);
	printf("\n\tAmount: %d", cust->amt);
}

Earnings *createEarnNode(Customer *cust){
	Earnings *newEarnNode = (Earnings *)malloc(sizeof(Earnings));

	newEarnNode->customer = cust;
	newEarnNode->next = NULL;

	return newEarnNode;
}

Earnings *insertEarnigs(Earnings *head, Customer *cust){
	Earnings *newEarnNode = createEarnNode(cust);

	if(head == NULL){
		head = newEarnNode;

		return head;
	}

	newEarnNode->next = head;
	head = newEarnNode;

	return head;
}

void displayEarn(Earnings *head){
	Earnings *temp = head;

	while(temp != NULL){
		printf("\n\tName: %s", temp->customer->name);
		printf("\n\tMonth: %s", temp->customer->month);
		printf("\n\tAmount: %d\n", temp->customer->amt);

		temp = temp->next;

	}
}

Expenditure *createExpenditure(char *month, int elec, int maint, int emp) {
	Expenditure *expen = (Expenditure *)malloc(sizeof(Expenditure));

	expen->electricity_bill = elec;
	expen->employee_salary = emp;
	expen->maintenance_bill = maint;
	strcpy(expen->month, month);

	printf("\n\tThe details updated successfully.\n");

	return expen;
}

Expen *createExpenNode(Expenditure *expenditure){
	Expen *newExpenNode = (Expen *)malloc(sizeof(Expen));

	newExpenNode->expenditure = expenditure;
	newExpenNode->next = NULL;

	return newExpenNode;
}

Expen *insertExpen(Expen *head, Expenditure *expenditure){
	Expen *newExpenNode = createExpenNode(expenditure);

	if(head == NULL){
		head = newExpenNode;

		return head;
	}

	newExpenNode->next = head;
	head = newExpenNode;

	return head;
}

int spend_sum(Expen *head, char month[]) {
        Expen *ptr = head;
        int sum =0;

        if(ptr == NULL)
        {
            printf("\n\tEmpty list..\n\t");
        }
        else
        {
            printf("\n\tPrinting values . . . . .\t\n");
            while (ptr != NULL)
            {
                if(!strcasecmp(month, ptr->expenditure->month)){
					sum += ptr->expenditure->electricity_bill;
					sum += ptr->expenditure->maintenance_bill;
					sum += ptr->expenditure->employee_salary;
                }
                ptr = ptr -> next;
            }
        }
        return sum;
}

int earnings_sum(Earnings *head, char month[]){
	Earnings *ptr = head;
	int sum = 0;

	if(ptr == NULL)
	{
		printf("\n\tEmpty list..\n\t");
	}
	else
	{
		while (ptr != NULL)
		{
			if(!strcasecmp(month, ptr->customer->month)){
				sum += ptr->customer->amt;
			}
			ptr = ptr->next;
		}
	}
	return sum;
}

Expenditure *getExpenDetails(){
	char month[MAX];
	int electric_bill, maintenance_bill, employee_salary;

	printf("\n\tEnter the expenditure details here:\t\n");

	printf("\n\tEnter the Month: ");
	scanf("%[^\n]%*c", month);

	printf("\n\tEnter the Expenditure for the month - %s:\t\n", month);

	printf("\n\tEnter the electricity charges: ");
	scanf("%d%*c", &electric_bill);

	printf("\n\tEnter the Maintenance Charge:");
	scanf("%d%*c", &maintenance_bill);

	printf("\n\tEnter the Money spent for the employee salary: ");
	scanf("%d%*c", &employee_salary);

    Expenditure *expen = createExpenditure(month, electric_bill, maintenance_bill, employee_salary);
    printf("\n\tThe data has been entered Successfully.");

    return expen;
}

void displaySpendSum(Expen *head){
	char choice, month[MAX];

    printf("\n\tDo you want to know the how much you spend this month:(Y/N)?");
    scanf("%[^\n]%*c", &choice);

    printf("\n\tEnter the month: ");
    scanf("%[^\n]%*c", month);

	if (choice =='y'|| choice == 'Y'){
        printf("\n\tThe total money spent for %s is %d.\t\n", month, spend_sum(head, month));
    }
}

void displayEarnSum(Earnings *head){
	char choice, month[MAX];

    printf("\n\tDo you want to know how much you earned this month:(Y/N)? ");
    scanf("%[^\n]%*c", &choice);

    printf("\n\tEnter the month: ");
    scanf("%[^\n]%*c", month);

	if (choice =='y'|| choice == 'Y'){
        printf("\n\tThe total money earned for %s is %d.\t\n", month, earnings_sum(head, month));
    }
}

int revenue(Earnings *earnHead, Expen *expenHead, char month[]){
	int earnings = earnings_sum(earnHead, month);
	int expenditure = spend_sum(expenHead, month);

	return earnings - expenditure;
}

void displayRevenue(Earnings *earnHead, Expen *expenHead){
	char choice, month[MAX];

    printf("\n\tDo you want to know the Total Reveue:(Y/N)? ");
    scanf("%[^\n]%*c", &choice);

    printf("\n\tEnter the month: ");
    scanf("%[^\n]%*c", month);

	if (choice =='y'|| choice == 'Y'){
        printf("\n\tThe Total Revenue for %s is %d.\t\n", month, revenue(earnHead, expenHead, month));
    }
}
