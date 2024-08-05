// Minh D Le
// COP1334C
// soccer.cpp

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Structure to store player information
struct Player {
    string name;
    int number;
    int goalsScored;
};

// Function prototypes
void loadTeamInformation(Player team[], const string& filename);
void displayRoster(const Player team[]);
void displayGoals(const Player team[]);
void displayStars(const Player team[]);
int calculateTotalGoals(const Player team[]);
void displayMenu();

int main() {
    const int TEAM_SIZE = 11;
    Player team[TEAM_SIZE];
    string filename;

    int choice;
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter the filename to load team information: ";
                cin >> filename;
                loadTeamInformation(team, filename);
                break;
            case 2:
                displayRoster(team);
                break;
            case 3:
                displayGoals(team);
                break;
            case 4:
                displayStars(team);
                break;
            case 5:
                cout << "Total goals scored by the team: " << calculateTotalGoals(team) << endl;
                break;
            case 6:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}

// Function to load team information from a file
void loadTeamInformation(Player team[], const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Unable to open file " << filename << endl;
        return;
    }

    for (int i = 0; i < 11; ++i) {
        file.ignore(); // Ignore newline left in stream
        getline(file, team[i].name);
        file >> team[i].number >> team[i].goalsScored;
    }

    file.close();
    cout << "Team information loaded successfully.\n";
}

// Function to display the roster
void displayRoster(const Player team[]) {
    cout << "Roster:\n";
    cout << "Number\tName\tGoals Scored\n";
    for (int i = 0; i < 11; ++i) {
        cout << team[i].number << "\t" << team[i].name << "\t" << team[i].goalsScored << endl;
    }
}

// Function to display team's goals
void displayGoals(const Player team[]) {
    int totalGoals = calculateTotalGoals(team);
    cout << "Total goals scored by the team: " << totalGoals << endl;
}

// Function to calculate total goals scored by the team
int calculateTotalGoals(const Player team[]) {
    int totalGoals = 0;
    for (int i = 0; i < 11; ++i) {
        totalGoals += team[i].goalsScored;
    }
    return totalGoals;
}

// Function to display team's star(s)
void displayStars(const Player team[]) {
    int maxGoals = 0;
    for (int i = 0; i < 11; ++i) {
        if (team[i].goalsScored > maxGoals) {
            maxGoals = team[i].goalsScored;
        }
    }

    cout << "Star(s) of the team (with highest goals scored):\n";
    for (int i = 0; i < 11; ++i) {
        if (team[i].goalsScored == maxGoals) {
            cout << team[i].name << " - Goals: " << team[i].goalsScored << endl;
        }
    }
}

// Function to display the menu options
void displayMenu() {
    cout << "\nMenu:\n";
    cout << "1. Load team's information\n";
    cout << "2. Display team's roster\n";
    cout << "3. Display team's goals\n";
    cout << "4. Display team's star(s)\n";
    cout << "5. Calculate and display total goals scored by the team\n";
    cout << "6. Quit\n";
}
