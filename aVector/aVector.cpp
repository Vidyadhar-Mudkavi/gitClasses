/**

  *File: aVector.cpp

  \brief
   - This file contains the implementation code for some of the overloaded
     operators for the three dimensional vector class.
     The operators overloaded are scalar multiplication,
     vector dot and cross products.

  *IMPORTANT NOTE: The precedence of ^ is very low and therefore
         expressions involving ^ must be properly
         paranthesised.

  *Comment:  commment. dfsfdsafjas

  \version  1.7

  *Dependencies:
   aBoolean

  \authors
         -  Premalatha, Vidyadhar Mudkavi, CTFD, NAL

  \date    
         -  19 February 1997
         -  21 July 1998
         -  20 April 1999 (conversion to canonical form)
         -  November 14, 2000
  */

// system includes

// sgi does not provide <cmath> header in place of <math.h>
#if defined(__sgi) && !defined(__GNUC__)
#  include <math.h>
#else
#  include <cmath>
#endif

// local includes
#include "aVector.h"
#include "vectorNode.h"

// const declarations
const char* aVector_id = 
   "@(#) aVector. implementation. ver. 1.7. Premalatha and Vidyadhar, CTFD, NAL.";

// function prototypes
// forward declarations
// begin class implementation

// static data initialization
#if VECTORSWITCH_OBJECT_COUNT_ON
int aVector::pv_num_vectors = 0;
#endif
   ////////////////////////////////////////
   //                                      
   //    implement constructors here       
   //                                      
   //                                      

/**
  *Purpose:
      this defines a default behaviour. the vector is set
      to a unit vector with components (1,0,0).
      note that the size is always 3.
  */
aVector::aVector()
   : pv_vec(new vectorNode())
{
#if VECTORSWITCH_OBJECT_COUNT_ON
   ++pv_num_vectors;
#endif
}

/**
  *Purpose:
      this constructor builds the vector with the values passed
      (the components in the stated order)
  */
aVector::aVector(double p0, double p1, double p2)
   : pv_vec( new vectorNode(p0, p1, p2) )
{
#if VECTORSWITCH_OBJECT_COUNT_ON
   ++pv_num_vectors;
#endif
}

/**
  *Purpose:
      this constructor allows us to return pointers to
      the underlying object and convert it to the handle.
  */
aVector::aVector(vectorNode* vc)
   : pv_vec(vc)
{
#if VECTORSWITCH_OBJECT_COUNT_ON
   ++pv_num_vectors;
#endif
}

/**
  *Purpose:
      this constructor builds aVector from vectorNode
  */
aVector::aVector(vectorNode& vn)
   : pv_vec( &vn )
{
#if VECTORSWITCH_OBJECT_COUNT_ON
   ++pv_num_vectors;
#endif
}

/**
  *Purpose:
      the special constructor
  */
aVector::aVector(const aVector& v)
   : pv_uc(v.pv_uc), pv_vec(v.pv_vec)
{
#if VECTORSWITCH_OBJECT_COUNT_ON
   ++pv_num_vectors;
#endif
}

   ////////////////////////////////////////
   //                                      
   //    implement assignment operators    
   //                                      
   //                                      

/**
   assigns a vector with another vector.
  */
aVector& aVector::operator=(const aVector& v)
{
   if ( pv_uc.isAttachingTo(v.pv_uc) )
   {
      delete pv_vec;
   }

   pv_vec = v.pv_vec;
   return *this;
}

   ////////////////////////////////////////
   //                                      
   //    implement the destructor          
   //                                      
   //                                      

aVector::~aVector()
{
   if ( pv_uc.isOnlyInstance() )
   {
      delete pv_vec;
   }

#if VECTORSWITCH_OBJECT_COUNT_ON
   --pv_num_vectors;
#endif
}

   ////////////////////////////////////////////
   //                                          
   //   implement other member functions here  
   //                                          
   //                                          

/**
  *Purpose: 
      this function determines if the vector is a null vector.
      this is rather tricky. we cannot be sure that the 
      computed magnitude is exactly zero (it never is). it is
      only numerically zero.

      best option, if available, is to use some system defined
      exception condition for division by "zero". if it were
      available, then we could test the computed magnitude
      against such a condition. but it appears that none exists!

      currently we resort to using some hardwired number to
      detect nullity. we will try to put this number as a
      product of some scale factor and numerical epsilon 
      generated by the machineConstants class.
  */
bool aVector::isNull()
{
   return pv_vec->isNull();
}


/**
   accessor member functions
  */

/**
  *Purpose:
      sets the vector to new components.
  */
void aVector::SetComponents(double p0, double p1, double p2)
{
   if ( pv_uc.makeCopy() )
   {
      pv_vec = new vectorNode(p0, p1, p2);
      return;
   }

   pv_vec->SetComponents(p0, p1, p2);
}

/**
  *Purpose:
      the index operator is the general method for both setting
      and getting a component by its position. the positioning follows
      the c/c++ array notation, i.e., index zero refers to the first
      component.
  */
double& aVector::operator[](int i)
{
   if ( pv_uc.makeCopy() )
   {
      pv_vec = new vectorNode(*pv_vec);
   }

   return (*pv_vec)[i];
}

double aVector::operator[](int i) const
{
   return (*pv_vec)[i];
}

/**
  *Purpose:
      the index operator to read an element. we use the fortran
      syntax.
  */
double aVector::operator()(int i) const
{
   return (*pv_vec)[i];
}

/**
  *Purpose:
      this function modifies the vector and makes into a unit vector
  */
void aVector::Normalize()
{
   if ( pv_uc.makeCopy() )
   {
      pv_vec = new vectorNode(*pv_vec);
   }
   pv_vec->Normalize();
}

/**
  *Purpose:
      returns the magnitude of the vector
  */
double aVector::GetMagnitude() const
{
   return pv_vec->GetMagnitude();
}

double aVector::GetMagnitudeSquare() const
{
   return pv_vec->GetMagnitudeSquare();
}

/**
  *Purpose:
      return the direction (unit vector)
      later add methods to check for underflow or
      numerical zero. we may need to borrow ideas
      from the book by kahaner, moler and nash.
  */
aVector aVector::GetDirection() const
{
   return pv_vec->GetDirection();
}

/**
  *Purpose:
      this is identical to the GetDirection function
  */
aVector aVector::GetUnitVector() const
{
   return pv_vec->GetUnitVector();
}

/**
  *Purpose:
      adds two vectors
  */
aVector aVector::operator+(const aVector& v2) const
{
   return pv_vec->operator+(*v2.pv_vec);
}

aVector& aVector::operator+=(const aVector& v)
{
   if ( pv_uc.makeCopy() == true )
   {
      pv_vec = new vectorNode( *pv_vec );
   }

   pv_vec->Add( *v.pv_vec );
   return *this;
}

aVector& aVector::operator-=(const aVector& v)
{
   if ( pv_uc.makeCopy() == true )
   {
      pv_vec = new vectorNode( *pv_vec );
   }

   pv_vec->Subtract( *v.pv_vec );
   return *this;
}

/**
  *Purpose:
      subtracts two vectors
  */
aVector aVector::operator-(const aVector& v2) const
{
   return pv_vec->operator-(*v2.pv_vec);
}

      ///////////////////////////////////////
      //
      // implement such functions as vector
      // dot product, cross product etc.
      //
/**
  *Purpose:
      computes the vector dot product (denoted by *)
  */
double aVector::operator*(const aVector& v2) const
{
   return pv_vec->operator*(*v2.pv_vec);
}

/**
  *Purpose:
      computes the scalar product of a vector (returns
      a vector). this has to be a friend function
  */
aVector operator*(double alpha, const aVector& v1)
{
   return v1.operator*(alpha);
}

/**
  *Purpose:
      computes the scalar product of a vector (the scalar
      is a post multiplier)
  */
aVector aVector::operator*(double alpha) const
{
   return pv_vec->operator*(alpha);
}

/**
  *Purpose:
      computes the scalar division of a vector
  */
aVector aVector::operator/(double alpha) const
{
   return pv_vec->operator/(alpha);
}

/**
  *Purpose:
      computes the cross product of a vector. this
      operator has a very low precedence and care must be
      taken while using it.
  */
aVector aVector::operator^(const aVector& v2) const
{
   return pv_vec->operator^(*v2.pv_vec);
}

/**
  *Purpose:
      writes the vector to an output stream
  */
std::ostream& operator<<(std::ostream& os, const aVector& v)
{
   v.pv_vec->Print(os);
   return os;
}

/**
  *Purpose:
      reads a vector from an input stream
  */
std::istream& operator>>(std::istream& is, aVector& v)
{
   double p0, p1, p2;

   is >> p0 >> p1 >> p2;

   v.SetComponents(p0, p1, p2);

   return is;
}

#if VECTORSWITCH_OBJECT_COUNT_ON
/**
  *Purpose:
      print the number of vector and vectorNode objects
      in existence.
  */
void aVector::PrintObjectCount(std::ostream& outs)
{
   outs  << std::endl
         << "** Number of aVector objects: " << pv_num_vectors
         << std::endl
         << "** Number of vector nodes:    " << vectorNode::GetNumVectorNodes()
         << std::endl;
}
#endif

/**
  *Purpose:
      this member function prints out all the options that have
      been turned on/off for the vector class. we need this for
      diagnostics.
  */
void aVector::DisplayOptions(std::ostream& out) const
{
#if VECTORSWITCH_DEBUG_ON
   out << "VECTORSWITCH_DEBUG is on" << std::endl;
#else
   out << "VECTORSWITCH_DEBUG is off" << std::endl;
#endif

#if VECTORSWITCH_CHECKBOUNDS_ON
   out << "VECTORSWITCH_CHECKBOUNDS is on" << std::endl;
#else
   out << "VECTORSWITCH_CHECKBOUNDS is off" << std::endl;
#endif

#if VECTORSWITCH_OBJECT_COUNT_ON
   out << "VECTORSWITCH_OBJECT_COUNT is on" << std::endl;
#else
   out << "VECTORSWITCH_OBJECT_COUNT is off" << std::endl;
#endif
}
