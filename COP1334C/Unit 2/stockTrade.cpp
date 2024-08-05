//Minh D Le
//COP1334C
//stockTrade.cpp

#include <iostream> //adds basic input output services
#include <string> //for string variables
#include <iomanip> //for 

using namespace std;

int main() {
    // variables

    std::string companyName, companySym;

    int numShares;

    double buyPrice, sellPrice;

    // user input

    std::cout << "Enter Company Name: ";
    std::getline(std::cin, companyName);

    std::cout << "Enter Company Symbol: ";
    std::getline(std::cin, companySym);

    std::cout << "Enter Number of Shares: ";
    std::cin >> numShares;

    std::cout << "Enter Buy Price per Share: ";
    std::cin >> buyPrice;

    std::cout << "Enter Sell Price per Share: ";
    std::cin >> sellPrice;

    // calculations
    
    double totalCost = numShares * buyPrice;
    double totalCost2 = (totalCost * 0.02) + totalCost; // adds the 2% fee
    double totalProceeds = numShares * sellPrice;
    double totalProceeds2 = totalProceeds - (totalProceeds * 0.02); // removes the 2% fee
    double commission = (totalCost + totalProceeds) * 0.02;
    double gainsLosses = totalProceeds - totalCost - commission;
    double percentage = (gainsLosses / totalCost2) * 100;

    // stock info

    std::cout << std::fixed << std::setprecision(2); // set precision
    std::cout << "\nStock Investment Performance Calculator ... " << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
    // std::setw(30) allows for even spacing between the label and the outputted inputs
    std::cout << std::left << std::setw(30) << "Company Name (No Spaces) & Symbol: " << companyName << " " << companySym << std::endl;
    std::cout << std::left << std::setw(30) << "Number of Shares Transacted: " << numShares << std::endl;
    std::cout << std::left << std::setw(30) << "Cost per Share (@ buying): " << "$" << buyPrice << std::endl;
    std::cout << std::left << std::setw(30) << "Price per Share (@ selling): " << "$" << sellPrice << std::endl;

    // gains/losses report

    std::cout << "\nRealized Gains/Losses Report ... " << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    std::cout << std::left << std::setw(30) << "Stock: " << companyName << " (" << companySym << ")" << std::endl;
    std::cout << std::left << std::setw(30) << "Quantity: " << numShares << " Shares." << std::endl;
    // put the \n in front of the statement, otherwise it leaves a strange gap infront of the input
    // adding the $ symbol separately after allows it to follow the printed input
    std::cout << "\n" << std::left << std::setw(30) << "Total Cost: "  << "$" << totalCost2 << std::endl;
    std::cout << std::left << std::setw(30) << "Total Proceeds: "  << "$" << totalProceeds2 << std::endl;
    std::cout << std::left << std::setw(30) << "Commissions: "  << "$" << commission << std::endl;
    std::cout << std::left << std::setw(30) << "Gains/Losses: "  << "$" << gainsLosses << " (" << percentage << "%)" << std::endl;

    return 0;

}

