//	************************************************************************************
//	Program Name	| Book.cpp
//	Program Title	| Source File for Book Class
//	Program Author	| Aadhil Mubarak Syed
//	************************************************************************************
//	Program Description:
//	--------------------
//	This source file contains the implementation for all of the method prototypes which
//	were declared in Book.hpp
//	************************************************************************************

#include "Book.hpp"

Book::Book() :
	title		 ("N/A"),
	genre		 (FICTION),
	level		 (TODDLER),
	author		 ("N/A"),
	availability (true),
	rating		 (0.f)
{}

Book::Book(string t, string a, Genre g, Level l, bool b) :
	title		 (t),
	genre		 (g),
	level		 (l),
	author		 (a),
	availability (b),
	rating		 (0.f)
{}

Book::Book(const Book &copy) :
	title		 (copy.title),
	genre		 (copy.genre),
	level		 (copy.level),
	author		 (copy.author),
	availability (copy.availability),
	rating		 (copy.rating)
{
	if (copy.reviews.size()) {
	for (int i = 0; i < copy.reviews.size(); i++) {
		this->reviews.push_back(copy.reviews[i]);
	}}
}

string	Book::getTitle	 	(void) const 	{ return title; 		 }
Genre  	Book::getGenre	 	(void) const	{ return genre; 		 }
Level  	Book::getLevel	 	(void) const	{ return level; 		 }
string 	Book::getAuthor	 	(void) const	{ return author;		 }
bool	Book::isAvailable	(void) const	{ return availability; 	 }
float	Book::getRating	 	(void) const	{ return rating;		 }
int		Book::reviewsize	(void) const	{ return reviews.size(); }

void 	Book::setTitle(string s)		{ title 	   = s; 						 }
void	Book::setGenre(Genre g)			{ genre  	   = g; 						 }
void	Book::setLevel(Level l)			{ level	 	   = l; 						 }
void	Book::setAuthor(string s)		{ author 	   = s; 						 }
void	Book::toggleAvailable(void)		{ availability = !availability; 			 }
void	Book::setAvailable(bool b)		{ availability = b; 						 }
void	Book::addReview(userReview r)  	{ reviews.push_back(r); calcRating(reviews); }

void	Book::calcRating(vector<userReview> r) {
	float rsum = 0.0f; for (int i = 0; i < r.size(); i++) { rsum += r[i].rating; }
	rating = (rsum / r.size());
}

Book& 	Book::operator= (const Book& copy) {
	this->title = copy.title;
	this->genre = copy.genre;
	this->level = copy.level;
	this->author = copy.author;
	this->availability = copy.availability;

	for (int i = 0; i < copy.reviews.size(); i++) {
		this->addReview(copy.reviews[i]);
	}
	return *this;
}

bool Book::operator <  (const Book& copy) { return (this->rating <	copy.rating); }
bool Book::operator <= (const Book& copy) { return (this->rating <= copy.rating); }
bool Book::operator >  (const Book& copy) { return (this->rating >	copy.rating); }
bool Book::operator >= (const Book& copy) { return (this->rating >= copy.rating); }
bool Book::operator == (const Book& copy) { return (this->rating == copy.rating); }
bool Book::operator != (const Book& copy) { return (this->rating != copy.rating); }
userReview Book::operator [] (int i) const { return reviews[i]; }
