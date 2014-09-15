#ifndef _VECTOREXCEPTIONS_
#define _VECTOREXCEPTIONS_
/**

  *File: vectorExceptions.h

  *Description:

   this file declares an exception class. it is derived from anException
   and when constructed, adds a header and trailer messages appropriate for
   the use of this class.

  *NOTE: since there may be more than one possible type of exception associated
         with a class, we have named the file as vectorExceptions (plural).

  *Version: 1.6 "@(#) vectorExceptions. header. ver. 1.6. Premalatha and Vidyadhar, CTFD, NAL."

  *Dependencies:


  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL

  *Date:    18 February 2000
  */

// system includes

// local includes
#include "anException.h"

// const declarations

// function prototypes

// forward declarations

// begin class declaration
class vectorException : public anException
{
   public:

   // constructors
      vectorException() {
         Header()  << "aVector: Exception raised!" << std::endl;
         Trailer() << "**************************" << std::endl;
      }

   protected:
      vectorException(const vectorException& v);
      vectorException& operator=(const vectorException& v);

   private:
};

// include any inline code here
                                //                 
                                //      \\^//      
                                //     o(!_!)o     
                                // __m__  o  __m__ 
                                //                 
#endif //_VECTOREXCEPTIONS_
