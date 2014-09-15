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

   cout << "Default basis constructed (vb): " << vb << endl;

   aVector v1, v2, v3;

   v1 = aVector(5.23, 1.34, 1.45);
   v2 = aVector(2.23, 2.34, 2.45);
//   v3 = aVector(3.23, 3.34, 3.45);

   v3 = v1^v2;
   v2 = v3^v1;

   cout << "Coplanarity: " << v1*(v2^v3) << endl;
   try
   {
      vb.Set(v1, v2, v3);

      cout << "Basis set to three new vectors (vb): " << vb << endl;

      aVectorBasis vb2 = vb;

      cout << "This basis (vb2): " << endl
           << vb2 << " is a copy of" << endl
           << "           (vb ): " << endl
           << vb  << endl;


      v1 = aVector(22.23, 22.34, 22.45);

      cout << "v1 and v2 are: " << endl
           << v1 << endl
           << v2 << endl;

      v3 = v1^v2;
      v2 = v3^v1;

      cout.precision(16);
      cout << "v1, v2 and v3 are: " << endl
           << v1 << endl
           << v2 << endl
           << v3 << endl;

      vb2.Set(v1, v2, v3);
      cout << "vb2 is set to:    " << endl
           << vb2 << endl
           << "vb  is unchanged: " << endl
           << vb << endl;

   // now try some transformation (rotate by 45 degrees about z axis
      v1 = aVector( 1.0, 1.0, 0.0);
      v2 = aVector(-1.0, 1.0, 0.0);
      v3 = aVector( 0.0, 0.0, 1.0);
      aVectorBasis vb2d(v1, v2, v3);

      v1 = aVector(0.0, 1.0, 0.0);  // the old y axis
      v2 = vb2d.ToNew(v1);

      cout << "on transformation:    " << v2 << endl;
      v2 = vb2d.ToOld(v2);
      cout << "on transforming back: " << v2 << endl;

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
      cout << "vector before transformation is: " << endl
           << "    " << v4 << endl;

      v4 = vb.ToNew(v4);
      cout << "vector after  transformation is: " << endl
           << "    " << v4 << endl;

   // transform back the same vector
      v4 = vb.ToOld(v4);
      cout << "vector after  inverse transformation is: " << endl
           << "    " << v4 << endl;

   // now take e1, e2 and e3 and transform them into the new basis
   // this gives us three new vectors (as seen from the new basis).
   // let this form a newer basis. dump the new basis and the newer
   // basis and see what they are. note that newer basis is the
   // OLD basis

   // first dump the new basis
      cout << endl
           << "The new basis is" << endl
           << vb << endl;
   // now get the newer basis
      v1 = vb.ToNew( aVector( 1.0, 0.0, 0.0 ) );   // e1
      v2 = vb.ToNew( aVector( 0.0, 1.0, 0.0 ) );   // e2
      v3 = vb.ToNew( aVector( 0.0, 0.0, 1.0 ) );   // e3

      vb.Set(v1, v2, v3);

      cout << endl
           << "The newer basis is" << endl
           << vb << endl;
   }
   catch (char* s)
   {
      cout << s << endl;
   }

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
