#ifndef _PLUME_ITOA_
#define _PLUME_ITOA_
/**

  *File: plume_itoa.h

  *Description:
   this file defines function to convert integer to string
   uses the new c++ implementation.
   has both char* style and std::string style.

   the function itoa in stdlib.h is non-standard! it is not supported by
   ANSI-C.

   the implementations given here are taken from the following:

   http://www.jb.man.ac.uk/~slowe/cpp/itoa.html

   a copy of this page is in the directory: D:\User\Prema\Langs\Cpp\Classes\Sinppets
   
  *Version: 1.0 "@(#) itoa. header. ver. 1.0. Premalatha and Vidyadhar, CTFD, NAL."

  *Dependencies:

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL.
  *Date:    2005-09-12
  */

// system includes
// standard template
#include <algorithm>

// local includes
#include "plume_Abs.h"

// const declarations
// function prototypes
// forward declarations

// begin class declaration
namespace plume
{
//////////////////////////////////////////////////////////
//
// char* version
//
   char* itoa(int value, char* result, int base)
   {
   // check that the base if valid
      if (base < 2 || base > 16) 
      { 
         *result = 0; return result; 
      }
   
      char* out = result;
      int quotient = value;
   
      do 
      {
#if 0 // replacing std::abs with plume::Abs template
         *out = "0123456789abcdef"[ std::abs( quotient % base ) ];
#endif
         *out = "0123456789abcdef"[ plume::Abs( quotient % base ) ];

         ++out;
         quotient /= base;
      }
      while ( quotient );
   
   // Only apply negative sign for base 10
      if ( value < 0 && base == 10) 
      {
         *out++ = '-';
      }
   
      std::reverse( result, out );
      *out = 0;
      return result;
   }

//////////////////////////////////////////////////////////
//
// std::string version
//
   std::string itoa(int value, std::string& result, int base)
   {
      enum { kMaxDigits = 35 };
      std::string buf;
      buf.reserve( kMaxDigits ); // Pre-allocate enough space.
   
   // check that the base if valid
      if (base < 2 || base > 16) 
      {
         return buf;
      }
   
      int quotient = value;
   
   // Translating number to string with base:
      do 
      {
#if 0 // replacing std::abs with plume::Abs template
         buf += "0123456789abcdef"[ std::abs( quotient % base ) ];
#endif
         buf += "0123456789abcdef"[ plume::Abs( quotient % base ) ];

         quotient /= base;
      } 
      while ( quotient );
   
   // Append the negative sign for base 10
      if ( value < 0 && base == 10)
      {
         buf += '-';
      }
   
      std::reverse( buf.begin(), buf.end() );

      result = buf;
      return result;
   }
}


// include any inline code here
                              //                 
                              //      \\^//      
                              //     o(!_!)o     
                              // --m--  o  --m-- 
                              //                 

#endif   // _PLUME_ITOA_
