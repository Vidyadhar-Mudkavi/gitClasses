/**

  *File: aVector.cpp

  *Description:

   This file contains the implementation code for some of the overloaded
   operators for the three dimensional vector class.
   The operators overloaded are scalar multiplication,
   vector dot and cross products.

  *IMPORTANT NOTE: The precedence of ^ is very low and therefore
         expressions involving ^ must be properly
         paranthesised.


  *Version: 1.3

  *Dependencies:
   aBoolean

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL

  *Date:    19 February 1997
            21 July 1998
            20 April 1999 (conversion to canonical form)
  */

// system includes
#include <math.h>
#include <stdlib.h>

// local includes
#include "aVector.h"

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
   this defines a default behaviour. the vector is set
   to a unit vector with components (1,0,0).
   note that the size is always 3.
  */
aVector::aVector()
   : pv_size(3)
{
   pv_p    = new double[pv_size]; // allocate space
   pv_p[0] = 1.0;                 // set default values
   pv_p[1] = 0.0;
   pv_p[2] = 0.0;

   ComputeMagnitude();           // compute and store vector mag
   pv_bln_true  = TRUE;
   pv_bln_false = FALSE;
   pv_is_null   = pv_bln_false;
}

/**
   this constructor builds the vector with the values passed
   (the components in the stated order)
  */
aVector::aVector(double p0, double p1, double p2)
   : pv_size(3)
{
   pv_p    = new double[pv_size];  // allocate space
   pv_p[0] = p0;
   pv_p[1] = p1;
   pv_p[2] = p2;

   ComputeMagnitude();    // compute and store vector mag

   pv_is_null   = isNullVector();

   pv_bln_true  = TRUE;
   pv_bln_false = FALSE;
}

/**
   the special constructor
  */
aVector::aVector(const aVector& v)
{
// make sure that the sizes match!
   pv_size = 3;
   
   if ( pv_size != v.pv_size )
   {
#ifdef STOP_ON_ERROR
   // raise an exception! presently take recourse to exit
      cerr << "Cannot build vector. Sizes don't match!"
           << endl
           << "Program exiting :-("
           << endl;
      exit(-1);
#else
      cerr << "Cannot build vector. Sizes don't match!"
           << endl
           << "No exception thrown, continuing with error state!"
           << endl;
#endif
   }

   pv_p    = new double[pv_size];  // allocate space

   pv_p[0] = v.pv_p[0];
   pv_p[1] = v.pv_p[1];
   pv_p[2] = v.pv_p[2];

   pv_magnitude = v.pv_magnitude;    

   pv_is_null   = isNullVector();

   pv_bln_true  = TRUE;
   pv_bln_false = FALSE;
}


   ////////////////////////////////////////
   //                                      
   //    implement assignment operators    
   //                                      
   //                                      

/**
   assigns a vector with another vector.
   do not delete the components if the 
   vector is being assigned to itself!
   For instance:
     aVector v1, v2;
     v1 = v1;  // equate to itself!
  */
aVector& aVector::operator=(const aVector& v)
{
// case when same vector is being equated
   if ( pv_p == v.pv_p )
   {
      return *this;
   }
   
   pv_size = v.pv_size;

// if size does not equal 3, raise an exception!
   if ( pv_size != 3 )
   {

#ifdef STOP_ON_ERROR
   // stop on error requested
      cerr << "Vector being assigned to is not three-dimensional!"
           << endl
           << "Program exiting :-("
           << endl;
      exit(-1);
#else
   // no stop on error. but no exception either at the moment
      cerr << "Vector being assigned to is not three-dimensional!"
           << endl
           << "Program continuing with error state!"
           << endl;
#endif
   }

   delete [] pv_p;      // clean up any old mess first
   
// allocate new space
   pv_p    = new double[pv_size];
   
   pv_p[0] = v.pv_p[0];
   pv_p[1] = v.pv_p[1];
   pv_p[2] = v.pv_p[2];
   
   pv_magnitude = v.pv_magnitude;

   pv_is_null   = v.pv_is_null;

   return *this;
}


   ////////////////////////////////////////
   //                                      
   //    implement the destructor          
   //                                      
   //                                      

aVector::~aVector()
{
   delete [] pv_p;
}

   ////////////////////////////////////////////
   //                                          
   //   implement other member functions here  
   //                                          
   //                                          


/**
   this is a helper function which checks bounds. program exits
   if the index is out of bounds and the flag STOP_ON_ERROR
   is set to ON. otherwise, an exception is raised. 

   currently. we resort to stopping on error.
  */
void aVector::CheckBounds(int elem) const
{
#ifdef STOP_ON_ERROR
// stop on error requested
   if (elem<0 || elem>=pv_size)
   {
     cerr << endl
	  << "aVector: Exception occurred: Vector component out of bounds."
	  << endl
	  << "         current component = " << elem << endl
	  << "         allowed range is: (0-" << pv_size-1 << ")" << endl
	  << "         Program exiting with status -1" << endl;
     exit(-1);
   }
#else
// no stop on error. but no exception thrown either
   if (elem<0 || elem>=pv_size)
   {
     cerr << endl
	  << "aVector: Exception occurred: Vector component out of bounds."
	  << endl
	  << "         current component = " << elem << endl
	  << "         allowed range is: (0-" << pv_size-1 << ")" << endl
	  << "         Program continuing with error state!" << endl;
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
aBoolean aVector::isNullVector()
{
// currently the check that 1+x=1 is not working 
   // satisfactorirly (actually, it is NOT working).
   //  we need to look into the machine epsilon to check
   // for magnitude being zero.
   double D_epsilon = 1.0e-14;

   if ( pv_magnitude <= D_epsilon )
      return aBoolean(TRUE);
   else
      return aBoolean(FALSE);
}

/**
   this function computes the magnitude and stores the
   value in a private variable. this is called whenever
   the vector is built or its components are altered.
  */
void aVector::ComputeMagnitude()
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
void aVector::SetComponents(double p0, double p1, double p2)
{
   pv_p[0] = p0;
   pv_p[1] = p1;
   pv_p[2] = p2;

// recompute magnitute and nullity
   ComputeMagnitude();
   pv_is_null = isNullVector();
}

/**
   the index operator is the general method for both setting
   and getting a component by its position. the positioning follows
   the c/c++ array notation, i.e., index zero refers to the first
   component.
  */
double& aVector::operator[](int i)
{
#ifdef CHECKBOUNDS_ON
   CheckBounds(i);
#endif

   return pv_p[i];
}

/**
   returns the magnitude of the vector
  */
double aVector::GetMagnitude() const
{
   return pv_magnitude;
}

/**
   return the director (unit vector)
   later add methods to check for underflow or
   numerical zero. we may need to borrow ideas
   from the book by kahaner, moler and nash.
  */
aVector aVector::GetDirection() const
{
   aVector* ptr_v;
   
   if ( pv_is_null )
   {
      ptr_v = new aVector(0.0, 0.0, 0.0);
   }
   else
   {
      ptr_v = new aVector(pv_p[0]/pv_magnitude,
                          pv_p[1]/pv_magnitude,
                          pv_p[2]/pv_magnitude);
   }

   return *ptr_v;
}


/**
   this is identical to the GetDirection function
  */
aVector aVector::GetUnitVector() const
{
   aVector* ptr_v;
   
   if ( pv_is_null )
   {
      ptr_v = new aVector(0.0, 0.0, 0.0);
   }
   else
   {
      ptr_v = new aVector(pv_p[0]/pv_magnitude,
                          pv_p[1]/pv_magnitude,
                          pv_p[2]/pv_magnitude);
   }

   return *ptr_v;
}


/**
   adds two vectors
  */
aVector operator+(const aVector& v1, const aVector& v2)
{
   return aVector( (v1.pv_p[0] + v2.pv_p[0]),
                   (v1.pv_p[1] + v2.pv_p[1]),
                   (v1.pv_p[2] + v2.pv_p[2]) );
}

/**
   subtracts two vectors
  */
aVector operator-(const aVector& v1, const aVector& v2)
{
   return aVector( (v1.pv_p[0] - v2.pv_p[0]),
                   (v1.pv_p[1] - v2.pv_p[1]),
                   (v1.pv_p[2] - v2.pv_p[2]) );
}


      ///////////////////////////////////////
      //
      // implement such functions as vector
      // dot product, cross product etc.
      //
/**
   computes the vector dot product (denoted by *)
  */
double operator*(const aVector& v1, const aVector& v2)
{
   return ( (v1.pv_p[0]*v2.pv_p[0]) + 
            (v1.pv_p[1]*v2.pv_p[1]) + 
            (v1.pv_p[2]*v2.pv_p[2]) );
}

/**
   computes the scalar product of a vector (returns
   a vector)
  */
aVector operator*(double alpha, const aVector& v1)
{
   return aVector( alpha*v1.pv_p[0], 
                   alpha*v1.pv_p[1], 
                   alpha*v1.pv_p[2] );
}

/**
   computes the scalar product of a vector (the scalar
   is a post multiplier)
  */
aVector operator*(const aVector v1, double alpha)
{
   return alpha * v1;  // use the previous definition
}


/**
   computes the cross product of a vector. this
   operator has a very low precedence and care must be
   taken while using it.
  */
aVector operator^(const aVector& v1, const aVector& v2)
{
   return aVector( (v1.pv_p[1]*v2.pv_p[2] - v2.pv_p[1]*v1.pv_p[2]),
                   (v1.pv_p[2]*v2.pv_p[0] - v2.pv_p[2]*v1.pv_p[0]),
                   (v1.pv_p[0]*v2.pv_p[1] - v2.pv_p[0]*v1.pv_p[1]) );
}

/**
   writes the vector to an output stream
  */
ostream& operator<<(ostream& os, const aVector& v)
{
   aBoolean t_or_f;
   t_or_f = v.pv_is_null;

   os << "[" 
      << v.pv_p[0] << ","
      << v.pv_p[1] << ","
      << v.pv_p[2] << "]";

#ifdef DEBUG_ON
   if (t_or_f == TRUE)
   {
      os << " (*** NULL ***)" << endl;
   } 
   else
   {
      os << endl;
   }
#endif

   return os;
}


/**
   reads a vector from an input stream
  */
istream& operator>>(istream& is, aVector& v)
{
   double p0, p1, p2;

   is >> p0 >> p1 >> p2;

   v.SetComponents(p0, p1, p2);

   return is;
}


/**
   this member function prints out all the options that have
   been turned on/off for the vector class. we need this for
   diagnostics.
  */
void aVector::DisplayOptions(ostream& out)
{
#ifdef DEBUG_ON
   out << "DEBUG is on" << endl;
#else
   out << "DEBUG is off" << endl;
#endif

#ifdef CHECKBOUNDS_ON
   out << "CHECKBOUNDS is on" << endl;
#else
   out << "CHECKBOUNDS is off" << endl;
#endif

#ifdef STOP_ON_ERROR
   out << "STOP_ON_ERROR is on" << endl;
#else
   out << "STOP_ON_ERROR is off" << endl;
#endif
}
