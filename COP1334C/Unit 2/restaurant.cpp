#include <iostream>
using namespace std;

// Demo/tutorial project

int main()
{
    //constants and variables
    const double TAX_RATE = 7.0, TIP_RATE = 18.0;
    double mealCost, taxAmt, tipAmt, total;

    //intro
    cout << "\nRestaurant Bill Calculator ..." << endl;

    //prompt user for cost of meal
    cout << "\nPlease enter cost of meal: " << endl;
    cin >> mealCost;

    // Calculate tax amount, tip amount, and total
    taxAmt = mealCost * TAX_RATE / 100;
    tipAmt = mealCost * TIP_RATE / 100;
    total = mealCost + taxAmt + tipAmt;

    // Display restaurant bill
    cout << "Restaurant Bill" << endl
        << "---------------------------" << endl
        << "\nCost of Meal:\t$" << mealCost << endl
        << "Tax Charge:\t$" << taxAmt << endl
        << "Tip Amount:\t$" << tipAmt << endl
        << "============================" << endl
        << "Total\t\t$" << total << endl << endl;

    return 0;

}