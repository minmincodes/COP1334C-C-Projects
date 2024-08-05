// Minh D Le
// COP1334C
// iMobile.cpp

#include <iostream>
#include <iomanip>

using namespace std;

int main () {

    // variables
    char plan;
    double basePrice, extraPrice, dataUsed, totalAmountDue;

    // print intro
    cout << "IMobile Bill Calculator ..." << '\n' << endl;
    cout << "Select a subscription package: ";
    cout << left << setw(10) << '\n' << "1. Package A";
    cout << left << setw(10) << '\n' << "2. Package B";
    cout << left << setw(10) << '\n' << "3. Package C";
    cout << '\n' << "Package: ";
    cin >> plan;

    // validate plan input
    while (plan != '1' && plan != '2' && plan != '3') {
        cout << '\n' << "Error ... Invalid package. Try again.";
        cout << '\n' << "Package: ";
        cin >> plan;
    }

    // prompt for amount of data used
    cout << '\n' << "How many gigabytes of data were used? ";
    cin >> dataUsed;

    // validate data input 
    while (dataUsed < 0) {
        cout << '\n' << "Error ... Invalid gigabytes entered. Try again.";
        cout << '\n' << "How many gigabytes of data were used? ";
        cin >> dataUsed;
    }

    // calculate plan
    switch (plan) {
        case '1':
            basePrice = 39.99;
            extraPrice = 10.00;
            if (dataUsed <= 4)
                totalAmountDue = basePrice;
            else
                totalAmountDue = basePrice + (dataUsed - 4) * extraPrice;
            break;
        case '2':
            basePrice = 59.99;
            extraPrice = 5.00;
            if (dataUsed <= 8)
                totalAmountDue = basePrice;
            else
                totalAmountDue = basePrice + (dataUsed - 8) * extraPrice;
            break;
        case '3':
            totalAmountDue = 69.99;
            break;
    }

    // output display
    cout << '\n' << "Total amount due is $" << totalAmountDue << endl;

    return 0;
}