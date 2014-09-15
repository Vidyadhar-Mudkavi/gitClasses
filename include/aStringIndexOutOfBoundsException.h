#ifndef _ASTRINGINDEXOUTOFBOUNDSEXCEPTION_
#define _ASTRINGINDEXOUTOFBOUNDSEXCEPTION_
/**

  *File: aStringIndexOutOfBoundsException.h

  *Description:

   this file declares class aStringIndexOutOfBoundsException

   this is an exception object which is thrown whenever a request
   for accessing a character out of the array boundaries.
   the object holds a message (character string), lower and upper
   indices and current index for which the fetch request is placed.

  *Version: 1.0

  *Dependencies:
   none

  *Note:

   when the object is thrown, the copy constructor is invoked. if
   this constructor is made private/protected, then the exception
   cannot be thrown.

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL

  *Date:    31 March 1999
  */

// system includes

// local includes

// const declarations

// function prototypes

// forward declarations

// begin class declaration

/**
   a simple structure to hold the range information
  */
struct theIndexRange
{
   int lower;
   int upper;
};

class aStringIndexOutOfBoundsException
{
   public:
   // constructors
      aStringIndexOutOfBoundsException(); // default
      aStringIndexOutOfBoundsException(const aStringIndexOutOfBoundsException& class_var);

   // destructor
      ~aStringIndexOutOfBoundsException();

   // accessor methods
	   void SetCurrentIndex(int ci);
	   void SetRange(int lower, int upper);
	   void SetMessage(char* m);

      theIndexRange GetRange();
	   int GetCurrentIndex();
	   char* GetMessage();

   protected:

   // assignment operator not required
      aStringIndexOutOfBoundsException& operator=(const aStringIndexOutOfBoundsException& class_var);

   
   protected:

   private:
   // indices
      int pv_lower_index;
      int pv_upper_index;
      int pv_current_index;

      char* pv_message;
};

// include any inline code here

#endif //_ASTRINGINDEXOUTOFBOUNDSEXCEPTION_
