/**

  *File: anException.cpp

  *Description:

   this file implements the class anException

  *Version: 1.0

  *Dependencies:

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL
  *Date:
  */

// system includes
#include <string>

// <strstream> is deprecated (except for Gnuc ver < 3)
#if defined(__GNUC__) && (__GNUC__ < 3)
#  include <strstream>
   typedef std::ostrstream    OSTRINGSTREAM;
#else
#include <sstream>
   typedef std::ostringstream OSTRINGSTREAM;
#endif

// local includes
#include "anException.h"
#include "plume_aStream.h"

// const declarations
const char* anException_id = 
   "@(#) anException. implementation. ver. 1.0. Premalatha and Vidyadhar, CTFD, NAL.";

// function prototypes

// forward declarations

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


// begin class implementation
   ////////////////////////////////////////
   //                                      
   //    implement constructors here       
   //                                      
   //                                      

/**
   default constructor
  */
anException::anException()
   : pv_leader_string( " ** " )
{
// empty
}

/**
   copy constructor
  */
anException::anException(const anException& except)
   : pv_message( except.pv_message ), 
     pv_start_message( except.pv_start_message ), pv_end_message( except.pv_end_message ),
     pv_leader_string( except.pv_leader_string )
{
// empty
}


anException::anException(const char* message)
   : pv_message( message ), pv_leader_string( " ** " )
{
// empty
}


   ////////////////////////////////////////
   //                                      
   //    implement assignment operators    
   //         HAS NONE
   //                                      

   ////////////////////////////////////////
   //                                      
   //    implement the destructor          
   //                                      
   //                                      

anException::~anException()
{
// empty
}

   ////////////////////////////////////////////
   //                                          
   //   implement other member functions here  
   //                                          
   //                                          
/**
   this function is used to insert a character string into the
   object
  */
anException& anException::operator<<(bool b)
{
   pv_message << b;
   return *this;
}

anException& anException::operator<<(char c)
{
   pv_message << c;
   return *this;
}

anException& anException::operator<<(const char* str)
{
   pv_message << str;
   return *this;
}

anException& anException::operator<<(const std::string& string)
{
   pv_message << string.c_str();
   return *this;
}

anException& anException::operator<<(short int si)
{
   pv_message << si;
   return *this;
}

anException& anException::operator<<(int i)
{
   pv_message << i;
   return *this;
}

anException& anException::operator<<(long int li)
{
   pv_message << li;
   return *this;
}

anException& anException::operator<<(unsigned short int usi)
{
   pv_message << usi;
   return *this;
}

anException& anException::operator<<(unsigned int ui)
{
   pv_message << ui;
   return *this;
}

anException& anException::operator<<(unsigned long int uli)
{
   pv_message << uli;
   return *this;
}

anException& anException::operator<<(float f)
{
   pv_message << f;
   return *this;
}

anException& anException::operator<<(double d)
{
   pv_message << d;
   return *this;
}

anException& anException::operator<<(long double ld)
{
   pv_message << ld;
   return *this;
}


/**
   the following functions insert the io manipulators
  */

// insertion for the GNUC g++ compiler ver < 3.0
#if defined(__GNUC__) && (__GNUC__ < 3)
anException& anException::operator<<(std::ostream& (*ptr_manipulator)(std::ostream&))
{
   pv_message << ptr_manipulator;
   return *this;
}
#endif

// insertion for the Microsoft Visual C++ compiler
#if defined(_MSC_VER)
anException& anException::operator<<(std::basic_ostream<char>& (*ptr_manipulator)(std::basic_ostream<char>&))
{
   pv_message << ptr_manipulator;
   return *this;
}

anException& anException::operator<<(std::basic_ios<char>& (*ptr_manipulator)(std::basic_ios<char>&))
{
   pv_message << ptr_manipulator;
   return *this;
}

anException& anException::operator<<(std::ios_base& (*ptr_manipulator)(std::ios_base&))
{
   pv_message << ptr_manipulator;
   return *this;
}
#endif

// insertion for Irix 6.5 and above C++ ver 7.3 and above.
#if defined(__sgi) && !defined(__GNUC__)
anException& anException::operator<<(std::basic_ostream<wchar_t, std::char_traits<wchar_t> >& (*ptr_manipulator)(std::basic_ostream<wchar_t, std::char_traits<wchar_t> >&))
{
   pv_message << ptr_manipulator;
   return *this;
}

anException& anException::operator<<(std::basic_ios<wchar_t, std::char_traits<wchar_t> >& (*ptr_manipulator)(std::basic_ios<wchar_t, std::char_traits<wchar_t> >&))
{
   pv_message << ptr_manipulator;
   return *this;
}

anException& anException::operator<<(std::ios_base& (*ptr_manipulator)(std::ios_base&))
{
   pv_message << ptr_manipulator;
   return *this;
}
#endif


// insertion for the GNUC g++ compiler ver >= 3.0
#if defined(__GNUC__) && (__GNUC__ >= 3)
anException& anException::operator<<(std::basic_ostream<char>& (*ptr_manipulator)(std::basic_ostream<char>&))
{
   pv_message << ptr_manipulator;
   return *this;
}

anException& anException::operator<<(std::basic_ios<char>& (*ptr_manipulator)(std::basic_ios<char>&))
{
   pv_message << ptr_manipulator;
   return *this;
}

anException& anException::operator<<(std::ios_base& (*ptr_manipulator)(std::ios_base&))
{
   pv_message << ptr_manipulator;
   return *this;
}
#endif

// insertion for some other unknown compiler
#if !defined(_KNOWN_COMPILER)
anException& anException::operator<<(std::basic_ostream<char>& (*ptr_manipulator)(std::basic_ostream<char>&))
{
   pv_message << ptr_manipulator;
   return *this;
}

anException& anException::operator<<(std::basic_ios<char>& (*ptr_manipulator)(std::basic_ios<char>&))
{
   pv_message << ptr_manipulator;
   return *this;
}

anException& anException::operator<<(std::ios_base& (*ptr_manipulator)(std::ios_base&))
{
   pv_message << ptr_manipulator;
   return *this;
}
#endif

#if 0
#if defined(__GNUC__) && (__GNUC__ < 3)
anException& anException::operator<<(std::ostream& (*ptr_manipulator)(std::ostream&))
{
   pv_message << ptr_manipulator;
   return *this;
}
#else
anException& anException::operator<<(std::basic_ostream<char>& (*ptr_manipulator)(std::basic_ostream<char>&))
{
   pv_message << ptr_manipulator;
   return *this;
}

anException& anException::operator<<(std::basic_ios<char>& (*ptr_manipulator)(std::basic_ios<char>&))
{
   pv_message << ptr_manipulator;
   return *this;
}

anException& anException::operator<<(std::ios_base& (*ptr_manipulator)(std::ios_base&))
{
   pv_message << ptr_manipulator;
   return *this;
}
#endif
#endif
  
/**
   this function outputs the exeption to the ostream
  */

std::ostream& operator<<(std::ostream& os, anException& except)
{
   except.Print(os);
   return os;
}

plume::aStream& anException::Header()
{
   return pv_start_message;
}

plume::aStream& anException::Trailer()
{
   return pv_end_message;
}



void anException::Print(std::ostream& os) 
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

void anException::PrintMultilineString(std::ostream& os, std::string s)
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
   void Throw(const char* c_string)
   {
      throw anException(c_string);
   }

   void Throw(anException e)
   {
      throw e;
   }
}

#if defined(_KNOWN_COMPILER)
#  undef _KNOWN_COMPILER
#endif
