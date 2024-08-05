// Minh D Le
// COP1334C
// paintEstimator.cpp

#include <iostream>
using namespace std;

// Function prototypes
double getPricePerGallon();
int getRooms();
int calcWallSpace(int rooms);
void calcPaint(int sqrFeet, double pricePaint, int& gallons, double& costPaint);
void calcLabor(int sqrFeet, double& hours, double& costLabor);
double calculateTotalCost(double costPaint, double costLabor);

int main() {
    // Variables to store user input and calculation results
    double pricePerGallon, costPaint, costLabor, totalCost;
    int numRooms, totalSquareFeet, gallonsRequired;
    double totalHours;

    // Prompt user for input
    pricePerGallon = getPricePerGallon();
    numRooms = getRooms();
    totalSquareFeet = calcWallSpace(numRooms);

    // Calculate paint requirements
    calcPaint(totalSquareFeet, pricePerGallon, gallonsRequired, costPaint);

    // Calculate labor requirements
    calcLabor(totalSquareFeet, totalHours, costLabor);

    // Calculate total cost
    totalCost = calculateTotalCost(costPaint, costLabor);

    // Display report
    cout << "Paint required: " << gallonsRequired << " gallons\n";
    cout << "Cost of paint: $" << costPaint << endl;
    cout << "Labor hours required: " << totalHours << " hours\n";
    cout << "Labor charges: $" << costLabor << endl;
    cout << "Total cost: $" << totalCost << endl;

    return 0;
}

// Function to get the price per gallon of paint from the user
double getPricePerGallon() {
    double price;
    cout << "Enter the price per gallon of paint: $";
    cin >> price;
    while (price < 0) {
        cout << "Invalid input. Please enter a price greater than or equal to 0: $";
        cin >> price;
    }
    return price;
}

// Function to get the number of rooms from the user
int getRooms() {
    int rooms;
    cout << "Enter the number of rooms to be painted: ";
    cin >> rooms;
    while (rooms < 1) {
        cout << "Invalid input. Please enter a number greater than 0: ";
        cin >> rooms;
    }
    return rooms;
}

// Function to calculate the total square feet of wall space
int calcWallSpace(int rooms) {
    int totalSquareFeet = 0;
    for (int i = 1; i <= rooms; ++i) {
        int squareFeet;
        cout << "Enter the square feet of wall space in room " << i << ": ";
        cin >> squareFeet;
        while (squareFeet < 25) {
            cout << "Invalid input. Please enter a value greater than or equal to 25: ";
            cin >> squareFeet;
        }
        totalSquareFeet += squareFeet;
    }
    return totalSquareFeet;
}

// Function to calculate the gallons of paint required and its cost
void calcPaint(int sqrFeet, double pricePaint, int& gallons, double& cost) {
    gallons = (sqrFeet + 114) / 115; // Round up to the nearest gallon
    cost = gallons * pricePaint;
}

// Function to calculate the labor hours required and its cost
void calcLabor(int sqrFeet, double& hours, double& cost) {
    hours = (double)sqrFeet / 115 * 8; // 8 hours per 115 square feet
    cost = hours * 25.0; // $25.00 per hour
}

// Function to calculate the total cost of the paint job
double calculateTotalCost(double costPaint, double costLabor) {
    return costPaint + costLabor;
}

