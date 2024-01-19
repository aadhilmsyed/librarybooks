//	************************************************************************************
//	Program Name	| LinkedList.cpp
//	Program Title	| Source File for Linked List Data Structure
//	Program Author	| Aadhil Mubarak Syed
//	************************************************************************************
//	Program Description:
//	--------------------
//	This source file contains the construct, destructor, and method implementations for
//	the linked list structure. This file also contains the methods to sort books based
//	on a selected criteria.
//	************************************************************************************

#include "LinkedList.hpp"

int DLLNode::totalnodes = 0;

int absval (int i) { if (i < 0) { return (i * -1); } else return i; }

DLLNode::DLLNode(DLLNode* l, Book* b) :
	left(l),
	right(nullptr),
	nodeBook(b)
{
	totalnodes++;
}

DLLNode::~DLLNode() {
	if (left) { this->left->right = this->right; delete left;  left  = nullptr; }
	if (right) { this->right->left = this->left; delete right; right = nullptr; }
	delete nodeBook; nodeBook = nullptr; totalnodes--;
}

int	  DLLNode::size() const { return totalnodes; }

void  DLLNode::insert(Book* b) {
	if (!this->nodeBook) { this->nodeBook = b; }
	else if (!this->right) { this->right = new DLLNode(this, b); }
	else { this->right->insert(b); }
}

void  DLLNode::swap (DLLNode *other) { Book* temp = this->nodeBook;
	this->nodeBook = other->nodeBook; other->nodeBook = temp;
}

void DLLNode::sortRating() { DLLNode* ptr = this; DLLNode* m = nullptr;

	/* Validate First Node */ while (ptr->left) { ptr = ptr->left; }

	for (DLLNode* p = ptr; p->right; p = p->right) { m = p; /* Perform */
	for (DLLNode* q = p->right;   q; q = q->right) { /* Selection Sort */
		if (q->nodeBook->getRating() > p->nodeBook->getRating()) { m = q; }
	}	if (m != p) { p->swap(m); } }

	/* Return to First Node */ while (ptr->left) { ptr = ptr->left; }

}

void DLLNode::sortTitle(string s) { /**/ this->sortRating();

	DLLNode* ptr = this; DLLNode* m = nullptr;
	/* Validate First Node */ while (ptr->left) { ptr = ptr->left; }

	for (DLLNode* p = ptr; p->right; p = p->right) { m = p; /* Perform */
	for (DLLNode* q = p->right;   q; q = q->right) { /* Selection Sort */
		if (absval(q->nodeBook->getTitle().compare(s)) <
			absval(p->nodeBook->getTitle().compare(s))) { m = q; }
	}	if (m != p) { p->swap(m); } }

	/* Return to First Node */ while (ptr->left) { ptr = ptr->left; }

}

void DLLNode::sortAuthor(string s) { /**/ this->sortRating();

	DLLNode* ptr = this; DLLNode* m = nullptr;
	/* Validate First Node */ while (ptr->left) { ptr = ptr->left; }

	for (DLLNode* p = ptr; p->right; p = p->right) { m = p; /* Perform */
	for (DLLNode* q = p->right;   q; q = q->right) { /* Selection Sort */
		if (absval(q->nodeBook->getAuthor().compare(s)) <
			absval(p->nodeBook->getAuthor().compare(s))) { m = q; }
	}	if (m != p) { p->swap(m); } }

	/* Return to First Node */ while (ptr->left) { ptr = ptr->left; }

}

void DLLNode::sortGenre(Genre g) {  /**/ this->sortRating();

	DLLNode* ptr = this; DLLNode* m = nullptr;
	/* Validate First Node */ while (ptr->left) { ptr = ptr->left; }

	for (DLLNode* p = ptr; p->right; p = p->right) { m = p;
		if (p->nodeBook->getGenre() == g) { continue; }		/* Perform */
	for (DLLNode* q = p->right; q; q = q->right) {	 /* Selection Sort */
		if (q->nodeBook->getGenre() == g) { m = q; break; }
	}	if (m != p) { p->swap(m); } else { break; } }

	/* Return to First Node */ while (ptr->left) { ptr = ptr->left; }

}

void DLLNode::sortLevel(Level l) {  /**/ this->sortRating();

	DLLNode* ptr = this; DLLNode* m = nullptr;
	/* Validate First Node */ while (ptr->left) { ptr = ptr->left; }

	for (DLLNode* p = ptr; p->right; p = p->right) { m = p;
		if (p->nodeBook->getLevel() == l) { continue; }		/* Perform */
	for (DLLNode* q = p->right; q; q = q->right) {	 /* Selection Sort */
		if (q->nodeBook->getLevel() == l) { m = q; break; }
	}	if (m != p) { p->swap(m); } else { break; } }

	/* Return to First Node */ while (ptr->left) { ptr = ptr->left; }

}
