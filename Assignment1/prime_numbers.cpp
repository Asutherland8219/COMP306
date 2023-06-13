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
