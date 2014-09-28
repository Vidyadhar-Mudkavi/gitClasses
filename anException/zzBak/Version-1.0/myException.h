#ifndef _MYEXCEPTION_
#define _MYEXCEPTION_
/**

  *File: myException.h

  *Description:

   this file declares class myException

  *Version: 1.0

  *Dependencies:

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL

  *Date:    February 18, 2000
  */

// system includes
//#include <iostream>
//#include <string>
//#include <iomanip>

// local includes
#include "anException.h"

// const declarations

// namespace

// forward declarations

// function prototypes

// begin class declaration

class myException : public anException
{
   public:
      myException() : pv_i(10) { Prepend(); };  // note Prepend
      myException(const myException& myen) : pv_i(myen.pv_i) {}
      ~myException() { /* empty */ }


   // these two function help us add a string before and after the user
   // insertions. prepend is done automatically. but append should be done
   // manually.
      void Prepend() {
         start_message << "Exception raised!" << "\n";
//         (*this) << "Exception raised!" << "\n";
      }

      void Append() {
         end_message << "Exception message returned" << std::endl;
//         (*this) << "Exception message returned" << std::endl;
      }

   protected:
      myException& operator=(const myException& mye); // no assignment

   private:
      int pv_i;
};



// include any inline code here

/**
   declare any typedef statements here
     ex: typedef aVortex areVortices;
   so that we can declare
     areVortices v1, v2, v3;
  */
                              //                 
                              //      \\^//      
                              //     o(!_!)o     
                              // __m__  o  __m__ 
                              //                 

#endif //_MYEXCEPTION_
