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

  *Version: 1.2

  *Dependencies:
   aBoolean

  *IMPORTANT NOTE: The precedence of ^ is very low and therefore
         expressions involving ^ must be properly
         paranthesised.

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL

  *Date:    19 February 1997, 08 June 1998, 8 June 1998
            21 July 1998
            20 April 1999 (conversion to canonical form)
  */

// system includes
#include <iostream.h>

// local includes
#include "aBoolean.h"
#include "vectorOptions.h"

// const declarations

// function prototypes

// forward declarations

// begin class declaration
class aVector
{
   public:

   // constructors
      aVector();                 // default
      aVector(const aVector& v); // copy
      aVector(double p0, double p1, 
              double p2);            // pass any three vals

   // assignment operator
      aVector& operator=(const aVector& v);

   // destructor
      ~aVector();

   // accessor member functions
      void   SetVector(double p0, double p1, double p2);
      void   SetAComp(int k, double p_val);  // sets k-th component

   // index operator as an accessor (both for storage and retrieval)
      double& operator[](int index);

      double Get1stComp() const;
      double Get2ndComp() const;
      double Get3rdComp() const;
      double GetAComp(int k) const; // gets k-th component

   // operations to return magnitude and unit vector
      double   GetMagnitude()  const;
      aVector  GetDirection()  const;
      aVector  GetUnitVector() const;

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

   protected:
   // helper functions for bound checking and computing magnitude
      void CheckBounds(int elem) const; 
      void ComputeMagnitude();    

   private:
      double*  pv_p;         // the array of three components
      short    pv_size;      // the array size
      double   pv_magnitude; // stores the magnitute of the vector
      aBoolean pv_is_null;   // stores the nullity status of the vector
      aBoolean pv_bln_true;  // we need these to compare
      aBoolean pv_bln_false; 

};

// include any inline code here

// typedef the aVector class to aPosition for ease of use
                              //
typedef aVector aPosition;    //      \\^//
typedef aVector aVelocity;    //     o(!_!)o
                              // --m--  o  --m-- 
                              //         
#endif //_AVECTOR_
