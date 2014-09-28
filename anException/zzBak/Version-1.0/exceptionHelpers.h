#ifndef _EXCEPTIONHELPERS_
#define _EXCEPTIONHELPERS_
/**

  *File: exceptionHelpers.h

  *Description:

   this file declares a bunch of (?) helper classes associated with anException.
   the classes are presented in exceptionHelper namespace.

   aStream is a class which can be used to insert objects of built-in types.
   it holds the inserted values as a character sequence in a string.

  *Version: 1.0

  *Dependencies:

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL

  *Date:    February 16, 2000
  */

// system includes
#include <string>
#include <strstream>

// local includes

// const declarations

// namespace

// forward declarations

// function prototypes
// begin class declaration

namespace exceptionHelper
{
   class aStream
   {
      public:
      // constructors

         std::string operator()() const {
            return pv_message;
         }

         std::string String() const {
            return pv_message;
         }

      // string and basic data type insertion operators
         inline aStream& operator<<(bool b);
         inline aStream& operator<<(char c);
         inline aStream& operator<<(const char* str);

         inline aStream& operator<<(short int si);
         inline aStream& operator<<(int i);
         inline aStream& operator<<(long int li);
 
         inline aStream& operator<<(unsigned short int usi);
         inline aStream& operator<<(unsigned int ui);
         inline aStream& operator<<(unsigned long int uli);
         inline aStream& operator<<(float f);
         inline aStream& operator<<(double d);
         inline aStream& operator<<(long double ld);

      // insertion of manipulators
         inline aStream& operator<<(std::basic_ostream<char>& (*manipulator)(std::basic_ostream<char>&));
         inline aStream& operator<<(std::basic_ios<char>& (*manipulator)(std::basic_ios<char>&));
         inline aStream& operator<<(std::ios_base& (*manipulator)(std::ios_base&));

      protected:

      private:
         std::string    pv_message; // the insertion string
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

// all the functions are inlined here
   aStream& aStream::operator<<(bool b)
   {
      std::ostrstream buff;
      buff << b << std::ends;
      pv_message += buff.str();

      return *this;
   }

   aStream& aStream::operator<<(char c)
   {
      std::ostrstream buff;
      buff << c << std::ends;
      pv_message += buff.str();

      return *this;
   }

   aStream& aStream::operator<<(const char* str)
   {
      std::ostrstream buff;
      buff << str << std::ends;
      pv_message += buff.str();

      return *this;
   }

   aStream& aStream::operator<<(short int si)
   {
      std::ostrstream buff;
      buff << si << std::ends;
      pv_message += buff.str();

      return *this;
   }

   aStream& aStream::operator<<(int i)
   {
      std::ostrstream buff;
      buff << i << std::ends;
      pv_message += buff.str();

      return *this;
   }
   
   aStream& aStream::operator<<(long int li)
   {
      std::ostrstream buff;
      buff << li << std::ends;
      pv_message += buff.str();

      return *this;
   }
   
   aStream& aStream::operator<<(unsigned short int usi)
   {
      std::ostrstream buff;
      buff << usi << std::ends;
      pv_message += buff.str();
      return *this;
   }
   
   aStream& aStream::operator<<(unsigned int ui)
   {
      std::ostrstream buff;
      buff << ui << std::ends;
      pv_message += buff.str();

      return *this;
   }

   aStream& aStream::operator<<(unsigned long int uli)
   {
      std::ostrstream buff;
      buff << uli << std::ends;
      pv_message += buff.str();

      return *this;
   }
   
   aStream& aStream::operator<<(float f)
   {
      std::ostrstream buff;
      buff << f << std::ends;
      pv_message += buff.str();

      return *this;
   }
   
   aStream& aStream::operator<<(double d)
   {
      std::ostrstream buff;
      buff << d << std::ends;
      pv_message += buff.str();

      return *this;
   }
   
   aStream& aStream::operator<<(long double ld)
   {
      std::ostrstream buff;
      buff << ld << std::ends;
      pv_message += buff.str();

      return *this;
   }

// insertion of manipulators
   aStream& aStream::operator<<(std::basic_ostream<char>& (*manipulator)(std::basic_ostream<char>&))
   {
      std::ostrstream buff;
      buff << manipulator << std::ends;
      pv_message += buff.str();

      return *this;
   }
   
   aStream& aStream::operator<<(std::basic_ios<char>& (*manipulator)(std::basic_ios<char>&))
   {
      std::ostrstream buff;
      buff << manipulator << std::ends;
      pv_message += buff.str();

      return *this;
   }
   
   aStream& aStream::operator<<(std::ios_base& (*manipulator)(std::ios_base&))
   {
      std::ostrstream buff;
      buff << manipulator << std::ends;
      pv_message += buff.str();

      return *this;
   }
}

#endif //_EXCEPTIONHELPERS_
