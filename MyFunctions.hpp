//	************************************************************************************
//	Program Name	| MyFunctions.hpp
//	Program Title	| Header File for Function Prototypes
//	Program Author	| Aadhil Mubarak Syed
//	************************************************************************************
//	Program Description:
//	--------------------
//	This header file contains all the function prototypes of the functions that are
//	used in the main program. The implementation can be found in MyFunctions.cpp
//	************************************************************************************

#ifndef MYFUNCTIONS_HPP_
#define MYFUNCTIONS_HPP_

#include "LinkedList.hpp"
#include "Book.hpp"
#include "HonorsProject.hpp"

//	************************************************************************************
//	Function Prototypes
//	************************************************************************************

	void 	 clearCIN		(void);
	void	 reset			(DLLNode*);
	void	 clear			(DLLNode*);

	void	 convEnum		(DLLNode*, string&, string&);
	int	 	 displayMenu	(void);
	Genre	 selectGenre    (void);
	Level	 selectLevel	(void);

	DLLNode* importData 	();
	void	 exportData		(DLLNode*);

	int	 	 displayBooks	(DLLNode*);
	void  	 displayInfo	(DLLNode*, int);

	void  	 addBookRating	(DLLNode*);
	void	 checkOutBook	(DLLNode*);
	void	 returnBook		(DLLNode*);
	void	 adminAddBooks	(DLLNode*);

#endif /* MYFUNCTIONS_HPP_ */
