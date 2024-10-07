#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

// Struct to hold runner data
struct Runner {
    string name;       // Runner's name
    int miles[7];      // Array to store miles run each day
    int totalMiles;    // Total miles run for the week
    double averageMiles; // Average miles run per day
};

// Function prototypes
void readData(Runner runners[], int size);
void calculateTotalsAndAverages(Runner runners[], int size);
void displayResults(const Runner runners[], int size);

int main() {
    const int NUM_RUNNERS = 5; // Number of runners
    Runner runners[NUM_RUNNERS]; // Array of Runner structs

    readData(runners, NUM_RUNNERS); // Read data from file
    calculateTotalsAndAverages(runners, NUM_RUNNERS); // Calculate totals and averages
    displayResults(runners, NUM_RUNNERS); // Display the results

    return 0;
}

// Function to read and store the runners' names and miles run each day
void readData(Runner runners[], int size) {
    ifstream inputFile("runners.txt"); // Open the input file

    if (!inputFile) { // Check if the file opened successfully
        cerr << "Error opening file." << endl;
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        inputFile >> runners[i].name; // Read the runner's name
        for (int j = 0; j < 7; j++) {
            inputFile >> runners[i].miles[j]; // Read the miles for each day
        }
    }
    inputFile.close(); // Close the input file
}

// Function to calculate total miles and average miles for each runner
void calculateTotalsAndAverages(Runner runners[], int size) {
    for (int i = 0; i < size; i++) {
        int sum = 0;
        for (int j = 0; j < 7; j++) {
            sum += runners[i].miles[j]; // Sum up the miles for each runner
        }
        runners[i].totalMiles = sum; // Store total miles
        runners[i].averageMiles = static_cast<double>(sum) / 7; // Calculate average miles
    }
}

// Function to display the results in a formatted table
void displayResults(const Runner runners[], int size) {
    cout << left << setw(15) << "Runner's Name"; // Column header for names
    cout << "Day 1  Day 2  Day 3  Day 4  Day 5  Day 6  Day 7  Total  Average" << endl;
    cout << string(75, '-') << endl; // Separator line

    for (int i = 0; i < size; i++) {
        cout << left << setw(15) << runners[i].name; // Print runner's name
        for (int j = 0; j < 7; j++) {
            cout << setw(6) << runners[i].miles[j]; // Print miles run each day
        }
        cout << setw(6) << runners[i].totalMiles; // Print total miles
        cout << fixed << setprecision(2) << runners[i].averageMiles; // Print average miles
        cout << endl;
    }
}