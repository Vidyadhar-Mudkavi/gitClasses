#ifndef _AVECTOR_
#define _AVECTOR_

/** 
  *File: aVector.h

  *Description:

   This file defines a three dimensional (3D) vector class.
   Operations such as addition, subtraction, cross product
   (denoted by ^) and dot product (denoted by *) are
   provided.

   The vector components are internally stored as an array.
   The array size is dynamically allocated. Thus, this
   implementation can be used for the n-dimensional vector as
   well.

  *Version: 1.0

  *Dependencies:
   aBoolean

  *IMPORTANT NOTE: The precedence of ^ is very low and therefore
         expressions involving ^ must be properly
         paranthesised.

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL
  *Date:    19 February 1997, 08 June 1998, 8 June 1998
            21 July 1998
  */


// system includes
#include <stdio.h>
#include <iostream.h>

// local includes
#include "aBoolean.h"


class aVector
{

   public:

   // constructors
      aVector();
      aVector(const double p[]);     // construct by passing an array
      aVector(double p0, double p1, 
              double p2);            // pass any three vals
      aVector(const aVector& v);     // special constructor

   // assignment operators
      aVector& operator=(const aVector& v); // special assignment
      aVector& operator=(const double p[]); // assign an array
      aVector& operator=(double p);         // assign only first elem.
                                            // (rest are zero).
   // destructor
      ~aVector();

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
      aVector  GetDirection()  const;
      aVector  GetUnitVector() const;

   // define vector operators using Java style operations
      aVector Plus(const aVector& v);
      aVector Minus(const aVector& v);

      double  Dot(const aVector& v);
      aVector Times(double p);
      aVector Cross(const aVector& v);

   // functions to query for nullity
      aBoolean isNullVector();

   // operator overloading defining +, - dot and cross products
      friend aVector operator+(const aVector& v1, const aVector& v2);
      friend aVector operator-(const aVector& v1, const aVector& v2); 

   // operator * is used both for dot and scalar product
      friend double  operator*(const aVector& v1, const aVector& v2); 
      friend aVector operator*(double a,          const aVector& v2); 
      friend aVector operator*(const aVector& v1, double a);

   // operator ^ is used for cross product. note that ^ has
   // very low precedence and hence parethesise properly
      friend aVector operator^(const aVector& v1, const aVector& v2);

   // attach object to iostreams for reading and writing
      friend ostream& operator<<(ostream& os, const aVector& v);
      friend istream& operator>>(istream& is, aVector& v);

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

// typedef the aVector class to aPosition for ease of use
typedef aVector aPosition;

#endif // _AVECTOR_
