/**
  *File: StreamManagerApp.cpp

  \details
   this file test drives objects of type streamManager
   defined in file streamManager.h

  \Version  1.0

  \Authors
          - Premalatha, Vidyadhar Mudkavi, CTFD, NAL
  \Date
          - 2008-05-28
  */

// version id
const char* StreamManagerApp_id = 
   "@(#) StreamManagerApp. application. ver. 1.0. Premalatha, Vidyadhar Mudkavi, CTFD, NAL.";

// system includes
#include <iostream>
#include <fstream>

// local includes
#include "cpuClock.h"
#include "anException.h"
#include "plume_streamOutputManager.h"

#include "aVector.h"

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

#if 0 // test code
   plume::streamOutputManager  class_var;
   plume::streamOutputManager* ptr_class_var;
#endif

// provide convenient i/o streams
   std::ostream& out = std::cout;
   std::istream& ein = std::cin;

   std::ofstream fout("DummyFile.dat");

// begin application
   try
   {
      plume::streamOutputManager som;
      int i = 15051968;
      som << i;
      som << std::endl;

      double f1 = 2.394832884483;
      double f2 = 3949828.3448382;

      som << f1 << "\t" << f2 << std::endl;

      aVector v1(2.0, 3.0, 4.0);

      som << "Test vector is: " << v1 << std::endl;

#if 0
      fout << "Test vector is: " << v1 << std::endl;
      fout.close();
#endif
      plume::streamOutputManager som2;
      som2 = fout;
      som2 << "Test vector is: " << v1 << std::endl;
      som2 << i << std::endl;
      som2 << f1 << "\t" << f2 << std::endl;
      fout.close();

   // wait for input
      ein >> i;
   }
   catch (anException e)
   {
      out << std::endl << e << std::endl;
   }

// stop the clock and display cpu time
   clock.Stop();
   clock.Display();

// write a closure message and finish the program
   out << std::endl << "Program <"       << prg_name
       << "> completed successfully :-)"
       << std::endl;
   return 0;
}
