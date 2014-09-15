/* vectest.cpp

   This file contains code to test the vector class.

   Authors: Vidyadhar, Premalatha; CTFD, NAL
   Date:    19 February 1997, 21 July 1998

*/

// system includes
#include <stdlib.h>
#include <iostream.h>

// local includes
#include "cpuClock.h"
#include "aVector.h"


void main(int argc, char* argv[])
{
   char* prg_name = argv[0];
   double x;

   cpuClock clock;
// start the clock
   clock.Start();

   aVector v1(0.3, 0.7, 0.4);

// check if checkbounds is working (provided CHECKBOUNDS is on)
   aVector v_test;

   v_test[0] = 1.12345678;
   v_test[1] = 2.12345678;
   v_test[2] = 3.12345678;

   cout << v_test << endl;
   cout << v_test[2] << endl;
   cout << v_test[1] << endl;
   cout << v_test[0] << endl;

   v_test[20];
   aVector v2(0.2, 0.5, 0.8), v3(0.7, 0.9, 1.0);
   aVector v4, v5, v6, v7;

   x = v1*v2;

   cout << v1 << endl;
   cout << v2 << endl;
   fprintf(stdout, "v1 . v2 = %lf\n", x);

   v4 = v1^(v2^v3);
   v5 = v2^(v3^v1);
   v6 = v3^(v1^v2);
   v7 = v4 + v5 + v6;
   cout << v7 << endl;

   cout << "Now v7 contains something.\n";
   v7 = v4;
   cout << v7 << endl;
   cout << "Now v7 must be a null vector.\n";
   v7 = (v1^(v2^v3)) + (v2^(v3^v1)) + (v3^(v1^v2));
   cout << v7 << endl;
   v4 = v1^(v2^v3);
   cout << v4 << endl;

   v5 = (v1*v3)*v2;
   cout << v5 << endl;

   v6 = (v1*v2)*v3;
   cout << v6 << endl;

   v7 = v5 - v6;
   cout << v7 << endl;

   cout << "Creating a different v7 object\n";
   v7.SetVector(0.4, 0.6, 0.9);
   cout << v7 << endl;
   cout << "Its magnitude = " << v7.GetMagnitude() << "\n";

   cout << "v5 vector is:\n";
   cout << v5 << endl;
   cout << "Its magnitude is: " << v5.GetMagnitude() << "\n";
   cout << "Storing unit vector corresponding to v7 in v5\n";
   v5 = v7.GetUnitVector();
   cout << "v5 vector NOW is changed to:\n";
   cout << v5 << endl;
   cout << "Its magnitude is: " << v5.GetMagnitude() << "\n";

   aPosition p;
   p.SetVector(0.3, 0.5, 0.7);
   cout << p << endl;

   aPosition* pp;
   pp = new aVector; // had forgotten to initialize!
   pp->SetVector(0.1, 0.9, 0.0);
   cout << *pp << endl;

   p = pp->GetUnitVector();
   cout << "Unit vector p: ";
   cout << p << endl;
   cout << "Magnitude of p is: " << p.GetMagnitude() << "\n";
   cout << "Magnitude of pp is: " << pp->GetMagnitude() << endl;

   aVector* p4;
   p4 = new aVector;
   *p4 = pp->GetUnitVector();
   cout << *p4 << endl;

// check some of the identities
   aVector a, b, c, d, e, temp, vresult;
   double result;

   a.SetVector(0.1, 0.22, 0.33);
   b.SetVector(0.47, 0.55, 0.795);
   c.SetVector(1.888, 10.9, 6.5);
   d.SetVector(0.9876, 3.5, 1.9567);
   temp.SetVector(8.1, 12.66666, 256.5879);

   e = temp.GetUnitVector();
   cout << "magnitude of e = " << e.GetMagnitude() << endl;

   vresult = a - (a*e)*e - (e^(a^e));
   cout << "First result is: \n";
   cout << vresult << endl;

   cout << "\nSecond result is: \n";
   result = (a^b)*(c^d) - (a*c)*(b*d) + (a*d)*(b*c);
   cout << result << endl;

   cout << "Third result is: \n";
   vresult = ((a^b)^(c^d)) - (c*(d^a))*b + (c*(d^b))*a;
   cout << vresult << endl;

   vresult = a;

   cout << "Fourth result is: " << endl;
   vresult = ((a^b)^(c^d)) - (a*(b^d))*c + (a*(b^c))*d;
   cout << vresult << endl;

   vresult = a;

   cout << "Fifth result is: " << endl;
   vresult = (a*(b^c))*d - (d*(b^c))*a - (a*(d^c))*b - (a*(b^d))*c;
   cout << vresult << endl;

// end the clock and print timing
   clock.Stop();
   clock.Display();
   
// finish the program with a message
   cout << "Program <" << prg_name << "> completed :-)"
        << endl;
}

