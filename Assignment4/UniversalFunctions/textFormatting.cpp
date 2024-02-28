//
// Created by asuth on 2/17/2024.
//

// ANSI codes
#define BOLD "\033[1m"
#define ITALIC "\033[3m"
#define RESET "\033[0m"

class textFormatter {
public:
    static void printBold(const std::string& text) {
        std::cout << BOLD << text << RESET;
    }

    static void printItalic(const std::string& text) {
        std::cout << ITALIC << text << RESET;
    }

    static void printBoldItalic(const std::string& text) {
        std::cout << BOLD << ITALIC << text << RESET;
    }
};

