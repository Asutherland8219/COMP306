//
// Created by asuth on 1/17/2024.
//

#include <iostream>

class ChapterOneGates {
public:
    bool panic_breaker;
    bool panicChoice(int choice) {
        switch (choice) {
            case 1:
                std::cout << "You vault over the edge and jump without a fear or care in the world!";
                panic_breaker = true;
                break;
            case 2:
                std::cout << "You reach into your pocket, and find a small bronze coin, you throw it in to the well...\n";
                std::cout << "and you wait...\n";
                std::cout << "and you wait...\n";
                std::cout << "and you wait...\n";
                std::cout << "But you never hear it hit the bottom.";
                break;
            case 3:
                std::cout << "You turn around to walk away thinking nothing of what just happened. Just as you start to walk away, a bird swoops down in front of your face. \n"
                             "Out of panic, you take a step back towards the well, losing your footing in the process and tumbling backwards while yelling: \n";
                std::cout << "ahhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh...\n";
                panic_breaker = true;
                break;
        }
        return panic_breaker;
    }




};

