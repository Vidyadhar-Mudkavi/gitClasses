/**

  *File: orthonormalVectorBasis.cpp

  *Description:

   this file implements the class orthonormalVectorBasis

  *Version: 1.0

  *Dependencies:

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL

  *Date:
  */

// system includes

// sgi does not provide <cmath> header in place of <math.h>
#if defined(__sgi) && !defined(__GNUC__)
#  include <math.h>
#else
#  include <cmath>
#endif


// local includes
#include "orthonormalVectorBasis.h"
#include "aVector.h"

// const declarations
const char* orthonormalVectorBasis_id = 
   "@(#) orthonormalVectorBasis. implementation. ver. 1.0. Premalatha and Vidyadhar, CTFD, NAL.";

#ifndef CHECK_FOR_ORTHONORMALITY
#define CHECK_FOR_ORTHONORMALITY
#endif

// function prototypes

// forward declarations

// begin class implementation
   ////////////////////////////////////////
   //                                      
   //    implement constructors here       
   //                                      
   //                                      

/**
   default constructor. constructs a trivial basis.
  */
orthonormalVectorBasis::orthonormalVectorBasis()
   : pv_v1( aVector(1.0, 0.0, 0.0) ),
     pv_v2( aVector(0.0, 1.0, 0.0) ),
     pv_v3( aVector(0.0, 0.0, 1.0) )
{
// empty
}

orthonormalVectorBasis::orthonormalVectorBasis(const aVector& v1, 
                                               const aVector& v2, 
                                               const aVector& v3)
   :  pv_v1( v1.GetUnitVector() ), 
      pv_v2( v2.GetUnitVector() ), 
      pv_v3( v3.GetUnitVector() )
{
#  if defined (CHECK_FOR_ORTHONORMALITY)
   try
   {
      CheckForOrthonormality();
   }
   catch (char* message)
   {
      throw message;
   }
#  endif
}


/**
   a copy constructor to enable duplicating of objects
  */
orthonormalVectorBasis::orthonormalVectorBasis(const orthonormalVectorBasis& onvb)
   : pv_v1(onvb.pv_v1), pv_v2(onvb.pv_v2), pv_v3(onvb.pv_v3)
{
}

   ////////////////////////////////////////
   //                                      
   //    implement the destructor          
   //                                      
   //                                      

orthonormalVectorBasis::~orthonormalVectorBasis()
{
// empty
}

   ////////////////////////////////////////////
   //                                          
   //   implement other member functions here  
   //                                          
   //                                          


/**
   sets the basis to the given vectors
  */
void orthonormalVectorBasis::Set(const aVector& v1, 
                                 const aVector& v2, 
                                 const aVector& v3)
{
   pv_v1 = v1.GetUnitVector();
   pv_v2 = v2.GetUnitVector();
   pv_v3 = v3.GetUnitVector();

#  if defined (CHECK_FOR_ORTHONORMALITY)
   try
   {
      CheckForOrthonormality();
   }
   catch (char* message)
   {
      throw message;
   }
#  endif
}

/**
  */
void orthonormalVectorBasis::operator<<(const std::vector<aVector>& vec_arr)
{
   if ( vec_arr.size() != 3 )
   {
      throw "Exception. Input std::vector has size different from 3!";
   }

   pv_v1 = vec_arr[0].GetUnitVector();
   pv_v2 = vec_arr[1].GetUnitVector();
   pv_v3 = vec_arr[2].GetUnitVector();

#  if defined (CHECK_FOR_ORTHONORMALITY)
   try
   {
      CheckForOrthonormality();
   }
   catch (char* message)
   {
      throw message;
   }
#  endif
}

/**
  */
aVector orthonormalVectorBasis::ToLocal(const aVector& v_world) const
{
   return aVector( v_world * pv_v1, v_world * pv_v2, v_world * pv_v3 );
}

/**
  */
aVector orthonormalVectorBasis::ToWorld(const aVector& v_local) const
{
   double p0, p1, p2;

   p0 = v_local(0) * pv_v1(0) + v_local(1) * pv_v2(0) + v_local(2) * pv_v3(0);
   p1 = v_local(0) * pv_v1(1) + v_local(1) * pv_v2(1) + v_local(2) * pv_v3(1);
   p2 = v_local(0) * pv_v1(2) + v_local(1) * pv_v2(2) + v_local(2) * pv_v3(2);

   return aVector(p0, p1, p2);
}


/**
   copies this object and returns a pointer to the abstract base class
  */
abstractVectorBasisNode* orthonormalVectorBasis::Copy() const
{
   return new orthonormalVectorBasis(*this);
}


/**
  */
void orthonormalVectorBasis::Print(std::ostream& os) const
{
   os << std::endl
      << "{" << pv_v1 << std::endl
      << " " << pv_v2 << std::endl
      << " " << pv_v3 << "}";
}

/**
   checks for orthonormality
  */

void orthonormalVectorBasis::CheckForOrthonormality() const
{
// first check for coplanarity
   double coplanarity = pv_v1 * (pv_v2 ^ pv_v3);

   if ( fabs(coplanarity) <= 1.0e-14 )
   {
      throw "Exception. The vectors are coplanar. No basis possible!";
   }

// now check if the vector basis is orthonormal
// the dot products must be zero. 
   double product_12 = pv_v1 * pv_v2;
   double product_23 = pv_v2 * pv_v3;
   double product_31 = pv_v3 * pv_v1;

   if ( ( fabs(product_12) >= 1.0e-14 ) ||
        ( fabs(product_23) >= 1.0e-14 ) ||
        ( fabs(product_31) >= 1.0e-14 ) )
   {
      throw "Exception. The vectors do not form an orthonormal basis.";
   }
}
