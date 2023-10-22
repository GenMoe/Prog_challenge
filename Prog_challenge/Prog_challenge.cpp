#include <iostream>
#include <string>
using namespace std;

//Day of the year class declaration
class DayOfYear
{
private:
	int day;
public:
	static int MonthDay[];
	static string NameMonth[];
	void print();
	void setDay(int day) { this-> day = day; }
};

// RESERVE space for all static class variables

//Set days of each month into an array
int DayOfYear::MonthDay[] = { 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
//Set the name of each month into an array
string DayOfYear::NameMonth[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };



void DayOfYear::print()
{
	int month = 0;

	while (DayOfYear::MonthDay[month] < day)
	
		month = (month + 1) % 12;
	if (month == 0)
		cout << "\nJanuary " << day << endl << endl;
	else
	{
		cout << endl << NameMonth[month] << " "
			<< day - MonthDay[month - 1] << endl << endl;
	}
}
//		cout << DayOfYear::NameMonth[month] << " " << day - DayOfYear::MonthDay[month - 1];

int main()
{
	DayOfYear dayOfYearObj;

	int day;
	cout << "Enter a number day of the year to translate into Month and day." << endl;
	cin >> day;

	//Error case: Under 0 or above 365
	if (day <= 0 || day > 365)
	{
		cout << "Error: Please enter a number between (0 and 365)." << endl;
	}

	dayOfYearObj.setDay(day);
	//print funt
	dayOfYearObj.print();

	return 0;
}