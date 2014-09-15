#ifndef _A2DVECTOR_
#define _A2DVECTOR_

/** 
  *File: a2DVector.h

  *Description:

   This file defines a two dimensional (3D) vector class.
   Operations such as addition, subtraction
   and dot product (denoted by *) are provided. there is no
   cross product.

   The vector components are internally stored as an array.
   The array size is dynamically allocated. Thus, this
   implementation can be used for the n-dimensional vector as
   well.
   
   this is adopted from aVector class.

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL
  *Date:    19 February 1997, 08 June 1998, 8 June 1998
            21 July 1998, 17 March 1999
  */


#include <stdio.h>
#include <iostream.h>

#include "aBoolean.h"

class a2DVector
{

   public:

   // constructors
      a2DVector();
      a2DVector(const double p[]);     // construct by passing an array
      a2DVector(double p0, double p1); // pass any two values
      a2DVector(const a2DVector& v);   // special constructor

   // assignment operators
      a2DVector& operator=(const a2DVector& v); // special assignment
      a2DVector& operator=(const double p[]);   // assign an array
      a2DVector& operator=(double p);           // assign only first elem.
                                                // (rest are zero).
   // destructor
      ~a2DVector();

   // accessor member functions
      void   SetComponents(const double p[]);      // by array
      void   SetComponents(double p0, double p1);  // explicit
      void   SetAComponent(int k, double p_val);   // sets k-th component

      double Get1stComponent() const;     // gets first
      double Get2ndComponent() const;     // gets second
      double GetAComponent(int k) const;  // gets k-th component

   // operations to return magnitude and unit vector
      double     GetMagnitude()  const;
      a2DVector  GetDirection()  const;
      a2DVector  GetUnitVector() const;

#if 0 // we will check this later
   // functions to query for nullity
      aBoolean isNullVector();
#endif

   // operator overloading defining +, - and dot
      a2DVector operator+(const a2DVector& v) const;
      a2DVector operator-(const a2DVector& v) const;

   // operator * is used both for dot and scalar product
      friend double    operator*(const a2DVector& v1, const a2DVector& v2); 
      friend a2DVector operator*(double a,            const a2DVector& v2); 
      friend a2DVector operator*(const a2DVector& v1, double a);

   // attach object to iostreams for reading and writing
      friend ostream& operator<<(ostream& os, const a2DVector& v);
      friend istream& operator>>(istream& is, a2DVector& v);

   private:
      // these are helper type of private methods
      void     CheckBounds(int elem) const;  // checks for over/underflow
      void     ComputeMagnitude();           // computes magnitude and stores

   private:
      double*  pv_p;         // the array of two components
      short    pv_size;      // the array size (fixed to 2)
      double   pv_magnitude; // stores the magnitute of the vector
      aBoolean pv_bln_true;  // we need these to compare
      aBoolean pv_bln_false; 
};

// typedef the a2DVector class to other similar
// classes such as position, velocity etc.
typedef a2DVector a2DPosition;
typedef a2DVector a2DVelocity;

typedef a2DVector are2DVectors;
typedef a2DVector are2DPositions;
typedef a2DVector are2DVelocities;

// include any inline code
#include "a2DVector.inl"

#endif // _A2DVECTOR_
