// Minh D Le
// COP1334C
// courseSummary.cpp


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// Function prototypes
void processGradesSummary();
void displayReport(const vector<string>& students, const vector<int>& grades);
void displayExitMessage();

// Trim leading and trailing whitespace from a string
string trim(const string& str) {
    size_t start = str.find_first_not_of(" \t");
    size_t end = str.find_last_not_of(" \t");
    if (start == string::npos || end == string::npos) {
        return "";
    }
    return str.substr(start, end - start + 1);
}

int main() {
    int choice;
    do {
        cout << "Menu:\n";
        cout << "1. Process Grades Summary report\n";
        cout << "2. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                processGradesSummary();
                break;
            case 2:
                displayExitMessage();
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 2);

    return 0;
}

void processGradesSummary() {
    string filename;
    cout << "Enter the name of the file storing the course information: ";
    cin >> filename;

    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: File \"" << filename << "\" not found.\n";
        return;
    }

    vector<string> students;
    vector<int> grades;
    string line;

    // Read course information from file (discard)
    getline(file, line); // Read and discard course number & description
    getline(file, line); // Read and discard instructor name
    getline(file, line); // Read and discard term

    // Read student data
    while (getline(file, line)) {
        // Read student name
        string studentName = line;
        // Consume newline character
        file.ignore(numeric_limits<streamsize>::max(), '\n');

        // Read student grade
        if (!getline(file, line)) {
            cout << "Error: Incomplete data for student \"" << studentName << "\". Skipping this student.\n";
            break;
        }

        // Convert grade to integer
        try {
            int grade = stoi(line);
            students.push_back(studentName); // Store student name
            grades.push_back(grade); // Store grade
        } catch (const invalid_argument& e) {
            cout << "Error: Invalid grade \"" << line << "\" encountered for student \"" << studentName << "\". Skipping this student.\n";
        }
    }

    file.close();

    // Display report
    displayReport(students, grades);
}

void displayReport(const vector<string>& students, const vector<int>& grades) {
    cout << "COP1334C - Introduction to C++ Programming\n" << '\n';
    cout << setw(20) << left << "Student" << "Grade\n";
    cout << "--------------------------------\n";

    // Display students and their grades
    for (size_t i = 0; i < students.size(); ++i) {
        cout << setw(20) << left << students[i] << grades[i] << endl;
    }

    // Calculate and display highest grade
    if (!grades.empty()) {
        int highestGrade = *max_element(grades.begin(), grades.end());
        cout << "Highest grade: " << highestGrade << endl;
    } else {
        cout << "No grades found.\n";
    }

    // Calculate and display lowest grade
    if (!grades.empty()) {
        int lowestGrade = *min_element(grades.begin(), grades.end());
        cout << "Lowest grade: " << lowestGrade << endl;
    } else {
        cout << "No grades found.\n";
    }

    // Calculate and display average grade
    if (!grades.empty()) {
        double averageGrade = accumulate(grades.begin(), grades.end(), 0.0) / grades.size();
        cout << fixed << setprecision(1);
        cout << "Average grade: " << averageGrade << endl;
    } else {
        cout << "No grades found.\n";
    }
}


void displayExitMessage() {
    cout << "Exiting the program. Goodbye!\n";
}
