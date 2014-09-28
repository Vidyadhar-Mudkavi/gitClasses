/**

  *File: useCounttst.cpp

  *Description:

   this file test drives objects of type useCount
   defined in file useCount.h

   actually, there is no direct use for useCount objects.
   they are used as part of handles. 

   to test this out, we will use the example stated in chapter 8
   of Koenig and Moo.

  *Version: 1.0

  *Dependencies:

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL

  *Date:
  */

// system includes
#include <iostream.h>

// local includes
#include "useCount.h"
#include "cpuClock.h"

// const declarations

// function prototypes

// forward declarations

int main(int argc, char* argv[])
{
// store the invoking program name
   char* prg_name = argv[0];

// create an object of cpuClock and start it
   cpuClock clock;
   clock.Start();

// declare an object of the test class
   useCount class_var;

// declare a pointer to an object of the test class
   useCount* ptr_class_var;

// stop the clock and display cpu time
   clock.Stop();
   clock.Display();

// write a closure message and finish the program
   cout << "Program <"
        << prg_name
        << "> completed successfully :-)"
        << endl;
   return 0;
}
