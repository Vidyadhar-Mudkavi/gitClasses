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

   in this version (1.3), we get rid of accessor methods such as
   Get1stComp etc and use the [] operator for both set/get
   operations.

   also, the options file is finetuned.

   in this version (1.4), most of the friend functions are made member
   functions. try not to have too many friends!

   the version 1.5 uses the handle class, i.e., this file is
   really a handle to an underlying class. 

   since use counting is used, and there appears to be a whole 
   lot of debate on what the handle should do when the object is
   written to, we introduce () operator to purely read the element.
   thus, the class user should use v(i) when the r-value is really
   what is needed and use v[i] when l-value is intended. one can
   still use v[i] as r-value, but it will be more expensive to do so.

  *Version: 1.5

  *Dependencies:
   aBoolean

  *Throws: 
	char* -- when bounds are exceeded.

  *IMPORTANT NOTE: The precedence of ^ is very low and therefore
         expressions involving ^ must be properly
         paranthesised.

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL

  *Date:    19 February 1997, 08 June 1998, 8 June 1998
            21 July 1998
            20 April 1999 (conversion to canonical form)
			06 October 1999 (handle class introduced)
  */

// system includes
#include <iostream>

// local includes
// include our aBoolean only if needed
#if defined(_MSC_VER) && (_MSC_VER < 1100)   // spaces matter!!
#  include "aBoolean.h"
#endif

#include "vectorOptions.h"
#include "useCount.h"

// const declarations

// function prototypes

// forward declarations
class vectorNode;

// begin class declaration
class aVector
{
   friend class vectorNode;
   friend aVector operator*(double a, const aVector& v2); 
   friend aVector operator*(double a, const vectorNode& v2); 

// attach object to iostreams for reading and writing
   friend std::ostream& operator<<(std::ostream& os, const aVector& v);
   friend std::istream& operator>>(std::istream& is, aVector& v);

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

   // accessor methods  (copies on write)
      double& operator[](int index);   // for component-wise in/out
      void SetComponents(double p0, 
                         double p1, 
                         double p2);  // set entire vector in one go

   // read only accessor
	   double operator()(int index) const;

   // operations to return magnitude and unit vector
      double   GetMagnitude()  const;
      aVector  GetDirection()  const;
      aVector  GetUnitVector() const;

   // functions to query for nullity
      bool isNull();

   // operator overloading defining +, - dot and cross products
      aVector operator+(const aVector& v2) const;
      aVector operator-(const aVector& v2) const; 

   // operator * is used both for dot and scalar product
      double  operator*(const aVector& v2) const;
      aVector operator*(double a) const;
   // friend  aVector operator*(double a, const aVector& v2); 

   // provide an operator to divide by a scalar
      aVector operator/(double a) const;

   // operator ^ is used for cross product. note that ^ has
   // very low precedence and hence parethesise properly
      aVector operator^(const aVector& v2) const;

   // a method which prints all the options that have been set
      void DisplayOptions(std::ostream& out=std::cout) const;

#if 0
   // for diagnostics
      int GetNoOfObjects();
#endif
   protected:

   private:
      aVector(vectorNode* vc); // convert pointers to this
      vectorNode*  pv_vec;     // points to underlying object
	   useCount     pv_uc;
};

// include any inline code here

// typedef the aVector class to aPosition for ease of use
                              //                 
typedef aVector aPosition;    //      \\^//      
typedef aVector aVelocity;    //     o(!_!)o     
typedef aVector areVectors;   // __m__  o  __m__ 
                              //                 
#endif //_AVECTOR_
