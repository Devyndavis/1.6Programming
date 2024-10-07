#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

// Constants
const int NUM_RUNNERS = 5; // Number of runners
const int NUM_DAYS = 7;     // Number of days in a week

// Function prototypes
void readData(string runners[], int miles[][NUM_DAYS], const string& filename);
void calculateTotalsAndAverages(const int miles[][NUM_DAYS], int totals[], double averages[]);
void outputResults(const string runners[], const int miles[][NUM_DAYS], const int totals[], const double averages[]);

int main() {
    string runners[NUM_RUNNERS];                  // Array to store runners' names
    int miles[NUM_RUNNERS][NUM_DAYS] = {0};       // 2D array to store miles run
    int totals[NUM_RUNNERS] = {0};                 // Array to store total miles run by each runner
    double averages[NUM_RUNNERS] = {0.0};          // Array to store average miles run by each runner

    // Read data from file
    readData(runners, miles, "runners.txt");

    // Calculate total and average miles run
    calculateTotalsAndAverages(miles, totals, averages);

    // Output the results
    outputResults(runners, miles, totals, averages);

    return 0;
}

// Function to read runners' names and miles run each day from a file
void readData(string runners[], int miles[][NUM_DAYS], const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error opening file!" << endl;
        exit(1);
    }

    for (int i = 0; i < NUM_RUNNERS; ++i) {
        inFile >> runners[i]; // Read runner's name
        for (int j = 0; j < NUM_DAYS; ++j) {
            inFile >> miles[i][j]; // Read miles for each day
        }
    }
    inFile.close();
}

// Function to calculate total and average miles run by each runner
void calculateTotalsAndAverages(const int miles[][NUM_DAYS], int totals[], double averages[]) {
    for (int i = 0; i < NUM_RUNNERS; ++i) {
        int total = 0;
        for (int j = 0; j < NUM_DAYS; ++j) {
            total += miles[i][j]; // Calculate total miles for each runner
        }
        totals[i] = total;                             // Store total miles
        averages[i] = static_cast<double>(total) / NUM_DAYS; // Calculate average miles
    }
}

// Function to output the results in a formatted table
void outputResults(const string runners[], const int miles[][NUM_DAYS], const int totals[], const double averages[]) {
    cout << left << setw(15) << "Runner Name"; // Table header
    for (int day = 1; day <= NUM_DAYS; ++day) {
        cout << setw(10) << "Day " + to_string(day); // Days of the week
    }
    cout << setw(15) << "Total Miles" << setw(15) << "Avg Miles" << endl;

    // Output results for each runner
    for (int i = 0; i < NUM_RUNNERS; ++i) {
        cout << left << setw(15) << runners[i]; // Runner's name
        for (int j = 0; j < NUM_DAYS; ++j) {
            cout << setw(10) << miles[i][j]; // Miles run each day
        }
        cout << setw(15) << totals[i] << setw(15) << fixed << setprecision(2) << averages[i] << endl; // Total and average
    }
}