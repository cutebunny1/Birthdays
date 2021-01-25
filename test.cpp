/**
 * test.cpp
 * Project UID: d27ac2f9d9ef51141f8207ca61bd9b22d96076f1
 * 
 * Kripa Srinivasan
 * kripas
 *
 * EECS 183: Project 2
 *
 * Testing functions for your birthdays.cpp implementation.
 * Holds the definitions of required testing functions.
 * We have stubbed all required functions for you.
 */

#include <cassert>
#include <cctype>
#include <iostream>
#include <limits>
#include <string>

using namespace std;


//************************************************************************
// You should have implemented the following functions in birthdays.cpp
//************************************************************************
int getMenuChoice();
bool isLeapYear (int year);
bool isGregorianDate(int m, int d, int y);
bool isValidDate(int month, int day, int year);
int determineDay (int month, int day, int year);
void printDayOfBirth(int day);
void determineDayOfBirth();
void print10LeapYears();

//************************************************************************
// Testing function declarations. Function definition is below main.
// Tests not run by these functions will not be run by the autograder.
//************************************************************************
void test_getMenuChoice();
void test_isGregorianDate();
void test_isLeapYear();
void test_isValidDate();
void test_determineDay();
void test_printDayOfBirth();
void test_determineDayOfBirth();
void test_print10LeapYears();

void startTests()
{
    // Write calls to your test functions here, e. g.,
    // test_getMenuChoice();
    test_isLeapYear();
    test_getMenuChoice();
    test_isGregorianDate();
    test_isValidDate();
    test_determineDay();
    test_printDayOfBirth();
    test_determineDayOfBirth();
    test_print10LeapYears();
    
    // Add more calls as you implement more functions.
    // While you're working on a function, it can be useful to comment
    //  out the calls to other functions' tests.

    // Make sure the only function you test in a test function
    //  like test_isGregorianDate is that function (isGregorianDate),
    //  or it may cause issues with the autograder.
}

void test_getMenuChoice()
{
    // getMenuChoice reads from cin, so you will need to
    // provide directions to the user for each test case
    cout << "Now testing funtion getMenuChoice()\n";
    cout << "Please enter 3: " << endl;
    int choice1 = getMenuChoice();
    cout << "Test result: expected: 3, actual: " << choice1 << endl;

    cout << "Please enter 5 then 1: ";
    int choice2 = getMenuChoice();
    cout << "Test result: " << endl;
    cout << "Expected: \"Invalid menu choice\", then 1." << endl;
    cout << "Actual: " << choice2 << endl;
    
    // Write additional tests here
    cout << "Please enter 1: ";
    int choice3 = getMenuChoice();
    cout << "Test result: expected: 1, actual: " << choice3 << endl;
    
    cout << "Please enter 2: ";
    int choice4 = getMenuChoice();
    cout << "Test result: expected: 2, actual: " << choice4 << endl;

    cout << "Please enter 8 then 10 then 2: ";
    int choice5 = getMenuChoice();
    cout << "Test result: " << endl;
    cout << "Expected: \"Invalid menu choice\", then \"Invalid menu choice\" ";
    cout << "then 2." << endl;
    cout << "Actual: " << choice5 << endl;
    
    cout << "Please enter 20 then 2: ";
    int choice6 = getMenuChoice();
    cout << "Test result: " << endl;
    cout << "Expected: \"Invalid menu choice\", then 2." << endl;
    cout << "Actual: " << choice6 << endl;
}

void test_isGregorianDate()
{
    // isGregorianDate does not read from cin, so
    // all its tests can be run automatically
    cout << "Now testing function isGregorianDate()\n";
    cout << "9/2/2019:  Expected: 1, Actual: " << isGregorianDate(9, 2, 2019) << endl;
    cout << "1/31/1001: Expected: 0, Actual: " << isGregorianDate(1, 31, 1001) << endl;
    
    // Write your tests here
    cout << "9/14/1752: Expected: 1, Actual: " << isGregorianDate(9, 14, 1752) << endl;
    cout << "1/10/1978: Expected: 1, Actual: " << isGregorianDate(1, 10, 1978) << endl;
    cout << "9/10/1752: Expected: 0, Actual: " << isGregorianDate(9, 10, 1752) << endl;
    cout << "9/13/1752: Expected: 0, Actual: " << isGregorianDate(9, 13, 1752) << endl;
    cout << "1/10/1751: Expected: 0, Actual: " << isGregorianDate(1, 10, 1751) << endl;
    cout << "12/2/2001: Expected: 1, Actual: " << isGregorianDate(12, 2, 2001) << endl;
    cout << "6/5/1999: Expected: 1, Actual: " << isGregorianDate(6, 5, 1999) << endl;
}

void test_isLeapYear()
{
    // Write your tests here
    cout << "Now testing function isLeapYear()" << endl;
    
    // Remember that true becomes 1 and false becomes 0
    // when you sent it to cout
    cout << "1768: Expected 1, Actual: " << isLeapYear(1768) << endl;
    cout << "1800: Expected 0, Actual: " << isLeapYear(1800) << endl;
    cout << "2000: Expected 1, Actual: " << isLeapYear(2000) << endl;
    cout << "1999: Expected 0, Actual: " << isLeapYear(1999) << endl;
    cout << "1988: Expected 1, Actual: " << isLeapYear(1988) << endl;
    cout << "2001: Expected 0, Actual: " << isLeapYear(2001) << endl;
}

void test_isValidDate()
{
    // Write your tests here
    cout << "Now testing function isValidDate()\n";
    cout << "13/20/1980: Expected 0, Actual: " << isValidDate(13, 20, 1980) << endl;
    cout << "1/32/1980: Expected 0, Actual: " << isValidDate(1, 32, 1980) << endl;
    cout << "4/31/2015: Expected 0, Actual: " << isValidDate(4, 31, 2015) << endl;
    cout << "5/23/1300: Expected 0, Actual: " << isValidDate(5, 23, 1300) << endl;
    cout << "2/29/2000: Expected 1, Actual: " << isValidDate(2, 29, 2000) << endl;
    cout << "2/29/2001: Expected 0, Actual: " << isValidDate(2, 29, 2001) << endl;
    cout << "2/28/2001: Expected 1, Actual: " << isValidDate(2, 28, 2001) << endl;
    cout << "12/2/2001: Expected 1, Actual: " << isValidDate(12, 2, 2001) << endl;
    cout << "5/30/1950: Expected 1, Actual: " << isValidDate(5, 30, 1950) << endl;
    cout << "10/15/1752: Expected 1, Actual: " << isValidDate(10, 15, 1752) << endl;
    cout << "2/31/2000: Expected 0, Actual: " << isValidDate(2, 31, 2000) << endl;
}

void test_determineDay()
{
    // Write your tests here
    cout << "Now testing function determineDay()\n";
    cout << "1/29/2064: Expected: 3, Actual: " << determineDay(1, 29, 2064) << endl;
    cout << "12/20/1999: Expected: 2, Actual: " << determineDay(12, 20, 1999) << endl;
    cout << "4/3/2001: Expected: 3, Actual: " << determineDay(4, 3, 2001) << endl;
    cout << "1/2/1999: Expected: 0, Actual: " << determineDay(1, 2, 1999) << endl;
    cout << "1/1/1999: Expected: 6, Actual: " << determineDay(1, 1, 1999) << endl;
    cout << "5/24/2000: Expected: 4, Actual: " << determineDay(5, 24, 2000) << endl;
    cout << "10/12/1800: Expected: 1, Actual: " << determineDay(10, 12, 1800) << endl;
    cout << "9/14/1752: Expected: 5, Actual: " << determineDay(9, 14, 1752) << endl;
    cout << "10/5/2020: Expected: 2, Actual: " << determineDay(10, 5, 2020) << endl;
}

void test_printDayOfBirth()
{
    // printDayOfBirth prints to cout rather than
    // returning a value.
    cout << "Now testing function printDayOfBirth()\n";
    cout << "1: Expected: Sunday, Actual: ";
    printDayOfBirth(1);
    cout << endl;

    // Write your tests here
    cout << "2: Expected: Monday, Actual: ";
    printDayOfBirth(2);
    cout << endl;
    
    cout << "3: Expected: Tuesday, Actual: ";
    printDayOfBirth(3);
    cout << endl;
    
    cout << "4: Expected: Wednesday, Actual: ";
    printDayOfBirth(4);
    cout << endl;
    
    cout << "5: Expected: Thursday, Actual: ";
    printDayOfBirth(5);
    cout << endl;
    
    cout << "6: Expected: Friday, Actual: ";
    printDayOfBirth(6);
    cout << endl;
    
    cout << "0: Expected: Saturday, Actual: ";
    printDayOfBirth(0);
    cout << endl;
}

void test_determineDayOfBirth()
{
    // Write your tests here
    cout << "Now testing function determineDayOfBirth()\n";
    cout << "Please enter 12 / 2 / 2001: " << endl << endl;
    cout << "Expected: " << endl;
    cout << "You were born on a: Sunday" << endl;
    cout << "Have a great birthday!!!" << endl << endl << "Actual: " << endl;
    determineDayOfBirth();
    cout << endl << endl;
    
    cout << "Please enter 5 / 23 / 1300: " << endl << endl;
    cout << "Expected: " << endl;
    cout << "Invalid date" << endl << endl;
    cout << "Actual: " << endl;
    determineDayOfBirth();
    cout << endl << endl;

    cout << "Please enter 9 / 28 / 2020: " << endl << endl;
    cout << "Expected: " << endl;
    cout << "You were born on a: Monday" << endl;
    cout << "Have a great birthday!!!" << endl << endl << "Actual: " << endl;
    determineDayOfBirth();
    cout << endl << endl;

    cout << "Please enter 5 / 30 / 1950: " << endl << endl;
    cout << "Expected: " << endl;
    cout << "You were born on a: Tuesday" << endl;
    cout << "Have a great birthday!!!" << endl << endl << "Actual: " << endl;
    determineDayOfBirth();
    cout << endl << endl;

    cout << "Please enter 2 / 28 / 2001: " << endl << endl;
    cout << "Expected: " << endl;
    cout << "You were born on a: Wednesday" << endl;
    cout << "Have a great birthday!!!" << endl << endl << "Actual: " << endl;
    determineDayOfBirth();
    cout << endl << endl;

    cout << "Please enter 1 / 1 / 1999: " << endl << endl;
    cout << "Expected: " << endl;
    cout << "You were born on a: Friday" << endl;
    cout << "Have a great birthday!!!" << endl << endl << "Actual: " << endl;
    determineDayOfBirth();
    cout << endl << endl;

    cout << "Please enter 10 / 6 / 2020: " << endl << endl;
    cout << "Expected: " << endl;
    cout << "You were born on a: Tuesday" << endl;
    cout << "Have a great birthday!!!" << endl << endl << "Actual: " << endl;
    determineDayOfBirth();
    cout << endl << endl;

    cout << "Please enter 6 / 15 / 1978: " << endl << endl;
    cout << "Expected: " << endl;
    cout << "You were born on a: Thursday" << endl;
    cout << "Have a great birthday!!!" << endl << endl << "Actual: " << endl;
    determineDayOfBirth();
    cout << endl << endl;
}

void test_print10LeapYears()
{
    // Write your tests here
    cout << "Now testing function print10LeapYears()\n";

    cout << "1746: Expected " ", Actual: " << endl;
    print10LeapYears();
    cout << endl << endl;

    cout << "1752: Expected: 1756 1760 1764 1768 1772 1776 1780 1784 1788";
    cout << " 1792, Actual: " << endl;
    print10LeapYears();
    cout << endl << endl;
    
    cout << "1768: Expected: 1772 1776 1780 1784 1788 1792 1796 1804 1808";
    cout << " 1812, Actual: " << endl;
    print10LeapYears();
    cout << endl << endl;

    cout << "1800: Expected: 1804 1808 1812 1816 1820 1824 1828 1832 1836 1840";
    cout << ", Actual: " << endl;
    print10LeapYears();
    cout << endl << endl;

    cout << "2000: Expected: 2004 2008 2012 2016 2020 2024 2028 2032 2036";
    cout << " 2040, Actual: " << endl;
    print10LeapYears();
    cout << endl << endl;

    cout << "1999: Expected: 2000 2004 2008 2012 2016 2020 2024 2028 2032";
    cout << " 2036, Actual: " << endl;
    print10LeapYears();
    cout << endl << endl;

    cout << "2001: Expected: 2004 2008 2012 2016 2020 2024 2028 2032 2036";
    cout << " 2040, Actual: " << endl;
    print10LeapYears();
    cout << endl << endl;
}
