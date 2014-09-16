#ifndef _ANANGLE_
#define _ANANGLE_
/**

  *File: anAngle.h

  *Description:

   this file declares class anAngle. this class essentially stores a
   number as a degree or radian. this class is a guard to make sure
   that we always pass radians into trignometric functions. 

   two simple support classes, viz., radian and degree are also declared.
   the angle class must be explicitly build with radian or degree measure.
   it will not accept a simple double (or float).

  *Version: 1.0

  *Dependencies:
   none

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL

  *Date: 10 February 2000
  */

// system includes
#include <math.h>

// local includes
// const declarations
// function prototypes
// forward declarations

// begin class declaration

class radian
{
   friend class anAngle;
   public:
      radian() : pv_value( 0 ) {}
      radian(double r) : pv_value( r ) {}

      double operator()() { return pv_value; }

   protected:
   private:
      double pv_value;
};

class degree
{
   friend class anAngle;
   public:
      degree() : pv_value( 0 ) {}
      degree(double d) : pv_value( d ) {}

      double ValueInDegrees() { return pv_value; }

      degree& operator=(double d) { pv_value = d; return *this; }

   protected:
   private:
      double pv_value;
};



class anAngle
{
   public:

   // constructors
      anAngle() { /* empty */ }

      explicit anAngle(radian r) 
         : pv_radians( r ), 
           pv_degrees( r.pv_value * 180.0 / anAngle::pv_pi ) { /* empty */ }
      explicit anAngle(degree d) 
         : pv_radians( d.pv_value * anAngle::pv_pi / 180.0 ), 
           pv_degrees( d ) { /* empty */ }

   // type conversion operator (returns only the radian measure)
      operator double () { return pv_radians(); }

   // assignment operators
      anAngle& operator=( const radian& r )
      {
         pv_radians = r;
         pv_degrees = r.pv_value * 180.0 / pv_pi;
         return *this;
      }

      anAngle& operator=( const degree& d )
      {
         pv_degrees = d;
         pv_radians = d.pv_value * pv_pi / 180.0;
         return *this;
      }

   protected:

   private:
   // the data
      radian pv_radians;   // angle stored as radians
      degree pv_degrees;   // angle stored as degrees
      static const double pv_pi;
};


const double anAngle::pv_pi = 4.0 * atan( 1.0 );

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
