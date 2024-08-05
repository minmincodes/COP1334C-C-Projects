#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function prototypes
void displayRules();
void playGame();
void generateMap(char map[][5], int& rangerRow, int& rangerCol, int& touristRow, int& touristCol);
void displayMap(char map[][5]);
void moveRanger(char map[][5], int& rangerRow, int& rangerCol, int& timeLeft);
void handleCell(char map[][5], int row, int col, int& timeLeft);

int main() {
    srand(time(nullptr)); // Seed the random number generator

    int choice;
    do {
        cout << "Lost in the Everglades - Main Menu\n";
        cout << "1. See rules\n";
        cout << "2. Play game\n";
        cout << "3. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                displayRules();
                break;
            case 2:
                playGame();
                break;
            case 3:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}

void displayRules() {
    cout << "Rules:\n";
    // Add rules here
}

void playGame() {
    char map[5][5]; // The Everglades map
    int rangerRow, rangerCol; // Ranger's position
    int touristRow, touristCol; // Tourist's position
    int timeLeft = 12; // Time left for rescue

    // Generate the map
    generateMap(map, rangerRow, rangerCol, touristRow, touristCol);

    // Game loop
    do {
        displayMap(map);
        moveRanger(map, rangerRow, rangerCol, timeLeft);
    } while (timeLeft > 0 && (rangerRow != touristRow || rangerCol != touristCol));

    // Check game over conditions
    if (timeLeft <= 0) {
        cout << "Time's up! The fate of the tourists is forever unknown.\n";
    } else {
        cout << "Congratulations! You rescued the tourists!\n";
    }
}

void generateMap(char map[][5], int& rangerRow, int& rangerCol, int& touristRow, int& touristCol) {
    // Initialize the map with unknown cells
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            map[i][j] = '*';
        }
    }

    // Place ranger at upper-left corner
    rangerRow = 0;
    rangerCol = 0;
    map[rangerRow][rangerCol] = 'R';

    // Place tourists at lower-right corner
    touristRow = 4;
    touristCol = 4;
    map[touristRow][touristCol] = 'T';

    // Randomly place 10 dangers
    for (int i = 0; i < 10; ++i) {
        int dangerRow = rand() % 5;
        int dangerCol = rand() % 5;
        map[dangerRow][dangerCol] = '?'; // Represents hidden danger
    }
}

void displayMap(char map[][5]) {
    cout << "Current map:\n";
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout << map[i][j] << ' ';
        }
        cout << endl;
    }
}

void moveRanger(char map[][5], int& rangerRow, int& rangerCol, int& timeLeft) {
    cout << "Enter the direction to move (U/D/L/R): ";
    char direction;
    cin >> direction;

    // Move ranger according to input direction
    switch(direction) {
        case 'U':
            if (rangerRow > 0) {
                rangerRow--;
            }
            break;
        case 'D':
            if (rangerRow < 4) {
                rangerRow++;
            }
            break;
        case 'L':
            if (rangerCol > 0) {
                rangerCol--;
            }
            break;
        case 'R':
            if (rangerCol < 4) {
                rangerCol++;
            }
            break;
        default:
            cout << "Invalid direction!\n";
    }

    // Handle the cell the ranger moved to
    handleCell(map, rangerRow, rangerCol, timeLeft);
}

void handleCell(char map[][5], int row, int col, int& timeLeft) {
    // Check if the cell contains a danger
    if (map[row][col] == '?') {
        // Determine the danger and handle it
        // For now, just decrement time by 5
        timeLeft -= 5;
        cout << "You encountered a danger! 5 gongs of time lost.\n";
    } else {
        // No danger, decrement time by 1
        timeLeft -= 1;
    }
}
