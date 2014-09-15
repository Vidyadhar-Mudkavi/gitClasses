/**

  *File: vectorNode.cpp

  *Description:

   This file contains the implementation code for some of the overloaded
   operators for the three dimensional vector class.
   The operators overloaded are scalar multiplication,
   vector dot and cross products.

  *IMPORTANT NOTE: The precedence of ^ is very low and therefore
         expressions involving ^ must be properly
         paranthesised.

  *Remark: objects of this class are created by aVector handle class

  *Version: 1.5

  *Dependencies:
   aBoolean

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL

  *Date:    19 February 1997
            21 July 1998
            20 April 1999 (conversion to canonical form)
            07 October 1999 (handle class added)
  */

// system includes
#include <math.h>
#include <stdlib.h>

// local includes
#include "aVector.h"
#include "vectorNode.h"

// const declarations

// function prototypes

// forward declarations

// begin class implementation

#if 0 // needed only for diagnostics
int vectorNode::pv_no_of_objects = 0;
#endif

   ////////////////////////////////////////
   //                                      
   //    implement constructors here       
   //                                      
   //                                      

/**
   this defines a default behaviour. the vector is set
   to a unit vector with components (1,0,0).
   note that the size is always 3.
  */
vectorNode::vectorNode()
   : pv_size(3)
{
   pv_p    = new double[pv_size];
   pv_p[0] = 1.0;                 // set default values
   pv_p[1] = 0.0;
   pv_p[2] = 0.0;

   ComputeMagnitude();           // compute and store vector mag

   pv_is_null   = false;

#if 0 // needed only for diagnostics
   pv_no_of_objects++;
#endif
}

/**
   this constructor builds the vector with the values passed
   (the components in the stated order)
  */
vectorNode::vectorNode(double p0, double p1, double p2)
   : pv_size(3)
{
   pv_p    = new double[pv_size];
   pv_p[0] = p0;
   pv_p[1] = p1;
   pv_p[2] = p2;

   ComputeMagnitude();    // compute and store vector mag

   pv_is_null   = isNull();

#if 0 // needed only for diagnostics
   pv_no_of_objects++;
#endif
}

/**
   the special constructor. never used. handle
   class takes care of this.
  */
vectorNode::vectorNode(const vectorNode& v)
   : pv_size(v.pv_size)
{
   pv_p    = new double[pv_size];
   pv_p[0] = v.pv_p[0];
   pv_p[1] = v.pv_p[1];
   pv_p[2] = v.pv_p[2];

   pv_magnitude = v.pv_magnitude;

   pv_is_null   = v.pv_is_null;

#if 0 // needed only for diagnostics
   pv_no_of_objects++;
#endif
}


   ////////////////////////////////////////
   //                                      
   //    implement assignment operators    
   //                                      
   //                                      

/**
   assignment is never used. taken care of by the
   handle class.
  */
vectorNode& vectorNode::operator=(const vectorNode& v)
{
   return *this;
}


   ////////////////////////////////////////
   //                                      
   //    implement the destructor          
   //                                      
   //                                      

vectorNode::~vectorNode()
{
   delete [] pv_p;

#if 0 // needed only for diagnostics
   pv_no_of_objects--;
#endif
}

   ////////////////////////////////////////////
   //                                          
   //   implement other member functions here  
   //                                          
   //                                          


/**
   this is a helper function which checks bounds. program exits
   if the index is out of bounds and the flag VECTOR_STOP_ON_ERROR
   is set to ON. otherwise, an exception is raised. 

   currently. we resort to stopping on error.
  */
void vectorNode::CheckBounds(int elem) const
{
#ifdef VECTOR_STOP_ON_ERROR
// stop on error requested
   if (elem<0 || elem>=pv_size)
   {
     std::cerr << std::endl
	  << "aVector: Exception occurred: Vector component out of bounds."
	  << std::endl
	  << "         current component = " << elem << std::endl
	  << "         allowed range is: (0-" << pv_size-1 << ")" << std::endl
	  << "         Program exiting with status -1" << std::endl;
     exit(-1);
   }
#else
// no stop on error. but no exception thrown either
   if (elem<0 || elem>=pv_size)
   {
     std::cerr << std::endl
	  << "aVector: Exception occurred: Vector component out of bounds."
	  << std::endl
	  << "         current component = " << elem << std::endl
	  << "         allowed range is: (0-" << pv_size-1 << ")" << std::endl
	  << "         Program continuing with error state!" << std::endl;
   }
#endif
}

/**
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
bool vectorNode::isNull()
{
// currently the check that 1+x=1 is not working 
// satisfactorirly (actually, it is NOT working).
//  we need to look into the machine epsilon to check
// for magnitude being zero.
   double D_epsilon = 1.0e-14;

   if ( pv_magnitude <= D_epsilon )
   {
      return true;
   }
   return false;
}

/**
   this function computes the magnitude and stores the
   value in a private variable. this is called whenever
   the vector is built or its components are altered.
  */
void vectorNode::ComputeMagnitude()
{
   pv_magnitude = sqrt( ( pv_p[0]*pv_p[0] + 
                          pv_p[1]*pv_p[1] + 
                          pv_p[2]*pv_p[2] )  );
}


/**
   accessor member functions
  */

/**
   sets the vector to new components.
  */
void vectorNode::SetComponents(double p0, double p1, double p2)
{
   pv_p[0] = p0;
   pv_p[1] = p1;
   pv_p[2] = p2;

// recompute magnitute and nullity
   ComputeMagnitude();
   pv_is_null = isNull();
}

/**
   the index operator is the general method for both setting
   and getting a component by its position. the positioning follows
   the c/c++ array notation, i.e., index zero refers to the first
   component.
  */
double& vectorNode::operator[](int i)
{
#ifdef VECTOR_CHECKBOUNDS_ON
   CheckBounds(i);
#endif

   return pv_p[i];
}


/**
   returns the magnitude of the vector
  */
double vectorNode::GetMagnitude() const
{
   return pv_magnitude;
}

/**
   return the director (unit vector)
   later add methods to check for underflow or
   numerical zero. we may need to borrow ideas
   from the book by kahaner, moler and nash.
  */
aVector vectorNode::GetDirection() const
{
   if ( pv_is_null )
   {
      return new vectorNode(0.0, 0.0, 0.0);
   }

   return new vectorNode(pv_p[0]/pv_magnitude,
                             pv_p[1]/pv_magnitude,
                             pv_p[2]/pv_magnitude);
}


/**
   this is identical to the GetDirection function
  */
aVector vectorNode::GetUnitVector() const
{
   if ( pv_is_null )
   {
      return new vectorNode(0.0, 0.0, 0.0);
   }
   
   return new vectorNode( pv_p[0]/pv_magnitude,
                          pv_p[1]/pv_magnitude,
                          pv_p[2]/pv_magnitude );
}


/**
   adds two vectors
  */
aVector vectorNode::operator+(const vectorNode& v2) const
{
   return new vectorNode( (pv_p[0] + v2.pv_p[0]),
                          (pv_p[1] + v2.pv_p[1]),
                          (pv_p[2] + v2.pv_p[2]) );
}

/**
   subtracts two vectors
  */
aVector vectorNode::operator-(const vectorNode& v2) const
{
   return new vectorNode( (pv_p[0] - v2.pv_p[0]),
                          (pv_p[1] - v2.pv_p[1]),
                          (pv_p[2] - v2.pv_p[2]) );
}


      ///////////////////////////////////////
      //
      // implement such functions as vector
      // dot product, cross product etc.
      //
/**
   computes the vector dot product (denoted by *)
  */
double vectorNode::operator*(const vectorNode& v2) const
{
   return ( (pv_p[0]*v2.pv_p[0]) + 
            (pv_p[1]*v2.pv_p[1]) + 
            (pv_p[2]*v2.pv_p[2]) );
}


/**
   computes the scalar product of a vector (the scalar
   is a post multiplier)
  */
aVector vectorNode::operator*(double alpha) const
{
   return new vectorNode( alpha * pv_p[0], 
                          alpha * pv_p[1], 
                          alpha * pv_p[2] );
}


/**
   this operator divides the vector by a scalar
  */
aVector vectorNode::operator/(double alpha) const
{
   if ( alpha == 0.0 )
   {
      throw "aVector: Exception: Division by zero in /";
   }

   return new vectorNode( pv_p[0] / alpha, 
                           pv_p[1] / alpha, 
                           pv_p[2] / alpha );
}

/**
   computes the cross product of a vector. this
   operator has a very low precedence and care must be
   taken while using it.
  */
aVector vectorNode::operator^(const vectorNode& v2) const
{
   return new vectorNode( (pv_p[1]*v2.pv_p[2] - v2.pv_p[1]*pv_p[2]),
                          (pv_p[2]*v2.pv_p[0] - v2.pv_p[2]*pv_p[0]),
                          (pv_p[0]*v2.pv_p[1] - v2.pv_p[0]*pv_p[1]) );
}

/**
   writes the vector to an output stream
  */
void vectorNode::Print(std::ostream& os)
{
   os << "[" 
      << pv_p[0] << ","
      << pv_p[1] << ","
      << pv_p[2] << "]";

#ifdef VECTOR_DEBUG_ON
   if (pv_is_null)
   {
      os << " (*** NULL ***)";
   } 
#endif
}




#if 0
/**
   reads a vector from an input stream
  */
istream& operator>>(istream& is, vectorNode& v)
{
   double p0, p1, p2;

   is >> p0 >> p1 >> p2;

   v.SetComponents(p0, p1, p2);

   return is;
}
#endif
