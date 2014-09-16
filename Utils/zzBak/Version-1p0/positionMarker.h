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

  *Version: 1.0

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
// const declarations
// function prototypes
// forward declarations
class positionMarker;
namespace plume
{
// these are the manipulators
   positionMarker& ends(positionMarker& pm);
   positionMarker& pause(positionMarker& pm);
   positionMarker& on(positionMarker& pm);
   positionMarker& off(positionMarker& pm);
}

// begin class declaration
class positionMarker
{
   friend positionMarker& plume::ends(positionMarker& pm);
   friend positionMarker& plume::pause(positionMarker& pm);
   friend positionMarker& plume::on(positionMarker& pm);
   friend positionMarker& plume::off(positionMarker& pm);
   friend std::ostream& operator<<(std::ostream& os, const positionMarker& pm) {
      os << pm.pv_message.c_str() << std::endl;
      return os;
   }

   public:

   // constructors
      positionMarker() : pv_on( 1 ) {};

   // destructor

   // insertion (to insert additional message etc)
   // insert a c string
      positionMarker& operator<<(char* c_string) {
         if ( pv_on ) {
            std::strstream buff;
            buff << c_string << std::ends;
            pv_message += buff.str();
         }
         return *this;
      }

   // insert a char
      positionMarker& operator<<(char c) {
         if ( pv_on ) {
            std::strstream buff;
            buff << c << std::ends;
            pv_message += buff.str();
         }
         return *this;
      }

   // insert short int
      positionMarker& operator<<(short int si) {
         if ( pv_on ) {
            std::strstream buff;
            buff << si << std::ends;
            pv_message += buff.str();
         }
         return *this;
      }

   // insert an int
      positionMarker& operator<<(int i) {
         if ( pv_on ) {
            std::strstream buff;
            buff << i << std::ends;
            pv_message += buff.str();
         }
         return *this;
      }

   // insert long int
      positionMarker& operator<<(long int li) {
         if ( pv_on ) {
            std::strstream buff;
            buff << li << std::ends;
            pv_message += buff.str();
         }
         return *this;
      }


   // insert a manipulator
      positionMarker& operator<< ( std::basic_ostream<char>& (*ptr_manipulator) (std::basic_ostream<char>&) ) {
         if ( pv_on ) {
            std::strstream buff;
            buff << ptr_manipulator << std::ends;
            pv_message += buff.str();
         }
         return *this;
      }

   // insert a manipulator for boolean type (this is different!!!!)
      positionMarker& operator<< ( std::ios_base& (*ptr_manipulator) (std::ios_base&) ) {
         if ( pv_on ) {
            std::strstream buff;
            buff << ptr_manipulator << std::ends;
            pv_message += buff.str();
         }
         return *this;
      }

   // want our own manipulators
      positionMarker& operator<<(positionMarker& (*ppmf)(positionMarker&)) {
         return ppmf(*this);
      }


   protected:
   // these are invoked by the manipulators
      void Off() {            // turns off the output
         pv_on = 0;
         pv_message = "";
      }

      void On() {             // turns on the output
         pv_on = 1;
      }

      void Ends() {           // ends the insertion (displays)
         if ( pv_on ) {
            std::cout << "   <<< " << pv_message.c_str() << " >>>" << std::endl;
            pv_message = "";
         }
      }

      void Pause() {          // displays the message and pauses
         if ( pv_on ) {
            std::cout << pv_message.c_str() << std::endl;

            std::cout << "   <<< ** Program paused." << std::endl
                      << "   <<< ** Type s to stop, any other key to continue. ";
            char c;
            std::cin.get(c);
            if ( c == 's' ) {
               std::cout << "   <<< ** Program terminated by user." << std::endl;
               exit(-1);
            }

            pv_message = "";  // erase the old message
         }
      }

   private:
   // assignment and default disabled
      positionMarker& operator=(const positionMarker& pm);

   private:
   // the name of the function being traced and the channel
      std::string pv_message;
      int pv_on;              // switch to turn on/off marking
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

namespace plume
{
   positionMarker& ends(positionMarker& pm)  // this name is matched in use
   {
      pm.Ends();
      return pm;
   }

   positionMarker& pause(positionMarker& pm)
   {
      pm.Pause();
      return pm;
   }

   positionMarker& on(positionMarker& pm)
   {
      pm.On();
      return pm;
   }
   
   positionMarker& off(positionMarker& pm)
   {
      pm.Off();
      return pm;
   }
}

#endif //   _POSITIONMARKER_

