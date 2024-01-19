//	************************************************************************************
//	Program Name	| HonorsProject.hpp
//	Program Title	| Header File for 'HonorsProject.cpp'
//	Program Author	| Aadhil Mubarak Syed
//	************************************************************************************
//	Program Description:
//	--------------------
//	This hpp file contains all the program includes and abstract data types (ADTS)
//	that are used in HonorsProject.cpp
//	************************************************************************************

#ifndef HONORSPROJECT_HPP_
#define HONORSPROJECT_HPP_

//	************************************************************************************
//	Program Includes (Pre-Processor Directives)
//	************************************************************************************

	#include <iostream>
	using namespace std;

	#include <cstring>
	#include <climits>
	#include <fstream>
	#include <iomanip>
	#include <vector>
	#include <string>

//	************************************************************************************
//	Abstract Data Types
//	************************************************************************************

	enum 	Genre { FICTION, NONFICTION, POETRY, DRAMA, FABLE, MYSTERY, MYTHOLOGY };
	enum 	Level { TODDLER, CHILDRENS, PRE_TEENS, YOUNG_ADULTS, ADULTS };
	struct	userReview { float rating; string comment; };	struct DLLNode;

#endif /* HONORSPROJECT_HPP_ */
