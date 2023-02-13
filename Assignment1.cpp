#include "Assignment1.h"
#include <array>
#include <fstream>
#include <iostream>
#include <stdexcept>
using namespace std;

void Assignment1::loadFile() {  // Will load the file as long as it exists and can load it.
    int i = 0;
    int temp = 0;

    ifstream myFile;

    myFile.exceptions(ifstream::failbit | ifstream::badbit);

    try {
        myFile.open("textInput.txt");
        while (myFile >> temp) {
            if (arrIndex >= MAX_ARRAY_SIZE) {
                throw out_of_range("\nToo many numbers in file. Please fix error and try again.\n");
                break;
            }
            nums[i++] = temp;
            arrIndex++;
            if (myFile.eof())
                break;
        }
        myFile.close();
    } catch (ifstream::failure e) {
        cerr << "Exception opening/reading/closing file\n";
    }
}

void Assignment1::findNumber(int numToSearch) {  // Will find a number and print the first instance of the integer.
    bool isFound = false;
    for (int i = 0; i < arrIndex; i++) {
        if (numToSearch == nums[i]) {
            cout << "The first occurance of " << numToSearch << " was found at index " << i << endl;
            isFound = true;
            break;
        }
    }
    if (!isFound)
        cout << "Number not found.\n";
}

void Assignment1::replaceNumber(int index, int num) {  // Will replace a number as long as its in range.
    if (index >= arrIndex) {
        throw out_of_range("\nIndex not found in array. Please enter another number and try again.\n");
    }
    cout << "Before replacement, index [" << index << "] has a value of " << nums[index] << endl;
    nums[index] = num;
    cout << "After replacement, index  [" << index << "] has a value of " << nums[index] << endl;
}

void Assignment1::addNumber(int num) {  // Will add a number to the end of the array as long as there is space at the end.
    if (arrIndex >= MAX_ARRAY_SIZE) {
        throw out_of_range("\nArray is full. Please remove some elements and try again.\n");
    } else {
        nums[arrIndex] = num;
        arrIndex++;
    }
}

void Assignment1::printArray() {  // Prints the array to the user in the console
    for (int i = 0; i < arrIndex; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

void Assignment1::removeNumber(int index) {  // Will remove a number from the array as long as the index is valid.
    if (arrIndex == 0 || index >= MAX_ARRAY_SIZE) {
        throw out_of_range("Cannot remove item from array.");
    } else {
        arrIndex--;
        nums[index] = 0;
    }
}

int main() {
    class Assignment1 a;

    // Variables to store the temporary parameters used in each function
    int selection = 0;
    int p1, p2;

    // Tries to load the file
    try {
        a.loadFile();
    } catch (const out_of_range& e) {
        cout << e.what() << endl;
    }

    while (selection != 6) {
        // Prompts the user to choose an option and then takes in their choice.
        cout << "\nWhat would you like to do?\n1) Print the array\n2) Find an integer\n3) Replace an integer\n"
                "4) Add an integer to the end of an array\n5) Remove an integer from the array\n6) Exit the program\n";

        cin >> selection;
        p1 = 0;
        p2 = 0;

        cout << endl;  // space for easier readibility in the console

        // Handles the different functions based on what number is input.
        switch (selection) {
            case 1:
                try {
                    a.printArray();
                } catch (const out_of_range& e) {
                    cout << e.what() << endl;
                }
                break;
            case 2:
                cout << "Which number would you like to find? ";
                cin >> p1;
                try {
                    a.findNumber(p1);
                } catch (const out_of_range& e) {
                    cout << e.what() << endl;
                }
                break;
            case 3:
                cout << "Enter an index and a number to put in that spot. (Seperated with a space). ";
                cin >> p1 >> p2;
                try {
                    a.replaceNumber(p1, p2);
                } catch (const out_of_range& e) {
                    cout << e.what() << endl;
                }
                break;
            case 4:
                cout << "Enter an integer to add to the end of the array. ";
                cin >> p1;
                try {
                    a.addNumber(p1);
                } catch (const out_of_range& e) {
                    cout << e.what() << endl;
                }
                break;
            case 5:
                cout << "Enter an index to remove from the array. ";
                cin >> p1;
                try {
                    a.removeNumber(p1);
                } catch (const out_of_range& e) {
                    cout << e.what() << endl;
                }
                break;
            case 6:
                exit(0);
                break;
            default:
                cout << "Please enter an integer from 1-6.\n";
        }
    }
    return 0;
}