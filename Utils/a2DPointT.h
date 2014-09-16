#ifndef _A2DPOINT_T_
#define _A2DPOINT_T_
/**

  *File: a2DPointT.h

  *Description:
   this template class will be used to store a two dimensional point.
   the components of the point use the standard name x and y.
   the function to retrieve the values are X() and Y(). the
   same ones with arguments will store the values.

   the class provides the following functionality:
      a2DPointT p1, p2, p3;
      real     alpha;
      p1 = p1 + p1;
      p1 = alpha * p2;  p2 = p2 * alpha;
      p3 = p2  - p1;
      p2 += p1;   p1 -= p2;
      p3 *= alpha;

   the operator () returns a pointer to the array containing the two values.

  *Version: 1.0 "@(#) a2DPointT. header. ver. 1.0. Premalatha and Vidyadhar, CTFD, NAL."

  *Dependencies:

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL.
  *Date:    August 24, 2000
  */

// system includes
// standard template
// local includes
// const declarations

// function prototypes
// forward declarations
// begin class declaration
template <class real>
class a2DPointT
{
   friend a2DPointT operator*(real alpha, const a2DPointT& p) {
      return a2DPointT( alpha*p.pv_val[0], alpha*p.pv_val[1] )
   }

   public:
   // constructors
      a2DPointT() {
         pv_val[0] = 0.0;  pv_val[1] = 0.0;
      }
      a2DPointT(real x, real y) {
         pv_val[0] = x;    pv_val[1] = y;
      }
      a2DPointT(const a2DPointT& p) {
         pv_val[0] = p.pv_val[0];   pv_val[1] = p.pv_val[1];
      }

   // assignment
      a2DPointT& operator=(a2DPointT& p) {
         pv_val[0] = p.pv_val[0];   pv_val[1] = p.pv_val[1];
         return *this;
      }

      void X(real x) {
         pv_val[0] = x;
      }

      void Y(real y) {
         pv_val[1] = y;
      }

      real X() const {
         return pv_val[0];
      }
      real Y() const {
         return pv_val[1];
      }

      const real* operator()() const {
         return &pv_val[0];
      }

      a2DPointT operator+(const a2DPointT& p) {
         return a2DPointT( (pv_val[0] + p.pv_val[0]), (pv_val[1] + p.pv_val[1]) );
      }
      a2DPointT operator-(const a2DPointT& p) {
         return a2DPointT( (pv_val[0] - p.pv_val[0]), (pv_val[1] - p.pv_val[1]) );
      }

      a2DPointT& operator+=(const a2DPointT& p) {
         pv_val[0] += p.pv_val[0];  pv_val[1] += p.pv_val[1];
         return *this;
      }

      a2DPointT& operator-=(const a2DPointT& p) {
         pv_val[0] -= p.pv_val[0];  pv_val[1] -= p.pv_val[1];
         return *this;
      }

      a2DPointT& operator*=(real alpha) {
         pv_val[0] *= alpha;  pv_val[1] *= alpha;
         return *this;
      }

      a2DPointT operator*(real alpha) {
         return a2DPointT( alpha*pv_val[0], alpha*pv_val[1] );
      }
   protected:
   private:
      real pv_val[2];
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
                              // --m--  o  --m-- 
                              //                 

#endif   // _A2DPOINT_T_
