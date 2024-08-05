// Minh D Le
// COP1334C
// ioShu.cpp

#include <iostream>
using namespace std;

// Function prototypes
void getInput(int arr[]);
bool isLoShuMagicSquare(int arr[][3]);
void displaySquare(int arr[][3]);
bool tryAgain();

int main() {
    do {
        int numbers[9];
        int square[3][3];

        // Get input from user
        getInput(numbers);

        // Fill square with user input
        int index = 0;
        for (int row = 0; row < 3; ++row) {
            for (int col = 0; col < 3; ++col) {
                square[row][col] = numbers[index++];
            }
        }

        // Display square
        cout << "Input square:\n";
        displaySquare(square);

        // Check if it's a Lo Shu Magic Square
        if (isLoShuMagicSquare(square)) {
            cout << "The square is a Lo Shu Magic Square.\n";
        } else {
            cout << "The square is not a Lo Shu Magic Square.\n";
        }
    } while (tryAgain());

    return 0;
}

// Function to get input from user
void getInput(int arr[]) {
    cout << "Enter a list of numbers from 1 to 9 in random order (without repeats):\n";
    for (int i = 0; i < 9; ++i) {
        cin >> arr[i];
        while (arr[i] < 1 || arr[i] > 9) {
            cout << "Invalid input. Please enter a number from 1 to 9: ";
            cin >> arr[i];
        }
        for (int j = 0; j < i; ++j) {
            if (arr[i] == arr[j]) {
                cout << "Invalid input. Number already entered. Please enter a different number: ";
                cin >> arr[i];
                j = -1; // Restart loop to check for repeat
            }
        }
    }
}

// Function to check if the square is a Lo Shu Magic Square
bool isLoShuMagicSquare(int arr[][3]) {
    // Check sum of rows, columns, and diagonals
    int rowSum = 0;
    for (int row = 0; row < 3; ++row) {
        int currentRowSum = 0;
        int currentColSum = 0;
        for (int col = 0; col < 3; ++col) {
            currentRowSum += arr[row][col];
            currentColSum += arr[col][row];
        }
        if (row == 0) {
            rowSum = currentRowSum;
        } else if (rowSum != currentRowSum || rowSum != currentColSum) {
            return false;
        }
    }

    // Check sum of main diagonal
    int mainDiagonalSum = 0;
    int secondaryDiagonalSum = 0;
    for (int i = 0; i < 3; ++i) {
        mainDiagonalSum += arr[i][i];
        secondaryDiagonalSum += arr[i][2 - i];
    }
    if (rowSum != mainDiagonalSum || rowSum != secondaryDiagonalSum) {
        return false;
    }

    return true;
}

// Function to display the square
void displaySquare(int arr[][3]) {
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            cout << arr[row][col] << " ";
        }
        cout << endl;
    }
}

// Function to ask user if they want to try again
bool tryAgain() {
    char choice;
    cout << "Would you like to try again? (y/n): ";
    cin >> choice;
    return (choice == 'y' || choice == 'Y');
}
