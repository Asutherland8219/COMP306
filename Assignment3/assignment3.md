Problem 1

Write a program that opens a file and counts the whitespace-separated words in that file. You may obtain the name of the input file either from the command line or via prompt and user input. Be sure to clearly document the method chosen.

You may test your program using any number of text files; however, you must be sure to test your program using the Sample Text File provided at the end of this assignment (excerpt.txt). This file is also available in the Assessment section of the course home page.
Problem 2

Write a program that opens a (text) file and displays the contents of that file one line at a time. You must obtain the name of the input file for this program via prompt and user input, not via command line arguments.

After a line has been displayed, the program should wait for the user to press the <Enter> key before displaying the next line in the file.

As with Problem 1, you may test your program on any number of text files; however, you must be sure to test your program using the Sample Text File provided at the end of this assignment (excerpt.txt).
Problem 3

Write a program in which you create a class called TextFileReader. The TextFileReader class must contain an instance variable consisting of an array of 100 elements.

TextFileReader should have two constructors: a default constructor and a constructor that takes a String argument that represents the name of a text file to be opened and read into the array of Strings. The first (default) constructor does not really do anything on its own. If the second constructor is used, it will open the file and read the contents of the file into the array of Strings, as follows: fill the array by having your program read one line of the file into each string, until you have filled the array. Once the array is full, you may stop reading the input file.

Add a member function contents(), which will convert the array of Strings into a single StringBuffer, which is then returned to the calling program so that it may be displayed.

Add a second member function display(), which prints the array to standard output using the format line #: <string>, where # is the actual line number and <string> is the stored string. [You can use the array counter for the # value.] Do not forget that line numbers for the output should start with 1, not 0.

Now, create a second class TextFileReaderDemo, which contains a main() method used to test TextFileReader. Create an instance of TextFileReader using the second constructor, and then call contents() to obtain the file’s text. Display the file’s contents to standard output. Finally, call display() to output the file’s text together with line numbers, as stated in the display() requirements.

TextFileReaderDemo should use command-line arguments to obtain the text file name supplied to the TextFileReader constructor.

As with Problems 1 and 2, you may test your program on any number of text files; however, you must be sure to test your program using the Sample Text File provided at the end of this assignment (excerpt.txt).
Problem 4

Write a program that creates three floating point arrays. Fill the first two arrays with 25 floating point numbers using loop structures, as follows: fill the first array with the loop counter value and fill the second array with the loop counter value squared. Finally, write a loop that adds the corresponding elements in the first two arrays and puts the result in the corresponding element of the third array. Display all three arrays using the format for counter; element + element = element.