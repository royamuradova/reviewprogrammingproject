#include <iostream>
#include <iomanip>

using namespace std;

// Constants
const int NUM_STUDENTS = 3;  // Adjust based on actual number of students
const int NUM_TESTS = 4;     // Adjust based on the number of tests

// Function prototypes
void getStudentData(string names[], int scores[][NUM_TESTS], int numStudents);
void calculateAverages(int scores[][NUM_TESTS], double averages[], int numStudents);
void assignLetterGrades(double averages[], char grades[], int numStudents);
void displayResults(string names[], double averages[], char grades[], int numStudents);

int main() {
    string studentNames[NUM_STUDENTS];
    int scores[NUM_STUDENTS][NUM_TESTS];
    double averages[NUM_STUDENTS];
    char grades[NUM_STUDENTS];

    // Get student data
    getStudentData(studentNames, scores, NUM_STUDENTS);

    // Calculate averages
    calculateAverages(scores, averages, NUM_STUDENTS);

    // Assign letter grades
    assignLetterGrades(averages, grades, NUM_STUDENTS);

    // Display results
    displayResults(studentNames, averages, grades, NUM_STUDENTS);

    return 0;
}

// Function to get student names and test scores
void getStudentData(string names[], int scores[][NUM_TESTS], int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        cout << "Enter student " << i + 1 << " name: ";
        cin >> names[i];

        cout << "Enter " << NUM_TESTS << " test scores for " << names[i] << ": ";
        for (int j = 0; j < NUM_TESTS; j++) {
            cin >> scores[i][j];
        }
    }
}

// Function to calculate student averages
void calculateAverages(int scores[][NUM_TESTS], double averages[], int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        int sum = 0;
        for (int j = 0; j < NUM_TESTS; j++) {
            sum += scores[i][j];
        }
        averages[i] = static_cast<double>(sum) / NUM_TESTS;
    }
}

// Function to assign letter grades based on average scores
void assignLetterGrades(double averages[], char grades[], int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        if (averages[i] >= 90) {
            grades[i] = 'A';
        } else if (averages[i] >= 80) {
            grades[i] = 'B';
        } else if (averages[i] >= 70) {
            grades[i] = 'C';
        } else if (averages[i] >= 60) {
            grades[i] = 'D';
        } else {
            grades[i] = 'F';
        }
    }
}

// Function to display student names, averages, and letter grades
void displayResults(string names[], double averages[], char grades[], int numStudents) {
    cout << "\nGrade Book Results:\n";
    cout << setw(15) << "Name" << setw(10) << "Average" << setw(10) << "Grade" << endl;
    cout << "-------------------------------------" << endl;

    for (int i = 0; i < numStudents; i++) {
        cout << setw(15) << names[i] 
             << setw(10) << fixed << setprecision(2) << averages[i] 
             << setw(10) << grades[i] << endl;
    }
}
