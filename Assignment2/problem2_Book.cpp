//
// Created by alex on 05/08/23.
//
#include <cstring>
#include <algorithm>
#include <string>

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
        };
        if (query == "ISBN") {
            return ISBN;
        };
        if (query == "AUTHOR") {
            return author;
        };
        if (query == "EDITION") {
            return edition;
        };
        if (query == "PUBLISHER") {
            return publisher;
        };
        if (query == "YEAR PUBLISHED") {
            return year_published;
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
        void setTitle(const string newTitle) {
            title = newTitle;
        }
        void setISBN(const string newISBN) {
            ISBN = newISBN;
        }
        void setAuthor(const string newAuthor) {
            author = newAuthor;
        }
        void setEdition(const string newEdition) {
            edition = newEdition;
        }
        void setPublisher(const string newPublisher) {
            publisher = newPublisher;
        }
        void setYearPublished(const string newYearPublished) {
            year_published = newYearPublished;
        }

    };

