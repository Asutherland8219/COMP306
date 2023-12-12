//
// Created by asuth on 12/10/2023.
//

#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <map>

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
    // Constructor that takes an array of strings for book information
    Book(const std::vector<std::string>& bookInfo) {
        if (bookInfo.size() == 6) {
            title = bookInfo[0];
            ISBN = bookInfo[1];
            author = bookInfo[2];
            edition = bookInfo[3];
            publisher = bookInfo[4];
            year_published = bookInfo[5];
        }
        else {
            throw std::invalid_argument("You are missing some mandatory fields to create a book. Please ensure you have the following details: \n"
                                        "title \n"
                                        "isbn \n"
                                        "author \n"
                                        "edition \n"
                                        "publisher \n"
                                        "year_published \n");
        };
    }

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
    static std::vector<Book> books;

    static void displayBooks(std::vector<Book> &finished_books, const std::string &message, const std::string field = "title") {
        if (field == "title") {
            std::cout << message << std::endl;
        }
        else {
            std::cout << message << field << std::endl;
        }
        for (auto book: finished_books) {
            book.details();
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    static void testBookshelf() {
        // Create a dozen books
        std::vector<std::vector<std::string>> books_raw = {
                {"Red Rising",  "034553980X", "Pierce Brown", "First Edition",  "Del Rey", "2014"},
                {"Golden Son", " 0345539834 ", "Pierce Brown", "Second Edition", "Del Rey", "2015"},
                {"Morning Star",  "9781444759075", "Pierce Brown", "First Edition",  "Del Rey", "2017"},
                {"Iron Gold", " 147364657X ", "Pierce Brown", "Second Edition", "Del Rey", "2018"},
                {"Dark Age",  "0425285960", "Pierce Brown", "First Edition",  "Del Rey", "2020"},
                {"Lightbringer", "0425285979", "Pierce Brown", "Second Edition", "Del Rey", "2023"},
                {"East of Eden",  "9780140186390", "John Steinbeck", "First Edition",  "Viking Press", "1952"},
                {"Of Mice and Men", "78901266754", "John Steinbeck", "Second Edition", "Covici Friede", "1937"},
                {"Babel",  "9780063021426", "R.F. Kuang", "First Edition",  "Harper Voyager", "2020"},
                {"The Name of the Wind", "756404079", "Patrick Rothfuss", "Second Edition", "DAW Books", "2007"},
                {"A Wise Man's Fear",  "9780756404734", "Patrick Rothfuss", "First Edition",  "DAW Books", "2011"},
                {"The Art of War", "000000000001", "Sun Tzu", "Archaic Edition", "Sun Tzu Publishing", "400"},
        };

        bulkCreateBooks(books_raw);

        // Display books in the order they were entered
        displayBooks(books, "Books in the order they were entered: ");

        // Sort books by year published
        string field = "YEAR PUBLISHED";
        bookSort(books, field);
        displayBooks(books, "Books sorted by entered field: ", field);


        // display books by sorting default of Title
        bookSort(books);
        displayBooks(books, "Books sorted by Default Field:" );
        books.clear();
    }

    static void testInvalidBook() {
        std::vector<std::vector<std::string>> books_raw_incorrect = {
                {"Red Rising",  "034553980X", "Pierce Brown", "First Edition",  "Del Rey"},
        };
        bulkCreateBooks(books_raw_incorrect);
        books.clear();
    }

    static void testSecondCondition() {
        // Test that if the name is the same, the books are ordered by year published
        std::vector<std::vector<std::string>> books_raw_same = {
                {"Red Rising",  "034553980X", "Pierce Brown", "First Edition",  "Del Rey", "2015"},
                {"Red Rising", " 0345539834 ", "Pierce Brown", "Second Edition", "Del Rey", "2000"},
                {"Red Rising", " 0345539833 ", "Pierce Brown", "Second Edition", "Del Rey", "2023"},
        };
        bulkCreateBooks(books_raw_same);
        bookSort(books);
        displayBooks(books, "Books with the same title sorted by year published: ");
        books.clear();
    }

    static void testDuplicateEntries() {
        std::vector<std::vector<std::string>> books_raw_same = {
                {"Red Rising",  "034553980X", "Pierce Brown", "First Edition",  "Del Rey", "2015"},
                {"Red Rising", " 0345539834 ", "Pierce Brown", "Second Edition", "Del Rey", "2000"},
                {"Red Rising", " 0345539834 ", "Pierce Brown", "Second Edition", "Del Rey", "2023"},
        };
        bulkCreateBooks(books_raw_same);
        bookSort(books);
        books.clear();
    }

    static bool compareBooks(Book book1, Book book2, std::string field = "TITLE") {
        std::string value1 = book1.get(field);
        std::string value2 = book2.get(field);

        // Because the year value is a converted int, sorting is difficult.
        // We change it back to int before sorting
        if (field == "TITLE" && value1 == value2) {
            field = "YEAR PUBLISHED";
            value1 = book1.get(field);
            value2 = book2.get(field);
        }

        // Duplicate condition; isbn are unique
        std::string isin1 = book1.get("isbn");
        std::string isin2 = book2.get("isbn");
        if (isin1 == isin2) {
            throw invalid_argument("Duplicate entry: ISBN values are unique, please make sure you do not have duplicate entries.\n");
        }

        if (field == "YEAR PUBLISHED") {
            return std::stoi(value1) < std::stoi(value2);
        } else {
            return value1 < value2;
        }

    }


    static void bulkCreateBooks(std::vector<std::vector<std::string>>& books_raw) {
        for (const auto &bookInfo: books_raw) {
            try {
                books.emplace_back(bookInfo);
            } catch (const std::invalid_argument& e) {
                std::cerr << "Error creating book: " << e.what() << std::endl;
            }
        }
    };

    // Function to sort books based on user-specified criteria
    static void bookSort(std::vector<Book>& books, const std::string& sortCriteria = "TITLE") {
        std::sort(books.begin(), books.end(), [&sortCriteria](const Book& book1, const Book& book2) {
            return compareBooks(book1, book2, sortCriteria);
        });
    }
};



std::vector<Book> Bookshelf::books;






