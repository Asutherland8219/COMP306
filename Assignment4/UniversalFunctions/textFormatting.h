#ifndef TEXT_FORMATTER_H
#define TEXT_FORMATTER_H

#include <iostream>
#include <string>

// ANSI codes
#define BOLD "\033[1m"
#define ITALIC "\033[3m"
#define RESET "\033[0m"

class textFormatter {
public:
    static void printBold(const std::string& text);
    static void printItalic(const std::string& text);
    static void printBoldItalic(const std::string& text);
};

#endif //TEXT_FORMATTER_H
