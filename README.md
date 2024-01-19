# Library Book Recommendation System Prototype

## Overview

This repository contains the source code for a book recommendation system prototype developed as part of the Las Positas Honors Transfer Program for the CS2 - Computing Fundamentals II course in Spring 2022. The project is mentored by Professor Carlos Moreno.

The program serves as a prototype for a book recommendation system, similar to those utilized in libraries and e-commerce platforms. Its primary objective is to interact with users, providing optimal book recommendations based on their preferences. The implementation showcases mastery of object-oriented programming, classes, algorithms, functions, files, and various data structures.

## Project Details

- **Program Name:** HonorsProject.cpp
- **Program Title:** Book Recommendation Program Prototype
- **Program Author:** Aadhil Mubarak Syed

## Program Includes

The program includes several header files that contribute to its functionality:

- **Book.hpp:** Contains the Book class declaration.
- **Book.cpp:** Contains the Book class implementation.
- **HonorsProject.hpp:** Includes main program dependencies and Abstract Data Types (ADTs).
- **HonorsProject.cpp:** Starting Point of the Program
- **LinkedList.hpp:** Declares the Linked List class.
- **LinkedList.cpp:** Defines the Linked List class.
- **MyFunctions.hpp:** Declares all program function prototypes.
- **MyFunctions.hpp:** Defines all program function prototypes.

## Main Function

The program's main function serves as the starting point, featuring a loop that presents a menu for user interaction. The menu allows users to perform various actions, including searching for books by title, author, genre, level, and rating. Users can also add and check out books, return books, and perform administrative tasks such as adding new books to the library.

```cpp
int main() {
    // ... (program initialization)

    // Program Loop
    while (keepGoing) {
        switch (displayMenu()) {
            // ... (menu options and corresponding actions)
        }
    }

    // ... (cleanup and program termination)
}
```

## Getting Started

To run the program, follow these steps:

1. In an IDE, Compile the source code using a C++ compiler.
2. Execute the compiled program.
3. Interact with the menu to perform various actions.

Otherwise, using a terminal, execute the following commands: 
```
g++ -o HonorsProject HonorsProject
./HonorsProject.cpp
```

## Additional Notes

- Ensure that the necessary header files are included and accessible during compilation.
- The program utilizes linked lists to manage the library of books.
- Data is imported and exported to/from files for persistence.

## Termination

The program concludes with a message: "Program Ending, Have a Nice Day."

Feel free to explore and enhance the program as needed!
