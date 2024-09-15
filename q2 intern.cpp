#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void registerUser() {
    string username, password;
    cout << "Enter a username: ";
    cin >> username;
    cout << "Enter a password: ";
    cin >> password;

    ofstream file;
    file.open(username + ".txt");

  
    file << username << endl << password << endl;
    file.close();

    cout << "Registration successful!\n";
}

bool loginUser() {
    string username, password, storedUsername, storedPassword;

    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

  
    ifstream file(username + ".txt");
    if (!file) {
        cout << "User not found! Please register first.\n";
        return false;
    }

    getline(file, storedUsername);
    getline(file, storedPassword);
    file.close();

    if (username == storedUsername && password == storedPassword) {
        cout << "Login successful!\n";
        return true;
    } else {
        cout << "Incorrect username or password.\n";
        return false;
    }
}

int main() {
    int choice;
    cout << "1. Register\n";
    cout << "2. Login\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            registerUser();
            break;
        case 2:
            loginUser();
            break;
        default:
            cout << "Invalid choice!\n";
            break;
    }

    return 0;
}

