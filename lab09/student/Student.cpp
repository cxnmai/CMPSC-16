#include "Student.h"
#include <sstream> // for ostringstream

Student::Student(int p, 
		      string lName, 
		      string fName) {
	perm = p;
	firstAndMiddleNames = fName;
	lastName = lName;
}

// THE NEXT 4 MEMBER FUNCTIONS NEED TO BE DEFINED BY THE STUDENT
//      AND ARE, IN THE MEANTIME, DEFINED AS STUBS:
int Student::getPerm() {
    // pre condition - student with perm initialized
    // post condition - returns perm as int
    return perm;
}

string Student::getLastName() {
    // pre condition - student with last name initialized
    // post condition - returns last name as string
    return lastName;
}

string Student::getFirstAndMiddleNames() { 
    // pre condition - student with first and middle names initialized 
    // post condition - returns as string
    return firstAndMiddleNames;
}

string Student::getFullName() { 
    // pre condition - student with first, middle, and last names initialized
    // post condition - returns full name as combined string
    return firstAndMiddleNames + " " + lastName;
}

// THIS MEMBER FUNCTION IS DEFINED FOR YOU ALREADY:
// DO NOT CHANGE IT
string Student::toString()  { 
  // e.g. [12345,Smith,Malory Logan]
  ostringstream oss;
  
  oss << "[" 
      << getPerm() << ","
      << getLastName() << ","
      << getFirstAndMiddleNames() << "]";
  return oss.str();
} 

