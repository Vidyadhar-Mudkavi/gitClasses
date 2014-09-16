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

// local includes
#include "outputChannel.h"

// const declarations
// function prototypes
// forward declarations

// begin class declaration
class objectTracer
{
   public:

   // constructors
   // assignment and default disabled
      objectTracer& operator=(const objectTracer& ft) {
         return *this;
      }

      objectTracer() {}

      objectTracer(char* name, outputChannel& oc) 
         : pv_function_name( name ), pv_ptr_output_channel( &oc ) {
         if ( pv_ptr_output_channel->pv_ptr_trace_stream )
         {
            *pv_ptr_output_channel->pv_ptr_trace_stream << " Entering function " 
                                                        << "<" << name
                                                        << ">" << std::endl;
         }
      }

   // destructor
      ~objectTracer() {
         if ( pv_ptr_output_channel->pv_ptr_trace_stream )
         {
            *pv_ptr_output_channel->pv_ptr_trace_stream << " Leaving function " 
                                                        << "<" 
                                                        << pv_function_name.c_str()
                                                        << ">" << std::endl;
         }
      }

   protected:

   private:

   private:
   // the name of the function being traced and the channel
      const std::string pv_function_name;
      outputChannel* pv_ptr_output_channel;
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

#endif //   _OBJECTTRACER_
