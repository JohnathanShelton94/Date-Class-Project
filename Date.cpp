//This is the Implementation file for the Date Class Project

#include "Date.h"
#include <iostream>
#include <stdexcept>
using namespace std;

    // Default constructor
Date::Date() : month(1), day(1), year(1930) {}

    // Parameterized constructor
Date::Date(int month, int day, int year) {
    setDate(month, day, year);
}

    // Set date with validation
void Date::setDate(int month, int day, int year) {
    if (month < 1 || month > 12 || day < 1 || day > daysInMonth(month, year)) {
        throw invalid_argument("Invalid date.");
    }
    this->month = month;
    this->day = day;
    this->year = year;
}

    // Getters
int Date::getMonth() const { return month; }
int Date::getDay() const { return day; }
int Date::getYear() const { return year; }

    // Check leap year
bool Date::isLeapYear(int year) const {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

    // Days in a month
int Date::daysInMonth(int month, int year) const {
    static const int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return (month == 2 && isLeapYear(year)) ? 29 : days[month - 1];
}

    // Print formats
void Date::printFormat1() const {
    cout << month << "/" << day << "/" << year << endl;
}

void Date::printFormat2() const {
    static const string monthNames[] = { "", "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December" };
    cout << monthNames[month] << " " << day << ", " << year << endl;
}

void Date::printFormat3() const {
    static const string monthNames[] = { "", "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December" };
    cout << day << " " << monthNames[month] << " " << year << endl;
}

    // Pre-decrement operator: --Date
Date& Date::operator--() {
    month--;
    if (month < 1) { 
        month = 12;
        year--;
    }
    day = daysInMonth(month, year); 
    return *this;
}

// Pre-increment operator: ++Date
Date& Date::operator++() {
    month++;
    if (month > 12) { 
        month = 1;
        year++;
    }
    day = daysInMonth(month, year); 
    return *this;
}


    // Post-decrement operator: Date--
Date Date::operator--(int) {
    Date temp = *this; // Save the current state
    day--;
    if (day < 1) { // If the day becomes less than 1, move to the previous month
        month--;
        if (month < 1) { // If the month becomes less than 1, move to December of the previous year
            month = 12;
            year--;
        }
        day = daysInMonth(month, year); // Set to the last day of the new month
    }
    return temp; // Return the old state
}

    // Post-increment operator: Date++
Date Date::operator++(int) {
    Date temp = *this; // Save the current state
    day++;
    if (day > daysInMonth(month, year)) { // If the day exceeds the days in the current month
        day = 1; // Reset to the first day of the next month
        month++;
        if (month > 12) { // If the month exceeds 12, move to January of the next year
            month = 1;
            year++;
        }
    }
    return temp; // Return the old state
}


    // Subtraction operator: Calculate difference in days
int Date::operator-(const Date& other) const {
    int totalDays1 = year * 365 + day;
    for (int i = 1; i < month; i++) totalDays1 += daysInMonth(i, year);

    int totalDays2 = other.year * 365 + other.day;
    for (int i = 1; i < other.month; i++) totalDays2 += daysInMonth(i, other.year);

    return abs(totalDays1 - totalDays2);
}

    // Output operator: <<
ostream& operator<<(ostream& out, const Date& date) {
    out << date.month << "/" << date.day << "/" << date.year;
    return out;
}

    // Input operator: >>
istream& operator>>(istream& in, Date& date) {
    int month, day, year;
    in >> month >> day >> year;
    date.setDate(month, day, year);
    return in;
}
