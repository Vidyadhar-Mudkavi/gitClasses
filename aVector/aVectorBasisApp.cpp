/**

  *File: aVectorBasisApp.cpp

  *Description:

   this file test drives objects of type aVectorBasis
   defined in file aVectorBasis.h

  *Version: 1.0

  *Dependencies:

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL

  *Date:
  */
// version id
const char* aVectorBasisApp_id = 
   "@(#) aVectorBasisApp. application. ver. 1.0. Premalatha and Vidyadhar, CTFD, NAL.";

// system includes
#include <iostream.h>

// local includes
#include "aVectorBasis.h"
#include "aVector.h"

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

//
   int i;

// declare an object of the test class
   aVectorBasis vb;

   std::cout << "Default basis constructed (vb): " << vb << std::endl;

   aVector v1, v2, v3;

   v1 = aVector(5.23, 1.34, 1.45);
   v2 = aVector(2.23, 2.34, 2.45);
//   v3 = aVector(3.23, 3.34, 3.45);

   v3 = v1^v2;
   v2 = v3^v1;

   std::cout << "Coplanarity: " << v1*(v2^v3) << std::endl;
   try
   {
      vb.Set(v1, v2, v3);

      std::cout << "Basis set to three new vectors (vb): " << vb << std::endl;

      aVectorBasis vb2 = vb;

      std::cout << "This basis (vb2): " << std::endl
           << vb2 << " is a copy of" << std::endl
           << "           (vb ): " << std::endl
           << vb  << std::endl;


      v1 = aVector(22.23, 22.34, 22.45);

      std::cout << "v1 and v2 are: " << std::endl
           << v1 << std::endl
           << v2 << std::endl;

      v3 = v1^v2;
      v2 = v3^v1;

      std::cout.precision(16);
      std::cout << "v1, v2 and v3 are: " << std::endl
           << v1 << std::endl
           << v2 << std::endl
           << v3 << std::endl;

      vb2.Set(v1, v2, v3);
      std::cout << "vb2 is set to:    " << std::endl
           << vb2 << std::endl
           << "vb  is unchanged: " << std::endl
           << vb << std::endl;

   // now try some transformation (rotate by 45 degrees about z axis
      v1 = aVector( 1.0, 1.0, 0.0);
      v2 = aVector(-1.0, 1.0, 0.0);
      v3 = aVector( 0.0, 0.0, 1.0);
      aVectorBasis vb2d(v1, v2, v3);

      v1 = aVector(0.0, 1.0, 0.0);  // the old y axis
      v2 = vb2d.ToLocal(v1);        // vb2d.ToNew(v1);

      std::cout << "on transformation:    " << v2 << std::endl;
      v2 = vb2d.ToWorld(v2);        // ToOld(v2);
      std::cout << "on transforming back: " << v2 << std::endl;

   // now take a random vector. a random basis and transform
   // the random vector to and fro and check
   // take an orthogonal system
      v1 = aVector( 1.0, 25., 0.52 );
      v2 = aVector( 893.15, 420.35, 35.525);
//      v3 = aVector(40.5, 1200.25, 0040.125);
      v3 = v1^v2;
      v2 = v3^v1;

      aVector v4(1.225, 0.255, 0.224);

      vb.Set(v1, v2, v3);
      std::cout << "vector before transformation is: " << std::endl
           << "    " << v4 << std::endl;

      v4 = vb.ToLocal(v4);       // ToNew(v4);
      std::cout << "vector after  transformation is: " << std::endl
           << "    " << v4 << std::endl;

   // transform back the same vector
      v4 = vb.ToWorld(v4);       // ToOld(v4);
      std::cout << "vector after  inverse transformation is: " << std::endl
           << "    " << v4 << std::endl;

   // now take e1, e2 and e3 and transform them into the new basis
   // this gives us three new vectors (as seen from the new basis).
   // let this form a newer basis. dump the new basis and the newer
   // basis and see what they are. note that newer basis is the
   // OLD basis

   // first dump the new basis
      std::cout << std::endl
           << "The new basis is" << std::endl
           << vb << std::endl;
   // now get the newer basis
      v1 = vb.ToLocal( aVector( 1.0, 0.0, 0.0 ) ); // ToNew( aVector( 1.0, 0.0, 0.0 ) );   // e1
      v2 = vb.ToLocal( aVector( 0.0, 1.0, 0.0 ) ); // ToNew( aVector( 0.0, 1.0, 0.0 ) );   // e2
      v3 = vb.ToLocal( aVector( 0.0, 0.0, 1.0 ) ); // ToNew( aVector( 0.0, 0.0, 1.0 ) );   // e3

      vb.Set(v1, v2, v3);

      std::cout << std::endl
           << "The newer basis is" << std::endl
           << vb << std::endl;
   }
   catch (char* s)
   {
      std::cout << s << std::endl;
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
