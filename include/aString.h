#ifndef _ASTRING_
#define _ASTRING_

/** 

  *File: aString.h
   
  *Description:
   this defines a string class which is useful in many string
   handling (which is otherwise cumbersome since one almost always
   forgets to initialize a string, or passes a string by value to
   a calling function and so on).
   
   the code below is developed from discussion given in Chapter 6
   of book by Stanley B. Lippman entitled C++ Primer.
   
   the string class makes use of operator overloading to provide
   such functionality as equating two strings (which results in making
   a copy of the string), checking for equality	of two strings, fetching
   characters in the string by index, scanning the string using an iterator
   and so on.
   
   the string class declares a special constructor of type X(const X&)
   which is invoked whenever memberwise initialization is needed. this
   is essential for the string class because it holds a data member which
   is of pointer type (the char* str member). without this, an equality
   operator would simply copy the address of the str member and not make
   a clone of the same (which would result in serious program error)
   specific attention is drawn to the reference on C++ Primer, page 249.
  
  *Version: 1.3

  *Dependencies:
   bool

  *Throws: aStringIndexOutOfBoundsException

  *Notes:
   
   version 1.1 used the non boolean return for conditional tests.
   the current version makes use of the boolean data type

  *References: 1. Stanley B. Lippman, 2. James O.Coplien

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD Division, NAL (in DLR)
  *Date:    Jan 19, 1998, Aug 12, 1998
  */


// system includes
#include <iostream>

// local includes
#if defined(_MSC_VER) && (_MSC_VER < 1100)
#  include "aBoolean.h"
#endif

#include "aStringIndexOutOfBoundsException.h"

//#include <debug.h>

class aString
{
   public:

   // constructors
      aString();                 // default constructor. string is null
      aString(const char* p_str);// constructs with this string 
                                 // (computes length too)
      aString(int   len);        // allocates this much space. string is null
                                 // this can be used as a buffer string
      aString(const aString& s); // the special constructor
  
   // assignment operators (copy operators)
      aString& operator=(const aString& s);  // assignment X& X::operator=(const X&)
      aString& operator=(const char* s);     // assigns a char array
    
      
   // destructors
      ~aString();

   // accessor methods
      int   GetLength() const;                  // returns the string length
      const char* GetStringAsConstCharArray() const; // returns string as char*
      char* GetStringAsCharArray();

      const char* GetCString() const;

      void  SetString(const char* p_str); // sets the string contents
                                          // (and recomputes the length)
   
 
   // provide a conversion operators
      operator const char*() const;          // aString to char*
      operator const std::string() const;    // aString to string
      
   // operators to check for equality and 
   // inequality of strings
      bool operator==(const aString& s) const; // string equals string
      bool operator==(const char* s)    const; // string equals char*
      bool operator!=(const aString& s) const; // same for inequality
      bool operator!=(const char* s)    const; // 
  
   // iterators and indexing operators
      char& operator[](int elem);      // index operator (useful)
      char  operator()();              // an iterator (also useful)
  

   // string concatenation operators 
   // the combinations include:
   // string + string      
   // string + char*
   // char*  + string (nonmember function)

      aString operator+(const aString& s2);
      aString operator+(const char* s2);   
      friend aString operator+(const char* s1, const aString& s2);

   // extraction and insertion for strings
      friend std::istream& operator>>(std::istream& is, aString& s);

   protected:

   private:
   // private methods here (helper member functions)
      void CheckBounds(int elem) const;   // checks index boundary

   private:
      int   pv_index;   // stores the current index (used by iterator)
      int   pv_length;  // stores the length of the string
      char* pv_str;     // stores the string (character array, C-string)
};

#endif // _ASTRING_

