//	************************************************************************************
//	Program Name	| LinkedList.hpp
//	Program Title	| Header File for Linked List Data Structure
//	Program Author	| Aadhil Mubarak Syed
//	************************************************************************************
//	Program Description:
//	--------------------
//	This header file contains the program includes necessary to construct the linked
//	list data structure as well as a declaration of the linked list node structure,
//	including it's attributes and methods
//	************************************************************************************

#ifndef LINKEDLIST_HPP_
#define LINKEDLIST_HPP_

#include <iostream>
using namespace std;

#include "Book.hpp"
#include "HonorsProject.hpp"

struct DLLNode {

	private: static int totalnodes;
	public:

		DLLNode* left; 	// Pointer to Address of Left Node
		DLLNode* right;	// Pointer to Address of Right Node
		Book* nodeBook;	// Value of Node (Book)

		DLLNode(DLLNode*, Book*);	// Overload Constructor
		virtual ~DLLNode();			// Virtual Destructor

		int	  size() const;		// Returns Number of Nodes in Linked List
		void  insert(Book*);	// Adds a Book to the End of the Linked List
		void  swap (DLLNode*);	// Swaps two elements in the Linked List

		void sortRating();			// Sorts books in linked list by rating
		void sortAuthor(string);	// Sorts books by relevance in author name
		void sortGenre(Genre);		// Sorts books by selected genre
		void sortLevel(Level);		// Sorts books by chosen level
		void sortTitle(string);		// Sorts books by releveance in book title

};

#endif /* LINKEDLIST_HPP_ */
