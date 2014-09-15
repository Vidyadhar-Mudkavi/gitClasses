#ifndef _ANEXCEPTION_
#define _ANEXCEPTION_

/**
   \file    anException.h

   \brief this file declares class anException - a general purpose class
   \details
      -   this class provides a basis for putting in exception information
         by other users. exceptions are basically error conditions and
         as such the user must be informed about the situation. information
         can be provided in terms of numerical values and text. this class
         helps store such information before the exception object is thrown.
         once thrown by the function which encouters the exception, it can
         be caught elsewhere. once caught, the information can be printed
         by simply inserting the exception object to the output stream.

   \version   1.2 "@(#) anException. header. ver. 1.2. Premalatha and Vidyadhar, CTFD, NAL."

   \authors 
      -   Premalatha, Vidyadhar Mudkavi, CTFD, NAL
   \date
      -   2009-04-07   inlined the whole code so that anException.cpp becomes redundant.
  */

// system includes 
#include <iostream>
#include <string>
#include <iomanip>

// <strstream> is deprecated (except for Gnuc ver < 3)
#if defined(__GNUC__) && (__GNUC__ < 3)
#  include <strstream>
   typedef std::ostrstream    OSTRINGSTREAM;
#else
#include <sstream>
   typedef std::ostringstream OSTRINGSTREAM;
#endif

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
   inline void Throw(const char* c_string);
   inline void Throw(anException e);
}

// function prototypes

// begin class declaration
class anException
{
   friend std::ostream& operator<<(std::ostream& os, anException& except);

   public:

   // constructors
      anException() : pv_leader_string( " ** " ) { /* empty */ }
   
      anException(const anException& except)
         : pv_message( except.pv_message ), 
           pv_start_message( except.pv_start_message ), 
           pv_end_message( except.pv_end_message ),
           pv_leader_string( except.pv_leader_string )
      { /* empty */ }

      anException(const char* message)
         : pv_message( message ), pv_leader_string( " ** " )
      { /* empty */ }

   // destructor
      virtual ~anException() { /* empty */ }

   // string and basic data type insertion operators
      inline anException& operator<<(bool b);
      inline anException& operator<<(char c);
      inline anException& operator<<(const char* str);
      inline anException& operator<<(const std::string& string);   // useful

      inline anException& operator<<(short int si);
      inline anException& operator<<(int i);
      inline anException& operator<<(long int li);

      inline anException& operator<<(unsigned short int usi);
      inline anException& operator<<(unsigned int ui);
      inline anException& operator<<(unsigned long int uli);
      inline anException& operator<<(float f);
      inline anException& operator<<(double d);
      inline anException& operator<<(long double ld);

   // need sometimes to explicitly terminate the message string
      inline anException& End();

   // insertion of manipulators

   // for sgi compiler
#if defined(__sgi) && !defined(__GNUC__)
      inline anException& 
      operator<<( std::basic_ostream<wchar_t, std::char_traits<wchar_t> >& (*ptr_manipulator) 
         (std::basic_ostream<wchar_t, std::char_traits<wchar_t> >& ));
      
      inline anException& 
      operator<<(std::basic_ios<wchar_t, std::char_traits<wchar_t> >& (*ptr_manipulator)
         (std::basic_ios<wchar_t, std::char_traits<wchar_t> >&));
      
      inline anException& operator<<(std::ios_base& (*ptr_manipulator)(std::ios_base&));
#endif

      // for gnu compiler ver < 3.0
#if defined(__GNUC__) && (__GNUC__ < 3)
      inline anException& operator<<(std::ostream& (*ptr_manipulator)(std::ostream&));
#endif

      // for Gnuc ver >=3.0
#if defined(__GNUC__) && (__GNUC__ >= 3)
      inline anException& 
      operator<<(std::basic_ostream<char>& (*ptr_manipulator)(std::basic_ostream<char>&));
      
      inline anException& 
      operator<<(std::basic_ios<char>& (*ptr_manipulator)(std::basic_ios<char>&));
      
      inline anException& 
      operator<<(std::ios_base& (*ptr_manipulator)(std::ios_base&));
#endif

      // for microsoft vc++ compilers
#if defined(_MSC_VER)
      inline anException& 
      operator<<(std::basic_ostream<char>& (*ptr_manipulator)(std::basic_ostream<char>&));
      
      inline anException& 
      operator<<(std::basic_ios<char>& (*ptr_manipulator)(std::basic_ios<char>&));
      
      inline anException& operator<<(std::ios_base& (*ptr_manipulator)(std::ios_base&));
#endif

      // some other compiler (make it same as vc++ compiler)
#if !defined(_KNOWN_COMPILER)
      inline anException& 
      operator<<(std::basic_ostream<char>& (*ptr_manipulator)(std::basic_ostream<char>&));
      
      inline anException& 
      operator<<(std::basic_ios<char>& (*ptr_manipulator)(std::basic_ios<char>&));
      
      inline anException& operator<<(std::ios_base& (*ptr_manipulator)(std::ios_base&));
#endif

#if 0
#if defined(__GNUC__) && (__GNUC__ < 3)
      inline anException& 
      operator<<(std::ostream& (*ptr_manipulator)(std::ostream&));
#else
      inline anException& 
      operator<<(std::basic_ostream<char>& (*ptr_manipulator)(std::basic_ostream<char>&));
      
      inline anException& 
      operator<<(std::basic_ios<char>& (*ptr_manipulator)(std::basic_ios<char>&));
      
      inline anException& operator<<(std::ios_base& (*ptr_manipulator)(std::ios_base&));
#endif
#endif

   // provide a means to insert into header and trailer messages
      inline plume::aStream& Header();
      inline plume::aStream& Trailer();
   
#if 0 // this is deprecated
      void SetLeaderString(char* l_string = " ** ")
      {
         pv_leader_string = l_string;
      }
#endif
   
   void SetLeaderString(std::string l_string = " ** ")
   {
      pv_leader_string = l_string;
   }

   protected:
   // provide some access to writing to underlying string via a derived class
      inline virtual void Print(std::ostream& os);
      inline void PrintMultilineString(std::ostream& os, std::string s);

   // two stream objects which help insert messages into these
      plume::aStream pv_start_message;
      plume::aStream pv_end_message;

   // the string containing the message
      plume::aStream pv_message;

   // assignment operator (disabled)
      anException& operator=(const anException& except)
      {
         return *this;
      }
      
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
   \brief   
      this function is used to insert a character string into the object
  */
inline anException& anException::operator<<(bool b)
{
   pv_message << b;
   return *this;
}

inline anException& anException::operator<<(char c)
{
   pv_message << c;
   return *this;
}

inline anException& anException::operator<<(const char* str)
{
   pv_message << str;
   return *this;
}

inline anException& anException::operator<<(const std::string& string)
{
   pv_message << string.c_str();
   return *this;
}

inline anException& anException::operator<<(short int si)
{
   pv_message << si;
   return *this;
}

inline anException& anException::operator<<(int i)
{
   pv_message << i;
   return *this;
}

inline anException& anException::operator<<(long int li)
{
   pv_message << li;
   return *this;
}

inline anException& anException::operator<<(unsigned short int usi)
{
   pv_message << usi;
   return *this;
}

inline anException& anException::operator<<(unsigned int ui)
{
   pv_message << ui;
   return *this;
}

inline anException& anException::operator<<(unsigned long int uli)
{
   pv_message << uli;
   return *this;
}

inline anException& anException::operator<<(float f)
{
   pv_message << f;
   return *this;
}

inline anException& anException::operator<<(double d)
{
   pv_message << d;
   return *this;
}

inline anException& anException::operator<<(long double ld)
{
   pv_message << ld;
   return *this;
}


/**
   \brief   the following functions insert the io manipulators
  */

// insertion for the GNUC g++ compiler ver < 3.0
#if defined(__GNUC__) && (__GNUC__ < 3)
// CHECK THIS. THE FUNCTION SIGNATURE WAS MISSING!!
inline anException& anException::operator<<(std::ios_base& (*ptr_manipulator)(std::ios_base&));
{
   pv_message << ptr_manipulator;
   return *this;
}
#endif

// insertion for the Microsoft Visual C++ compiler
#if defined(_MSC_VER)
inline anException& 
anException::operator<<(std::basic_ostream<char>& (*ptr_manipulator)(std::basic_ostream<char>&))
{
   pv_message << ptr_manipulator;
   return *this;
}

inline anException& 
anException::operator<<(std::basic_ios<char>& (*ptr_manipulator)(std::basic_ios<char>&))
{
   pv_message << ptr_manipulator;
   return *this;
}

inline anException& anException::operator<<(std::ios_base& (*ptr_manipulator)(std::ios_base&))
{
   pv_message << ptr_manipulator;
   return *this;
}
#endif

// insertion for Irix 6.5 and above C++ ver 7.3 and above.
#if defined(__sgi) && !defined(__GNUC__)
inline anException& 
anException::operator<<( std::basic_ostream<wchar_t, 
                         std::char_traits<wchar_t> >& 
                           (*ptr_manipulator)(std::basic_ostream<wchar_t, std::char_traits<wchar_t> >&)
                       )
{
   pv_message << ptr_manipulator;
   return *this;
}

inline anException& 
anException::operator<<( std::basic_ios<wchar_t, 
                         std::char_traits<wchar_t> >& 
                            (*ptr_manipulator)(std::basic_ios<wchar_t, std::char_traits<wchar_t> >&)
                       )
{
   pv_message << ptr_manipulator;
   return *this;
}

inline anException& anException::operator<<(std::ios_base& (*ptr_manipulator)(std::ios_base&))
{
   pv_message << ptr_manipulator;
   return *this;
}
#endif


// insertion for the GNUC g++ compiler ver >= 3.0
#if defined(__GNUC__) && (__GNUC__ >= 3)
inline anException& 
anException::operator<<(std::basic_ostream<char>& (*ptr_manipulator)(std::basic_ostream<char>&))
{
   pv_message << ptr_manipulator;
   return *this;
}

inline anException& 
anException::operator<<(std::basic_ios<char>& (*ptr_manipulator)(std::basic_ios<char>&))
{
   pv_message << ptr_manipulator;
   return *this;
}

inline anException& anException::operator<<(std::ios_base& (*ptr_manipulator)(std::ios_base&))
{
   pv_message << ptr_manipulator;
   return *this;
}
#endif

// insertion for some other unknown compiler
#if !defined(_KNOWN_COMPILER)
inline anException& 
anException::operator<<(std::basic_ostream<char>& (*ptr_manipulator)(std::basic_ostream<char>&))
{
   pv_message << ptr_manipulator;
   return *this;
}

inline anException& 
anException::operator<<(std::basic_ios<char>& (*ptr_manipulator)(std::basic_ios<char>&))
{
   pv_message << ptr_manipulator;
   return *this;
}

inline anException& 
anException::operator<<(std::ios_base& (*ptr_manipulator)(std::ios_base&))
{
   pv_message << ptr_manipulator;
   return *this;
}
#endif

#if 0
#if defined(__GNUC__) && (__GNUC__ < 3)
inline anException& 
anException::operator<<(std::ostream& (*ptr_manipulator)(std::ostream&))
{
   pv_message << ptr_manipulator;
   return *this;
}
#else
inline anException& 
anException::operator<<(std::basic_ostream<char>& (*ptr_manipulator)(std::basic_ostream<char>&))
{
   pv_message << ptr_manipulator;
   return *this;
}

inline anException& 
anException::operator<<(std::basic_ios<char>& (*ptr_manipulator)(std::basic_ios<char>&))
{
   pv_message << ptr_manipulator;
   return *this;
}

inline anException& 
anException::operator<<(std::ios_base& (*ptr_manipulator)(std::ios_base&))
{
   pv_message << ptr_manipulator;
   return *this;
}
#endif
#endif
  
/**
   this function outputs the exeption to the ostream
  */

inline std::ostream& operator<<(std::ostream& os, anException& except)
{
   except.Print(os);
   return os;
}

inline plume::aStream& anException::Header()
{
   return pv_start_message;
}

inline plume::aStream& anException::Trailer()
{
   return pv_end_message;
}



inline void anException::Print(std::ostream& os) 
{
   pv_start_message << std::ends;
   pv_message       << std::ends;
   pv_end_message   << std::ends;

   PrintMultilineString( os, pv_start_message() );
   PrintMultilineString( os, pv_message() );
   PrintMultilineString( os, pv_end_message() );
#if 0
   os << pv_leader_string.c_str() << pv_start_message << std::endl;

   std::string message = pv_message.c_str();
   int len = message.size();
   if ( len == 0 )
   {
      os << pv_leader_string.c_str() << pv_end_message << std::endl;
      return;
   }

   OSTRINGSTREAM* ptr_oss = new OSTRINGSTREAM;
   int i;
   char c;
   for (i=0; i<len; ++i)
   {
      c = message[i];
      if ( c == '\n' )
      {
         *ptr_oss << std::ends;
         os << pv_leader_string.c_str() << ptr_oss->str() << std::endl;
         delete ptr_oss;
         ptr_oss = new OSTRINGSTREAM;
      }
      else
      {
         *ptr_oss << c;
      }
   }

   *ptr_oss << std::ends;
   os << pv_leader_string.c_str() << ptr_oss->str() << std::endl;
   os << pv_leader_string.c_str() << pv_end_message;
//   delete ptr_oss;
   why has this delete been commented?;
#endif
}

inline void anException::PrintMultilineString(std::ostream& os, std::string s)
{
   OSTRINGSTREAM* ptr_oss = new OSTRINGSTREAM;

   int len = static_cast<int>( s.size() );
   
   int i;
   char c;
   for (i=0; i<len; ++i)
   {
      c = s[i];
      if ( c == '\n' )
      {
         *ptr_oss << std::ends;
         os << pv_leader_string.c_str() << ptr_oss->str() << std::endl;
         delete ptr_oss;
         ptr_oss = new OSTRINGSTREAM;
      }
      else
      {
         *ptr_oss << c;
      }
   }

   *ptr_oss << std::ends;
   os << pv_leader_string.c_str() << ptr_oss->str() << std::endl;
#if 0 // this ptr_oss was not deleted. delted now. October 22, 2001
      // changes made by vm, pl.
//   should you not delete this ptr_oss?;
#endif
   delete ptr_oss;
}

namespace plume
{
   inline void Throw(const char* c_string)
   {
      throw anException(c_string);
   }

   inline void Throw(anException e)
   {
      throw e;
   }
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
