#ifndef _POSITIONMARKER_
#define _POSITIONMARKER_
/**

  *File: positionMarker.h

  *Description:

   this file declares class positionMarker. this is intended to be a 
   debug tool. instances of this class
   are used to mark a position in a line of code. often, it is very
   difficult to debug without inserting print statements at appropriate
   locations in a line of code. though, a throw mechanism gets out of regular
   flow of the program, we cannot tell as to which location the code 
   came out from. therefore, we still need to mark locations. 
   this is styled along the function tracer concept.

  *References: Ruminations on C++. Koenig and Moo, 1996. Chapter 27.

  *Version: 1.1 "@(#) positionMarker. header. ver. 1.1. Premalatha and Vidyadhar, CTFD, NAL."

  *Dependencies:
   none

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL

  *Date: 21 February 2000
  */

// system includes
#include <iostream>
#include <string>
#include <strstream>

// local includes
#include "plume_aStream.h"

// const declarations
// function prototypes
// forward declarations
class positionMarker;
namespace plume
{
// these are the manipulators
   inline positionMarker& ends(positionMarker& pm);
   inline positionMarker& pause(positionMarker& pm);
   inline positionMarker& on(positionMarker& pm);
   inline positionMarker& off(positionMarker& pm);
}

// begin class declaration
class positionMarker
{
   friend positionMarker& plume::ends(positionMarker& pm);
   friend positionMarker& plume::pause(positionMarker& pm);
   friend positionMarker& plume::on(positionMarker& pm);
   friend positionMarker& plume::off(positionMarker& pm);

   friend std::ostream& operator<<(std::ostream& os, const positionMarker& pm)
   {
      os << pm.pv_message << std::endl;
      return os;
   }

   public:
   // constructors
      inline positionMarker();

   // insertion operations

   // want our own manipulators to be inserted
      inline positionMarker& operator<<
         (positionMarker& (*ppmf)(positionMarker&));

   // insert a manipulator
#if defined(__GNUC__)
      inline positionMarker& operator<<
         ( std::ostream& (*ptr_manipulator) (std::ostream&) );
#else
      inline positionMarker& operator<<
         ( std::basic_ostream<char>& (*ptr_manipulator) (std::basic_ostream<char>&) );

   // insert a manipulator for boolean type (this is different!!!!)
      inline positionMarker& operator<<
         ( std::ios_base& (*ptr_manipulator) (std::ios_base&) );
#endif

      inline positionMarker& operator<<(char* c_string); // insert string
      inline positionMarker& operator<<(char c);         // insert a char
      inline positionMarker& operator<<(short int si);   // insert short int
      inline positionMarker& operator<<(int i);          // insert int
      inline positionMarker& operator<<(long int li);    // insert long int

   protected:
   // these are invoked by the manipulators (helpers)
      inline void Off();      // turns off the output
      inline void On();       // turns on the output
      inline void Ends();     // ends the insertion (displays)
      inline void Pause();    // displays the message and pauses

   private:
   // assignment disabled
      positionMarker& operator=(const positionMarker& pm);

   private:
      plume::aStream pv_message; // the string to be printed at the marked line
      int pv_on;                 // switch to turn on/off marking
};


// include any inline code here

/**
  *Purpose: construction. defaults to on position
  */
inline positionMarker::positionMarker()
   : pv_on( 1 ) 
{
//empty
};
   // insertion (to insert additional message etc)
   // want our own manipulators

/**
  *Purpose: enable inserting a manipulator of our own. the insertion
      operator can now take a specific manipulator function pointer.
  */
inline positionMarker& positionMarker::operator<<(positionMarker& (*ppmf)(positionMarker&))
{
   return ppmf(*this);
}

#if defined(__GNUC__)
/**
  *Purpose: enable insertion of standard stream manipulators already defined
      as part of the C++ language facilities.
  */
inline positionMarker& positionMarker::operator<< ( std::ostream& (*ptr_manipulator) (std::ostream&) )
{
   if ( pv_on ) 
   {
      pv_message << ptr_manipulator;
   }
   return *this;
}
#else
/**
  *Purpose: enable insertion of standard stream manipulators already defined
      as part of the C++ language facilities.
  */
inline positionMarker& positionMarker::operator<< ( std::basic_ostream<char>& (*ptr_manipulator) (std::basic_ostream<char>&) )
{
   if ( pv_on )
   {
      pv_message << ptr_manipulator;
   }
   return *this;
}

   // insert a manipulator for boolean type (this is different!!!!)
/**
  *Purpose: insertion of standard manipulator for boolean type is
      different in non gnu compilers (at least microsoft).
  */
inline positionMarker& positionMarker::operator<< ( std::ios_base& (*ptr_manipulator) (std::ios_base&) )
{
   if ( pv_on )
   {
      pv_message << ptr_manipulator;
   }
   return *this;
}
#endif

/**
  *Purpose: insert a character string
  */
inline positionMarker& positionMarker::operator<<(char* c_string)
{
   if ( pv_on ) 
   {
      pv_message << c_string;
   }
   return *this;
}

/**
  *Purpose: insert a single character
  */
inline positionMarker& positionMarker::operator<<(char c)
{
   if ( pv_on )
   {
      pv_message << c;
}
   return *this;
}

/**
  *Purpose: insert a short int
  */
inline positionMarker& positionMarker::operator<<(short int si)
{
   if ( pv_on )
   {
      pv_message << si;
   }
   return *this;
}

/**
  *Purpose: insert an int
  */
inline positionMarker& positionMarker::operator<<(int i)
{
   if ( pv_on )
   {
      pv_message << i;
   }
   return *this;
}

/**
  *Purpose: insert a long int
  */
inline positionMarker& positionMarker::operator<<(long int li)
{
   if ( pv_on )
   {
      pv_message << li;
   }
   return *this;
}

/**
  *Purpose: turns off the output (helper for manipulator)
  */
inline void positionMarker::Off()
{
   pv_on = 0;
   pv_message.Clear();
}

/**
  *Purpose: turns on the output (helper for manipulator)
  */
inline void positionMarker::On()
{
   pv_on = 1;
}

/**
  *Purpose: inserts an end of stream (helper for manipulator).
      message is also displayed when this is inserted.
  */
inline void positionMarker::Ends()
{
   if ( pv_on )
   {
      pv_message << std::ends;
      std::cout << "   <<< " << pv_message << " >>>" << std::endl;
      pv_message.Clear();
   }
}

/**
  *Purpose: pauses the output. whatever message at pause is displayed.
      (helper for manipulator)
  */
inline void positionMarker::Pause()
{
   if ( pv_on )
   {
      pv_message << std::ends;
      std::cout << pv_message << std::endl;

      std::cout << "   <<< ** Program paused." << std::endl
                << "   <<< ** Type s to stop, any other key to continue. ";
            
      char c;
      std::cin.get(c);
      if ( c == 's' ) 
      {
         std::cout << "   <<< ** Program terminated by user." << std::endl;
         ::exit(-1);
      }

      pv_message.Clear();  // erase the old message
   }
}


// now implement the manipulators that are specific to
// this class. these functions are matched in name in
// their usage during the program.
namespace plume
{
   inline positionMarker& ends(positionMarker& pm)
   {
      pm.Ends();
      return pm;
   }

   inline positionMarker& pause(positionMarker& pm)
   {
      pm.Pause();
      return pm;
   }

   inline positionMarker& on(positionMarker& pm)
   {
      pm.On();
      return pm;
   }
   
   inline positionMarker& off(positionMarker& pm)
   {
      pm.Off();
      return pm;
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

#endif   // _POSITIONMARKER_

