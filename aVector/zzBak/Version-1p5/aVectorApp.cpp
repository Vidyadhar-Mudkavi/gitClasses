/**

  *File: aVectorApp.cpp

  *Description:

   this file test drives objects of type aVector
   defined in file aVector.h

   the class aVector is now a handle to the underlying
   vectorData. this means that there is never a need to declare a 
   pointer to vector.

  *Version: 1.5

  *Dependencies:

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL

  *Date:    19 February 1997, 21 July 1998
            22 April 1999 (conversion to canonical form)

  */

// system includes
#include <iostream>

// local includes
#include "aVector.h"
#include "cpuClock.h"

// const declarations

// function prototypes
void ModifyVector(aVector& v);
aVector ReturnObjectA(const aVector v);
aVector ReturnObjectB(aVector v);
void JustATest(const aVector v) {
   double x;
   x = v[1];   // ok to use [] since a const object.
}


// forward declarations

int main(int argc, char* argv[])
{
// store the invoking program name
   char* prg_name = argv[0];
   double x;


// create an object of cpuClock and start it
   cpuClock clock;
   clock.Start();

   aVector v1(0.3, 0.7, 0.4);

// output the options that have been set
   v1.DisplayOptions();

// check if checkbounds is working (provided CHECKBOUNDS is on)
   aVector v_test;

   v_test[0] = 1.12345678;
   v_test[1] = 2.12345678;
   v_test[2] = 3.12345678;

   v_test[2] = v_test[1];

   JustATest(v_test);

   std::cout << v_test << std::endl;
   std::cout << v_test(2) << std::endl;
   std::cout << v_test(1) << std::endl;
   std::cout << v_test(0) << std::endl;

//   v_test[20];
   aVector v2(0.2, 0.5, 0.8), v3(0.7, 0.9, 1.0);
   aVector v4, v5, v6, v7;

   x = v1*v2;

   std::cout << v1 << std::endl;
   std::cout << v2 << std::endl;
   std::cout << "v1 . v2 = " << x << std::endl;

   v4 = v1^(v2^v3);
   v5 = v2^(v3^v1);
   v6 = v3^(v1^v2);
   v7 = v4 + v5 + v6;
   std::cout << v7 << std::endl;

   std::cout << "Now v7 contains something.\n";
   v7 = v4;
   std::cout << v7 << std::endl;
   std::cout << "Now v7 must be a null vector.\n";
   v7 = (v1^(v2^v3)) + (v2^(v3^v1)) + (v3^(v1^v2));
   std::cout << v7 << std::endl;
   v4 = v1^(v2^v3);
   std::cout << v4 << std::endl;

   v5 = (v1*v3)*v2;
   std::cout << v5 << std::endl;

   v6 = (v1*v2)*v3;
   std::cout << v6 << std::endl;

   v7 = v5 - v6;
   std::cout << v7 << std::endl;

   std::cout << "Creating a different v7 object\n";
//   v7.SetComponents(0.4, 0.6, 0.9);
// instead use
   v7 = aVector(0.4, 0.6, 0.9);

   std::cout << v7 << std::endl;
   std::cout << "Its magnitude = " << v7.GetMagnitude() << "\n";

   std::cout << "v5 vector is:\n";
   std::cout << v5 << std::endl;
   std::cout << "Its magnitude is: " << v5.GetMagnitude() << "\n";
   std::cout << "Storing unit vector corresponding to v7 in v5\n";
   
   v5 = v7.GetUnitVector();
   std::cout << "v5 vector NOW is changed to:\n";
   std::cout << v5 << std::endl;
   std::cout << "Its magnitude is: " << v5.GetMagnitude() << "\n";

// have not yet tried this one.
   v5 = aVector(3.210, 4.202e01, 5.2019);
   std::cout << "v5 has been set to: " << v5 << std::endl;
   std::cout << " magnitude is: " << v5.GetMagnitude() << std::endl;

   v5 = v5.GetDirection();
   std::cout << "v5 now stores the direction (unit vector)." << std::endl;
   std::cout << "v5 now is: " << v5 << std::endl
        << " magnitude is: " << v5.GetMagnitude() << std::endl;

   v5 = aVector(1,1,1);
   std::cout << "v5 now is: " << v5 << std::endl;
   v5 = v5 + v5 + v5 + v5;
   std::cout << "after adding to itself many times v5 is: " << v5 << std::endl;
// pause here
   int dummy;
   std::cin >> dummy;

   aPosition p;
   p.SetComponents(0.3, 0.5, 0.7);
   std::cout << p << std::endl;

   aPosition* pp;
   pp = new aVector; // had forgotten to initialize!
   pp->SetComponents(0.1, 0.9, 0.0);
   std::cout << *pp << std::endl;

   p = pp->GetUnitVector();
   std::cout << "Unit vector p: ";
   std::cout << p << std::endl;
   std::cout << "Magnitude of p is: " << p.GetMagnitude() << "\n";
   std::cout << "Magnitude of pp is: " << pp->GetMagnitude() << std::endl;

   aVector* p4;
   p4 = new aVector;
   *p4 = pp->GetUnitVector();
   std::cout << *p4 << std::endl;

// check some of the identities
   aVector a, b, c, d, e, temp, vresult;
   double result;

   a.SetComponents(0.1, 0.22, 0.33);
   b.SetComponents(0.47, 0.55, 0.795);
   c.SetComponents(1.888, 10.9, 6.5);
   d.SetComponents(0.9876, 3.5, 1.9567);
   temp.SetComponents(8.1, 12.66666, 256.5879);

   e = temp.GetUnitVector();
   std::cout << "magnitude of e = " << e.GetMagnitude() << std::endl;

   vresult = a - (a*e)*e - (e^(a^e));
   std::cout << "First result is: \n";
   std::cout << vresult << std::endl;

   std::cout << "\nSecond result is: \n";
   result = (a^b)*(c^d) - (a*c)*(b*d) + (a*d)*(b*c);
   std::cout << result << std::endl;

   std::cout << "Third result is: \n";
   vresult = ((a^b)^(c^d)) - (c*(d^a))*b + (c*(d^b))*a;
   std::cout << vresult << std::endl;

   vresult = a;

   std::cout << "Fourth result is: " << std::endl;
   vresult = ((a^b)^(c^d)) - (a*(b^d))*c + (a*(b^c))*d;
   std::cout << vresult << std::endl;

   vresult = a;

   std::cout << "Fifth result is: " << std::endl;
   vresult = (a*(b^c))*d - (d*(b^c))*a - (a*(d^c))*b - (a*(b^d))*c;
   std::cout << vresult << std::endl;


// after adding handle, check the following
//   std::cout << "No of objects " << " vresult " << vresult.GetNoOfObjects() << std::endl;

   aVector v100 = aVector(1.0, 2.0, 3.0);

//   std::cout << "No of objects " << "(v100 created) "  << v100.GetNoOfObjects() << std::endl;

   aVector v101(v100);

//   std::cout << "No of objects " << "(v101 from v100 created) "  << v100.GetNoOfObjects() << std::endl;

   std::cout << "v100 and v101 are" << std::endl
        << v100 << std::endl << v101 << std::endl;

   v101[2] = v101(2) + 3.0;

//   std::cout << "No of objects " << "(v101 changed) "  << v100.GetNoOfObjects() << std::endl;

   std::cout << "only v101 changed. now they are" << std::endl
        << v100 << std::endl << v101 << std::endl;


   v101 = v100;

//   std::cout << "No of objects " << "(v101 assigned to v100) "  << v100.GetNoOfObjects() << std::endl;

   std::cout << "v101 assigned to v100. now they are" << std::endl
        << v100 << std::endl << v101 << std::endl;

   
// check how the passing and return from functions is affected
   std::cout << "Before ModifyVector call " << v100 << std::endl;
//   std::cout << "No of objects " << "(before call) "  << v100.GetNoOfObjects() << std::endl;
   ModifyVector(v100);
   std::cout << "After ModifyVector call " << v100 << std::endl;
//   std::cout << "No of objects " << "(after call) "  << v100.GetNoOfObjects() << std::endl;

   std::cout << "---------" << std::endl;
   std::cout << "calling Func A: " << std::endl;
   v101 = ReturnObjectA(v100);
//   std::cout << "(after call) "  << v100.GetNoOfObjects() << std::endl;
   std::cout << "(after call) "  << v101 << std::endl;

   std::cout << "---------" << std::endl;
   std::cout << "calling Func B: " << std::endl;
   v101 = ReturnObjectB(v100);
//   std::cout << "(after call) "  << v100.GetNoOfObjects() << std::endl;
   std::cout << "(after call) "  << v101 << std::endl;
        

// check reading in the values from input stream
   std::cout << "Type in three values: " << std::endl;
   std::cin  >> v101;
   std::cout << "After input: " << v101 << std::endl;


// this bit is from panel code. take any four vectors (in some order). 
// take average point on each segment (of a quadrilateral defined by these four)
// the average points necessarily lie in a plane, i.e., their triple scalar
// product is zero.
   aVector p0, p1, p2, p3;
   p0 = aVector(3.,   3.0,   242.0);
   p1 = aVector(23.,  31.0,  392.0);
   p2 = aVector(0.01, 1.50,  21.0);
   p3 = aVector(2.01, 11.20, 5.0e1);

   aVector p01 = (p0 + p1)/2.0;  // average of p0 and p1 etc.
   aVector p12 = (p1 + p2)/2.0;
   aVector p23 = (p2 + p3)/2.0;
   aVector p30 = (p3 + p0)/2.0;

   a = p01 - p12;
   b = p23 - p12;
   c = p30 - p23;

   double tsp = a * (b^c);

   std::cout << "The triple scalar product is: " << tsp << std::endl;

// stop the clock and display cpu time
   clock.Stop();
   clock.Display();

// write a closure message and finish the program
   std::cout << "Program " << prg_name
        << " completed successfully :-)" << std::endl;
   return 0;
}


void ModifyVector(aVector& v)
{
//   std::cout << "No of objects " << "(inside function before) "  << v.GetNoOfObjects() << std::endl;
   v[2] = v(2) + 4.0;
//   std::cout << "No of objects " << "(inside function after ) "  << v.GetNoOfObjects() << std::endl;
}


aVector ReturnObjectA(const aVector v)
{
   return aVector(v(0), v(1)+1, v(2));
}

aVector ReturnObjectB(aVector v)
{
   v[1] = v(1) + 1;
   return v;
}

