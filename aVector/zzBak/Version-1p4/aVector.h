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

   in this version, we get rid of accessor methods such as
   Get1stComp etc and use the [] operator for both set/get
   operations.

   also, the options file is finetuned.

   in this version, most of the friend functions are made member
   functions. try not to have too many friends!

  *Version: 1.4

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
      aVector();                       // default
      aVector(const aVector& v);       // copy constructor
      aVector(double p0, double p1,    // pass any three vals
              double p2);            

   // assignment operator
      aVector& operator=(const aVector& v);

   // destructor
      ~aVector();

   // accessor methods
      double& operator[](int index);   // for component-wise in/out
      void SetComponents(double p0,    // set entire vector in one go
                         double p1, 
                         double p2);

   // operations to return magnitude and unit vector
      double   GetMagnitude()  const;
      aVector  GetDirection()  const;
      aVector  GetUnitVector() const;

   // functions to query for nullity
      aBoolean isNullVector();

   // operator overloading defining +, - dot and cross products
      aVector operator+(const aVector& v2) const;
      aVector operator-(const aVector& v2) const; 

   // operator * is used both for dot and scalar product
      double  operator*(const aVector& v2) const;
      aVector operator*(double a) const;
      friend  aVector operator*(double a, const aVector& v2); 

   // operator ^ is used for cross product. note that ^ has
   // very low precedence and hence parethesise properly
      aVector operator^(const aVector& v2) const;

   // attach object to iostreams for reading and writing
      friend ostream& operator<<(ostream& os, const aVector& v);
      friend istream& operator>>(istream& is, aVector& v);

   // a method which prints all the options that have been set
      void DisplayOptions(ostream& out=cout);

   protected:
   // helper functions for bound checking and computing magnitude
      void CheckBounds(int elem) const; 
      void ComputeMagnitude();    

   private:
      double*  pv_p;         // the array of three components
      short    pv_size;      // the array size
      double   pv_magnitude; // stores the magnitute of the vector
      aBoolean pv_is_null;   // stores the nullity status of the vector
};

// include any inline code here

// typedef the aVector class to aPosition for ease of use
                              //                 
typedef aVector aPosition;    //      \\^//      
typedef aVector aVelocity;    //     o(!_!)o     
                              // --m--  o  --m-- 
                              //                 
#endif //_AVECTOR_
