#include <iostream>
#include <vector>
#include <iomanip> // For std::fixed and std::setprecision
using namespace std;

double calculateCGPA(const vector<double>& gradePoints, const vector<int>& creditHours) {
    double totalGradePoints = 0;
    int totalCredits = 0;

    for (size_t i = 0; i < gradePoints.size(); ++i) {
        totalGradePoints += gradePoints[i] * creditHours[i];
        totalCredits += creditHours[i];
    }

    return totalCredits == 0 ? 0.0 : totalGradePoints / totalCredits;
}

int main() {
    int numSubjects;

    cout << "Enter the number of subjects: ";
    cin >> numSubjects;

    if (numSubjects <= 0) {
        cout << "Error: Number of subjects must be greater than zero." << endl;
        return 1;
    }

    vector<double> gradePoints(numSubjects);
    vector<int> creditHours(numSubjects);

    for (int i = 0; i < numSubjects; ++i) {
        cout << "Enter grade point for subject " << i + 1 << ": ";
        cin >> gradePoints[i];
        if (gradePoints[i] < 0) {
            cout << "Error: Grade points cannot be negative." << endl;
            return 1;
        }

        cout << "Enter credit hours for subject " << i + 1 << ": ";
        cin >> creditHours[i];
        if (creditHours[i] < 0) {
            cout << "Error: Credit hours cannot be negative." << endl;
            return 1;
        }
    }

    double cgpa = calculateCGPA(gradePoints, creditHours);
    cout << fixed << setprecision(2); // Format output to two decimal places
    cout << "Your CGPA is: " << cgpa << endl;

    return 0;
}

