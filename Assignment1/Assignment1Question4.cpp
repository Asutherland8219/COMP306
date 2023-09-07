/*
 Title: Assignment1Question4.cpp
 Description: A help function for basic CPP
 Date: May 22nd, 2023
 Author: Alex Sutherland
 StudentID: 3640392
 Version: 1.0
*/

/*
 DOCUMENTATION
 
 Program Purpose:
	Allow the user to select things related to CPP to help and provide information.
 	
 Compile (assuming Cygwin is running): g++ -o Assignment1 Assignment1Question4.cpp
 Execution (assuming Cygwin is running): ./Assignment1Question4.exe

 Classes (functions):
	- helpMenu() : The base menu setting for the program. Lists the available options
    - userInput() : The input function, once entered, returns the corresponding information

 Variables:
 	char input : A char value input, because data uses both int and char, it is best to convert int to char to avoid loops.
 	bool running : a flag to indicate if the program is running or not.

*/

/*
 TEST PLAN
 
 Normal case:
 	>helpMenu()
 	

 Case 1 (infinite loop)
 	> If we didn't convert int to a char in the input and we didn't get the expected value, it would loop.

 Case 2 (Selection outside of listed selection)
    > Raise invalid selection and return back to the helpMenu listing the selections

 Case 3 (No selection)
    > Wait and do nothing, continue holding at the helpMenu

 Case 4 (Upper or lowercase x)
    > program accepts both variations, conditional logic works for both X and x

 Discussion:
 	This program, unlike the tempConversion, will not end if too many bad inputs are given. The separation of the input
 	and the menu allow the program to restart back to the original menu. This allows for a user to select more than one
 	of the items in the list and educate themselves on multiple topics, not just one at a time.

 	Incorrect inputs are not supported but if entered an exception will be raised and the program will restart
 	(ie. just wait at the menu)
 
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

    while (running) {

        cout << "Select Help on: \n";
        cout << "\t 1. If\n";
        cout << "\t 2. Switch\n";
        cout << "\t 3. For\n";
        cout << "\t 4. While\n";
        cout << "\t 5. Do-while\n";
        cout << "\t x. Exit\n";
        cin >> input;

        cout << "\nSelection: " << input << "\n";

        if (input == 'x' || input == 'X') {
            running = false;
            cout << "\nThank you. Good bye. \n";
            break;
        } else {
            userInput(input);

        }
    }
}



void userInput(char choice) {
    // encapsulation of the input code where we will print the info based on the input.

    switch (choice) {
        case '1':
            cout << "Help on If: \n" ;
            cout << "A condtional statement to check if the data meets a set condtion. It operates on true/false logic. \n";
            cout << "If the condition is met, the if statement is evaluated as true and the appropirate codeblock is executed. \n";
            cout << "If the condition is not met we default to false and the code continues. \n" ;
            cout << "We can also create an else statement to specify another code block to be executed if the if condition is evaluated as false. \n";
            cout << "Source: Think CPP  Chapter 4 Conditionals and Recursions. \n";
            break;
        case '2':
            cout << "Help on Switch: \n" ;
            cout << "A statement based on specific cases. The switch statement evaluates an expression once, then compares the expression value to each possible case. \n";
            cout << "If a match exists then the corresponding codeblock is executed. If you want to exit early on a match, you can add a break function. \n";
            cout << "A break can save time in looping over the remaining cases if the case is already met. \n";
            cout << "Additionally, you can add a default statement that will execute if no case is matched. \n";
            cout << "Source: https://www.w3schools.com/cpp/cpp_switch.asp \n";
            break;
        case '3':
            cout << "Help on For: \n" ;
            cout << "A loop function that will run a finite amount of times. \n";
            cout << "The for loop operates based on three [optional] parameters: \n";
            cout << "\t 1. Initialization: initializes the variables, executed only once. \n";
            cout << "\t 2. Condition: the condition to be met, if met the code block is executed, if not the loop is terminated. \n";
            cout << "\t 3. Update: updates the value of the initialized variables and again checks the condition. \n";
            cout << "Sources :\n https://www.programiz.com/cpp-programming/for-loop \n";
            cout << "https://learn.microsoft.com/en-us/cpp/cpp/for-statement-cpp?view=msvc-170 \n";

            break;
        case '4':
            cout << "Help on While:  \n" ;
            cout << "A loop function that runs while a conditional statement is evaluated as true. A while loop begins by evaluating the condtion; \n";
            cout << "If the condition is true, the code block inside the loop is executed. This process continues until the condition evaluates as false.\n";
            cout << "When it is evaluated as false the loop terminates. \n";
            cout << "While loops can be dangerous because if a condition is never set to false, the loop will run indefinitely.\n";
            cout << "For safety, you can add a simple counter variable and increment on each loop. Once the counter value is hit, exit the loop.\n";
            cout << "Source: https://www.programiz.com/cpp-programming/do-while-loop \n";
            break;
        case '5':
            cout << "Help on Do-While: \n"  ;
            cout << "A variant of a standard while loop but differs by adding a 'do' code block. This code block is executed once before the condition is checked. \n";
            cout << "While the condition evaluates to true, the body of the loop inside of the do code block is executed. After execution the condition is evaluated again. \n";
            cout << "If the condition is false, the loop ends. \n";
            cout << "Source: https://www.programiz.com/cpp-programming/do-while-loop \n";
            break;
        default:
            cout << "Invalid selection. Please select an item from the options listed.\n";
            break;
    }
}
