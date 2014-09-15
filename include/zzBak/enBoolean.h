#ifndef _ENBOOLEAN_
#define _ENBOOLEAN_

/**
  *File: enBoolean.h

  *Description:
   this is a boolean data type. it declares an enumerated
   type and introduces the names FALSE and TRUE. the values
   TRUE and FALSE are determined by self consistent checks
   so that TRUE really will yield TRUE if the quantities equal.


  *Note: the values `true' and `false' are tagged as keywords
         for future use (when compiled using the MSDV). so
         also, the word `bool'. that is, the future c++ will
         support bool data type with values false and true.
         it is, therefore, not a good idea to use these in this
         program.

  *Version: 1.3

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL (in DLR)
  *Date:    18 Feb. 1998, 17 Jul. 1998
  */

// system includes

// application include
// #include <debug.h>

// #defines

// consts

/* declare an enumerated type and generate false and
   true values using the machine implementation for
   equality or inequality
 */
#if 0
enum enBool 
{
   FALSE = (0 == 1),    // must be false
   TRUE  = (1 == 1)     // must be true
};
#endif

#endif // _ENBOOLEAN_

