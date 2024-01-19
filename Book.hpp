//	************************************************************************************
//	Program Name	| Book.hpp
//	Program Title	| Header File for Book Class
//	Program Author	| Aadhil Mubarak Syed
//	************************************************************************************
//	Program Description:
//	--------------------
//	This header file contains all the private/public attributes & method prototypes for
// 	the Book class which will be implemented in Book.cpp
//	************************************************************************************

#ifndef BOOK_HPP_
#define BOOK_HPP_

#include "HonorsProject.hpp"

class Book {

	private:

		string 				title;					// attribute
		Genre  				genre;					// attribute
		Level				level;					// attribute
		string				author;					// attribute
		bool				availability;			// attribute
		float				rating;					// attribute
		vector<userReview>	reviews;				// attribute

		void	calcRating(vector<userReview>);		// method

	public:

		Book();										// default constructor
		Book(string, string, Genre, Level, bool); 	// overload constructor
		Book(const Book&);							// copy constructor

		friend void displayInfo (DLLNode*, int);	// friend function

		string	getTitle	 (void) const;			// method - getter
		Genre  	getGenre	 (void) const;			// method - getter
		Level  	getLevel	 (void) const;			// method - getter
		string 	getAuthor	 (void) const;			// method - getter
		bool	isAvailable  (void) const;			// method - getter
		float	getRating	 (void) const;			// method - getter
		int		reviewsize	 (void) const;			// method - getter

		void 	setTitle(string);					// method - setter
		void	setGenre(Genre);					// method - setter
		void	setLevel(Level);					// method - setter
		void	setAuthor(string);					// method - setter
		void	toggleAvailable(void);				// method - setter
		void 	setAvailable(bool);					// method - setter
		void	addReview(userReview);				// method - setter

		Book& 	operator =  (const Book&);			// operator overload
		bool	operator <  (const Book&);			// operator overload
		bool	operator <= (const Book&);			// operator overload
		bool	operator >  (const Book&);			// operator overload
		bool	operator >= (const Book&);			// operator overload
		bool	operator == (const Book&);			// operator overload
		bool	operator != (const Book&);			// operator overload
		userReview operator [] (int) const;		// operator overload

};

#endif /* BOOK_HPP_ */
