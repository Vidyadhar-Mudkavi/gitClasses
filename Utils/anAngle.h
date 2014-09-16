#ifndef _ANANGLE_
#define _ANANGLE_
/**

  *File: anAngle.h

  *Description:

   this file declares class anAngle. this class essentially stores a
   number as a degree or radian. this class is a guard to make sure
   that we always pass radians into trignometric functions. 

   two simple support classes, viz., radian and degree are also declared.
   the angle class must be explicitly built with radian or degree measure.
   it will not accept a simple double (or float).

  *Version: 1.0 "@(#) anAngle. header. ver. 1.0. Premalatha and Vidyadhar, CTFD, NAL."


  *Dependencies:
   none

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL

  *Date: 10 February 2000
  */

// system includes

// sgi does not provide <cmath> header in place of <math.h>
#if defined(__sgi) && !defined(__GNUC__)
#  include <math.h>
#else
#  include <cmath>
#endif

#include <iostream>

// standard template

// local includes
#include "pulsar.h"

// const declarations
// function prototypes
// forward declarations
class anAngle;

// begin class declaration

/************** CLASS degree **************/
class degree
{
   friend class anAngle;
   friend class radian;

// input. reads a double as a degree measure
   friend std::istream& operator>>(std::istream& is, degree& alpha) {
      double value;
      is >> value;
      alpha = degree(value);
      return is;
   }
// output
   friend std::ostream& operator<<(std::ostream& os, degree& d) {
      os << d.pv_value;
      return os;
   }

   public:
      degree() : pv_value( 0 ) {
      // empty
      }
      explicit degree(double d) : pv_value( d ) {
      // empty
      }
      double ValueInDegrees() const { 
         return pv_value; 
      }

   // other functionality
      degree& operator+=(const degree& d) {
         pv_value += d.pv_value;
         return *this;
      }

      degree& operator-=(const degree& d) {
         pv_value -= d.pv_value;
         return *this;
      }

   protected:
   private:
      double pv_value;
};

typedef degree degrees;

/************** CLASS radian **************/
class radian
{
   friend class anAngle;
   friend class degree;

   friend std::ostream& operator<<(std::ostream& os, const anAngle& alpha);

// input. reads a double as a radian
   friend std::istream& operator>>(std::istream& is, radian& alpha) {
      double value;
      is >> value;
      alpha = radian(value);
      return is;
   }

// output
   friend std::ostream& operator<<(std::ostream& os, const radian& r) {
      os << r.pv_value;
      return os;
   }

   public:
      radian() : pv_value( 0 ) {
      // empty
      }
      radian(const degree& d) : pv_value( d.pv_value * pulsar::pi / 180.0 ) {
      // empty
      }
      explicit radian(double r) : pv_value( r ) {
      // empty
      }

#if 0 // sgi compiler indicates that a type qualifier on return type is
      // meaningless. 
      const double operator()() const {
         return pv_value;
      }
#endif

      double operator()() const {
         return pv_value;
      }

      operator double () {    // conversion operator (to double)
         return pv_value;
      }

   // assignment
      radian& operator=(const radian& r) {
         pv_value = r.pv_value;
         return *this;
      }
      radian& operator=(double d) {
         pv_value = d;
         return *this;
      }
      radian& operator=(const degree& d) {
         pv_value = d.pv_value * pulsar::pi / 180.0;
         return *this;
      }

   // other operations
      radian& operator-=(const radian& r) {
         pv_value -= r.pv_value;
         return *this;
      }
      
      radian& operator+=(const radian& r) {
         pv_value += r.pv_value;
         return *this;
      }

      radian operator*(double scale_factor) const {
         return radian( pv_value*scale_factor );
      }

   protected:
   private:
      double pv_value;
};

typedef radian radians;

/************** CLASS anAngle **************/
class anAngle
{
// input. reads only as radians
   friend std::istream& operator>>(std::istream& is, anAngle& alpha) {
      double value;
      is >> value;
      alpha = anAngle( radian(value) );
      return is;
   }
// output
   friend std::ostream& operator<<(std::ostream& os, const anAngle& alpha) {
      os << alpha.pv_radians.pv_value;
      return os;
   }

// scaling
   friend anAngle operator*(double scale_factor, const anAngle& alpha) {
      return anAngle( alpha.Radians() * scale_factor );
   }

   public:

   // constructors
      anAngle() { 
      // empty
      }

      anAngle(const radian& r) : pv_radians( r ), 
                                 pv_degrees( degree(r.pv_value * 180.0 / pulsar::pi) ) {
         // empty
      }
      anAngle(const degree& d) : pv_radians( d.pv_value * pulsar::pi / 180.0 ), 
                                 pv_degrees( d ) {
      // empty
      }

   // type conversion operator (returns only the radian measure)

#if 0 // sgi compiler says that a type qualifier on return type is meaningless.
      operator const double () const {
         return pv_radians();
      }
#endif

      operator double () const {
         return pv_radians();
      }

   // explicit value in degrees (returned as a double)
      double Degrees() const {
         return pv_degrees.ValueInDegrees();
      }

   // explicit value in radians
      radian Radians() const {
         return pv_radians;
      }

   // assignment operators
      anAngle& operator=( const anAngle& a ) {
         pv_radians = a.pv_radians;
         pv_degrees = a.pv_degrees;
         return *this;
      }

      anAngle& operator=( const radian& r ) {
         pv_radians = r;
         pv_degrees = degree( r.pv_value * 180.0 / pulsar::pi );
         return *this;
      }

      anAngle& operator=( const degree& d ) {
         pv_degrees = d;
         pv_radians = d.pv_value * pulsar::pi / 180.0;
         return *this;
      }

      anAngle& operator+=( const anAngle& a ) {
         pv_radians += a.pv_radians;
         pv_degrees += a.pv_degrees;
         return *this;
      }

      anAngle& operator-=( const anAngle& a ) {
         pv_radians -= a.pv_radians;
         pv_degrees -= a.pv_degrees;
         return *this;
      }

      anAngle operator*(double scale_factor) const {
         return anAngle( radians(pv_radians.pv_value * scale_factor) );
      }
   protected:

   private:
   // the data
      radian pv_radians;   // angle stored as radians
      degree pv_degrees;   // angle stored as degrees
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
                              // __m__  o  __m__ 
                              //                 

#endif //_ANANGLE_
