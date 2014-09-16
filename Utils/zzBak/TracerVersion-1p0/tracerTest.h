#ifndef _TRACERTEST_
#define _TRACERTEST_
/**

  *File: objectTracer.h

  *Description:

   this file code needs to test object and function tracing.
   it declares a few classes and function headers.

  *Version: 1.0

  *Dependencies:
   none

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL

  *Date: 22 February 2000
  */

// system includes
// local includes
//#include "traceable.h"

// const declarations
// function prototypes
// forward declarations

// begin class declaration
#if 0
class traceableClass
{
   public:
   // constructors
      traceableClass() : pv_trace("**traceableClass**") {
      // empty
      }
   // destructor
   protected:

   private:
      objectTracer pv_trace;
};
#endif

// write a class to enable interface style use
#if 0
class myTraceable
{
   public:
      myTraceable() : pv_trace("<<SomeObject>>") {
      // empty
      }

      myTraceable(char* object_name) : pv_trace(object_name)
      {
      // empty
      }

   protected:
   private:
      objectTracer pv_trace;
};
#endif


#include <string>
#include <list>
#include <iostream>

namespace eatc
{
#include "traceable.h"
};

class anotherTraceableClass : public eatc::traceable
{
   public:
      anotherTraceableClass() : eatc::traceable("anotherTraceableClass")
      {
      // empty
      }
   protected:
   private:
};


namespace eyatc
{
#include "traceable.h"
}

#if 1
class yetAnotherTraceableClass : public eyatc::traceable
{
   public:
      yetAnotherTraceableClass() : eyatc::traceable("yetAnotherTraceableClass")
      {
      // empty
      }
   protected:
   private:
};
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

#endif //   _TRACERTEST_
