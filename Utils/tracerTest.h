#ifndef _TRACERTEST_
#define _TRACERTEST_
/**

  *File: tracerTest.h

  *Description:

   this file contains a couple of classes that are turned into
   traceable classes by simply deriving them from the template
   class traceable. there two types of uses shown.

  *Version: 1.1 "@(#) tracerTest. header. ver. 1.1. Premalatha and Vidyadhar, CTFD, NAL."

  *Dependencies:
   none

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL

  *Date: February 22, 2000
         February 15, 2001
  */

// system includes
// local includes
#include "traceable.h"

// const declarations
// function prototypes
// forward declarations

// begin class declaration
class anotherTraceableClass;
typedef traceable<anotherTraceableClass> traceableATC;   // for brevity

class anotherTraceableClass : public traceableATC
{
   public:
      anotherTraceableClass() : traceableATC("anotherTraceableClass")
      {
      // empty
      }
   protected:
   private:
};


// this is another class showing a slightly different type of
// use.
class yetAnotherTraceableClass;
typedef traceable<yetAnotherTraceableClass> traceableYATC;

class yetAnotherTraceableClass : public traceableYATC
{
   public:
      yetAnotherTraceableClass()
      {
         SetTypeName("yetAnotherTraceableClass");
      }
   protected:
   private:
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

#endif   // _TRACERTEST_
