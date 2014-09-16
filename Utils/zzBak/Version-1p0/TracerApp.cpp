/**

  *File: TracerApp.cpp

  *Description:

   this file test drives the objects of type functionTracer and objectTracer.

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

#include "anAngle.h"

// const declarations

// create output channels for debug
outputChannel channel1;
outputChannel channel2;

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

// want to makr lines
   positionMarker pm;

//   pm << plume::off;

// open a file
   std::ofstream out("MyTestFile.txt");

   channel1.ResetStream(out);
   channel1.Off();

//   channel1.ResetStream(channel2);

// invoke a function
   Function1();
 
   pm << "About to test anAngle class" << plume::pause;
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
   std::cout <<   sin( anAngle( degree(45) ) ) << std::endl
             <<   sin( anAngle( radian(1) ) ) << std::endl;

// insert a position marker here
   pm << plume::on << " I am here." << plume::pause;

// stop the clock and display cpu time
   clock.Stop();
   clock.Display();

// write a closure message and finish the program
   std::cout << "Program " << prg_name
        << " completed successfully :-)" << std::endl;
   return 0;
}


void Function1()
{
   functionTracer ft("Function1", channel1);
   
   ft << "This is a test message" << std::endl << std::endl;
   ft << 5 << " I inserted an int!!!" << std::endl;

   char c = 'A';

   ft << "Inserted a char this time!!! " << c << std::endl;

   bool b = true;
   ft << std::boolalpha;
   ft << "inserting a bool which has value true: " << b << std::endl;
   ft << false << std::endl;
   ft << std::noboolalpha << ' ' << false << std::endl;
   Function2();
}

void Function2()
{
   functionTracer ft("Function2", channel2);

   ft << "This is inside the second function. still live." << std::endl;
}

