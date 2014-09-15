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

  *Date: 10 February 2000
  */

// system includes
#include <string>
#include <strstream>

// local includes
// const declarations
// function prototypes
namespace plume
{
   class positionMarker;
   void (*pause) (void);
   void Pause(positionMarker& pm);
}

// forward declarations

// begin class declaration
class positionMarker
{
   public:

   // constructors
      positionMarker() {};

   // destructor

   // insertion (to insert additional message etc)
   // insert a c string
      positionMarker& operator<<(char* c_string) {
         std::strstream buff;
         buff << c_string << std::ends;
         pv_message += buff.str();
      }

   // insert a char
      positionMarker& operator<<(char c) {
         std::strstream buff;
         buff << c << std::ends;
         pv_message += buff.str();
      }

   // insert short int
      positionMarker& operator<<(short int si) {
         std::strstream buff;
         buff << si << std::ends;
         pv_message += buff.str();
      }

   // insert an int
      positionMarker& operator<<(int i) {
         std::strstream buff;
         buff << i << std::ends;
         pv_message += buff.str();
      }

   // insert long int
      positionMarker& operator<<(long int li) {
         std::strstream buff;
         buff << li << std::ends;
         pv_message += buff.str();
      }


   // insert a manipulator
      positionMarker& operator<< ( std::basic_ostream<char>& (*ptr_manipulator) (std::basic_ostream<char>&) ) {
         std::strstream buff;
         buff << ptr_manipulator << std::ends;
         pv_message += buff.str();
      }

   // insert a manipulator for boolean type (this is different!!!!)
      positionMarker& operator<< ( std::ios_base& (*ptr_manipulator) (std::ios_base&) ) {
         std::strstream buff;
         buff << ptr_manipulator << std::ends;
         pv_message += buff.str();
      }

   // define our own manipulators
      void Pause() {
         std::cout << "   ** Program paused." 
                   << "   ** Type s to stop, any other key to continue. ";
         char c;
         std::cin.get(c);
         if ( c == 's' ) {
            exit(-1);
         }

         pv_message = "";  // erase the old message
      }

      void operator<< ( void (*p) ( void ) ) {
         plume::Pause(*this);
      }

   protected:

   private:
   // assignment and default disabled
      positionMarker& operator=(const positionMarker& pm);

   private:
   // the name of the function being traced and the channel
      std::string pv_message;
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
   void Pause(positionMarker& pm)
   {
      pm.Pause();
   }
}

#endif //   _POSITIONMARKER_
