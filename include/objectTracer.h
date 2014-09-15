#ifndef _OBJECTTRACER_
#define _OBJECTTRACER_
/**

  *File: objectTracer.h

  *Description:

   this file declares class objectTracer. instances of this class
   are used by objects which can be traced (their invocation and destruction).

   Ref: Ruminations on C++. Koenig and Moo, 1996. Chapter 27.

  *Version: 1.0

  *Dependencies:
   none

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL

  *Date: 21 February 2000
  */

// system includes
#include <string>
#include <list>

// local includes
//#include "outputChannel.h"

// const declarations
// function prototypes
// forward declarations

// begin class declaration
struct tracerInfo
{
// constructor
   tracerInfo() : live_objects( 0 ), total_objects( 0 ) {
      object_name = "An object";
   }

   tracerInfo(char* object_name) : live_objects( 0 ), total_objects( 0 ) {
      this->object_name = object_name;
   }
   std::list<long int>  constructed;
   std::list<long int>  destroyed;
   long int             live_objects;
   long int             total_objects;
   std::string          object_name;
};

class objectTracer
{
   public:
   // constructors
      objectTracer() : pv_object_id( ++pv_info.total_objects ) {
         ++pv_info.live_objects;
         pv_info.constructed.push_front(pv_object_id);
      }

      objectTracer(const objectTracer& ot) : pv_object_id( ++pv_info.total_objects ) {
         ++pv_info.live_objects;
         pv_info.constructed.push_front(pv_object_id);
      }

      objectTracer& operator=(const objectTracer& ft) {
         return *this;
      }

   // destructor
      ~objectTracer() {
         pv_info.destroyed.push_front(pv_object_id);
         if ( --pv_info.live_objects == 0 )
         {
            pv_info.constructed.sort();
            pv_info.destroyed.sort();

            std::list<long int>::iterator itc    = pv_info.constructed.begin();
            std::list<long int>::iterator itcend = pv_info.constructed.end();

            std::list<long int>::iterator itd    = pv_info.destroyed.begin();
            std::list<long int>::iterator itdend = pv_info.destroyed.end();

            for ( ; itc != itcend || itd != itdend; ++itc, ++itd )
            {
               std::cout << pv_info.object_name.c_str() << ": " 
                         << *itc << " Constructed" << std::endl;
               std::cout << pv_info.object_name.c_str() << ": " 
                         << *itd << " Destroyed" << std::endl;
            }
         }
      }

   protected:

   private:
   // the name of the function being traced and the channel
      static tracerInfo    pv_info;
      long int             pv_object_id;
};

#ifndef NAME_OF_TRACED_OBJECT
#define NAME_OF_TRACED_OBJECT tracerInfo objectTracer::pv_info
#endif

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

#endif //   _OBJECTTRACER_
