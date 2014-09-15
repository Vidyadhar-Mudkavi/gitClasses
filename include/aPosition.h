#ifndef _APOSITION_
#define _APOSITION_

/** 
  *File: aPosition.h

  *Description:

   This file defines a three dimensional (3D) vector class.
   Operations such as addition, subtraction, cross product
   (denoted by ^) and dot product (denoted by *) are
   provided.

   The vector components are internally stored as an array.
   The array size is dynamically allocated. Thus, this
   implementation can be used for the n-dimensional vector as
   well.

  *IMPORTANT NOTE: The precedence of ^ is very low and therefore
         expressions involving ^ must be properly
         paranthesised.

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL
  *Date:    19 February 1997, 08 June 1998, 8 June 1998
            21 July 1998
  */


#include <stdio.h>
#include <iostream.h>

#include "aBoolean.h"

class aPosition
{

   public:

   // constructors
      aPosition();
      aPosition(const double p[]);     // construct by passing an array
      aPosition(double p0, double p1, 
              double p2);            // pass any three vals
      aPosition(const aPosition& v);     // special constructor

   // assignment operators
      aPosition& operator=(const aPosition& v); // special assignment
      aPosition& operator=(const double p[]); // assign an array
      aPosition& operator=(double p);         // assign only first elem.
                                            // (rest are zero).
   // destructor
      ~aPosition();

   // accessor member functions
      void   SetVector(const double p[]);
      void   SetVector(double p0, double p1, double p2);
      void   SetAComp(int k, double p_val);  // sets k-th component

      double Get1stComp() const;
      double Get2ndComp() const;
      double Get3rdComp() const;
      double GetAComp(int k) const; // gets k-th component

   // operations to return magnitude and unit vector
      double   GetMagnitude()  const;
      aPosition  GetDirection()  const;
      aPosition  GetUnitVector() const;

   // define vector operators using Java style operations
      aPosition Plus(const aPosition& v);
      aPosition Minus(const aPosition& v);

      double  Dot(const aPosition& v);
      aPosition Times(double p);
      aPosition Cross(const aPosition& v);

   // functions to query for nullity
      aBoolean isNullVector();

   // operator overloading defining +, - dot and cross products
      friend aPosition operator+(const aPosition& v1, const aPosition& v2);
      friend aPosition operator-(const aPosition& v1, const aPosition& v2); 

   // operator * is used both for dot and scalar product
      friend double  operator*(const aPosition& v1, const aPosition& v2); 
      friend aPosition operator*(double a,          const aPosition& v2); 
      friend aPosition operator*(const aPosition& v1, double a);

   // operator ^ is used for cross product. note that ^ has
   // very low precedence and hence parethesise properly
      friend aPosition operator^(const aPosition& v1, const aPosition& v2);

   // attach object to iostreams for reading and writing
      friend ostream& operator<<(ostream& os, const aPosition& v);
      friend istream& operator>>(istream& is, aPosition& v);

   private:
      // these are helper type of private methods
      void     CheckBounds(int elem) const; // checks for over/underflow
      void     ComputeMagnitude();    // computes magnitude and stores

   private:
      double*  pv_p;         // the array of three components
      short    pv_size;      // the array size
      double   pv_magnitude; // stores the magnitute of the vector
      aBoolean pv_is_null;   // stores the nullity status of the vector
      aBoolean pv_bln_true;  // we need these to compare
      aBoolean pv_bln_false; 
};

// typedef the aPosition class to aPosition for ease of use
typedef aPosition aPosition;

#endif // _APOSITION_
