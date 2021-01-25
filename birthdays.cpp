/**
 * birthdays.cpp
 * Project UID: d27ac2f9d9ef51141f8207ca61bd9b22d96076f1
 * 
 * Kripa Srinivasan
 * kripas
 *
 * EECS 183: Project 2
 *
 * Project description: an application to identify the day of the week on which you were born
 */

#include <cmath>
#include <iostream>
#include <string>

using namespace std;


/**
 * REQUIRES: nothing
 * MODIFIES: cout
 * EFFECTS:  Prints out the initial heading for the program
 */
void printHeading();


/**
 * REQUIRES: nothing
 * MODIFIES: cout
 * EFFECTS:  Prints out the final greeting for the program
 */
void printCloser();


/**
 * REQUIRES: nothing
 * MODIFIES: cout 
 * EFFECTS:  Prints the menu text. Does not read from cin.
 */
void printMenu();

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: nothing
 * MODIFIES: cout, cin
 * EFFECTS:  1. Prints the menu
 *           2. Reads the input from the user
 *           3. Checks to make sure the input is within range for the menu
 *              If not prints "Invalid menu choice"
 *           4. Continues to print the menu and read an input until 
 *              a valid one is entered
 *           5. Returns the user's choice of menu options
 * 
 *           This function must call printMenu().
 */
int getMenuChoice();

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: month, day, year represent a valid date
 * MODIFIES: nothing
 * EFFECTS:  Returns true if the date is in the limits
 *           of the Gregorian calendar otherwise returns false
 *           See the spec for definition of "limits of the Gregorian calendar"
 */
bool isGregorianDate(int month, int day, int year);

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: year is a Gregorian year
 * MODIFIES: nothing
 * EFFECTS:  returns true if the year is a leap year
 *           otherwise returns false.
 *           See the spec for definition of a leap year.
 */
bool isLeapYear(int year);

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: month, day, year may represent a date
 * MODIFIES: nothing
 * EFFECTS:  returns true if the date is valid
 *           otherwise returns false
 *           See the spec for definition of "valid"
 */
bool isValidDate(int month, int day, int year);

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: month, day, year is a valid date
 *           i.e., the date passed to this function has already passed
 *               isValidDate()
 * MODIFIES: nothing
 * EFFECTS:  returns the value f that Zeller's formula calculates
 */
int determineDay(int month, int day, int year);

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: day is a value of f output by Zeller's formula
*            (0 represents Saturday, 1 Sunday, 2 Monday, 3 Tuesday, etc)
 * MODIFIES: cout
 * EFFECTS:  prints the day of the week corresponding to day, suchas
 *           "Sunday", "Monday", ..., "Saturday"
 */
void printDayOfBirth(int day);

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: nothing
 * MODIFIES: cout, cin
 * EFFECTS:  Asks for the month / day / year of the user's birthday.
 *           If the date is valid, it will print the day
 *           of the week you were born on
 *           Otherwise, it will print "Invalid date" prompt.
 */
void determineDayOfBirth();

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: nothing
 * MODIFIES: cin, cout
 * EFFECTS:  Asks for a Gregorian year and prints the
 *           10 leap years after (not including) the year entered.
 *           If the year is invalid, it prints nothing.
 */
void print10LeapYears();


// birthdays() function calls all the other functions to run the code
// depending on user input, calls appropriate function
void birthdays() {
    printHeading();
    int getChoice = getMenuChoice();
    while (getChoice != 3) {
        if (getChoice == 1) {
            determineDayOfBirth();
            cout << endl;
            getChoice = getMenuChoice();
        } else if (getChoice == 2) {
            cout << endl;
            print10LeapYears();
            cout << endl;
            getChoice = getMenuChoice();
        }
    } if (getChoice == 3) {
        printCloser();
    }
    return;
}


void printHeading() {
    cout << "*******************************" << endl
         << "      Birthday Calculator      " << endl
         << "*******************************" << endl << endl;
    return;
}


void printCloser() {
    cout << endl;
    cout << "****************************************************" << endl
         << "      Thanks for using the Birthday Calculator      " << endl
         << "****************************************************" << endl
         << endl;
    return;
}


void printMenu() {
    cout << "Menu Options" << endl
         << "------------" << endl;
    cout << "1) Determine day of birth" << endl;
    cout << "2) Print the next 10 leap years" << endl;
    cout << "3) Finished" << endl << endl;
    
    cout << "Choice --> ";
    return;
}


int getMenuChoice() {
    // prints menu until user input is a valid choice
    // returns user's choice of menu options
    printMenu();
    int choice;
    cin >> choice;
    while (choice != 1 && choice != 2 && choice != 3) {
        cout << endl << "Invalid menu choice" << endl << endl;
        printMenu();
        cin >> choice;
    }
    return choice;
}


bool isGregorianDate(int month, int day, int year) {
    // Any date that falls on or after 9/14/1752 is a Gregorian date
    // which is why these numbers are used to return true / false
    if ((year > 1752) || ((year == 1752) && (month == 9) && (day >= 14)) ||
        ((year == 1752) && (month > 9))) {
        return true;
    } else {
        return false;
    }
}


bool isLeapYear(int year) {
    // Every year evenly divisble by 4 is a leap year in the Gregorian calendar
    if (year % 4 == 0){
        // Exception if the year is divisible by 100 (not a leap year)
        // unless the year is ALSO divisible by 400 (then it is a leap year)
        if (year % 100 == 0) {
            if (year % 400 == 0){
                return true;
            } else {
                return false;
            }
        } else {
            return true;
        }
    } else {
        return false;
    }
}


bool isValidDate(int month, int day, int year) {
    // tests if date is Gregorian and is valid
    if (isGregorianDate(month, day, year) && (month >= 1 && month <= 12)) {
        // testing if inputted dates in February are valid
        if (month == 2) {
            if (isLeapYear(year) && ((day >= 1) && (day <= 29))) {
                return true;
            } else if (day >= 1 && day <= 28) {
                return true;
            } else {
                return false;
            }
        // testing for months that have 30 days
        } else if ((month == 4) || (month == 6) || (month == 9) ||
                   (month == 11)) {
            if (day >= 1 && day <= 30) {
                return true;
            } else {
                return false;
            }
        // testing for months that have 31 days
        } else if (month >= 1 && month <= 12) {
            if (day >= 1 && day <= 31) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    } else {
        return false;
    }
}


int determineDay(int month, int day, int year) {
    int Y = 0;
    int C = 0;
    int zeller = 0;
    
    // convert Jan and Feb to months 13 and 14 & decrementing year by 1
    if (month == 1 || month == 2) {
        month += 12;
        year -= 1;
    }
    
    // determine the first two digits of the year number
    C = year / 100;
    // determine the last two digits of the year number
    Y = year % 100;
    
    // Using Zeller's formula to compute the day of the week
    // on which a certain date occured/will occur
    zeller = int(day + floor((13 * (month + 1)) / 5) + Y + floor(Y / 4) +
                 floor(C / 4) + (5*C)) % 7;
    
    return zeller;
}


void printDayOfBirth(int day) {
    // converts numbers to correpsonding day of the week
    if (day == 0) {
        cout << "Saturday" << endl;
    } else if (day == 1) {
        cout << "Sunday" << endl;
    } else if (day == 2) {
        cout << "Monday" << endl;
    } else if (day == 3) {
        cout << "Tuesday" << endl;
    } else if (day == 4) {
        cout << "Wednesday" << endl;
    } else if (day == 5) {
        cout << "Thursday" << endl;
    } else if (day == 6) {
        cout << "Friday" << endl;
    }
    return;
}


void determineDayOfBirth() {
    int month = 0;
    int day = 0;
    int year = 0;
    char slash;
    
    // asks for the month / day / year of the user's birthday
    cout << endl << "Enter your date of birth" << endl;
    cout << "format: month / day / year  --> ";
    cin >> month >> slash >> day >> slash >> year;
    cout << endl;
    
    // based on user input, determines if date is valid
    // if valid, prints day of the week for date
    if (!isValidDate(month, day, year)){
        cout << "Invalid date" << endl;
    } else if (isValidDate(month, day, year)){
        cout << "You were born on a: ";
        printDayOfBirth(determineDay(month, day, year));
        cout << endl;
        cout << "Have a great birthday!!!" << endl;
    }
    return;
}


void print10LeapYears() {
    // prints next 10 leap years
    int year;
    cout << "Enter year --> ";
    cin >> year;
    cout << endl;
    // testing if Gregorian and if leap year, then print out current leap
    // year and the next 9 leap years
    if (year >= 1752){
        year += 1;
        while (!isLeapYear(year)) {
            year += 1;
        } if (isLeapYear(year)) {
            for (int i = 0; i < 10; ++i) {
                cout << "Leap year is ";
                cout << year << endl;
                year += 1;
                while (!isLeapYear(year)) {
                    year += 1;
                };
            }
        }
    }
    return;
}
