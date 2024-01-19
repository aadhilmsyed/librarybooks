//	************************************************************************************
//	Program Name	| MyFunctions.cpp
//	Program Title	| Source File for Function Prototypes
//	Program Author	| Aadhil Mubarak Syed
//	************************************************************************************
//	Program Description:
//	--------------------
//	This header file contains the implementation of all the function prototypes that
//	were declared in MyFunctions.hpp
//	************************************************************************************

#include "MyFunctions.hpp"

void clearCIN (void) {
	cin.clear(),
	cin.ignore(INT_MAX, '\n');
}

void reset (DLLNode* library) {
	while (library->right) { library = library->right; }
}

void clear (DLLNode* ptr) {
	while (ptr->left) { ptr = ptr->left; delete ptr->right; ptr->right = nullptr; }
}

int	displayMenu (void) {

	int userinput = -999;

	cout << "========================================" << endl
		 << "    Book Recommendation Program Menu    " << endl
		 << "----------------------------------------" << endl
		 << "<0> Exit the Program					 " << endl
		 << "<1> Search by Title					 " << endl
		 << "<2> Search by Author                    " << endl
		 << "<3> Search by Genre 					 " << endl
		 << "<4> Search by Level					 " << endl
		 << "<5> Get Top Rated Books				 " << endl
		 << "<6> Add a Rating for a Book			 " << endl
		 << "<7> Check Out a Book					 " << endl
		 << "<8> Return a Book                       " << endl
		 << "<9> Add a Book to Program (Admin Only)  " << endl
		 << "========================================" << endl;

	while (userinput < 0 || userinput > 9) {
		cout << "Please select an option from the menu: ";
		cin  >> userinput; clearCIN();
	}	return userinput;
}

Genre selectGenre() {	int userint = -999;

	// Display Genre Menu
	cout << "========================================" << endl
		 << "      Select a Genre from the Menu      " << endl
		 << "========================================" << endl
		 << "<0> Fiction                             " << endl
		 << "<1> Non-Fiction                         " << endl
		 << "<2> Poetry                              " << endl
		 << "<3> Drama                               " << endl
		 << "<4> Fable                               " << endl
		 << "<5> Mystery                             " << endl
		 << "<6> Mythology                           " << endl
		 << "========================================" << endl;

	// Prompt & Validate User Input
	while (userint < 0 || userint > 6) {
		cout << "Please select a genre: ";
		cin  >> userint; clearCIN();
	}	return static_cast<Genre>(userint);	// Returns Enum Value
}

Level selectLevel() {	int userint = -999;

	// Display Reading Level Menu
	cout << "========================================" << endl
		 << "      Select a Level from the Menu      " << endl
		 << "========================================" << endl
		 << "<0> Toddler                             " << endl
		 << "<1> Childrens                           " << endl
		 << "<2> Pre-Teens                           " << endl
		 << "<3> Young Adults                        " << endl
		 << "<4> Adults                              " << endl
		 << "========================================" << endl;

	// Prompt & Validate User Input
	while (userint < 0 || userint > 4) {
		cout << "Please select a genre: ";
		cin  >> userint; clearCIN();
	}	return static_cast<Level>(userint);
}

void convEnum (DLLNode* ptr, string &genre, string &level) {

	switch (ptr->nodeBook->getGenre()) {
		case FICTION:	 genre = "Fiction"; 	break;
		case NONFICTION: genre = "Non-Fiction"; break;
		case POETRY:	 genre = "Poetry"; 		break;
		case DRAMA:		 genre = "Drama"; 		break;
		case FABLE:		 genre = "Fable"; 		break;
		case MYSTERY:	 genre = "Mystery"; 	break;
		case MYTHOLOGY:	 genre = "Mythology"; 	break;
	}

	switch (ptr->nodeBook->getLevel()) {
		case TODDLER:		level = "Toddler"; 		break;
		case CHILDRENS:		level = "Childrens"; 	break;
		case PRE_TEENS:		level = "Pre-Teens"; 	break;
		case YOUNG_ADULTS:	level = "Young Adults"; break;
		case ADULTS:		level = "Adults"; 		break;
	}
}

//
//DLLNode* importData () {
//
//	fstream inFile; inFile.open("BookFile.txt", ios::in);
//	int size, myint; string str; /**/ inFile >> size;
//	Book* temp = nullptr; DLLNode* ptr = new DLLNode(nullptr, nullptr);
//
//	for (int i = 0; i < size; i++) {
//
//		// Creates new Book and adds to Linked List Library
//		temp = nullptr; temp = new Book(); ptr->insert(temp);
//
//		getline(inFile, str); temp->setTitle(str);	// reads book title
//		getline(inFile, str); temp->setAuthor(str); // reads book author
//
//		// Reads and Converts Integer Values
//		inFile >> myint; /**/ temp->setGenre(static_cast<Genre>(myint));
//		inFile >> myint; /**/ temp->setLevel(static_cast<Level>(myint));
//		inFile >> myint; /**/ temp->setAvailable(static_cast<bool>(myint));
//
//		inFile >> myint; /* reads number of reviews */ if (myint > 0) {
//		for (int i = 0; i < myint; i++) {	userReview r; /* adds reviews to library */
//			inFile >> r.rating; getline(inFile, r.comment); temp->addReview(r);
//		}}
//
//	}	return ptr;
//}

void exportData	(DLLNode *library) {

	fstream outFile; outFile.open("BookFile.txt" , ios::out);

	outFile << library->size() << endl;

	for (DLLNode* ptr = library; ptr; ptr = ptr->right) {
		outFile << ptr->nodeBook->getTitle()  	 << endl; // writes Title to File
		outFile << ptr->nodeBook->getAuthor() 	 << endl; // writes Author to File
		outFile << ptr->nodeBook->getGenre()	 << endl; // writes Genre to File
		outFile << ptr->nodeBook->getLevel()  	 << endl; // writes Level to File
		outFile << ptr->nodeBook->isAvailable()  << endl; // writes Availability to File
		outFile << ptr->nodeBook->reviewsize() 	 << endl; // writes # of Reviews to File
		int size = ptr->nodeBook->reviewsize();			  /* Validates # of Reviews */
		if (size) { for (int i = 0; i < size; i++) { Book* temp = ptr->nodeBook;
			outFile << temp->operator[](i).rating  << endl; // writes review rating
			outFile << temp->operator[](i).comment << endl; // writes review comment
		}}
	}
}

int	displayBooks (DLLNode *library) {	DLLNode* ptr = library;

	// Menu Title Display
	cout << "========================================" << endl
		 << "       Recommended Books For You        " << endl
		 << "========================================" << endl
		 << "<#>|Book Title                      |Rtg" << endl
		 << "---|--------------------------------|---" << endl;
	cout << "<0>|Return to Program Menu          |   " << endl;

	/* Loop to Display Books in Linked List (Library) */ int i = 0;
	for (i = 1; i < 10; i++) {	string str = ptr->nodeBook->getTitle();
		cout << "<" << i << ">"; if (str.length() > 32) { cout << "|";
			for (int j = 0; j < 29; j++) { cout << str[j]; } cout << "...";
		} else { cout << "|" << left << setw(32) << str; }
		cout << "|" << setprecision(1) << setw(3)  << left
			 << fixed << ptr->nodeBook->getRating();
		cout << endl; if (ptr->right) { ptr = ptr->right; } else { break; }
	}

	/* Menu End Display */	int userinput; reset(library);
	cout << "========================================" << endl;
	do {	/* User Selection & Input Validation */
		cout << "Please select a book to view info: ";
		cin  >> userinput; clearCIN();
	}	while (userinput < 0 || userinput > i); return userinput;
}

void  displayInfo  (DLLNode *library, int index) { DLLNode* ptr = library;

	for (int i = 1; i < index; i++) { ptr = ptr->right; } char user = ' ';
	string genre = " ", level = " "; convEnum(ptr, genre, level);

	cout << "========================================"    << endl;
	cout << "Book Title | " << ptr->nodeBook->getTitle()  << endl;
	cout << "Author     | " << ptr->nodeBook->getAuthor() << endl;
	cout << "Avg Rating | " << ptr->nodeBook->getRating() << endl;
	cout << "Genre      | " << genre  					  << endl;
	cout << "Rdg Level  | " << level  					  << endl;
	cout << "========================================"    << endl;

	while (user != 'r' && user != 'R' &&	/* User Input */
		   user != 'm' && user != 'M') {	/* Validation */
		cout << "Press r to read reviews, or press m to" << endl
			 << "return to the menu: "; cin.get(user); clearCIN();
	}
	cout << "----------------------------------------" << endl;

	if (user == 'r' || user == 'R') {
	for (int i = 0; i < ptr->nodeBook->reviews.size(); i++) {
		cout << "Rating: "  << ptr->nodeBook->reviews[i].rating  << endl;
		cout << "Comment: " << ptr->nodeBook->reviews[i].comment << endl;
		cout << "----------------------------------------" << endl;
	}}	reset(library);
}

void  addBookRating	(DLLNode *library) { DLLNode* ptr = library;

	/* Prompt User Input for Title */
	cout << "Enter the name of the title of the Book that you would ";
	cout << "you would like\nto add a review for: "; string title;
	getline(cin, title); ptr->sortTitle(title); userReview rev;

	// Give user instructions for selecting from book menu
	cout << "\nPlease select a book from the following list. If the " << endl
		 << "book you are searching for is not on the list, then the" << endl
		 << "book isn't currently in the library." 		 <<	endl  << endl;

	int user = displayBooks(ptr); if (user != 0) { char yn = ' ';

		for (int i = 1; i < user; i++) { ptr = ptr->right; } // Find Book

		while (yn != 'y' && yn != 'Y' && yn != 'n' && yn != 'N') {
			cout << "Please confirm that you would like to add a review for " << endl;
			cout << ptr->nodeBook->getTitle() << " (y/n): "; cin.get(yn);
		}	/* User Confirmation */

		if (yn == 'y' || yn == 'Y') {
			cout << "Please enter a rating (1-5) for the book: ";
			cin  >> rev.rating; clearCIN();	// User Enters 5-Star Rating

			cout << "Enter a short comment for the book: ";
			getline(cin, rev.comment);		// User Enters Comment

			ptr->nodeBook->addReview(rev); // Adds the Review to the Book
			cout << "Your review was successfully added! " << endl;
		}	else { cout << "Returning to menu..." << endl; }
		}	reset(library);
}

void checkOutBook  (DLLNode *library) { DLLNode* ptr = library;

	/* Prompt User Input for Title */
	cout << "Enter the name of the title of the Book that you would ";
	cout << "you would like\nto check out: "; string title;
	getline(cin, title); ptr->sortTitle(title); userReview rev;

	// Give user instructions for selecting from book menu
	cout << "Please select a book from the following list. If the book " << endl
		 << "you are searching for is not on the list, then the book "   << endl
		 << "isn't currently in the library." 					<<	endl << endl;

	int user = displayBooks(ptr);

	if (user != 0) { /* Book is Found */	char yn = ' ';

		for (int i = 1; i < user; i++) { ptr = ptr->right; } // Find Book

		while (yn != 'y' && yn != 'Y' && yn != 'n' && yn != 'N') {
			cout << "Please confirm that you would like to check out " << endl;
			cout << ptr->nodeBook->getTitle() << " (y/n): "; cin.get(yn);
		}

		if (yn == 'n' || yn == 'N') { cout << "Book not Found. Returning to menu.\n"; }
		else if (!ptr->nodeBook->isAvailable()) {
			cout << "Book is unavailable in library." << endl;
		}
		else {	ptr->nodeBook->toggleAvailable();
			cout << "The book has been checked out. Have a Nice Day!" << endl;
		}
	}	reset(library);
}

void returnBook	(DLLNode *library) { DLLNode* ptr = library;

	/* Prompt User Input for Title */
	cout << "Enter the name of the title of the Book that you would ";
	cout << "you would like\nto return "; string title;
	getline(cin, title); ptr->sortTitle(title); userReview rev;

	// Give user instructions for selecting from book menu
	cout << "Please select a book from the following list. If the book " << endl
		 << "you are searching for is not on the list, then the book "   << endl
		 << "isn't currently in the library." 					<<	endl << endl;

	int user = displayBooks(ptr);

	if (user != 0) { /* Book is Found */	char yn = ' ';

		for (int i = 1; i < user; i++) { ptr = ptr->right; } // Find Book

		while (yn != 'y' && yn != 'Y' && yn != 'n' && yn != 'N') {
			cout << "Please confirm that you would like to return: " << endl;
			cout << ptr->nodeBook->getTitle() << " (y/n): "; cin.get(yn);
		}

		if (yn == 'n' || yn == 'N') { cout << "Book not Found. Returning to menu.\n"; }
		else if (ptr->nodeBook->isAvailable()) {
			cout << "Book is already in the library." << endl;
		}
		else {ptr->nodeBook->toggleAvailable();
			cout << "The book has been returned. Have a Nice Day!" << endl;
		}
	}	reset(library);
}

void adminAddBooks (DLLNode *library) { string str; Book* temp = nullptr;

	// Password Verification
	cout << "Please enter the password: "; getline(cin, str); char user = 'y';
	if (str != "CS2Spring2022") { cout << "Incorrect Password. Returning to Menu." << endl; }
	else {	while (user == 'y' || user == 'Y') { str = "xyz"; temp = new Book;
		cout << "Enter the title of the book: ";  getline(cin, str); temp->setTitle(str);
		cout << "Enter the name of the author: "; getline(cin, str); temp->setAuthor(str);
		temp->setGenre(selectGenre()); temp->setLevel(selectLevel());
		if (!temp->isAvailable()) { temp->toggleAvailable(); } // Set Availability

		/* Prompt User for Review Input and Validate */		user  = ' ';
		while (user != 'n' && user != 'N' && user != 'y' && user != 'Y') {
			cout << "Would you like to add any reviews (y/n)? "; cin.get(user); clearCIN();
		}

		// Add Reviews to Book if User Selects y
		if ( user == 'y' || user == 'Y') { userReview rev;
			cout << "Please enter a rating (1-5) for the book: ";
			cin  >> rev.rating; clearCIN();	/* User Enters 5-Star Rating */
			cout << "Enter a short comment for the book: ";
			getline(cin, rev.comment);		/* User Enters Comment */
			temp->addReview(rev); 			/* Adds Review to Book */
			cout << "Your review was successfully added! " << endl;
		}	user = ' '; /* resets value of char for next input */

		while (user != 'n' && user != 'N' && user != 'y' && user != 'Y') {
			cout << "Would you like to add another book (y/n)? "; cin.get(user); clearCIN();
		}	library->insert(temp); temp = nullptr; /* Adds book to library */
	}}	reset(library);
}

DLLNode* importData () { DLLNode* library = nullptr; Book* temp = nullptr; userReview r;

	temp = new Book("West of Kabul, East of New York", "Tamim Ansary", NONFICTION, YOUNG_ADULTS, true);
	r.rating = 5; r.comment = "Very Nice Book. Would Recommend to High School and College Students";
	temp->addReview(r); library = new DLLNode(nullptr, temp); temp = nullptr;

	temp = new Book("How to be an Antiracist", "Ibram X. Kendi", NONFICTION, ADULTS, true);
	r.rating = 3; r.comment = "This was a good book, but the text can get very blunt at times.";
	temp->addReview(r); r.rating = 2; r.comment = "I wouldn't recommend this book. Not enjoyable.";
	temp->addReview(r); r.rating = 3; r.comment = "I read this for my English course. It was okay.";
	temp->addReview(r); library->insert(temp); temp = nullptr;

	temp = new Book("The Book of Joy", "Douglas Abrams", NONFICTION, YOUNG_ADULTS, true);
	r.rating = 4; r.comment = "This book really dives into what it takes to achieve happiness.";
	temp->addReview(r); r.rating = 5; r.comment = "Great Book, I really enjoyed it!";
	temp->addReview(r); library->insert(temp); temp = nullptr;

	temp = new Book("Blood and Earth", "Kevin bales", NONFICTION, YOUNG_ADULTS, true);
	r.rating = 3; r.comment = "This book is a little dark but still good nonetheless";
	temp->addReview(r); r.rating = 4; r.comment = "Personally I enjoyed this book a lot.";
	temp->addReview(r); library->insert(temp); temp = nullptr;

	temp = new Book("To Kill a Mockingbird", "Harper Lee", FICTION, YOUNG_ADULTS, true);
	r.rating = 4; r.comment = "This book was very enjoyable to read and depicts the real world";
	temp->addReview(r); r.rating = 5; r.comment = "Would Highly Recommend to any High School Students";
	temp->addReview(r); r.rating = 4; r.comment = " ";
	temp->addReview(r); r.rating = 1; r.comment = "Don't recommend reading this book, really just boring";
	temp->addReview(r); library->insert(temp); temp = nullptr;

	temp = new Book("The Giver", "Lois Lowry", FICTION, PRE_TEENS, true);
	r.rating = 5; r.comment = "One of the best dystopian novels, would recommend";
	temp->addReview(r); r.rating = 4; r.comment = "Amazing book, truly enjoyed it";
	temp->addReview(r); library->insert(temp); temp = nullptr;

	temp = new Book("The Hunger Games", "Suzanne Collins", FICTION, YOUNG_ADULTS, true);
	r.rating = 4; r.comment = "It's a nice book, but the ending was a little disappointing";
	temp->addReview(r); r.rating = 5; r.comment = "Really nice book, read it for my English class and loved it";
	temp->addReview(r); r.rating = 5; r.comment = " ";
	temp->addReview(r); library->insert(temp); temp = nullptr;

	temp = new Book("The Very Hungry Caterpillar", "Eric Carle", FABLE, TODDLER, true);
	r.rating = 5; r.comment = "Great Book. This is my child's favorite book";
	temp->addReview(r); r.rating = 2; r.comment = " ";
	temp->addReview(r); r.rating = 3; r.comment = "It was a good book, my kids loved it";

	temp = new Book("The Tortoise and the Hare", "Aesop", FABLE, TODDLER, true);
	r.rating = 2; r.comment = "Had to simulate this book in the program and didn't like it";
	temp->addReview(r); r.rating = 5; r.comment = "My children love reading this book at night";
	temp->addReview(r); library->insert(temp); temp = nullptr;

	temp = new Book("Dr. Seuss's ABCs", "Dr. Seuss", FABLE, TODDLER, true);
	r.rating = 4; r.comment = "Great book, my toddler keeps wants to read this book everytime.";
	temp->addReview(r); r.rating = 3; r.comment = " ";
	temp->addReview(r); r.rating = 4; r.comment = "Nice book to read for children";
	temp->addReview(r); library->insert(temp); temp = nullptr;

	temp = new Book("The Subtle Art of Not Giving a F*ck", "Mark Manson", NONFICTION, ADULTS, true);
	r.rating = 4; r.comment = "Make sure this book doesn't go near young children";
	temp->addReview(r); r.rating = 5; r.comment = "No comment, just absolutely loved it. Must read.";
	temp->addReview(r); r.rating = 5; r.comment = "Would definitely recommend to all my friends";
	temp->addReview(r); r.rating = 5; r.comment = " ";
	temp->addReview(r); library->insert(temp); temp = nullptr;

	temp = new Book("Charlotte’s Web", "E.B. White", FABLE, CHILDRENS, true);
	r.rating = 4; r.comment = "Loved it!";
	temp->addReview(r); r.rating = 3; r.comment = "This story makes no sense at all";
	temp->addReview(r); r.rating = 4; r.comment = " ";
	temp->addReview(r); r.rating = 5; r.comment = " ";
	temp->addReview(r); library->insert(temp); temp = nullptr;

	temp = new Book("Diary of a Wimpy Kid", "Jeff Kinney", FICTION, CHILDRENS, true);
	r.rating = 5; r.comment = "Loved it!";
	temp->addReview(r); r.rating = 3; r.comment = " ";
	temp->addReview(r); r.rating = 4; r.comment = "Can get very addicting";
	temp->addReview(r); r.rating = 5; r.comment = "Best thing I read all year!";
	temp->addReview(r); library->insert(temp); temp = nullptr;

	temp = new Book("Magic Tree House Set", "Mary Pope Osborn", FABLE, CHILDRENS, true);
	r.rating = 4; r.comment = "Great book!";
	temp->addReview(r); r.rating = 3; r.comment = "This book was okay.";
	temp->addReview(r); r.rating = 4; r.comment = "Really nice boook for children in elementary";
	temp->addReview(r); r.rating = 4; r.comment = "All grown up but still love reading it";
	temp->addReview(r); library->insert(temp); temp = nullptr;

	temp = new Book("Percy Jackson & The Olympians Series", "Rick Riordan", MYTHOLOGY, PRE_TEENS, true);
	r.rating = 5; r.comment = "Wow I got so hooked onto these, would recommend reading this!";
	temp->addReview(r); r.rating = 4; r.comment = "Great combination of mythology and Fiction";
	temp->addReview(r); r.rating = 4; r.comment = "I've read this series so many times, it's great";
	temp->addReview(r); r.rating = 4; r.comment = " ";
	temp->addReview(r); library->insert(temp); temp = nullptr;

	temp = new Book("The Lost Hero", "Rick Riordan", MYTHOLOGY, PRE_TEENS, true);
	r.rating = 3; r.comment = "This book was a disappointment compared to the original series";
	temp->addReview(r); r.rating = 4; r.comment = "Including Roman mythology added a nice twist";
	temp->addReview(r); r.rating = 4; r.comment = " ";
	temp->addReview(r); r.rating = 4; r.comment = "Greek Mythology + Roman Mythology = Awesome";
	temp->addReview(r); library->insert(temp); temp = nullptr;

	temp = new Book("The Mark of Athena", "Rick Riordan", MYTHOLOGY, PRE_TEENS, true);
	r.rating = 3; r.comment = "This book was a disappointment compared to the original series";
	temp->addReview(r); r.rating = 4; r.comment = "Including Roman mythology added a nice twist";
	temp->addReview(r); r.rating = 4; r.comment = " ";
	temp->addReview(r); r.rating = 4; r.comment = "Greek Mythology + Roman Mythology = Awesome";
	temp->addReview(r); library->insert(temp); temp = nullptr;

	temp = new Book("The Son of Neptune", "Rick Riordan", MYTHOLOGY, PRE_TEENS, true);
	r.rating = 3; r.comment = "This book was a disappointment compared to the original series";
	temp->addReview(r); r.rating = 4; r.comment = "Including Roman mythology added a nice twist";
	temp->addReview(r); r.rating = 4; r.comment = " ";
	temp->addReview(r); r.rating = 4; r.comment = "Greek Mythology + Roman Mythology = Awesome";
	temp->addReview(r); library->insert(temp); temp = nullptr;

	temp = new Book("Fahrenheit 451", "Ray Bradbury", FICTION, YOUNG_ADULTS, true);
	r.rating = 3; r.comment = "Didn't like the book too much";
	temp->addReview(r); r.rating = 4; r.comment = "It was an alright book";
	temp->addReview(r); r.rating = 4; r.comment = " ";
	temp->addReview(r); library->insert(temp); temp = nullptr;

	temp = new Book("Romeo & Juliet", "William Shakespeare", FICTION, YOUNG_ADULTS, true);
	r.rating = 2; r.comment = "Never want to read this ever again.";
	temp->addReview(r); r.rating = 3; r.comment = "Don't get why English teachers like this";
	temp->addReview(r); r.rating = 3; r.comment = "Hated every part about it. Too exaggerated";
	temp->addReview(r); r.rating = 1; r.comment = " ";
	temp->addReview(r); library->insert(temp); temp = nullptr;

	temp = new Book("The Family Across the Street", "Nicole Trope", MYSTERY, YOUNG_ADULTS, true);
	r.rating = 5; r.comment = "WOW! This book was filled with suspense and I loved it!";
	temp->addReview(r); r.rating = 4; r.comment = "Would highly recommend reading this. Great book!";
	temp->addReview(r); r.rating = 4; r.comment = "Amazing book, would recommend reading.";
	temp->addReview(r); library->insert(temp); temp = nullptr;

	temp = new Book("The Diary of a Young Girl", "Anne Frank", NONFICTION, YOUNG_ADULTS, true);
	r.rating = 4; r.comment = "Gives a great insight about what the holocaust was like";
	temp->addReview(r); r.rating = 4; r.comment = "Perfectly depicts the life of a young girl";
	temp->addReview(r); r.rating = 3; r.comment = "Good book.";
	temp->addReview(r); library->insert(temp); temp = nullptr;

	temp = new Book("The Boy Who Dared", "Susan Campbell Bartoletti", MYSTERY, YOUNG_ADULTS, true);
	r.rating = 5; r.comment = " ";
	temp->addReview(r); r.rating = 4; r.comment = "Nice book!";
	temp->addReview(r); r.rating = 3; r.comment = "Wasn't as good as I expected";
	temp->addReview(r); library->insert(temp); temp = nullptr;

	return library;
}
