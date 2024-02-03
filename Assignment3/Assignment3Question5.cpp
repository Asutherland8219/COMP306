/*
 Title: Assignment3Question5.cpp
 Description: Create a book class, sort the books by various parameters in a bookshelf
 Date: January 28th, 2024
 Author: Alex Sutherland
 StudentID: 3640392
 Version: 1.0
*/


/*
 DOCUMENTATION

 Program Purpose:
	Create a book and bookshelf class. Sort books via various params in the bookshelf. Add validation protocol for data quality as well.

 Compile (assuming Cygwin is running): g++ -o Assignment3 Assignment3Question5.cpp
 Execution (assuming Cygwin is running): ./Assignment3Question5.exe

 Classes (functions):
    - Class
        - Book
            - Functions
                - Book(std::vector<std::string>) - the main book constructor, takes a vector of strings
                - get(string query) - The getter for book, with a queryable input
                - details() - Prints all the details of a book

        - BookShelf
            - Functions
                - displayBooks(std::vector<Book>, std::string, std::string)
                    - The output function, can include a custom message (first string) or filter by a specific field (2nd string)
                - testBookshelf() - Test function, outputs books in the order entered, followed by sorted by year and title, then
                    finally sorted by default field, title.
                - testInvalidBookFew() - Test if too few fields are entered, error raised.
                - testInvalidBookMany() - Test if too many fields are entered, error raised.
                - testSecondCondition() - Test if the name is the same the books are sorted by year published.
                - testDuplicateEntries() - Test if ISBN are the same raise an error.
                - compareBooks(Book, Book, string) - compare books also has a field param if comparing for specific assignment
                - bulkCreateBooks(std::vector<std::vector<std::string>>, debug= True)
                    - Create a list of books based on raw data. Also have option to debug for more verbose and less aggressive error handling.
                - bookSort(std::vector<Book>, string)
                    - Sort the books based on a specific criteria
                - assertInvalidArgument(std::function)

 Variables:
 	- string title - the book title
 	- string ISBN - the ISBN code
 	- string author - the author of the novel
 	- string edition - the edition of the novel (ie. 1st, 2nd)
 	- string publisher - the publisher of the novel
 	- string year_published - the year published

 	- std::vector<std::string> bookInfo - the book data in the format of list of strings, single entry
 	- string query - the query string
 	- std::vector<Book> - a list of Books
 	- std::vector<std::vector<std::string>> books_raw - a list of bookInfo, a list of lists of strings

*/

/*
 TEST PLAN

 Normal case:
    Bookshelf bookshelf;
    bookshelf.testBookshelf();
    Output:
        Books in the order they were entered:
            Title: Red Rising
            ISBN: 034553980X
            Author: Pierce Brown
            Edition: First Edition
            Publisher: Del Rey
            Year Published: 2014

            Title: Golden Son
            ISBN:  0345539834
            Author: Pierce Brown
            Edition: Second Edition
            Publisher: Del Rey
            Year Published: 2015

            Title: Morning Star
            ISBN: 9781444759075
            Author: Pierce Brown
            Edition: First Edition
            Publisher: Del Rey
            Year Published: 2017

            Title: Iron Gold
            ISBN:  147364657X
            Author: Pierce Brown
            Edition: Second Edition
            Publisher: Del Rey
            Year Published: 2018

            Title: Dark Age
            ISBN: 0425285960
            Author: Pierce Brown
            Edition: First Edition
            Publisher: Del Rey
            Year Published: 2020

            Title: Lightbringer
            ISBN: 0425285979
            Author: Pierce Brown
            Edition: Second Edition
            Publisher: Del Rey
            Year Published: 2023

            Title: East of Eden
            ISBN: 9780140186390
            Author: John Steinbeck
            Edition: First Edition
            Publisher: Viking Press
            Year Published: 1952

            Title: Of Mice and Men
            ISBN: 78901266754
            Author: John Steinbeck
            Edition: Second Edition
            Publisher: Covici Friede
            Year Published: 1937

            Title: Babel
            ISBN: 9780063021426
            Author: R.F. Kuang
            Edition: First Edition
            Publisher: Harper Voyager
            Year Published: 2020

            Title: The Name of the Wind
            ISBN: 756404079
            Author: Patrick Rothfuss
            Edition: Second Edition
            Publisher: DAW Books
            Year Published: 2007

            Title: A Wise Man's Fear
            ISBN: 9780756404734
            Author: Patrick Rothfuss
            Edition: First Edition
            Publisher: DAW Books
            Year Published: 2011

            Title: The Art of War
            ISBN: 000000000001
            Author: Sun Tzu
            Edition: Archaic Edition
            Publisher: Sun Tzu Publishing
            Year Published: 400


            Books sorted by entered field: YEAR PUBLISHED
            Title: The Art of War
            ISBN: 000000000001
            Author: Sun Tzu
            Edition: Archaic Edition
            Publisher: Sun Tzu Publishing
            Year Published: 400

            Title: Of Mice and Men
            ISBN: 78901266754
            Author: John Steinbeck
            Edition: Second Edition
            Publisher: Covici Friede
            Year Published: 1937

            Title: East of Eden
            ISBN: 9780140186390
            Author: John Steinbeck
            Edition: First Edition
            Publisher: Viking Press
            Year Published: 1952

            Title: The Name of the Wind
            ISBN: 756404079
            Author: Patrick Rothfuss
            Edition: Second Edition
            Publisher: DAW Books
            Year Published: 2007

            Title: A Wise Man's Fear
            ISBN: 9780756404734
            Author: Patrick Rothfuss
            Edition: First Edition
            Publisher: DAW Books
            Year Published: 2011

            Title: Red Rising
            ISBN: 034553980X
            Author: Pierce Brown
            Edition: First Edition
            Publisher: Del Rey
            Year Published: 2014

            Title: Golden Son
            ISBN:  0345539834
            Author: Pierce Brown
            Edition: Second Edition
            Publisher: Del Rey
            Year Published: 2015

            Title: Morning Star
            ISBN: 9781444759075
            Author: Pierce Brown
            Edition: First Edition
            Publisher: Del Rey
            Year Published: 2017

            Title: Iron Gold
            ISBN:  147364657X
            Author: Pierce Brown
            Edition: Second Edition
            Publisher: Del Rey
            Year Published: 2018

            Title: Dark Age
            ISBN: 0425285960
            Author: Pierce Brown
            Edition: First Edition
            Publisher: Del Rey
            Year Published: 2020

            Title: Babel
            ISBN: 9780063021426
            Author: R.F. Kuang
            Edition: First Edition
            Publisher: Harper Voyager
            Year Published: 2020

            Title: Lightbringer
            ISBN: 0425285979
            Author: Pierce Brown
            Edition: Second Edition
            Publisher: Del Rey
            Year Published: 2023


            Books sorted by Default Field [Title]:
            Title: A Wise Man's Fear
            ISBN: 9780756404734
            Author: Patrick Rothfuss
            Edition: First Edition
            Publisher: DAW Books
            Year Published: 2011

            Title: Babel
            ISBN: 9780063021426
            Author: R.F. Kuang
            Edition: First Edition
            Publisher: Harper Voyager
            Year Published: 2020

            Title: Dark Age
            ISBN: 0425285960
            Author: Pierce Brown
            Edition: First Edition
            Publisher: Del Rey
            Year Published: 2020

            Title: East of Eden
            ISBN: 9780140186390
            Author: John Steinbeck
            Edition: First Edition
            Publisher: Viking Press
            Year Published: 1952

            Title: Golden Son
            ISBN:  0345539834
            Author: Pierce Brown
            Edition: Second Edition
            Publisher: Del Rey
            Year Published: 2015

            Title: Iron Gold
            ISBN:  147364657X
            Author: Pierce Brown
            Edition: Second Edition
            Publisher: Del Rey
            Year Published: 2018

            Title: Lightbringer
            ISBN: 0425285979
            Author: Pierce Brown
            Edition: Second Edition
            Publisher: Del Rey
            Year Published: 2023

            Title: Morning Star
            ISBN: 9781444759075
            Author: Pierce Brown
            Edition: First Edition
            Publisher: Del Rey
            Year Published: 2017

            Title: Of Mice and Men
            ISBN: 78901266754
            Author: John Steinbeck
            Edition: Second Edition
            Publisher: Covici Friede
            Year Published: 1937

            Title: Red Rising
            ISBN: 034553980X
            Author: Pierce Brown
            Edition: First Edition
            Publisher: Del Rey
            Year Published: 2014

            Title: The Art of War
            ISBN: 000000000001
            Author: Sun Tzu
            Edition: Archaic Edition
            Publisher: Sun Tzu Publishing
            Year Published: 400

            Title: The Name of the Wind
            ISBN: 756404079
            Author: Patrick Rothfuss
            Edition: Second Edition
            Publisher: DAW Books
            Year Published: 2007

 Bad Case
    Not user input based, so less likely to experience any serious issues. Possible margin of error would come from entering
    duplicate entries and entering an incorrect value for certain fields like year.

    Because these are based on pre-set data, any bad case or errors is executed in the test functions.

    // Test second condition
    bookshelf.testSecondCondition();
    Output:
        Books with the same title sorted by year published:
            Title: Red Rising
            ISBN:  0345539834
            Author: Pierce Brown
            Edition: Second Edition
            Publisher: Del Rey
            Year Published: 2000

            Title: Red Rising
            ISBN: 034553980X
            Author: Pierce Brown
            Edition: First Edition
            Publisher: Del Rey
            Year Published: 2015

            Title: Red Rising
            ISBN:  0345539833
            Author: Pierce Brown
            Edition: Second Edition
            Publisher: Del Rey
            Year Published: 2023


    bookshelf.testInvalidBookFew();
    Output:
        Success: std::invalid_argument caught - You are missing some mandatory fields to create a book. Please ensure you have
        the following details:
        title
        isbn
        author
        edition
        publisher
        year_published


    bookshelf.testInvalidBookMany();
    Output:
        Success: std::invalid_argument caught - You have entered too many fields. Please ensure you have the following details:

        title
        isbn
        author
        edition
        publisher
        year_published


    bookshelf.testDuplicateEntries();
    Output:
        Success: std::invalid_argument caught - Duplicate entry: ISBN values are unique, please make sure you do not have duplicate entries.


 Discussion:
 	Create a Bookshelf, along with a Book class. The bookshelf contains books and allows for various sorting methods.
 	Handle things like duplicates and conflicting data (ie. same name).
*/

#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <functional>
#include <stdexcept>

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
        else if (bookInfo.size() > 6){
            throw std::invalid_argument("You have entered too many fields. Please ensure you have the following details: \n"
                                        "title \n"
                                        "isbn \n"
                                        "author \n"
                                        "edition \n"
                                        "publisher \n"
                                        "year_published \n");
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
        displayBooks(books, "Books sorted by Default Field [Title]:" );
        books.clear();
    }

    static void testInvalidBookFew() {
        bool debug;
        std::vector<std::vector<std::string>> books_raw_incorrect = {
                {"Red Rising",  "034553980X", "Pierce Brown", "First Edition",  "Del Rey"},
        };
        assertInvalidArgument([&]() {bulkCreateBooks(books_raw_incorrect, debug=true); });
        books.clear();
    }

    static void testInvalidBookMany() {
        bool debug;
        std::vector<std::vector<std::string>> books_raw_incorrect = {
                {"Red Rising",  "034553980X", "Pierce Brown", "First Edition",  "Del Rey", "2014", "My favorite"},
        };
        assertInvalidArgument([&]() {bulkCreateBooks(books_raw_incorrect, debug=true); });
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
        assertInvalidArgument([&]() {bookSort(books);});
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


    static void bulkCreateBooks(std::vector<std::vector<std::string>>& books_raw, bool debug = true) {
        for (const auto &bookInfo: books_raw) {
            try {
                books.emplace_back(bookInfo);
            } catch (const std::invalid_argument& e) {
                if (!debug) {
                    std::cerr << "Error creating book: " << e.what() << std::endl;
                    throw;
                }
                throw;
            }
        }
    };

    // Function to sort books based on user-specified criteria
    static void bookSort(std::vector<Book>& books, const std::string& sortCriteria = "TITLE") {
        std::sort(books.begin(), books.end(), [&sortCriteria](const Book& book1, const Book& book2) {
            return compareBooks(book1, book2, sortCriteria);
        });
    }

    // an assertion test argument; raises the error in a quieter fashion
    // accepts a function to run
    static void assertInvalidArgument(const std::function<void()>& func) {
        try {
            func();
        } catch (const std::invalid_argument &e) {
            std::cerr << "Success: std::invalid_argument caught - " << e.what() << std::endl;
        }
    }

};



std::vector<Book> Bookshelf::books;






