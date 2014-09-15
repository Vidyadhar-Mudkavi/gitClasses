/** 

  *File: aVector.cpp

   This file contains the implementation code for some of the overloaded
   operators for the three dimensional vector class.
   The operators overloaded are scalar multiplication,
   vector dot and cross products.

  *IMPORTANT NOTE: The precedence of ^ is very low and therefore
         expressions involving ^ must be properly
         paranthesised.

  *Version: 1.0

  *Dependencies:
   aBoolean

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL
  *Date:    19 February 1997
            21 July 1998
  */

#include <math.h>
#include <stdlib.h>

#include <myHeaders.h>

#include "aVector.h"

// Constructors

// the default one
aVector::aVector()                // unit vector (first component)
{
   pv_size = 3;                   // dealing with 3D vectors only
   pv_p    = new double[pv_size]; // allocate space
   pv_p[0] = 1.0;                 // set default values
   pv_p[1] = 0.0;
   pv_p[2] = 0.0;

   ComputeMagnitude();           // compute and store vector mag
   pv_bln_true  = TRUE;
   pv_bln_false = FALSE;
   pv_is_null   = pv_bln_false;
}

/* 
   this one takes in an array as the parameter
   if by some misfortune, the length of the input
   array is smaller than needed, then blindly assigning
   values from the input array will lead to some elements
   missing data. so, if the array terminates, set the
   rest of the components to zero. a limitation, perhaps.
 */
aVector::aVector(const double pp[])
{
   pv_size = 3;                    // dealing with 3D vectors only
   pv_p    = new double[pv_size];  // allocate new space

   for (int i=0; i<pv_size; i++)
   {
      if (pp+i != NULL_PTR)
         pv_p[i] = pp[i];
      else
         pv_p[i] = 0.0;
   }

   ComputeMagnitude();    // compute and store vector mag

   pv_is_null   = isNullVector();

   pv_bln_true  = TRUE;
   pv_bln_false = FALSE;
}

// this one takes three parameters 
aVector::aVector(double p0, double p1, double p2)
{
   pv_size = 3;                    // dealing with 3D vectors only
   pv_p    = new double[pv_size];  // allocate space
   pv_p[0] = p0;
   pv_p[1] = p1;
   pv_p[2] = p2;

   ComputeMagnitude();    // compute and store vector mag

   pv_is_null   = isNullVector();

   pv_bln_true  = TRUE;
   pv_bln_false = FALSE;
}

// the special constructor
aVector::aVector(const aVector& v)
{
   pv_size = 3;                    // dealing with 3D vectors only
   pv_p    = new double[pv_size];  // allocate space

   pv_p[0] = v.pv_p[0];
   pv_p[1] = v.pv_p[1];
   pv_p[2] = v.pv_p[2];

   pv_magnitude = v.pv_magnitude;    

   pv_is_null   = isNullVector();

   pv_bln_true  = TRUE;
   pv_bln_false = FALSE;
}


/* 
   implement the helpers which are declared as private member 
   functions
 */

void aVector::CheckBounds(int elem) const
{
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
}

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

void aVector::ComputeMagnitude()
{
   pv_magnitude = sqrt( ( pv_p[0]*pv_p[0] + 
                       pv_p[1]*pv_p[1] + 
                       pv_p[2]*pv_p[2] )  );
}

/* implement the assignment operators */
      
aVector& aVector::operator=(const aVector& v)
{
   pv_size = v.pv_size;

   delete [pv_size] pv_p;     // clean up any old mess first
   
// allocate new space
   pv_p    = new double[pv_size];
   
   pv_p[0] = v.pv_p[0];
   pv_p[1] = v.pv_p[1];
   pv_p[2] = v.pv_p[2];
   
   pv_magnitude = v.pv_magnitude;

   pv_is_null   = v.pv_is_null;

   return *this;
}

aVector& aVector::operator=(const double pp[])
{
   pv_size = 3;              // dealing with 3D vectors only
   delete [pv_size] pv_p;    // clean up any old mess
   pv_p = new double[pv_size];  // allocate new space

   for (int i=0; i<pv_size; i++)
   {
      if (pp+i != NULL_PTR)
         pv_p[i] = pp[i];
      else
         pv_p[i] = 0.0;
   }

   ComputeMagnitude();    // compute and store vector magnitude

   pv_is_null = isNullVector();

   return *this;
}

aVector& aVector::operator=(double pp)
{
   pv_size = 3;                // dealing with 3D vectors only
   delete [pv_size] pv_p;      // clean up any old mess
   pv_p = new double[pv_size]; // allocate new space

   pv_p[0] = pp;
   pv_p[1] = 0.0;
   pv_p[2] = 0.0;

   pv_magnitude = pp;
 
   pv_is_null   = isNullVector();

   return *this;
}


// destructor
aVector::~aVector()
{
   delete [pv_size] pv_p;
}

/* accessor member functions
 */

// set a vector using three explicit values passed
void aVector::SetVector(double p0, double p1, double p2)
{
   pv_p[0] = p0;
   pv_p[1] = p1;
   pv_p[2] = p2;

   ComputeMagnitude();

   pv_is_null = isNullVector();
}

// set a vector using an array passed as parameter
// if the array values fall short, fill the rest with zero.
void aVector::SetVector(const double pp[])
{
   for (int i=0; i<pv_size; i++)
   {
      if (pp+i != NULL_PTR)
         pv_p[i] = pp[i];
      else
         pv_p[i] = 0.0;
   }

   ComputeMagnitude();    // compute and store vector magnitude

   pv_is_null = isNullVector();
}

// set a vector's i-th component.
void aVector::SetAComp(int i, double p_val)
{
   CheckBounds(i);
   pv_p[i] = p_val;

   ComputeMagnitude();

   pv_is_null = isNullVector();
}


// get the first component
inline double aVector::Get1stComp() const
{
   return pv_p[0];
}

// get the second component
inline double aVector::Get2ndComp() const
{
   return pv_p[1];
}

// get the third component
inline double aVector::Get3rdComp() const
{
   return pv_p[2];
}

// get some component. the index is not the array index.
double aVector::GetAComp(int i) const
{
   CheckBounds(i);
   return pv_p[i-1];
}


// operations to return magnitude and unit vector
double aVector::GetMagnitude() const
{
   return pv_magnitude;
}

// later add methods to check for underflow or
// numerical zero. we may need to borrow ideas
// from the book by kahaner, moler and nash.
aVector aVector::GetDirection() const
{
   aVector v;
   
   if ( pv_is_null == pv_bln_false )
   {
      v.SetVector(pv_p[0]/pv_magnitude,
                  pv_p[1]/pv_magnitude,
                  pv_p[2]/pv_magnitude);
   }
   else
   {
      v.SetVector(0.0, 0.0, 0.0);
   }
   return v;
}


aVector aVector::GetUnitVector() const
{
   if ( pv_is_null == pv_bln_true )
   {
      cout << "aVector: Error: Unit Vector has zero magnitude"
           << "         Program exiting with status -1 :-(" 
           << endl;
      exit(-1);
   }

   return aVector(pv_p[0]/pv_magnitude,
                  pv_p[1]/pv_magnitude,
                  pv_p[2]/pv_magnitude);
}


/* vector addition and subtraction
 */

aVector operator+(const aVector& v1, const aVector& v2)
{
   return aVector( (v1.pv_p[0] + v2.pv_p[0]),
                   (v1.pv_p[1] + v2.pv_p[1]),
                   (v1.pv_p[2] + v2.pv_p[2]) );
}

aVector operator-(const aVector& v1, const aVector& v2)
{
   return aVector( (v1.pv_p[0] - v2.pv_p[0]),
                   (v1.pv_p[1] - v2.pv_p[1]),
                   (v1.pv_p[2] - v2.pv_p[2]) );
}

// Java influenced style of member function for addition and subtraction
aVector aVector::Plus(const aVector& v)
{
   return aVector( (pv_p[0] + v.pv_p[0]),
                   (pv_p[1] + v.pv_p[1]),
                   (pv_p[2] + v.pv_p[2]) );
}


aVector aVector::Minus(const aVector& v)
{
   return aVector( (pv_p[0] - v.pv_p[0]),
                   (pv_p[1] - v.pv_p[1]),
                   (pv_p[2] - v.pv_p[2]) );
}


/* 
   Vector dot product, scalar multiplication and cross product
 */

// the operator * here indicates a dot product (because of the
// type of the operands)
double operator*(const aVector& v1, const aVector& v2)
{
   return ( (v1.pv_p[0]*v2.pv_p[0]) + 
            (v1.pv_p[1]*v2.pv_p[1]) + 
            (v1.pv_p[2]*v2.pv_p[2]) );
}

// for the following two, * denotes a scalar multiplication
aVector operator*(double alpha, const aVector& v1)
{
   return aVector( alpha*v1.pv_p[0], 
                   alpha*v1.pv_p[1], 
                   alpha*v1.pv_p[2] );
}

aVector operator*(const aVector v1, double alpha)
{
   return alpha * v1;  // use the previous definition
}

// now for Java style product member functions
double aVector::Dot(const aVector& v)
{
   return ( (pv_p[0]*v.pv_p[0]) + 
            (pv_p[1]*v.pv_p[1]) + 
            (pv_p[2]*v.pv_p[2]) );
}

aVector aVector::Times(double alpha)
{
   return aVector( alpha*pv_p[0], 
                   alpha*pv_p[1], 
                   alpha*pv_p[2] );
}


aVector operator^(const aVector& v1, const aVector& v2)
{
   return aVector( (v1.pv_p[1]*v2.pv_p[2] - v2.pv_p[1]*v1.pv_p[2]),
                   (v1.pv_p[2]*v2.pv_p[0] - v2.pv_p[2]*v1.pv_p[0]),
                   (v1.pv_p[0]*v2.pv_p[1] - v2.pv_p[0]*v1.pv_p[1]) );
}


aVector aVector::Cross(const aVector& v)
{
   return aVector( (pv_p[1]*v.pv_p[2] - v.pv_p[1]*pv_p[2]),
                   (pv_p[2]*v.pv_p[0] - v.pv_p[2]*pv_p[0]),
                   (pv_p[0]*v.pv_p[1] - v.pv_p[0]*pv_p[1]) );
}


/*
   operators to read and write the object
 */

ostream& operator<<(ostream& os, const aVector& v)
{
   aBoolean t_or_f;
   t_or_f = v.pv_is_null;
   os << "[" 
      << v.pv_p[0] << ","
      << v.pv_p[1] << ","
      << v.pv_p[2] << "]" << endl;

   if (t_or_f == TRUE)
   {
      os << "   * The vector is a Null Vector * " 
         << "mag: " << v.pv_magnitude 
         << " "
         << "mag+1: " << v.pv_magnitude+1.0
         << endl;
   } else
   {
      os << "   *** the vector is NOT null. ***  "
         << "mag: " << v.pv_magnitude 
         << " "
         << "mag+1: " << v.pv_magnitude+1.0
         << endl;
   }

   return os;
}


istream& operator>>(istream& is, aVector& v)
{
   double p0, p1, p2;

   is >> p0 >> p1 >> p2;

   v.SetVector(p0, p1, p2);

   return is;
}



#if 0  // this is older stuff. we will use cin and cout mostly.
void aVector::DumpObject(FILE* out_file)
{
   fprintf(out_file, "aVector: (%lf, %lf, %lf)\n", p1, p2, p3);
}


/* dont think that this is working fine. check this. */

void aVector::DumpObject(FILE* out_file, char* object_name)
{
   fprintf(out_file, "aVector: %s (%lf, %lf, %lf)\n", object_name,
                                     p1, p2, p3);
}
#endif
