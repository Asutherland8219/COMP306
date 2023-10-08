/*
 Title: Assignment2Question2.cpp
 Description: The Book Class
 Date: October 5th, 2023
 Author: Alex Sutherland
 StudentID: 3640392
 Version: 1.0
*/


/*
 DOCUMENTATION

 Program Purpose:
	Create a book class that stores information about a particular book. These attributes include title,
 isbn number, author, edition, publisher and year.

 Compile (assuming Cygwin is running): g++ -o Assignment2 Assignment2Question2.cpp
 Execution (assuming Cygwin is running): ./Assignment2Question2.exe

 Classes (functions):
	- Book()
        - Title:
        - ISBN Number:
        - Author:
        - Edition:
        - Publisher:
        - Year Published:

        Getters:
            - Get(input)
                An input driven getter, used to fetch any of the attributes listed

            - Details()
                A details function, that prints all the attributes at once

        Setters:
            - setTitle()
            - setISBN()
            - setAuthor()
            - setEdition()
            - setPublisher()
            - setYearPublished()

        The setters use string value inputs to know what to change the existing values to. These values all correspond with
        the setter name. For example setTitle() uses the title variable etc...

        Assignment Requirements were to create a Book() class with getters and setters. I opted to create the getters
        as an input based function and the additional details is nice for printing out the entire information of the Book.

 Variables:
    ** The getter uses query input
    string query;

 	string title;
    string ISBN;
    string author;
    string edition;
    string publisher;
    string year_published;

*/

/*
 TEST PLAN

 Normal case:

     Book red_rising = Book();

     red_rising.setTitle("Red Rising");
     red_rising.setISBN("034553980X");
     red_rising.setAuthor("Pierce Brown");
     red_rising.setEdition("1st Edition");
     red_rising.setPublisher("Del Rey Books");
     red_rising.setYearPublished("Jan. 1 2014");

     red_rising.details();
     --> Title: Red Rising
         ISBN: 034553980X
         Author: Pierce Brown
         Edition: 1st Edition
         Publisher: Del Rey Books
         Year Published: Jan. 1 2014


     // create a second book, this time only getting one item at a time
     Book golden_son = Book();
     golden_son.setTitle("Golden Son");
     golden_son.setISBN("0345539818");
     golden_son.setAuthor("Pierce Brown");
     golden_son.setEdition("1st Edition");
     golden_son.setPublisher("Del Rey Books");
     golden_son.setYearPublished("Jan. 6 2015");

     // get all the details
     golden_son.get("title")
     --> Golden Son

     golden_son.get("isbn")
     --> 0345539818

     golden_son.get("author")
     --> Pierce Brown

     golden_son.get("edition")
     --> 1st Edition

     golden_son.get("publisher")
     --> Del Rey Books

     golden_son.get("year published")
     --> Jan. 6 2015

 Bad Case:
    Some values, such as the ISBN are actually numeric so could be a double. However, I have set the value as a string in order to avoid any type issues.
    If a numeric value is entered, the program will not compile.

 Discussion:
    With the setter functions, we could also opt to print the output. As a sort of confirmation of the value being set.
    This is not necessary given the constraints of this assignment, but could be implemented if desired.

*/
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

class Book {
private:
    string title;
    string ISBN;
    string author;
    string edition;
    string publisher;
    string year_published;

public:
    //get
    string get(string query) {
        // capitalize the function
        std::transform(query.begin(), query.end(), query.begin(), ::toupper);

        if (query == "TITLE") {
            return title;
        }
        if (query == "ISBN"){
            return ISBN;
        }
        if (query == "AUTHOR") {
            return author;
        }
        if (query == "EDITION") {
            return edition;
        }
        if (query == "PUBLISHER") {
            return publisher;
        }
        if (query == "YEAR PUBLISHED") {
            return year_published;
        }
        else {
            return "Incorrect input, please try again.";
        };
    };

    void details() {
        cout << "Title: " << title << std::endl;
        cout << "ISBN: " << ISBN << std::endl;
        cout << "Author: " << author << std::endl;
        cout << "Edition: " << edition << std::endl;
        cout << "Publisher: " << publisher << std::endl;
        cout << "Year Published: " << year_published << std::endl;
    }

public:
        //setters
        void setTitle(const string& newTitle) {
            title = newTitle;
        }
        void setISBN(const string& newISBN) {
            ISBN = newISBN;
        }
        void setAuthor(const string& newAuthor) {
            author = newAuthor;
        }
        void setEdition(const string& newEdition) {
            edition = newEdition;
        }
        void setPublisher(const string& newPublisher) {
            publisher = newPublisher;
        }
        void setYearPublished(const string& newYearPublished) {
            year_published = newYearPublished;
        }

    };

