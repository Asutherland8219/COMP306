/*
 Title: cppHelp.cpp
 Description: A help flow for common C++ topics
 Date: May 22nd, 2023
 Author: Alex Sutherland
 StudentID: 3640392
 Version: 1.0
*/
#include <iostream>
#include <iomanip>
using namespace std;

void helpMenu() {
    /*
    Create a help menu for C++ topics such as if, switch, for , while, do-while
    */
   char input;
   bool running = true;
   void userInput(char);

   while(running) {

    cout << "Select Help on: \n";
    cout << "\t 1. If\n";
    cout << "\t 2. Switch\n";
    cout << "\t 3. For\n";
    cout << "\t 4. While\n";
    cout << "\t 5. Do-while\n";
    cout << "\t x. Exit\n";
    cin >> input;

    // because the inputs can be both int and char it is best for us to convert the int to char and handle accordingly

   switch (input) {
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
            cout << "\nSelection: " << input << "\n";
            userInput(input);
            break;
        case 'x':
            cout << "\nSelection: " << input << "\n";
            running = false;
            cout << "\nThank you. Good bye.";
            break;
        default:
            cout << "\nSelection: " << input << "\n";
            cout << "Invalid selection. Please select an item from the options listed.";
            break;
    }
}

};

void userInput(char choice) {
    // encapsulation of the input code where we will print the info based on the input.

    switch (choice) {
        case '1':
            cout << "Help on If: ..." ; 
            break;
        case '2':
            cout << "Help on Switch: ..." ;
            break;
        case '3':
            cout << "Help on For: ..." ;
            break;
        case '4':
            cout << "Help on While: ..." ;
            break;
        case '5':
            cout << "Help on Do-While: ..."  ;
            break;
        default:
            cout << "Invalid selection. Please select an item from the options listed above."  ;
            break;
    }
}
