// Date Class Project.cpp : This file contains the 'main' function for the Date Class Project

#include "Date.h"
#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
    try {
        // 1. Default constructor
        Date date1;
        cout << "Default constructor: ";
        date1.printFormat1();

        // 2. Parameterized constructor
        Date date2(12, 25, 2021);
        cout << "Parameterized constructor: ";
        date2.printFormat2();

        // 3. Test setDate()
        date1.setDate(4, 15, 2023);
        cout << "Set date to 4/15/2023: ";
        date1.printFormat3();

        // 4. Invalid date (13/45/2018)
        try {
            date1.setDate(13, 45, 2018);
        }
        catch (const invalid_argument& e) {
            cout << "Testing the date (13/45/2018): " << e.what() << endl;
        }

        // 5. Invalid date (4/31/2000)
        try {
            date1.setDate(4, 31, 2000);
        }
        catch (const invalid_argument& e) {
            cout << "Testing the date (4/31/2000): " << e.what() << endl;
        }

        // 6. Invalid date (2/29/2009)
        try {
            date1.setDate(2, 29, 2009);
        }
        catch (const invalid_argument& e) {
            cout << "Testing the date (2/29/2009): " << e.what() << endl;
        }

        // 7. Difference of 8 days
        Date date3(4, 10, 2014), date4(4, 18, 2014);
        cout << "Testing the days between 4/10/2014 and 4/18/2014: " << (date4 - date3) << " days" << endl;

        // 8. Difference of 815 days
        Date date5(2, 2, 2006), date6(11, 10, 2003);
        cout << "Testing the days between 2/2/2006 and 11/10/2003: " << (date5 - date6) << " days" << endl;

        // 9. Pre-decrement operator (--Date)
        Date date7(2, 29, 2008);
        --date7;
        cout << "Pre-decrement Operator test (2/29/2008 to 1/31/2008): ";
        date7.printFormat1();

        // 10. Pre-increment operator (++Date)
        ++date7;
        cout << "Pre-increment Operator test (1/31/2008 to 2/29/2008): ";
        date7.printFormat1();

        // 11. Post-decrement and Post-increment
        date7--;
        cout << "Repeating Previous tests with Post-decrement Operator: ";
        date7.printFormat1();
        date7++;
        cout << "Repeating Previous tests with Post-increment Operator: ";
        date7.printFormat1();

        // 12. Post-increment operator across year boundary
        Date date8(12, 31, 2024);
        date8++;
        cout << "Setting the date to December 31st and testing Post-increment Operator (12/31/2024 to 1/1/2025): ";
        date8.printFormat1();

        // 13. Post-decrement operator across year boundary
        date8--;
        cout << "Testing Post-decrement Operator to return date to January (1/1/2025 to 12/31/2024): ";
        date8.printFormat1();

        // 14. Pre-increment and Pre-decrement across year
        ++date8;
        cout << "Repeating Previous steps with Pre-increment Operator: ";
        date8.printFormat1();
        --date8;
        cout << "Repeating Previous steps with Pre-decrement Operator: ";
        date8.printFormat1();

        // 15. Input operator (cin >> Date)
        cout << "Enter a date (MM DD YYYY) In this exact format: ";
        cin >> date1;

        // 16. Output operator (cout << Date)
        cout << "You entered the date: " << date1 << endl;

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
