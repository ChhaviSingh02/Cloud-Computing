// Cloud Computing Lab Exercise 3
// File Handling using C language in Virtual Machine
// Date: 30/1/2025
// Q1. Write a C program to perform basic file handling operations. Your program should:
// 1.	Create a file and write user input into it.
// 2.	Read the contents of the file and display them on the screen.
// 3.	Append new data to the existing file without deleting the previous content.
// Q2. Extend the file handling program to include additional functionalities:
// 1.	Delete a file if the user chooses to.
// 2.	Search for a specific word or phrase in the file and display the number of occurrences.


#include <iostream>
#include <fstream>
#include <string>
// #include <filesystem>
#include <cstdio>  // Include this header for the remove function


using namespace std;

void createAndWrite();
void readFile();
void appendToFile();
void deleteFile();
void searchInFile();

int main() {
    int choice;
    while (true) {
        cout << "\nFile Handling Options:\n";
        cout << "1. Create and Write a File\n";
        cout << "2. Read a File\n";
        cout << "3. Append Data to a File\n";
        cout << "4. Delete a File\n";
        cout << "5. Search for a Word in a File\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // To handle newline characters

        switch (choice) {
            case 1:
                createAndWrite();
                break;
            case 2:
                readFile();
                break;
            case 3:
                appendToFile();
                break;
            case 4:
                deleteFile();
                break;
            case 5:
                searchInFile();
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
    return 0;
}

void createAndWrite() {
    string filename, content;
    cout << "Enter the filename: ";
    cin >> filename;
    cin.ignore();

    ofstream file(filename);  // Open file in write mode
    if (!file) {
        cout << "Error creating file!\n";
        return;
    }

    cout << "Enter content to write into the file: ";
    getline(cin, content);

    file << content;
    file.close();
    cout << "File written successfully.\n";
}

void readFile() {
    string filename, line;
    cout << "Enter the filename to read: ";
    cin >> filename;
    
    ifstream file(filename);  // Open file in read mode
    if (!file) {
        cout << "Error: File not found!\n";
        return;
    }

    cout << "\nFile Content:\n";
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

void appendToFile() {
    string filename, content;
    cout << "Enter the filename to append data: ";
    cin >> filename;
    cin.ignore();

    ofstream file(filename, ios::app);  // Open file in append mode
    if (!file) {
        cout << "Error opening file!\n";
        return;
    }

    cout << "Enter content to append: ";
    getline(cin, content);

    file << "\n" << content;
    file.close();
    cout << "Data appended successfully.\n";
}

void deleteFile() {
    string filename;
    cout << "Enter the filename to delete: ";
    cin >> filename;

    // Check if file exists before deleting
    ifstream file(filename);
    if (!file) {
        cout << "Error: File not found!\n";
        return;
    }
    file.close();  // Close file before attempting deletion

    // if (remove(filename.c_str()) == 0) {
    //     cout << "File deleted successfully.\n";
    // } else {
    //     cout << "Error deleting file. It may be in use or protected.\n";
    // }
}

void searchInFile() {
    string filename, word, fileWord;
    int count = 0;

    cout << "Enter the filename to search in: ";
    cin >> filename;
    cout << "Enter the word to search: ";
    cin >> word;

    ifstream file(filename);
    if (!file) {
        cout << "Error: File not found!\n";
        return;
    }

    while (file >> fileWord) {
        if (fileWord == word) {
            count++;
        }
    }

    file.close();
    cout << "The word '" << word << "' appeared " << count << " times in the file.\n";
}
