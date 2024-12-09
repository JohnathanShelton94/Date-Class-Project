//This is the header file for the Date Class Project

#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

class Date {
private:
    int month;  // Stores the month (1–12)
    int day;    // Stores the day (1–31, depending on the month)
    int year;   // Stores the year

    // Helper functions
    bool isLeapYear(int year) const;         // Determines if a year is a leap year
    int daysInMonth(int month, int year) const; // Returns the number of days in a given month

public:
    // Constructors
    Date();                                 // Default constructor (sets to 1/1/1930)
    Date(int month, int day, int year);     // Parameterized constructor

    // Set and Get functions
    void setDate(int month, int day, int year); // Sets the date with validation
    int getMonth() const;                  // Returns the month
    int getDay() const;                    // Returns the day
    int getYear() const;                   // Returns the year

    // Print functions
    void printFormat1() const;             // MM/DD/YYYY format
    void printFormat2() const;             // Month Day, Year format
    void printFormat3() const;             // Day Month Year format

    // Operator overloads
    Date& operator++();                    // Prefix increment (++Date)
    Date operator++(int);                  // Postfix increment (Date++)
    Date& operator--();                    // Prefix decrement (--Date)
    Date operator--(int);                  // Postfix decrement (Date--)
    int operator-(const Date& other) const; // Subtraction operator for date difference

    // Input/output operators
    friend std::ostream& operator<<(std::ostream& out, const Date& date); // Output operator (<<)
    friend std::istream& operator>>(std::istream& in, Date& date);        // Input operator (>>)
};

#endif
