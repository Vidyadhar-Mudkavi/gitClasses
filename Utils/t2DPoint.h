#ifndef _T2DPOINT_
#define _T2DPOINT_
/**

  *File: t2DPoint.h

  *Description:
   this class will be used to store a two dimensional point.
   the components of the point use the standard name x and y.
   the function to retrieve the values are X() and Y(). the
   same ones with arguments will store the values.

   the class provides the following functionality:
      t2DPoint p1, p2, p3;
      real     alpha;
      p1 = p1 + p1;
      p1 = alpha * p2;  p2 = p2 * alpha;
      p3 = p2  - p1;
      p2 += p1;   p1 -= p2;
      p3 *= alpha;

   the operator () returns a pointer to the array containing the two values.

   NOW A TEMPLATE

  *Version: 1.0 "@(#) t2DPoint. header. ver. 1.0. Premalatha and Vidyadhar, CTFD, NAL."

  *Dependencies:

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL.
  *Date:    August 24, 2000
  */

// system includes
#include <iostream>

// standard template
#include <vector>

// local includes
// const declarations
// forward declarations
template <class real>
class t2DPoint;

// function prototypes
template <class real>
std::ostream& operator<<(std::ostream& os, const t2DPoint<real>& p);

// begin class declaration
template <class real>
class t2DPoint
{
   friend std::ostream& operator<<(std::ostream& os, t2DPoint& p) {
      p.Print(os);
      return os;
   }

   friend std::ostream& operator<<(std::ostream& os, const t2DPoint& p) {
      p.PrintConst(os);
      return os;
   }

   friend std::istream& operator>>(std::istream& is, t2DPoint& p) {
      real x, y;
      is >> x >> y;
      p.Set(x, y);
      return is;
   }

   friend t2DPoint operator*(real alpha, const t2DPoint& p) {
      return t2DPoint( alpha*p.pv_x, alpha*p.pv_y );
   }

   public:
   // constructors
      t2DPoint() {
         pv_x = 0.0;  pv_y = 0.0;
      }

      t2DPoint(real x, real y) {
         pv_x = x;    pv_y = y;
      }

      t2DPoint(const t2DPoint& p) {
         pv_x = p.pv_x;   pv_y = p.pv_y;
      }

   // assignment
      inline t2DPoint& operator=(const t2DPoint& p);

      inline void X(real x);
      inline void Y(real y);
      inline void Set(real x, real y);
      inline real X() const;
      inline real Y() const;

      inline const real* operator()() const;
      
      inline t2DPoint operator+(const t2DPoint& p) const;
      inline t2DPoint operator-(const t2DPoint& p) const;
      inline t2DPoint& operator+=(const t2DPoint& p);
      inline t2DPoint& operator-=(const t2DPoint& p);
      inline t2DPoint& operator*=(real alpha);
      inline t2DPoint operator*(real alpha) const;

   // output
      inline void Print(std::ostream& os);
      inline void PrintConst(std::ostream& os) const;

   protected:
   private:
      real pv_x, pv_y;
};

// include any inline code here
// assignment
template <class real>
inline t2DPoint<real>& t2DPoint<real>::operator=(const t2DPoint& p) 
{
   pv_x = p.pv_x;   pv_y = p.pv_y;
   return *this;
}

// set the first coordinate
template <class real>
inline void t2DPoint<real>::X(real x) 
{
   pv_x = x;
}

// set the second coordinate
template <class real>
inline void t2DPoint<real>::Y(real y) 
{
   pv_y = y;
}

// set the point with two arguments
template <class real>
inline void t2DPoint<real>::Set(real x, real y)
{
   pv_x = x;
   pv_y = y;
}

// return the first coordinate
template <class real>
inline real t2DPoint<real>::X() const 
{
   return pv_x;
}

// return the second coordinate
template <class real>
inline real t2DPoint<real>::Y() const 
{
   return pv_y;
}

template <class real>
inline const real* t2DPoint<real>::operator()() const 
{
   real* ret_val = new real[2];
   ret_val[0] = pv_x; ret_val[1] = pv_y;
   return ret_val;
}

// add two points
template <class real>
inline t2DPoint<real> t2DPoint<real>::operator+(const t2DPoint& p) const 
{
   return t2DPoint( (pv_x + p.pv_x), (pv_y + p.pv_y) );
}

// subtract two points
template <class real>
inline t2DPoint<real> t2DPoint<real>::operator-(const t2DPoint& p) const 
{
   return t2DPoint( (pv_x - p.pv_x), (pv_y - p.pv_y) );
}


template <class real>
inline t2DPoint<real>& t2DPoint<real>::operator+=(const t2DPoint& p) 
{
   pv_x += p.pv_x;  pv_y += p.pv_y;
   return *this;
}

template <class real>
inline t2DPoint<real>& t2DPoint<real>::operator-=(const t2DPoint& p) 
{
   pv_x -= p.pv_x;  pv_y -= p.pv_y;
   return *this;
}

template <class real>
inline t2DPoint<real>& t2DPoint<real>::operator*=(real alpha) 
{
   pv_x *= alpha;  pv_y *= alpha;
   return *this;
}

// multiply alpha to the point
template <class real>
inline t2DPoint<real> t2DPoint<real>::operator*(real alpha) const 
{
   return t2DPoint( alpha*pv_x, alpha*pv_y );
}


// print non const point
template <class real>
inline void t2DPoint<real>::Print(std::ostream& os)
{
   os << " (" << pv_x << ", " << pv_y << ") ";
}
 
// print const point
template <class real>
inline void t2DPoint<real>::PrintConst(std::ostream& os) const
{
   os << " (" << pv_x << ", " << pv_y << ") ";
}
/**
   declare any typedef statements here
     ex: typedef aVortex areVortices;
   so that we can declare
     areVortices v1, v2, v3;
  */
                              //                 
                              //      \\^//      
                              //     o(!_!)o     
                              // --m--  o  --m-- 
                              //                 

#endif   // _T2DPOINT_
