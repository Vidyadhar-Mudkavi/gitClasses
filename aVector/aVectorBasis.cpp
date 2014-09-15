/**

  *File: aVectorBasis.cpp

  *Description:

   this file implements the class aVectorBasis

  *Version: 1.0

  *Dependencies:
   useCount, aVector, vectorBasisNode (handle to)

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL

  *Date: October 12, 1999
  */

// system includes

// sgi does not provide <cmath> header in place of <math.h>
#if defined(__sgi) && !defined(__GNUC__)
#  include <math.h>
#else
#  include <cmath>
#endif


// local includes
#include "aVectorBasis.h"
#include "orthonormalVectorBasis.h"
#include "aVector.h"

// const declarations
const char* aVectorBasis_id = 
   "@(#) aVectorBasis. implementation. ver. 1.0. Premalatha and Vidyadhar, CTFD, NAL.";

// function prototypes

// forward declarations

// begin class implementation
   ////////////////////////////////////////
   //                                      
   //    implement constructors here       
   //                                      
   //                                      

/**
   default constructor. builds a trivial basis
  */
aVectorBasis::aVectorBasis()
   : pv_basis( new orthonormalVectorBasis() )
{
// empty
}

/**
   this constructor builds a basis from given three vectors.

   it is assumed that the input vectors v1, v2 and v3 are not
   unit vectors in general. we compute unit vectors here.

  *Throws: char* if the vectors are coplanar.
  */
aVectorBasis::aVectorBasis( const aVector& v1, 
                            const aVector& v2,
                            const aVector& v3 )
   : pv_basis( new orthonormalVectorBasis( v1, v2, v3 ) )
{
// empty
}

/**
   this constructor allows us to return pointers to
   the underlying objects to the handle class
  */
aVectorBasis::aVectorBasis(abstractVectorBasisNode* ptr_vbn)
   : pv_basis(ptr_vbn)
{
// empty
}

/**
   copy constructor
  */
aVectorBasis::aVectorBasis(const aVectorBasis& basis)
   : pv_basis(basis.pv_basis), pv_uc(basis.pv_uc)
{
// empty
}



   ////////////////////////////////////////
   //                                      
   //    implement assignment operators    
   //                                      
   //                                      

aVectorBasis& aVectorBasis::operator=(const aVectorBasis& basis)
{
   if ( pv_uc.isAttachingTo(basis.pv_uc) )
   {
      delete pv_basis;
   }

   pv_basis = basis.pv_basis;

   return *this;
}

   ////////////////////////////////////////
   //                                      
   //    implement the destructor          
   //                                      
   //                                      

aVectorBasis::~aVectorBasis()
{
   if ( pv_uc.isOnlyInstance() )
   {
      delete pv_basis;
   }
}

   ////////////////////////////////////////////
   //                                          
   //   implement other member functions here  
   //                                          
   //                                          

/**
   the following is an accessor function. this sets the basis
   to the given vectors. 
  */
void aVectorBasis::Set(const aVector& v1, const aVector v2,
                       const aVector& v3)
{
   if ( pv_uc.makeCopy() )
   {
      pv_basis = pv_basis->Copy();
   }

   pv_basis->Set(v1, v2, v3);
}


/**
   this function is an accessor which can used like so:
      std::vector<aVector> vec_arr(3);
      vec_arr(1) = aVector(2., 3., 4.);
      // ....
      aVectorBasis vb;
      // ..
      vb << vec_arr;
  */
void aVectorBasis::operator<<(const std::vector<aVector>& v)
{
   if ( v.size() != 3 )
   {
      throw "Exception in aVectorBasis::operator<<(const std::vector<aVector>& v)";
   }

   if ( pv_uc.makeCopy() )
   {
      pv_basis = pv_basis->Copy();
   }

   pv_basis->Set( v[0], v[1], v[2] );
}
  
/**
   this function transforms a given vector in the old basis (world coord system)
   to the new basis, i.e., the local system
  */
aVector aVectorBasis::ToLocal(const aVector& v_world) const
{
   return pv_basis->ToLocal(v_world);
}

/**
   this function transforms a given vector in the local basis to the
   old basis, i.e., the world system (as far as this basis is concerned).
  */
aVector aVectorBasis::ToWorld(const aVector& v_local) const
{
   return pv_basis->ToWorld(v_local);
}

/**
   
  */
/**
   this function is used to display the basis. it simply writes 
   to the  output stream.
  */
std::ostream& operator<<(std::ostream& os, const aVectorBasis& basis)
{
   basis.pv_basis->Print(os);
   return os;
}


