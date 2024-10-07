#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

// Function prototypes
void readData(string names[], int miles[][7], int size);
void calculateTotalsAndAverages(const int miles[][7], int totalMiles[], double averageMiles[], int size);
void displayResults(const string names[], const int miles[][7], const int totalMiles[], const double averageMiles[], int size);

int main() {
    const int NUM_RUNNERS = 5; // Number of runners
    string names[NUM_RUNNERS]; // Array to store runner names
    int miles[NUM_RUNNERS][7]; // 2D array to store miles run each day
    int totalMiles[NUM_RUNNERS] = {0}; // Array to store total miles for each runner
    double averageMiles[NUM_RUNNERS] = {0.0}; // Array to store average miles for each runner

    readData(names, miles, NUM_RUNNERS);
    calculateTotalsAndAverages(miles, totalMiles, averageMiles, NUM_RUNNERS);
    displayResults(names, miles, totalMiles, averageMiles, NUM_RUNNERS);

    return 0;
}

// Function to read and store the runners' names and miles run each day
void readData(string names[], int miles[][7], int size) {
    ifstream inputFile("runners.txt"); // Open the input file

    if (!inputFile) { // Check if the file opened successfully
        cerr << "Error opening file." << endl;
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        inputFile >> names[i]; // Read the runner's name
        for (int j = 0; j < 7; j++) {
            inputFile >> miles[i][j]; // Read the miles for each day
        }
    }
    inputFile.close(); // Close the input file
}

// Function to calculate total miles and average miles for each runner
void calculateTotalsAndAverages(const int miles[][7], int totalMiles[], double averageMiles[], int size) {
    for (int i = 0; i < size; i++) {
        int sum = 0;
        for (int j = 0; j < 7; j++) {
            sum += miles[i][j]; // Sum up the miles for each runner
        }
        totalMiles[i] = sum; // Store total miles
        averageMiles[i] = static_cast<double>(sum) / 7; // Calculate average miles
    }
}

// Function to display the results in a formatted table
void displayResults(const string names[], const int miles[][7], const int totalMiles[], const double averageMiles[], int size) {
    cout << left << setw(15) << "Runner's Name"; // Column header for names
    cout << "Day 1  Day 2  Day 3  Day 4  Day 5  Day 6  Day 7  Total  Average" << endl;
    cout << string(75, '-') << endl; // Separator line

    for (int i = 0; i < size; i++) {
        cout << left << setw(15) << names[i]; // Print runner's name
        for (int j = 0; j < 7; j++) {
            cout << setw(6) << miles[i][j]; // Print miles run each day
        }
        cout << setw(6) << totalMiles[i]; // Print total miles
        cout << fixed << setprecision(2) << averageMiles[i]; // Print average miles
        cout << endl;
    }
}