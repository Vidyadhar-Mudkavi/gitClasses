#ifndef _PLUME_STREAM_OUTPUT_MANAGER_
#define _PLUME_STREAM_OUTPUT_MANAGER_
/**
  *File: streamOutputManager.h

  \details
   this file declares class streamOutputManager. the idea is to let this class manage output with
   specific reference to formatting numbers. fortran has in built facility that formats output,
   especially that of numerical output. but in c++, this is often a "pain". we develop this class
   with that in mind.

   to use, one would create this class and direct all output to this class. some default formatting
   is already provided.

  \Version  1.0 "@(#) streamOutputManager. header. ver. 1.0. Premalatha, Vidyadhar Mudkavi, CTFD, NAL."

  \Authors
          - Premalatha, Vidyadhar Mudkavi, CTFD, NAL

  \Date
          - 2008-05-28
  */

// set compiler flag
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

// system includes
#include <iostream>

// <strstream> is deprecated (except for Gnuc ver < 3)
#if defined(__GNUC__) && (__GNUC__ < 3)
#  include <strstream>
   typedef std::ostrstream    OSTRINGSTREAM;
#else
#include <sstream>
   typedef std::ostringstream OSTRINGSTREAM;
#endif

// standard template
// local includes
#include "anException.h"

// const declarations
// function prototypes
// forward declarations

// begin class declaration
namespace plume
{
   class streamOutputManager
   {
      // friend std::ostream& operator<<(std::ostream& os, const streamOutputManager& p);
      typedef anException exception;

      public:
      // constructors
         streamOutputManager(std::ostream& out = std::cout)
         {
            pv_ptr_os = &out;
            SetFormats();
            SetDigits();
         }

         streamOutputManager(const streamOutputManager& som)
            : pv_ptr_os( som.pv_ptr_os )
         {
         }

      // assignment operator
         streamOutputManager& operator=(const streamOutputManager& som)
         {
            if (this == &som)
            {
               return *this;
            }
            pv_ptr_os = som.pv_ptr_os;
            return *this;
         }

      // destructor
         ~streamOutputManager()
         {
            pv_ptr_os = 0;
         }


      // other functionality
         void operator=(std::ostream& out)
         {
            pv_ptr_os = &out;
         }

      // this is the primary template function which will be used to insert all types
         template <typename T>
         streamOutputManager& operator<<(const T& p)
         {
            (*pv_ptr_os) << p;
            return *this;
         }

      // insertion of manipulators requires special treatment. see plume::aStream
      
      // for sgi compiler
#     if defined(__sgi) && !defined(__GNUC__)
         inline streamOutputManager& operator<<( std::basic_ostream<wchar_t, std::char_traits<wchar_t> >& (*ptr_manipulator) (std::basic_ostream<wchar_t, std::char_traits<wchar_t> >& ));
         inline streamOutputManager& operator<<(std::basic_ios<wchar_t, std::char_traits<wchar_t> >& (*ptr_manipulator)(std::basic_ios<wchar_t, std::char_traits<wchar_t> >&));
         inline streamOutputManager& operator<<(std::ios_base& (*ptr_manipulator)(std::ios_base&));
#     endif

      // for gnu compiler ver < 3.0
#     if defined(__GNUC__) && (__GNUC__ < 3)
         inline streamOutputManager& operator<<(std::ostream& (*ptr_manipulator)(std::ostream&));
#     endif

      // for Gnuc ver >=3.0
#     if defined(__GNUC__) && (__GNUC__ >= 3)
         inline streamOutputManager& operator<<(std::basic_ostream<char>& (*ptr_manipulator)(std::basic_ostream<char>&));
         inline streamOutputManager& operator<<(std::basic_ios<char>& (*ptr_manipulator)(std::basic_ios<char>&));
         inline streamOutputManager& operator<<(std::ios_base& (*ptr_manipulator)(std::ios_base&));
#     endif

      // for microsoft vc++ compilers
#     if defined(_MSC_VER)
         inline streamOutputManager& operator<<(std::basic_ostream<char>& (*ptr_manipulator)(std::basic_ostream<char>&));
         inline streamOutputManager& operator<<(std::basic_ios<char>& (*ptr_manipulator)(std::basic_ios<char>&));
         inline streamOutputManager& operator<<(std::ios_base& (*ptr_manipulator)(std::ios_base&));
#     endif

      // some other compiler (make it same as vc++ compiler)
#     if !defined(_KNOWN_COMPILER)
         inline streamOutputManager& operator<<(std::basic_ostream<char>& (*ptr_manipulator)(std::basic_ostream<char>&));
         inline streamOutputManager& operator<<(std::basic_ios<char>& (*ptr_manipulator)(std::basic_ios<char>&));
         inline streamOutputManager& operator<<(std::ios_base& (*ptr_manipulator)(std::ios_base&));
#     endif

      protected:
      private:
         std::ostream* pv_ptr_os;

      // helper function(s)
         inline void SetFormats();
         inline void ResetFormats();
         inline void SetDigits(const int& numDigits=16);

      // need to explicitly instantiate the template std::ends
      // this turned out to be a necessity while compiling on Irix 6.5
#     if defined(_MSC_VER)
         std::basic_ostream<char>& (*pv_ptr_ends) (std::basic_ostream<char>&);
#     endif

#     if defined(__sgi) && !defined(__GNUC__)
         std::basic_ostream<wchar_t, std::char_traits<wchar_t> >& (*pv_ptr_ends) (std::basic_ostream<wchar_t, std::char_traits<wchar_t> >&);
#     endif

#     if defined(__GNUC__) && (__GNUC__ < 3)
         std::ostream& (*pv_ptr_ends) (std::ostream&);
#     endif

#     if defined(__GNUC__) && (__GNUC__ >= 3)
         std::ostream& (*pv_ptr_ends) (std::ostream&);
#     endif

#     if !defined(_KNOWN_COMPILER)
         std::basic_ostream<char>& (*pv_ptr_ends) (std::basic_ostream<char>&);
#     endif
   };

// include any inline code here
/**
  \note
      - all accessors are inlined here.
  */

/**
  \brief   
  - this function sets up formats
  \Return  
  - void
  \Param
  - void
  \Throws
  - no exception
  */
  void streamOutputManager::SetFormats()
  {
     const std::ios::fmtflags flags
      = std::ios::dec | std::ios::scientific | std::ios::showpos;
     pv_ptr_os->setf(flags);
//   pv_ptr_os->unsetf(flags);
  }

/**
  \brief   
  - this function resets formats
  \Return  
  - void
  \Param
  - void
  \Throws
  - no exception
  */
  void streamOutputManager::ResetFormats()
  {
     const std::ios::fmtflags flags
      = std::ios::dec | std::ios::scientific | std::ios::showpos;
     pv_ptr_os->unsetf(flags);
  }


/**
  \brief   
  - this function sets number of digits to be output (defaults to 16)
  \Return  
  - void
  \Param
  - void
  \Throws
  - no exception
  */
  void streamOutputManager::SetDigits(const int& numDigits)
  {
     pv_ptr_os->precision(numDigits);
  }
  
// insertion of manipulators
/**
  \note
      - insertion of manipulators needs special care. these are inlined here. declared in the body.
  */

// Gnuc compiler ver < 3.0
#if defined(__GNUC__) && (__GNUC__ < 3)
   streamOutputManager& streamOutputManager::operator<<(std::ostream& (*ptr_manipulator)(std::ostream&))
   {
      if ( ptr_manipulator == std::ends )
      {
         *pv_ptr_os << std::ends;
         return *this;
      }
      *pv_ptr_os << ptr_manipulator;  return *this;
   }
#endif

// SGI using C++ 7.3 on Irix >=6.5
#if defined(__sgi) && !defined(__GNUC__)
   streamOutputManager& streamOutputManager::operator<<(std::basic_ostream<wchar_t, std::char_traits<wchar_t> >& (*ptr_manipulator)(std::basic_ostream<wchar_t, std::char_traits<wchar_t> >&))
   {
      if ( ptr_manipulator == pv_ptr_ends )
      {
         *pv_ptr_os << std::ends;
         return *this;
      }
      *pv_ptr_os << ptr_manipulator;  return *this;
   }
   
   streamOutputManager& streamOutputManager::operator<<(std::basic_ios<wchar_t, std::char_traits<wchar_t> >& (*ptr_manipulator)(std::basic_ios<wchar_t, std::char_traits<wchar_t> >&))
   {
      *pv_ptr_os << ptr_manipulator;  return *this;
   }

   streamOutputManager& streamOutputManager::operator<<(std::ios_base& (*ptr_manipulator)(std::ios_base&))
   {
      *pv_ptr_os << ptr_manipulator;  return *this;
   }
#endif


// Microsoft VC++
#if defined(_MSC_VER)
   streamOutputManager& streamOutputManager::operator<<(std::basic_ostream<char>& (*ptr_manipulator)(std::basic_ostream<char>&))
   {
      if ( ptr_manipulator == pv_ptr_ends )
      {
         *pv_ptr_os << std::ends;
         return *this;
      }
      *pv_ptr_os << ptr_manipulator;  return *this;
   }
   
   streamOutputManager& streamOutputManager::operator<<(std::basic_ios<char>& (*ptr_manipulator)(std::basic_ios<char>&))
   {
      *pv_ptr_os << ptr_manipulator;  return *this;
   }

   streamOutputManager& streamOutputManager::operator<<(std::ios_base& (*ptr_manipulator)(std::ios_base&))
   {
      *pv_ptr_os << ptr_manipulator;  return *this;
   }
#endif


// Gnuc compiler ver >= 3.0 (same as vc++)
#if defined(__GNUC__) && (__GNUC__ >= 3)
   streamOutputManager& streamOutputManager::operator<<(std::basic_ostream<char>& (*ptr_manipulator)(std::basic_ostream<char>&))
   {
      if ( ptr_manipulator == pv_ptr_ends )
      {
         *pv_ptr_os << std::ends;
         return *this;
      }
      *pv_ptr_os << ptr_manipulator;  return *this;
   }
   
   streamOutputManager& streamOutputManager::operator<<(std::basic_ios<char>& (*ptr_manipulator)(std::basic_ios<char>&))
   {
      *pv_ptr_os << ptr_manipulator;  return *this;
   }

   streamOutputManager& streamOutputManager::operator<<(std::ios_base& (*ptr_manipulator)(std::ios_base&))
   {
      *pv_ptr_os << ptr_manipulator;  return *this;
   }
#endif

// some other compiler that we dont know yet (use same as vc++)
#if !defined(_KNOWN_COMPILER)
   streamOutputManager& streamOutputManager::operator<<(std::basic_ostream<char>& (*ptr_manipulator)(std::basic_ostream<char>&))
   {
      if ( ptr_manipulator == pv_ptr_ends )
      {
         *pv_ptr_os << std::ends;
         return *this;
      }
      *pv_ptr_os << ptr_manipulator;  return *this;
   }
   
   streamOutputManager& streamOutputManager::operator<<(std::basic_ios<char>& (*ptr_manipulator)(std::basic_ios<char>&))
   {
      *pv_ptr_os << ptr_manipulator;  return *this;
   }

   streamOutputManager& streamOutputManager::operator<<(std::ios_base& (*ptr_manipulator)(std::ios_base&))
   {
      *pv_ptr_os << ptr_manipulator;  return *this;
   }
#endif


/**
   declare any typedef statements here   (e.g.: typedef aVortex areVortices;)
  */
                              //                 
                              //      \\^//      
                              //     o(!_!)o     
                              // __m__  o  __m__ 
                              //                 

}
#endif   // _PLUME_STREAM_OUTPUT_MANAGER_
