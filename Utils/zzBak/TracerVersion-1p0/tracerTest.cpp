/**

  *File: tracerTest.cpp

  *Description:

   this file implements functions and classes declared in tracerTest.h file.

  *Version: 1.0

  *Dependencies:

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL

  *Date:    22 February 2000
  */

// system includes
// local includes
#include "functionTracer.h"
#include "tracerTest.h"
//#include "objectTracer.h"

// const declarations
// function prototypes
// forward declarations

//NAME_OF_TRACED_OBJECT = "Prema_traceableClass";

extern outputChannel channel1;
extern outputChannel channel2;

void Function1();
void Function2();

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

   ft << "This is inside the second function. still live.";// << std::endl;
}


#include <list>
#include <string>
#include <iostream>

namespace eatc
{
#include "traceable.cpp"
}

namespace eyatc
{
#include "traceable.cpp"
}
