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

  *Version: 1.0 "@(#) outputChannel. header. ver. 1.0. Premalatha and Vidyadhar, CTFD, NAL."


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
      inline outputChannel(std::ostream* ptr_os = &std::cout);

   // basic functionality
      inline void Off();
      inline void ResetStream(std::ostream& os);
      inline void ResetStream(outputChannel& oc);
      inline std::ostream& operator()();

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
  *Purpose: construction. essentially sets the internal
      stream to the input stream or to the default
      std::cout.
  */
inline outputChannel::outputChannel(std::ostream* ptr_os) 
   : pv_ptr_trace_stream( ptr_os ) 
{
// empty
}


/**
  *Purpose: turns off the output
  */
inline void outputChannel::Off() 
{
   pv_ptr_trace_stream = 0;
}

/**
  *Purpose: resets the output stream to a new stream
  */
inline void outputChannel::ResetStream(std::ostream& os) 
{
   pv_ptr_trace_stream = &os;
}

/**
  *Purpose: resets the output stream to another output channel
  */
inline void outputChannel::ResetStream(outputChannel& oc) 
{
   pv_ptr_trace_stream = oc.pv_ptr_trace_stream;
}

/**
  *Purpose: provides access to the stream into which output
      can be inserted.
  */
inline std::ostream& outputChannel::operator()() 
{
   return *pv_ptr_trace_stream;
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

#endif //_OUTPUTCHANNEL_
