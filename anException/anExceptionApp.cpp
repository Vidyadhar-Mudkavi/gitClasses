/**

  *File: anExceptionApp.cpp

  *Description:

   this file test drives objects of type anException
   defined in file anException.h

  *Version: 1.0

  *Dependencies:

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL

  *Date:
  */

// system includes
//#include <iostream.h>
#include <iostream>
#include <strstream>

// local includes
#include "exceptions.h"
#include "cpuClock.h"

// const declarations

// function prototypes
void BadFunction(int i);

// forward declarations

int main(int argc, char* argv[])
{
// store the invoking program name
   char* prg_name = argv[0];

// create an object of cpuClock and start it
   cpuClock clock;
   clock.Start();

// call a bad function
   try
   {
      BadFunction(5);
   }
   catch (anException e)
   {
      std::cout << e << std::endl;
   }

// stop the clock and display cpu time
   clock.Stop();
   clock.Display();

// write a closure message and finish the program
   std::cout << "Program <"
             << prg_name
             << "> completed successfully :-)"
             << std::endl;
   return 0;
}

/**
   we may, if need be, derive our own exception class from the
   exceptionNode and override the Print function. this is
   demonstrated here.

  */

class myExcept : public anException
{
   public:
      myExcept()
      {
         Header()  << "********************************" << std::endl
                   << "  This is a start message" << std::endl;
         Trailer() << "  This is a end  message" << std::endl
                   << "********************************" << std::endl;
      }

   protected:
   private:
};

// the following function throws an exception
void BadFunction(int i)
{
   myExcept e;
   e << "I have thrown the derived exception!!!!!" << std::endl;
   e << "Exception raised by Bad Function." << std::endl
     << " exception occrred when evaluating something" << std::endl;
   e << " the value of int is : " << i << std::endl;

   e << " there is a double of " << 3.14156 << std::endl
     << " and a float of " << 4.15f << std::endl;


   if ( i == 5 )
   {
      plume::Throw(e);
   }
}
