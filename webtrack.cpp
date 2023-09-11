#include <bits/stdc++.h>
#include <string.h>
using namespace std;

// Global variables to store the current URL and browsing history
string currenturl = "";
stack<string> forwardstack;   // Stores website when forward button is pressed
stack<string> backwardstack;  // Stores website when backward button is pressed

// Function to store a new URL when it's opened
void visit_new_url(string url) {
    if (currenturl != "") {
        backwardstack.push(currenturl);  // Push the current web address into the backward_stack
    }
    currenturl = url;  // Set the current URL to the new URL
}

// Function for when the forward button is pressed
void forwardbuttonpressed() {
    if (forwardstack.empty() || currenturl == forwardstack.top()) {
        cout << "No operation done\n";  // If there's no forward history or already on the last page
        return;
    } else {
        backwardstack.push(currenturl);  // Push the current state to the backward stack
        currenturl = forwardstack.top();  // Set the current state to the top of the forward stack
        forwardstack.pop();  // Remove it from the forward stack
    }
}

// Function to handle the state when the backward button is pressed
void backwardbuttonpressed() {
    if (backwardstack.empty() || currenturl == backwardstack.top()) {
        cout << "No operation done\n";  // If there's no backward history or already on the first page
        return;
    } else {
        forwardstack.push(currenturl);  // Push the current URL to the forward stack
        currenturl = backwardstack.top();  // Set the current URL to the top of the backward stack
        backwardstack.pop();  // Pop it from the backward stack
    }
}

// Function to print the current URL
void printurl() {
    cout << "Current URL is: " << currenturl << " \n";
}

// Function that simulates a simple browser with choices
void finalsimulationFunction() {
    cout << "Welcome to the Browser\n";
    cout << "Enter 1 to enter a new URL\n";
    cout << "Enter 2 for pressing the forward button\n";
    cout << "Enter 3 for pressing the backward button\n";
    cout << "Enter 4 to stop all operations\n";
    int n;
    while (n != 4) {
        cout << "Enter your choice:-\n";
        cin >> n;
        switch (n) {
            case 1: {
                cout << "Enter new URL\n";
                string url;
                cin >> url;
                visit_new_url(url);
                printurl();
                break;
            }
            case 2: {
                forwardbuttonpressed();
                printurl();
                break;
            }
            case 3: {
                backwardbuttonpressed();
                printurl();
                break;
            }
            case 4: {
                cout << "Exited. Thank you.";
                break;
            }
            default: {
                cout << "Invalid input\n";
                break;
            }
        }
    }
}

int main() {
    finalsimulationFunction();
    return 0;
}
