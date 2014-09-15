#ifndef _ASINDEXOUTOFBOUNDSEXCEPTION_
#define _ASINDEXOUTOFBOUNDSEXCEPTION_
/**

  *File: aSIndexOutOfBoundsException.h

  *Description:

   this file declares class aSIndexOutOfBoundsException

  *Version: 1.0

  *Dependencies:

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL

  *Date:
  */

// system includes

// local includes

// const declarations

// function prototypes

// forward declarations

// begin class declaration
class aSIndexOutOfBoundsException
{
   public:
	void SetCurrentIndex(int current_index);
	void SetRange(int lower, int upper);
	void SetMessage(char* m);

   // constructors
      aSIndexOutOfBoundsException(); // default

   // destructor
      ~aSIndexOutOfBoundsException();

   protected:
   // special constructor not needed
      aSIndexOutOfBoundsException(const aSIndexOutOfBoundsException& class_var);

   // assignment operator not needed
      aSIndexOutOfBoundsException& operator=(const aSIndexOutOfBoundsException& class_var);

   private:
      char* pv_message;
      int   pv_lower_index;
      int   pv_upper_index;
      int   pv_current_index;

};

// include any inline code here

#endif //_ASINDEXOUTOFBOUNDSEXCEPTION_
