// Minh D Le
// COP1334C
// loanCalculator.cpp

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <limits>

using namespace std;

int main() {
    // variables
    string borrowerName, loanerName, reportDate;
    double loanAmount, annualInterestRate;
    int termYears;

    // prompting
    // intro strings
    cout << "Loan Payment Calculator ...";
    cout << '\n' << "Please enter the following information: ";
    cout << '\n' << "Borrower's Name: ";
    getline(cin, borrowerName);
    cout << "Loaning Institution: ";
    getline(cin, loanerName);
    // loan amount
    cout << '\n' << "Loan Amount ($): ";
    cin >> loanAmount;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // apy 
    cout << "Annual Interest Rate (%): ";
    cin >> annualInterestRate;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // loan term 
    cout << "Term of Loan (years): ";
    cin >> termYears;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // date report
    cout << '\n' << "Date of Report: ";
    getline(cin, reportDate);
    cout << "\n---------------------------------------------";

    // calculations
    // monthly payment
    double monthlyInterestRate = annualInterestRate / 12 /100;
    double monthlyInterestRate2 = monthlyInterestRate * 100;
    int numberOfPayments = termYears * 12;
    double monthlyPayment = (monthlyInterestRate * loanAmount) / (1 - pow(1 + monthlyInterestRate, -numberOfPayments));
    // to be paid
    double totalAmountPaid = monthlyPayment * numberOfPayments;
    // interest paid 
    double totalInterestPaid = totalAmountPaid - loanAmount;

    // output 
    cout << fixed << showpoint << setprecision(2);
    cout << '\n' << "Loan Payment Summary Report";
    // initial strings
    cout << '\n' << setw(30) << left << loanerName << right << setw(10) << borrowerName << endl;
    cout << setw(30) << left << "Annual Interest Rate: " << annualInterestRate << "%" << endl;
    cout << setw(30) << left << "Date: " << reportDate << endl;
    // loan/interest/monthly/payments/
    cout << '\n' << setw(30) << left << "Loan Amount: " << right << setw(10) << "$ " << loanAmount << endl;
    cout << setw(30) << left << "Monthly Interest Rate: " << right << setw(10) << " " << monthlyInterestRate2 << "%" << endl;
    cout << setw(30) << left << "Number of Payments: " << right << setw(10) << " " << numberOfPayments << endl;
    cout << setw(30) << left << "Monthly Payment: " << right << setw(10) << "$ " << monthlyPayment << endl;
    // final total
    cout << '\n' << setw(30) << left << "Total Amount to be Paid: " << right << setw(10) << "$ " << totalAmountPaid << endl;
    cout << setw(30) << left << "Total Interest Paid: " << right << setw(10) << "$ " << totalInterestPaid << endl;

    cout << "\n---------------------------------------------";

    return 0;


}
