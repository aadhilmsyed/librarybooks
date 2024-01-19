//	************************************************************************************
//	Spring 2022		| Las Positas Honors Transfer Program (Program Development)
//	************************************************************************************
//	Project Mentor	| Professor Carlos Moreno
//	Honors Course	| CS2 - Computing Fundamentals II
//	************************************************************************************
//	Program Name	| HonorsProject.cpp
//	Program Title	| Book Recommendation Program Prototype
//	Program Author	| Aadhil Mubarak Syed
//	************************************************************************************
//	Program Description:
//	--------------------
//	This program is a prototype of a book recommendation system such as the ones used
//	in libraries and other e-commerce sites for books. The objective of this project is
//	to create a well-developed program that can interact with a user to provide
//	the optimal book based on the user’s preference through a series of object-oriented
//	programming, classes, algorithms, functions, files, and various data structures to
//	demonstrate mastery of the learning outcomes in CS2.
//	************************************************************************************

//	************************************************************************************
//	Program Includes (Header Files)
//	************************************************************************************

	#include "Book.hpp"				// Contains Book Class
	#include "HonorsProject.hpp"	// Contains Program Includes & ADTs
	#include "LinkedList.hpp"		// Contains Linked List Class
	#include "MyFunctions.hpp"		// Contains All Program Function Prototypes

//	************************************************************************************
//	Main Function (Starting Point of Program)
//	************************************************************************************

int main() {

	DLLNode *library = importData(); 	// Create Library Linked List

	bool	 keepGoing = true;			// Controls Program Loop
	string	 userstr = " ";				// User String Input
	int		 userint = 0;				// Integer Return Value Functions

	// Program Loop
	while (keepGoing) { /* Program Menu Display Loop */ switch (displayMenu()) {
		case 0: keepGoing = false; break; /* Break out of While Loop & Switch */
		case 1:	cout << "Enter the title of the book: "; getline(cin, userstr);
				library->sortTitle(userstr); userint = displayBooks(library);
				if (userint != 0) { displayInfo(library, userint); } break;
		case 2: cout << "Enter the author name: "; getline(cin, userstr);
				library->sortAuthor(userstr); userint = displayBooks(library);
				if (userint != 0) { displayInfo(library, userint); } break;
		case 3: library->sortGenre(selectGenre()); userint = displayBooks(library);
				if (userint != 0) { displayInfo(library, userint); } break;
		case 4: library->sortLevel(selectLevel()); userint = displayBooks(library);
				if (userint != 0) { displayInfo(library, userint); } break;
		case 5:	library->sortRating(); userint = displayBooks(library);
				if (userint != 0) { displayInfo(library, userint); } break;
		case 6: addBookRating(library); break; case 7: checkOutBook(library);  break;
		case 8: returnBook(library);	break; case 9: adminAddBooks(library); break;
	}}	reset(library); /* Returns Library to first node in Linked List */

	 exportData(library); /* Exports to File */	clear(library); /* Releases Memory */
	cout << "\nProgram Ending, Have a Nice Day" << endl; return 0; // Terminate Program
}

//	************************************************************************************
