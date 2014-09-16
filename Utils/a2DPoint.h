#ifndef _A2DPOINT_
#define _A2DPOINT_
/**

  *File: a2DPoint.h

  *Description:
   this class will be used to store a two dimensional point.
   the components of the point use the standard name x and y.
   the function to retrieve the values are X() and Y(). the
   same ones with arguments will store the values.

   the class provides the following functionality:
      a2DPoint p1, p2, p3;
      real     alpha;
      p1 = p1 + p1;
      p1 = alpha * p2;  p2 = p2 * alpha;
      p3 = p2  - p1;
      p2 += p1;   p1 -= p2;
      p3 *= alpha;

   the operator () returns a pointer to the array containing the two values.

   NOW A TEMPLATE

  *Version: 1.0 "@(#) a2DPoint. header. ver. 1.0. Premalatha and Vidyadhar, CTFD, NAL."

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
class a2DPoint;

// function prototypes
template <class real>
std::ostream& operator<<(std::ostream& os, const a2DPoint<real>& p);

// begin class declaration
template <class real>
class a2DPoint
{
   friend std::ostream& operator<<(std::ostream& os, a2DPoint& p) {
      p.Print(os);
      return os;
   }

   friend std::ostream& operator<<(std::ostream& os, const a2DPoint& p) {
      p.PrintConst(os);
      return os;
   }

   friend std::istream& operator>>(std::istream& is, a2DPoint& p) {
      real x, y;
      is >> x >> y;
      p.Set(x, y);
      return is;
   }

#if 0 // this leaks out memory
   friend a2DPoint& operator*(real alpha, const a2DPoint& p) {
      return *new a2DPoint( alpha*p.pv_x, alpha*p.pv_y );
   }
#endif
   friend a2DPoint operator*(real alpha, const a2DPoint& p) {
      return a2DPoint( alpha*p.pv_x, alpha*p.pv_y );
   }
   this line is introduced to check the above changes.;

   public:
   // constructors
      a2DPoint() {
         pv_x = 0.0;  pv_y = 0.0;
      }

      a2DPoint(real x, real y) {
         pv_x = x;    pv_y = y;
      }

      a2DPoint(const a2DPoint& p) {
         pv_x = p.pv_x;   pv_y = p.pv_y;
      }

   // assignment
      inline a2DPoint& operator=(const a2DPoint& p);

      inline void X(real x);
      inline void Y(real y);
      inline void Set(real x, real y);
      inline real X() const;
      inline real Y() const;

      inline const real* operator()() const;
      
#if 0 // memory leaks not accounted for here!!!
      inline a2DPoint& operator+(const a2DPoint& p) const;
      inline a2DPoint& operator-(const a2DPoint& p) const;
      inline a2DPoint& operator+=(const a2DPoint& p);
      inline a2DPoint& operator-=(const a2DPoint& p);
      inline a2DPoint& operator*=(real alpha);
      inline a2DPoint& operator*(real alpha) const;
#endif
      inline a2DPoint operator+(const a2DPoint& p) const;
      inline a2DPoint operator-(const a2DPoint& p) const;
      inline a2DPoint operator*(real alpha) const;

      inline a2DPoint& operator+=(const a2DPoint& p);
      inline a2DPoint& operator-=(const a2DPoint& p);
      inline a2DPoint& operator*=(real alpha);

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
inline a2DPoint<real>& a2DPoint<real>::operator=(const a2DPoint& p) 
{
   pv_x = p.pv_x;   pv_y = p.pv_y;
   return *this;
}

// set the first coordinate
template <class real>
inline void a2DPoint<real>::X(real x) 
{
   pv_x = x;
}

// set the second coordinate
template <class real>
inline void a2DPoint<real>::Y(real y) 
{
   pv_y = y;
}

// set the point with two arguments
template <class real>
inline void a2DPoint<real>::Set(real x, real y)
{
   pv_x = x;
   pv_y = y;
}

// return the first coordinate
template <class real>
inline real a2DPoint<real>::X() const 
{
   return pv_x;
}

// return the second coordinate
template <class real>
inline real a2DPoint<real>::Y() const 
{
   return pv_y;
}

template <class real>
inline const real* a2DPoint<real>::operator()() const 
{
   real* ret_val = new real[2];
   ret_val[0] = pv_x; ret_val[1] = pv_y;
   return ret_val;
}


// add two points
template <class real>
inline a2DPoint<real> a2DPoint<real>::operator+(const a2DPoint& p) const 
{
   return a2DPoint( (pv_x + p.pv_x), (pv_y + p.pv_y) );
}

// subtract two points
template <class real>
inline a2DPoint<real> a2DPoint<real>::operator-(const a2DPoint& p) const 
{
   return a2DPoint( (pv_x - p.pv_x), (pv_y - p.pv_y) );
}


template <class real>
inline a2DPoint<real>& a2DPoint<real>::operator+=(const a2DPoint& p) 
{
   pv_x += p.pv_x;  pv_y += p.pv_y;
   return *this;
}

template <class real>
inline a2DPoint<real>& a2DPoint<real>::operator-=(const a2DPoint& p) 
{
   pv_x -= p.pv_x;  pv_y -= p.pv_y;
   return *this;
}

template <class real>
inline a2DPoint<real>& a2DPoint<real>::operator*=(real alpha) 
{
   pv_x *= alpha;  pv_y *= alpha;
   return *this;
}

// multiply alpha to the point
template <class real>
inline a2DPoint<real> a2DPoint<real>::operator*(real alpha) const 
{
   return a2DPoint( alpha*pv_x, alpha*pv_y );
}


// print non const point
template <class real>
inline void a2DPoint<real>::Print(std::ostream& os)
{
   os << " (" << pv_x << ", " << pv_y << ") ";
}
 
// print const point
template <class real>
inline void a2DPoint<real>::PrintConst(std::ostream& os) const
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

#endif   // _A2DPOINT_
