/**

  *File: pulsar.cpp

  \brief
   -  This file contains the implementation of pulsar class. this
      class essentially holds various mathematical and
      physical constants. they are, of course, static objects.

      earlier, these were enclosed in a namespace (file pulsar_constants.h).
      however, this results in unpredicted behaviour since some constants
      may not initialize on first use properly. (there is no language
      guarantee).
   

      data marked with [W] taken from en.wikipedia.org/wiki
         
  \version  1.0

  *Dependencies:

  \authors
      -  Premalatha, Vidyadhar Mudkavi, CTFD, NAL

  \date:    
      -  June      26, 2003
  */

// system includes

// sgi does not provide <cmath> header in place of <math.h>
#if defined(__sgi) && !defined(__GNUC__)
#  include <math.h>
#else
#  include <cmath>
#endif

// local includes
#include "pulsar.h"

// const declarations
const char* pulsar_id = 
   "@(#) pulsar. implementation. ver. 1.0. Premalatha and Vidyadhar, CTFD, NAL.";

// function prototypes
// forward declarations
// static data initialization


// mathematical constants
const double pulsar::pi         = 3.14159265358979323846264338327950288; // [W]
const double pulsar::e          = 2.71828182845904523536028747135266249; // [W] Napier constant

const double pulsar::two_pi     = 2.0 * pi;
const double pulsar::four_pi    = 4.0 * pi;
const double pulsar::pi_by_two  = pi / 2.0;
const double pulsar::pi_square  = pi * pi;

const double pulsar::root_two   = ::sqrt(2.0);
const double pulsar::root_three = ::sqrt(3.0);

const double pulsar::gamma      = 0.57721566490153286060651209008240243; // [W] euler constant

// physical constants
const double pulsar::c    = 2.99792458  * 1.0e+08;  // speed of light in vacuum (m/s) [W]
const double pulsar::ec   = 1.602176462 * 1.0e-19;  // elementary charge (C=coulomb) [W] 
const double pulsar::N_A  = 6.02214199  * 1.0e+23;  // Avogadro's constant (mol^-1) [W]
const double pulsar::m_u  = 1.66053873  * 1.0e-27;  // atomic mass unit (kg) [W]



////////////////////////////////////////////////
//
// implementation to guarantee proper initialization.
//

short int pulsarInitializer::pv_count(0);

pulsarInitializer::pulsarInitializer()
{
   if (pv_count++ == 0)
   {
      pulsar::Init();
   }
}


pulsarInitializer::~pulsarInitializer()
{
   if (--pv_count == 0)
   {
   }
}


void pulsar::Init()
{
// empty
}


