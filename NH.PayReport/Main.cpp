// Pay Report
// Nicholas Hansen

#include <iostream>
#include <conio.h>

using namespace std;

struct Employee {
	int ID = 0;
	string FirstName;
	string LastName;
	float HoursWorked = 0.0;
	float HourlyRate = 0.0;
};

void EmployeePay(Employee* pE, float pay) {
	cout << pE->ID << ". " << pE->FirstName << " " << pE->LastName << ": $" << pay << "\n";
}

void PrintPayReport(Employee* arr, int size){
	cout << "Pay Report\n";
	cout << "----------\n";
	float totalPay = 0;
	for (int i = 0; i < size; i++) {
		float pay = arr[i].HourlyRate * arr[i].HoursWorked;
		EmployeePay(&arr[i], pay);
		totalPay += pay;
	}
	cout << "\nTotal Pay: $" << totalPay;
}

int main()
{
	int num = -1;

	while (num < 0) { 
		cout << "How many Employees do you have? ";
		cin >> num; 
	}

	cout << '\n';

	Employee* employees = new Employee[num];
	for (int i = 0; i < num; i++) {
		//Automatically creates an Employee ID
		employees[i].ID = i + 1;

		//Asks user for Employee First Name
		cout << "Employee " << employees[i].ID << "'s First Name : ";
		cin >> employees[i].FirstName;

		//Asks user for Employee Last Name
		cout << "Employee " << employees[i].ID << "'s Last Name: ";
		cin >> employees[i].LastName;

		//Asks user for Employee Hours Worked
		cout << "Total hours Employee " << employees[i].ID << " worked: ";
		cin >> employees[i].HoursWorked;

		//Asks user for Employee Hourly Rate
		cout << "Employee " << employees[i].ID << "'s Hourly Rate: ";
		cin >> employees[i].HourlyRate;

		cout << '\n';
	}
	
	PrintPayReport(employees, num);

	(void)_getch();
	return 0;
}
