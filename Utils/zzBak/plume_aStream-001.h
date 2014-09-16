#ifndef _PLUME_ASTREAM_
#define _PLUME_ASTREAM_

/**

  *File: plume_aStream.h

  *Description:

   this file declares a bunch of (?) helper classes associated with anException.
   the classes are presented in exceptionHelper namespace.

   aStream is a class which can be used to insert objects of built-in types.
   it holds the inserted values as a character sequence in a string.

   checking if an std::ends is inserted (via a pointer to manipulator) seems
   to work differently for GNUC (version < 3.0), and VC++ (6.0), 
   Irix C++ (7.2) and Irix C++ (7.3.1.2m) 

  *Version: 1.1

  *Dependencies:

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL

  *Date:    February 16, 2000
            July     23, 2003
  */

// system includes
#include <string>
#include <iostream>

// <strstream> is deprecated (except for Gnuc ver < 3)
#if defined(__GNUC__) && (__GNUC__ < 3)
#  include <strstream>
   typedef std::ostrstream    OSTRINGSTREAM;
#else
#include <sstream>
   typedef std::ostringstream OSTRINGSTREAM;
#endif

// local includes
// const declarations
// namespace
// forward declarations
// function prototypes

// begin class declaration

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

namespace plume
{
   class aStream
   {
      inline friend std::ostream& operator<<(std::ostream& os, const aStream& s);

      public:
      // constructors

         aStream() : pv_ptr_oss( new OSTRINGSTREAM ), 
                     pv_string_terminated( false ),
                     pv_ptr_ends( std::ends ) {};

         aStream(const char* str) : pv_ptr_oss( new OSTRINGSTREAM ), 
                                    pv_string_terminated( false ),
                                    pv_ptr_ends( std::ends ) {
            *pv_ptr_oss << str;
         }


      // accessor
         inline std::string operator()() const;

      // function to clear the string
         inline void Clear();

      // insertion of manipulators
      
      // for sgi compiler
#if defined(__sgi) && !defined(__GNUC__)
         inline aStream& operator<<( std::basic_ostream<wchar_t, std::char_traits<wchar_t> >& (*ptr_manipulator) (std::basic_ostream<wchar_t, std::char_traits<wchar_t> >& ));
         inline aStream& operator<<(std::basic_ios<wchar_t, std::char_traits<wchar_t> >& (*ptr_manipulator)(std::basic_ios<wchar_t, std::char_traits<wchar_t> >&));
         inline aStream& operator<<(std::ios_base& (*ptr_manipulator)(std::ios_base&));
#endif

      // for gnu compiler ver < 3.0
#if defined(__GNUC__) && (__GNUC__ < 3)
         inline aStream& operator<<(std::ostream& (*ptr_manipulator)(std::ostream&));
#endif

      // for Gnuc ver >=3.0
#if defined(__GNUC__) && (__GNUC__ >= 3)
         inline aStream& operator<<(std::basic_ostream<char>& (*ptr_manipulator)(std::basic_ostream<char>&));
         inline aStream& operator<<(std::basic_ios<char>& (*ptr_manipulator)(std::basic_ios<char>&));
         inline aStream& operator<<(std::ios_base& (*ptr_manipulator)(std::ios_base&));
#endif

      // for microsoft vc++ compilers
#if defined(_MSC_VER)
         inline aStream& operator<<(std::basic_ostream<char>& (*ptr_manipulator)(std::basic_ostream<char>&));
         inline aStream& operator<<(std::basic_ios<char>& (*ptr_manipulator)(std::basic_ios<char>&));
         inline aStream& operator<<(std::ios_base& (*ptr_manipulator)(std::ios_base&));
#endif

      // some other compiler (make it same as vc++ compiler)
#if !defined(_KNOWN_COMPILER)
         inline aStream& operator<<(std::basic_ostream<char>& (*ptr_manipulator)(std::basic_ostream<char>&));
         inline aStream& operator<<(std::basic_ios<char>& (*ptr_manipulator)(std::basic_ios<char>&));
         inline aStream& operator<<(std::ios_base& (*ptr_manipulator)(std::ios_base&));
#endif

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

      protected:

      private:

      // std::ostrstream* pv_ptr_oss;  // deprecated
         OSTRINGSTREAM*   pv_ptr_oss;  // buffer to store insertions
         std::string      pv_value;    // the insertion string
         bool             pv_string_terminated;

      // need to explicitly instantiate the template std::ends
      // this turned out to be a necessity while compiling on Irix 6.5
#if defined(_MSC_VER)
         std::basic_ostream<char>& (*pv_ptr_ends) (std::basic_ostream<char>&);
#endif

#if defined(__sgi) && !defined(__GNUC__)
         std::basic_ostream<wchar_t, std::char_traits<wchar_t> >& (*pv_ptr_ends) (std::basic_ostream<wchar_t, std::char_traits<wchar_t> >&);
#endif

#if defined(__GNUC__) && (__GNUC__ < 3)
         std::ostream& (*pv_ptr_ends) (std::ostream&);
#endif

#if defined(__GNUC__) && (__GNUC__ >= 3)
         std::ostream& (*pv_ptr_ends) (std::ostream&);
#endif

#if !defined(_KNOWN_COMPILER)
         std::basic_ostream<char>& (*pv_ptr_ends) (std::basic_ostream<char>&);
#endif
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

// the basic accessor
   std::string aStream::operator ()() const
   {
      if ( pv_string_terminated )
      {
         return pv_value;
      }

      return std::string();
   }

// function to clear the contents
   void aStream::Clear()
   {
      pv_value = std::string();
   }

   std::ostream& operator<<(std::ostream& os, const aStream& s) {
      if ( s.pv_string_terminated )
      {
         os << s.pv_value.c_str();
      }
      os << std::string(); 
      return os;
   }

// insertion of manipulators

// Gnuc compiler ver < 3.0
#if defined(__GNUC__) && (__GNUC__ < 3)
   aStream& aStream::operator<<(std::ostream& (*ptr_manipulator)(std::ostream&))
   {
      if ( ptr_manipulator == std::ends )
      {
         *pv_ptr_oss << std::ends;
         pv_value = pv_ptr_oss->str();
         delete pv_ptr_oss;
         pv_ptr_oss = new OSTRINGSTREAM;
         pv_string_terminated = true;
         return *this;
      }
      pv_string_terminated = false;
      *pv_ptr_oss << ptr_manipulator;  return *this;
   }
#endif

// SGI using C++ 7.3 on Irix >=6.5
#if defined(__sgi) && !defined(__GNUC__)
   aStream& aStream::operator<<(std::basic_ostream<wchar_t, std::char_traits<wchar_t> >& (*ptr_manipulator)(std::basic_ostream<wchar_t, std::char_traits<wchar_t> >&))
   {
      if ( ptr_manipulator == pv_ptr_ends )
      {
         *pv_ptr_oss << std::ends;
         pv_value = pv_ptr_oss->str();
         delete pv_ptr_oss;
         pv_ptr_oss = new OSTRINGSTREAM;
         pv_string_terminated = true;
         return *this;
      }
      pv_string_terminated = false;
      *pv_ptr_oss << ptr_manipulator;  return *this;
   }
   
   aStream& aStream::operator<<(std::basic_ios<wchar_t, std::char_traits<wchar_t> >& (*ptr_manipulator)(std::basic_ios<wchar_t, std::char_traits<wchar_t> >&))
   {
      pv_string_terminated = false;
      *pv_ptr_oss << ptr_manipulator;  return *this;
   }

   aStream& aStream::operator<<(std::ios_base& (*ptr_manipulator)(std::ios_base&))
   {
      pv_string_terminated = false;
      *pv_ptr_oss << ptr_manipulator;  return *this;
   }
#endif


// Microsoft VC++
#if defined(_MSC_VER)
   aStream& aStream::operator<<(std::basic_ostream<char>& (*ptr_manipulator)(std::basic_ostream<char>&))
   {
      if ( ptr_manipulator == pv_ptr_ends )
      {
         *pv_ptr_oss << std::ends;
         pv_value = pv_ptr_oss->str();
         delete pv_ptr_oss;
         pv_ptr_oss = new OSTRINGSTREAM;
         pv_string_terminated = true;
         return *this;
      }
      pv_string_terminated = false;
      *pv_ptr_oss << ptr_manipulator;  return *this;
   }
   
   aStream& aStream::operator<<(std::basic_ios<char>& (*ptr_manipulator)(std::basic_ios<char>&))
   {
      pv_string_terminated = false;
      *pv_ptr_oss << ptr_manipulator;  return *this;
   }

   aStream& aStream::operator<<(std::ios_base& (*ptr_manipulator)(std::ios_base&))
   {
      pv_string_terminated = false;
      *pv_ptr_oss << ptr_manipulator;  return *this;
   }
#endif


// Gnuc compiler ver >= 3.0 (same as vc++)
#if defined(__GNUC__) && (__GNUC__ >= 3)
   aStream& aStream::operator<<(std::basic_ostream<char>& (*ptr_manipulator)(std::basic_ostream<char>&))
   {
      if ( ptr_manipulator == pv_ptr_ends )
      {
         *pv_ptr_oss << std::ends;
         pv_value = pv_ptr_oss->str();
         delete pv_ptr_oss;
         pv_ptr_oss = new OSTRINGSTREAM;
         pv_string_terminated = true;
         return *this;
      }
      pv_string_terminated = false;
      *pv_ptr_oss << ptr_manipulator;  return *this;
   }
   
   aStream& aStream::operator<<(std::basic_ios<char>& (*ptr_manipulator)(std::basic_ios<char>&))
   {
      pv_string_terminated = false;
      *pv_ptr_oss << ptr_manipulator;  return *this;
   }

   aStream& aStream::operator<<(std::ios_base& (*ptr_manipulator)(std::ios_base&))
   {
      pv_string_terminated = false;
      *pv_ptr_oss << ptr_manipulator;  return *this;
   }
#endif

// some other compiler that we dont know yet (use same as vc++)
#if !defined(_KNOWN_COMPILER)
   aStream& aStream::operator<<(std::basic_ostream<char>& (*ptr_manipulator)(std::basic_ostream<char>&))
   {
      if ( ptr_manipulator == pv_ptr_ends )
      {
         *pv_ptr_oss << std::ends;
         pv_value = pv_ptr_oss->str();
         delete pv_ptr_oss;
         pv_ptr_oss = new OSTRINGSTREAM;
         pv_string_terminated = true;
         return *this;
      }
      pv_string_terminated = false;
      *pv_ptr_oss << ptr_manipulator;  return *this;
   }
   
   aStream& aStream::operator<<(std::basic_ios<char>& (*ptr_manipulator)(std::basic_ios<char>&))
   {
      pv_string_terminated = false;
      *pv_ptr_oss << ptr_manipulator;  return *this;
   }

   aStream& aStream::operator<<(std::ios_base& (*ptr_manipulator)(std::ios_base&))
   {
      pv_string_terminated = false;
      *pv_ptr_oss << ptr_manipulator;  return *this;
   }
#endif

// insertion of standard data types
   
   aStream& aStream::operator<<(bool b)
   {
      pv_string_terminated = false;
      *pv_ptr_oss << b;    return *this;
   }

   aStream& aStream::operator<<(char c)
   {
      pv_string_terminated = false;
      *pv_ptr_oss << c;    return *this;
   }

   aStream& aStream::operator<<(const char* str)
   {
      pv_string_terminated = false;
      *pv_ptr_oss << str;  return *this;
   }

   aStream& aStream::operator<<(short int si)
   {
      pv_string_terminated = false;
      *pv_ptr_oss << si;   return *this;
   }

   aStream& aStream::operator<<(int i)
   {
      pv_string_terminated = false;
      *pv_ptr_oss << i;    return *this;
   }
   
   aStream& aStream::operator<<(long int li)
   {
      pv_string_terminated = false;
      *pv_ptr_oss << li;   return *this;
   }

   aStream& aStream::operator<<(unsigned short int usi)
   {
      pv_string_terminated = false;
      *pv_ptr_oss << usi;  return *this;
   }
   aStream& aStream::operator<<(unsigned int ui)
   {
      pv_string_terminated = false;
      *pv_ptr_oss << ui;   return *this;
   }
   aStream& aStream::operator<<(unsigned long int uli)
   {
      pv_string_terminated = false;
      *pv_ptr_oss << uli;  return *this;
   }

   aStream& aStream::operator<<(float f)
   {
      pv_string_terminated = false;
      *pv_ptr_oss << f;    return *this;
   }
   aStream& aStream::operator<<(double d)
   {
      pv_string_terminated = false;
      *pv_ptr_oss << d;    return *this;
   }
   aStream& aStream::operator<<(long double ld)
   {
      pv_string_terminated = false;
      *pv_ptr_oss << ld;   return *this;
   }
}

#if defined(_KNOWN_COMPILER)
#  undef _KNOWN_COMPILER
#endif

#endif //   _PLUME_ASTREAM_
