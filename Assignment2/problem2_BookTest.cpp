//
// Created by alex on 05/08/23.
//

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class BookTest {
public:
    explicit BookTest(){
        // Test function for the Book class ; mainly on creation
        // test getters in the main
        Book red_rising = Book();

        red_rising.setTitle("Red Rising");
        red_rising.setISBN("034553980X");
        red_rising.setAuthor("Pierce Brown");
        red_rising.setEdition("1st Edition");
        red_rising.setPublisher("Del Rey Books");
        red_rising.setYearPublished("Jan. 1 2014");
    }
};
