/**

  *File: vectorBasisNode.cpp

  *Description:

   this file implements the class vectorBasisNode

  *Version: 1.0

  *Dependencies:

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL

  *Date:
  */

// system includes
#include <math.h>

// local includes
#include "vectorBasisNode.h"

// const declarations

// function prototypes

// forward declarations

// begin class implementation
   ////////////////////////////////////////
   //                                      
   //    implement constructors here       
   //                                      
   //                                      

/**
   default constructor
  */
vectorBasisNode::vectorBasisNode()
   : pv_v1( aVector(1.0, 0.0, 0.0) ),
     pv_v2( aVector(0.0, 1.0, 0.0) ),
     pv_v3( aVector(0.0, 0.0, 1.0) )
{
// empty
}


vectorBasisNode::vectorBasisNode(const aVector& v1,
                                 const aVector& v2,
                                 const aVector& v3)
   :  pv_v1( v1.GetUnitVector() ), 
      pv_v2( v2.GetUnitVector() ), 
      pv_v3( v3.GetUnitVector() )
{
   double coplanarity = v1 * (v2 ^ v3);

   if ( fabs(coplanarity) <= 1.0e-14 )
   {
      throw "Exception. The vectors are coplanar. No basis possible!";
   }
}

/**
   copy constructor
  */
vectorBasisNode::vectorBasisNode(const vectorBasisNode& vb_node)
{
   throw "Exception. Copy constructor for vectorBasisNode invoked!";
}

   ////////////////////////////////////////
   //                                      
   //    implement assignment operators    
   //                                      
   //                                      

vectorBasisNode& vectorBasisNode::operator=(const vectorBasisNode& vb_node)
{
   throw "Exception. Assignment on vectorBasisNode invoked!";
   return *this;
}

   ////////////////////////////////////////
   //                                      
   //    implement the destructor          
   //                                      
   //                                      

vectorBasisNode::~vectorBasisNode()
{
// empty
}

   ////////////////////////////////////////////
   //                                          
   //   implement other member functions here  
   //                                          
   //                                          

/**
   this function sets the elements of the basis to new basis
  */
void vectorBasisNode::Set( const aVector& v1,
                           const aVector& v2,
                           const aVector& v3 )
{
   double coplanarity = v1 * (v2 ^ v3);

   if ( fabs(coplanarity) <= 1.0e-14 )
   {
      throw "Exception. The vectors are coplanar. No basis possible!";
   }

   pv_v1 = v1.GetUnitVector();
   pv_v2 = v2.GetUnitVector();
   pv_v3 = v3.GetUnitVector();
}


/**
   this function transforms a given vector in the old basis
   to the new basis
  */
aVector vectorBasisNode::ToNew(const aVector& v_old) const
{
   return aVector( v_old * pv_v1, v_old * pv_v2, v_old * pv_v3 );
}


/**
   this function transforms a given vector in the new basis
   to the old basis
  */
aVector vectorBasisNode::ToOld(const aVector& v_new) const
{
   double p0, p1, p2;

   p0 = v_new(0) * pv_v1(0) + v_new(1) * pv_v2(0) + v_new(2) * pv_v3(0);
   p1 = v_new(0) * pv_v1(1) + v_new(1) * pv_v2(1) + v_new(2) * pv_v3(1);
   p2 = v_new(0) * pv_v1(2) + v_new(1) * pv_v2(2) + v_new(2) * pv_v3(2);

   return aVector(p0, p1, p2);
}

/**
   output
  */
void vectorBasisNode::Print(ostream& os)
{
   os << "{" << pv_v1 << endl
      << " " << pv_v2 << endl
      << " " << pv_v3 << "}";
}


void vectorBasisNode::Print(std::ostream& os)
{
   os << "{" << pv_v1 << std::endl
      << " " << pv_v2 << std::endl
      << " " << pv_v3 << "}";
}

