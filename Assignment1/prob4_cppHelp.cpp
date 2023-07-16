/*
 Title: tempConversion.cpp
 Description: A temperature conversion application based on user input
 Date: May 22nd, 2023
 Author: Alex Sutherland
 StudentID: 3640392
 Version: 1.0
*/

/*
 DOCUMENTATION
 
 Program Purpose:
	Convert a user entered value to either Fahrenheight or Celsius, also entered by the user.
 	
 Compile (assuming Cygwin is running): g++ -o Assignment1 tempConversion.cpp
 Execution (assuming Cygwin is running): ./tempConversion.exe
 
 Classes:
	- tempOutputs : Enter the temp and desired units, output is the answer in sentence format.

 Variables:
 	temperature - int - the temperature value 
 	units - char - the Units you would like to conver to
*/

/*
 TEST PLAN
 
 Normal case:
 	>printTable()
 	

 Case 1 (infinite loop)
 	> if we ommit the final point of 12, the loop may continue indefinitely.
 

 Discussion:
 	The values are hard coded in this program so any issues that may occur are limited. If we had a prompt and input model
	then the test plan would have to be much more elaborate.
 
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

        if (input == 'x') {
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
            cout << "Though optional, one of the three must be present. \n";
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
