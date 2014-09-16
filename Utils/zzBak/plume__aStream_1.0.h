#ifndef _PLUME_ASTREAM_
#define _PLUME_ASTREAM_
/**

  *File: plume_aStream.h

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
#include <iostream>

// local includes

// const declarations

// namespace

// forward declarations

// function prototypes


// begin class declaration

namespace plume
{

   
   class aStream
   {
      inline friend std::ostream& operator<<(std::ostream& os, const aStream& s);
      public:
      // constructors

#if defined(_MSC_VER)
         aStream() : pv_ptr_oss( new std::ostrstream ), 
                     pv_string_terminated( false ),
                     pv_ptr_ends( std::ends ) {};

         aStream(const char* str) : pv_ptr_oss( new std::ostrstream ), 
                                    pv_string_terminated( false ),
                                    pv_ptr_ends( std::ends ) {
            *pv_ptr_oss << str;
         }
#else
         aStream() : pv_ptr_oss( new std::ostrstream ), 
                     pv_string_terminated( false ) {};

         aStream(const char* str) : pv_ptr_oss( new std::ostrstream ), 
                                    pv_string_terminated( false )  {
            *pv_ptr_oss << str;
         }
#endif

      // accessor
         inline std::string operator()() const;

      // function to clear the string
         inline void Clear();

      // insertion of manipulators


#if defined(__sgi)
         template<class _char, class _traits>   
            inline aStream& operator<<( std::basic_ostream<_char, _traits>& (*ptr_manipulator) (std::basic_ostream<_char, _traits>& ));
         template<class _char, class _traits>
            inline aStream& operator<<(std::basic_ios<_char, _traits>& (*ptr_manipulator)(std::basic_ios<_char, _traits>&));
         inline aStream& operator<<(std::ios_base& (*ptr_manipulator)(std::ios_base&));
#else

#  if defined(__GNUC__)
         inline aStream& operator<<(std::ostream& (*ptr_manipulator)(std::ostream&));
#  else
         inline aStream& operator<<(std::basic_ostream<wchar_t>& (*ptr_manipulator)(std::basic_ostream<wchar_t>&));
         inline aStream& operator<<(std::basic_ios<char>& (*ptr_manipulator)(std::basic_ios<char>&));
         inline aStream& operator<<(std::ios_base& (*ptr_manipulator)(std::ios_base&));
#  endif
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
         std::ostrstream* pv_ptr_oss;  // buffer to store insertions
         std::string      pv_value;    // the insertion string
         bool             pv_string_terminated;

      // need to explicitly instantiate the template std::ends
      // this turned out to be a necessity while compiling on Irix 6.5
#if defined(_MSC_VER)
         std::basic_ostream<wchar_t>& (*pv_ptr_ends) (std::basic_ostream<wchar_t>&);
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
#if defined(__GNUC__)
   aStream& aStream::operator<<(std::ostream& (*ptr_manipulator)(std::ostream&))
   {
      if ( ptr_manipulator == std::ends )
      {
         *pv_ptr_oss << std::ends;
         pv_value = pv_ptr_oss->str();
         delete pv_ptr_oss;
         pv_ptr_oss = new std::ostrstream;
         pv_string_terminated = true;
         return *this;
      }
      pv_string_terminated = false;
      *pv_ptr_oss << ptr_manipulator;  return *this;
   }
#else
#  if defined(__sgi)
   template<class _char, class _traits>
   aStream& aStream::operator<<(std::basic_ostream<_char, _traits>& (*ptr_manipulator)(std::basic_ostream<_char, _traits>&))
   {
      if ( ptr_manipulator == std::ends )
      {
         *pv_ptr_oss << std::ends;
         pv_value = pv_ptr_oss->str();
         delete pv_ptr_oss;
         pv_ptr_oss = new std::ostrstream;
         pv_string_terminated = true;
         return *this;
      }
      pv_string_terminated = false;
      *pv_ptr_oss << ptr_manipulator;  return *this;
   }
   
   template<class _char, class _traits>
   aStream& aStream::operator<<(std::basic_ios<_char, _traits>& (*ptr_manipulator)(std::basic_ios<_char, _traits>&))
   {
      pv_string_terminated = false;
      *pv_ptr_oss << ptr_manipulator;  return *this;
   }

   aStream& aStream::operator<<(std::ios_base& (*ptr_manipulator)(std::ios_base&))
   {
      pv_string_terminated = false;
      *pv_ptr_oss << ptr_manipulator;  return *this;
   }

#  else
   aStream& aStream::operator<<(std::basic_ostream<wchar_t>& (*ptr_manipulator)(std::basic_ostream<wchar_t>&))
   {
//      if ( ptr_manipulator == std::ends )
      if ( ptr_manipulator == pv_ptr_ends )
      {
         *pv_ptr_oss << std::ends;
         pv_value = pv_ptr_oss->str();
         delete pv_ptr_oss;
         pv_ptr_oss = new std::ostrstream;
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

#  endif
#endif
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

#endif //   _PLUME_ASTREAM_
