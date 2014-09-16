/**

  *File: TracerApp.cpp

  *Description:

   this file test drives the objects of type functionTracer and
   traceable interface which enables one to convert an existing
   class to trace the objects created and destroyed.

  *Version: 1.0

  *Dependencies:

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL

  *Date:    10 February 2000
  */

// system includes
#include <iostream>
#include <fstream>
#include <iomanip>

// local includes
#include "cpuClock.h"
#include "functionTracer.h"
#include "outputChannel.h"
#include "positionMarker.h"
//#include "objectTracer.h"
#include "anAngle.h"

#include "tracerTest.h"
// const declarations

// global objects
// create output channels for debug
outputChannel channel1;
outputChannel channel2;

//#include "plume_aStream.h"

// function prototypes
void Function1();
void Function2();

// forward declarations

int main(int argc, char* argv[])
{
// store the invoking program name
   char* prg_name = argv[0];

// create an object of cpuClock and start it
   cpuClock clock;
   clock.Start();

// want to mark lines
   positionMarker pm;

//   pm << plume::off;

// open a file
   std::ofstream out("MyTestFile.txt");

   channel1.ResetStream(out);
//   channel1.Off();
   channel2.Off();

//   channel1.ResetStream(channel2);

// invoke a function
   Function1();
 
   pm << "About to test anAngle class";// << plume::pause;
// test out the degree, angle etc.
   anAngle alpha;
   alpha = degree(45);
   std::cout << "sin of 45 dgrees is: " << sin(alpha) << std::endl;

   pm << "alpha = degree(45) is over" << plume::ends;
   alpha = degree(90);
   std::cout << "sin of 90 dgrees is: " << sin(alpha) << std::endl;

   alpha = radian(45.0);
//   sin( degree(45) );  // error
//   sin( radian(1.0) ); // error
   std::cout << sin( anAngle( degree(45) ) ) << std::endl
             << sin( anAngle( radian(1) ) )  << std::endl;

// insert a position marker here
//**   pm << plume::off;
   pm << " I am here." << plume::pause;

   pm << "******** Testing aStream object ***********" << plume::ends;

   int i=5;
   pm << " the value of i is: " << i << plume::ends;

   plume::aStream my_s;

   my_s << "~~~~~~~~~Inserted this into the stream." << std::endl << std::ends;
   std::cout << my_s;

   my_s << "~~~~*****Now the string is different" << std::endl << std::endl;
   my_s << std::ends;
   std::cout << my_s;
   my_s << std::ends;
   std::cout << my_s;


// is the new traceable class, traceable??
#if 1
   pm << plume::ends;
   pm << "checking anotherTraceableClass **** " << plume::ends;

   anotherTraceableClass atc;

   pm << plume::pause;
#endif

#if 1
   pm << plume::ends;
   pm << "checking yetAnotherTraceableClass **** " << plume::ends;

   yetAnotherTraceableClass yatc;
   yetAnotherTraceableClass yatc1;
   yetAnotherTraceableClass yatc2;
 
   pm << plume::pause;
#endif


#if 0 // turn off object tracing for the moment
// now let us test object tracing
   traceableClass tc;
   traceableClass* ptc = new traceableClass;
   traceableClass* ptca = new traceableClass[2];
   delete ptc;
   delete [] ptca;
#endif


// stop the clock and display cpu time
   clock.Stop();
   clock.Display();

// write a closure message and finish the program
   std::cout << "Program " << prg_name
             << " completed successfully :-)" << std::endl;

   return 0;
}
