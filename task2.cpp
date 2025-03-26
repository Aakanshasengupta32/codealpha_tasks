#include <iostream>
#include <fstream>
#include <string>
#include <algorithm> // For trimming whitespace
using namespace std;

void registerUser();
bool loginUser();

int main() {
    int choice;

    do {
        cout << "\n===== Login & Registration System =====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                if (loginUser()) {
                    cout << "Login Successful!\n";
                } else {
                    cout << "Login Failed! Incorrect username or password.\n";
                }
                break;
            case 3:
                cout << "Exiting the system...\n";
                break;
            default:
                cout << "Invalid choice! Please enter 1, 2, or 3.\n";
        }
    } while (choice != 3);

    return 0;
}

// Utility function to trim leading and trailing whitespace
string trim(const string& str) {
    size_t first = str.find_first_not_of(" \t");
    size_t last = str.find_last_not_of(" \t");
    return (first == string::npos || last == string::npos) ? "" : str.substr(first, last - first + 1);
}

void registerUser() {
    string username, password;

    cout << "Enter a username: ";
    cin >> username;
    username = trim(username);
    if (username.empty()) {
        cout << "Error: Username cannot be empty or only spaces.\n";
        return;
    }

    cout << "Enter a password: ";
    cin >> password;
    password = trim(password);
    if (password.empty()) {
        cout << "Error: Password cannot be empty or only spaces.\n";
        return;
    }

    ifstream readFile("users.txt");
    if (!readFile) {
        ofstream createFile("users.txt");
        if (!createFile) {
            cout << "Error: Unable to create user file.\n";
            return;
        }
        createFile.close();
    }

    string storedUser, storedPass;
    while (readFile >> storedUser >> storedPass) {
        if (storedUser == username) {
            cout << "Error: Username already exists. Try a different one.\n";
            readFile.close();
            return;
        }
    }
    readFile.close();

    ofstream writeFile("users.txt", ios::app);
    if (!writeFile) {
        cout << "Error: Unable to write to user file.\n";
        return;
    }
    writeFile << username << " " << password << endl;
    writeFile.close();

    cout << "Registration Successful!\n";
}

bool loginUser() {
    string username, password;

    cout << "Enter your username: ";
    cin >> username;
    username = trim(username);
    if (username.empty()) {
        cout << "Error: Username cannot be empty or only spaces.\n";
        return false;
    }

    cout << "Enter your password: ";
    cin >> password;
    password = trim(password);
    if (password.empty()) {
        cout << "Error: Password cannot be empty or only spaces.\n";
        return false;
    }

    ifstream readFile("users.txt");
    if (!readFile) {
        cout << "Error: No registered users found or unable to open user file.\n";
        return false;
    }

    string storedUser, storedPass;
    while (readFile >> storedUser >> storedPass) {
        if (storedUser == username && storedPass == password) {
            readFile.close();
            return true;
        }
    }
    readFile.close();
    return false;
}

