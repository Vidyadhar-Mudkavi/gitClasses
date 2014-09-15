#ifndef _AVECTORBASIS_
#define _AVECTORBASIS_
/**

  *File: aVectorBasis.h

  *Description:

   this file declares class aVectorBasis.

   objects of this class represent a triad of vectors (3D) that form
   a basis. the class provides means to transform a given vector in the
   old basis to the new one and vice versa.

   the basis is initialized with three arbitrary non-coplanar vectors.
   these vectors define a new basis. however, if the three vectors
   are orthonormal, then we are dealing with transformations involving
   Cartesian vectors.

   this class is a handle to a basis of vectors. by default, the handle
   is attached to the orthonormal basis. initial implementation
   checks if the given vectors are mutually orthogonal or not. if not,
   an exception is thrown.

   if the object is constructed without any vectors, then the basis
   defaults to a trivial triad, i.e., the
   three basis vectors are the same as the old one. this means that
   they are simply e1, e2 and e3.

   the basis objects can be assigned to, copied from, passed into etc.
   but, one cannot individually set a single vector of the basis at a
   time.

   the basis formed from given vectors v1, v2 and v3 is termed as the
   new basis and the basis in which v1, v2 and v3 themselves are defined
   is termed as the old basis. the functions used to transform from "old"
   to "new" and vice-versa use this notion of new and old.

   the basis can be set using Set member function or by using the
   opertor << with the operand being the std::vector of exactly three
   element each of which is aVector.

  *Version: 1.0
   no general transformation is handled.

  *Dependencies:
   aVector, useCount

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL

  *Date:    15 October 1999
  */

// system includes
#include <iostream>

// stl includes
#include <vector>

// local includes
#include "useCount.h"

// const declarations

// function prototypes

// forward declarations
class aVector;
class abstractVectorBasisNode;

// begin class declaration
class aVectorBasis
{
// output
   friend std::ostream& operator<<(std::ostream& os, const aVectorBasis& vb);

   public:

   // constructors
      aVectorBasis(); // default
      aVectorBasis(const aVector& v1, 
                   const aVector& v2,     // builds the basis from
                   const aVector& v3);    // v1, v2 v3.

      aVectorBasis(const aVectorBasis& basis);

   // assignment operator
      aVectorBasis& operator=(const aVectorBasis& basis);

   // destructor
      ~aVectorBasis();

   // other functionality here
   // accessor functions
      void operator<<(const std::vector<aVector>& basis_components);
      void Set(const aVector& v1, const aVector v2,
               const aVector& v3);

   // functions to transform a given vector
      aVector ToNew(const aVector& v_old) const;
      aVector ToOld(const aVector& v_new) const;

   protected:

   private:
   // constructor for converting pointer
      aVectorBasis(abstractVectorBasisNode* ptr_vbn);

      abstractVectorBasisNode* pv_basis;
      useCount                 pv_uc;
};

// include any inline code here

/**
   declare any typedef statements here
     ex: typedef aVortex areVortices;
   so that we can declare
     areVortices v1, v2, v3;
  */
                              //                 
                              //      \\^//      
                              //     o(!_!)o     
                              // __m__  o  __m__ 
                              //                 

#endif //_AVECTORBASIS_
