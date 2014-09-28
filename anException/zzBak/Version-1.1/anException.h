#ifndef _ANEXCEPTION_
#define _ANEXCEPTION_

/**

  *File: anException.h

  *Description:

   this file declares class anException

  *Version: 1.1 "@(#) anException. header. ver. 1.1. Premalatha and Vidyadhar, CTFD, NAL."

  *Dependencies:

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL

  *Date:
  */

// system includes 
#include <iostream>
#include <string>
#include <iomanip>

// local includes
#include "plume_aStream.h"

// const declarations

// identify a compiler
#if defined(_KNOWN_COMPILER)
#  undef _KNOWN_COMPILER
#endif

#if defined(_MSC_VER)
#  define _KNOWN_COMPILER
#endif

#if defined(__GNUC__)
#  define _KNOWN_COMPILER
#endif

#if defined(__sgi)
#  define _KNOWN_COMPILER
#endif

// forward declarations
class anException;
namespace plume
{
   void Throw(const char* c_string);
   void Throw(anException e);
}

// function prototypes

// begin class declaration
class anException
{
   friend std::ostream& operator<<(std::ostream& os, anException& except);

   public:

   // constructors
      anException(); // default
      anException(const anException& except);
      anException(const char* message);

   // destructor
      virtual ~anException();

   // string and basic data type insertion operators
      anException& operator<<(bool b);
      anException& operator<<(char c);
      anException& operator<<(const char* str);
      anException& operator<<(const std::string& string);   // useful

      anException& operator<<(short int si);
      anException& operator<<(int i);
      anException& operator<<(long int li);

      anException& operator<<(unsigned short int usi);
      anException& operator<<(unsigned int ui);
      anException& operator<<(unsigned long int uli);
      anException& operator<<(float f);
      anException& operator<<(double d);
      anException& operator<<(long double ld);

   // need sometimes to explicitly terminate the message string
      inline anException& End();

   // insertion of manipulators

   // for sgi compiler
#if defined(__sgi) && !defined(__GNUC__)
      anException& operator<<( std::basic_ostream<wchar_t, std::char_traits<wchar_t> >& (*ptr_manipulator) (std::basic_ostream<wchar_t, std::char_traits<wchar_t> >& ));
      anException& operator<<(std::basic_ios<wchar_t, std::char_traits<wchar_t> >& (*ptr_manipulator)(std::basic_ios<wchar_t, std::char_traits<wchar_t> >&));
      anException& operator<<(std::ios_base& (*ptr_manipulator)(std::ios_base&));
#endif

      // for gnu compiler ver < 3.0
#if defined(__GNUC__) && (__GNUC__ < 3)
      anException& operator<<(std::ostream& (*ptr_manipulator)(std::ostream&));
#endif

      // for Gnuc ver >=3.0
#if defined(__GNUC__) && (__GNUC__ >= 3)
      anException& operator<<(std::basic_ostream<char>& (*ptr_manipulator)(std::basic_ostream<char>&));
      anException& operator<<(std::basic_ios<char>& (*ptr_manipulator)(std::basic_ios<char>&));
      anException& operator<<(std::ios_base& (*ptr_manipulator)(std::ios_base&));
#endif

      // for microsoft vc++ compilers
#if defined(_MSC_VER)
      anException& operator<<(std::basic_ostream<char>& (*ptr_manipulator)(std::basic_ostream<char>&));
      anException& operator<<(std::basic_ios<char>& (*ptr_manipulator)(std::basic_ios<char>&));
      anException& operator<<(std::ios_base& (*ptr_manipulator)(std::ios_base&));
#endif

      // some other compiler (make it same as vc++ compiler)
#if !defined(_KNOWN_COMPILER)
      anException& operator<<(std::basic_ostream<char>& (*ptr_manipulator)(std::basic_ostream<char>&));
      anException& operator<<(std::basic_ios<char>& (*ptr_manipulator)(std::basic_ios<char>&));
      anException& operator<<(std::ios_base& (*ptr_manipulator)(std::ios_base&));
#endif

#if 0
#if defined(__GNUC__) && (__GNUC__ < 3)
      anException& operator<<(std::ostream& (*ptr_manipulator)(std::ostream&));
#else
      anException& operator<<(std::basic_ostream<char>& (*ptr_manipulator)(std::basic_ostream<char>&));
      anException& operator<<(std::basic_ios<char>& (*ptr_manipulator)(std::basic_ios<char>&));
      anException& operator<<(std::ios_base& (*ptr_manipulator)(std::ios_base&));
#endif
#endif

   // provide a means to insert into header and trailer messages
      plume::aStream& Header();
      plume::aStream& Trailer();
      void SetLeaderString(char* l_string = " ** ") {
         pv_leader_string = l_string;
      }

   protected:
   // provide some access to writing to underlying string via a derived class
      virtual void Print(std::ostream& os);
      void PrintMultilineString(std::ostream& os, std::string s);

   // two stream objects which help insert messages into these
      plume::aStream pv_start_message;
      plume::aStream pv_end_message;

   // the string containing the message
      plume::aStream pv_message;

   // assignment operator (disabled)
      anException& operator=(const anException& except);
   private:
      std::string pv_leader_string;
};

// include any inline code here

inline anException& anException::End()
{
   pv_message.EndString();
   return *this;
}

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

#if defined(_KNOWN_COMPILER)
#  undef _KNOWN_COMPILER
#endif


#endif //_ANEXCEPTION_
