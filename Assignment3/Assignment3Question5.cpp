//
// Created by asuth on 12/10/2023.
//

#include <algorithm>
#include <string>
#include <iostream>
#include <vector>

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
    //Constructor
    Book(string title_str, string isbn_str, string author_str, string edition_str, string publisher_str, string year_published) :
    title(title_str), ISBN(isbn_str), author(author_str), edition(edition_str), publisher(publisher_str), year_published(year_published) {}

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

class Bookshelf {
public:
    static void sortBooks(std::vector<Book>& books) {
        std::sort(books.begin(), books.end(), BookComparator());
    }

    static void displayBooks(const std::vector<Book>& books, const std::string& message) {
        std::cout << message << std::endl;
        for (const auto book : books) {

            book.details();
        }
        std::cout << std::endl;
    }

    static void main() {
        // Create a dozen books
        std::vector<Book> books = {
                {"Book1", "123456", "Author1", "First Edition", "Publisher1", 2000},
                {"Book2", "789012", "Author2", "Second Edition", "Publisher2", 1998},

        };

        // Display books in the order they were entered
        displayBooks(books, "Books in the order they were entered:");

        // Sort books and display again
        sortBooks(books);
        displayBooks(books, "Books sorted by title and year of publication:");
    }
};

    void bookSort(std::vector<Book> books, string field = "title" )
    // default to title if no explicit field is given

    {

};

// function for checking for duplicates

    bool bookCheck() {

};





