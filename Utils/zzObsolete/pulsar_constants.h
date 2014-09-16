#ifndef _PULSAR_CONSTANTS_
#define _PULSAR_CONSTANTS_
/**

  *File: pulsar_constants.h

  *Description:

   this file stores a collection of useful constants such as
   the pi, pi/2, 2*pi etc. they are enclosed in the namespace pulsar.


  *Note:    note that the prefix pulsar implies namespace encapsulation.

  *Version: 1.0 "@(#) pulsar::constants. header. ver. 1.0. Premalatha and Vidyadhar, CTFD, NAL."

  *Dependencies:

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL.
  *Date:    August 16, 2000
  */

#include <cmath>

// begin class declaration

// dummy class (for vc++ browsing!)
class pulsarConstants
{
};

namespace pulsar
{
// mathematical constants
   const double pi         = 4.0 * ::atan(1.0);
   const double two_pi     = 2.0 * pi;
   const double pi_by_two  = pi / 2.0;
   const double pi_square  = pi * pi;

   const double root_two   = ::sqrt(2.0);
   const double root_three = ::sqrt(3.0);

   const double e          = ::cosh(1.0) + ::sinh(1.0);  // napier's constant
   const double gamma      = 0.577215664901532860606512; // euler constant

// physical constants
   const double c    = 2.997925  * 1.0e+08;  // speed of light in vacuum (m/s)
   const double ec   = 1.6021917 * 1.0e-19;  // elementary charge (coulomb) 
   const double N_a  = 6.022169  * 1.0e+23;  // avogadro constant ( mol ^ -1)
   const double u    = 1.660531  * 1.0e-27;  // atomic mass unit (kg)
//   const double 
//   const double 
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

#endif   // _PULSAR_CONSTANTS_
