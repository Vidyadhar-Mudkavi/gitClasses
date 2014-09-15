#ifndef _VECTORNODE_
#define _VECTORNODE_
/**

  *File: vectorNode.h

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

   the version 1.5 uses the handle class, i.e., this file is
   really a handle to an underlying class. 

   since use counting is used, and there appears to be a whole 
   lot of debate on what the handle should do when the object is
   written to, we introduce () operator to purely read the element.
   thus, the class user should use v(i) when the r-value is really
   what is needed and used v[i] when l-value is intended. one can
   still use v[i] as r-value, but it will be more expensive to do so.

   in version 1.7, the temporary returns are fixed.

  *Version: 1.7 "@(#) vectorNode. header. ver. 1.7. Premalatha and Vidyadhar, CTFD, NAL."

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
            November 14, 2000
  */

// system includes
#include <iostream>

// local includes
#include "vectorSwitches.h"

// const declarations

// function prototypes

// forward declarations

// begin class declaration
class vectorNode
{
   friend class aVector;

// attach object to iostreams for reading and writing
   friend std::ostream& operator<<(std::ostream& os, const aVector& v);

   public:

   protected:
   // constructors
      vectorNode();                       // default
      vectorNode(const vectorNode& v);    // copy constructor
      vectorNode(double p0, double p1,    // pass any three vals
                 double p2);            

   // assignment operator
      vectorNode& operator=(const vectorNode& v);

   // destructor
      ~vectorNode();

   // accessor methods
      double& operator[](int index);      // for component-wise in/out
      void SetComponents(double p0,       // set entire vector in one go
                         double p1, 
                         double p2);

   // operations to return magnitude and unit vector
      double   GetMagnitude()  const;
      double   GetMagnitudeSquare() const;
      aVector  GetDirection()  const;
      aVector  GetUnitVector() const;

   // functions to query for nullity
      bool isNull();

      void Normalize();       // makes the vector a unit vector

   // operator overloading defining +, - dot and cross products
      aVector operator+(const vectorNode& v2) const;
      aVector operator-(const vectorNode& v2) const; 

      void Add(const vectorNode& vn);
      void Subtract(const vectorNode& vn);

   // operator * is used both for dot and scalar product
      double  operator*(const vectorNode& v2) const;
      aVector operator*(double a) const;
   // friend  aVector operator*(double a, const vectorNode& v2); 

   // provide an operator to divide by a scalar
      aVector operator/(double a) const;

   // operator ^ is used for cross product. note that ^ has
   // very low precedence and hence parethesise properly
      aVector operator^(const vectorNode& v2) const;

   // helper functions for bound checking and computing magnitude
      void CheckBounds(int elem) const; 
      void ComputeMagnitude();    

   // output
      void Print(std::ostream& os);

   private:
      double*     pv_p;         // the array of three components
      const short pv_size;      // the array size
      double      pv_magnitude; // stores the magnitute of the vector
      bool        pv_is_null;   // stores the nullity status of the vector

   // helpers etc
#if VECTORSWITCH_OBJECT_COUNT_ON
      static int  pv_num_vector_nodes;
      static int  GetNumVectorNodes();
#endif
};

// include any inline code here
                              //                 
                              //      \\^//      
                              //     o(!_!)o     
                              // __m__  o  __m__ 
                              //                 
#endif //_VECTORNODE_
