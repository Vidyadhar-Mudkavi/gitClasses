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
#include "myException.h"   // my test class

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
   catch (myException e)
   {
      std::cout << e << std::endl;
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

   override the Append and Prepend functions and provide a conversion operator.
  */

// the following function throws an exception
void BadFunction(int i)
{
   anException e;
   e << "Exception raised by Bad Function." << std::endl
     << " exception occrred when evaluating something" << std::endl;
   e << " the value of int is : " << i << std::endl;

   e << " there is a double of " << 3.14156 << std::endl
     << " and a float of " << 4.15f << std::endl;

   myException mye;

   mye << "I have thrown the derived exception!!!!!" << std::endl;
   mye.Append();  // do this manually!
   if ( i == 5 )
   {
      //nal::Throw(mye);
      throw mye;
   }
}

#if 0
      // tell the compiler as to how to convert this object to anException
      operator anException() {
         std::cout << "Now the object is being converted!" << std::endl;
         Append();
         return anException( Convert() );
      }
#endif

#if 0
      // the print function does everything
      void Print(std::ostream& os) {
         pv_message += "Exception raised!";
         pv_message += "\n";

         os << pv_message.c_str() << std::endl
            << " This message is an additional behaviour!!" << std::endl
            << " exit code is: " << pv_i << std::endl;
      }
#endif
