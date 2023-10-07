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

 Bad Case

 Discussion:

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

