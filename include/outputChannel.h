#ifndef _OUTPUTCHANNEL_
#define _OUTPUTCHANNEL_
/**

  *File: outputChannel.h

  *Description:

   this file declares class outputChannel. instances of this class
   are used by functions which can be traced (their invocation and destruction).
   the output channel class is used to direct debug output (or any other output)
   to a certain channel. 

   Ref: Ruminations on C++. Koenig and Moo, 1996. Chapter 27.

  *Version: 1.0

  *Dependencies:
   none

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL

  *Date: 10 February 2000
  */

// system includes
#include <iostream>

// local includes
// const declarations
// function prototypes
// forward declarations

// begin class declaration
class outputChannel
{
   friend class functionTracer;

   public:

   // constructors

      outputChannel(std::ostream* os = &std::cout) 
         : pv_ptr_trace_stream( os ) {
      // empty
      }

   // destructor (not necessary!)

      void Off() {                           // turns off 
         pv_ptr_trace_stream = 0;
      }

      void ResetStream(std::ostream& os) {   // resets the out stream (ptr)
         pv_ptr_trace_stream = &os;
      }

      void ResetStream(outputChannel& oc) {  // resets the out stream to another channel
         pv_ptr_trace_stream = oc.pv_ptr_trace_stream;
      }

      std::ostream& operator()() {
         return *pv_ptr_trace_stream;
      }

   protected:
   private:
   // assignment disabled
      outputChannel& operator=(const outputChannel& oc) {
         return *this;
      }

   private:
   // a pointer to the output stream
      std::ostream* pv_ptr_trace_stream;
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

#endif //_OUTPUTCHANNEL_
