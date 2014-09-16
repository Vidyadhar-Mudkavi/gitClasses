#ifndef _PULSAR_H_
#define _PULSAR_H_
/**

  *File: pulsar.h

  *Description:

   this file stores a collection of useful constants such as
   the pi, pi/2, 2*pi etc. earlier they were enclosed in a namespace.
   but this creates a problem of proper initialization of the constants.
   it is, therefore, safer to enclose them in a class and then
   initialize them in an implementation file.

   when static data is implemented across different implementation files,
   and if one file uses the data from the other, then there is a potential
   danger. there is no guarantee of initialization.

   here, we hard code the values for pi and e. it appears that there is
   always a difficulty in initializing pi with a call to atan function. we
   have not sorted this out yet.

   there is a solution to ensure that the data is correctly initialized when
   used across implementation files. this is done through an initializer class.
   see http://aips2.nrao.edu/released/docs/notes/173.text

   the constants marked with [W] are taken from
         http://en.wikipedia.org/
   

  *Version: 1.0 "@(#) pulsar. header. ver. 1.0. Premalatha and Vidyadhar, CTFD, NAL."

  *Dependencies:

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL.
  *Date:    August 16, 2000
            June   26, 2003   // converted from pulsar_constants namespace
                              // to genuine class
  */


// system includes

// standard template

// local includes

// const declarations
// function prototypes
// forward declarations

class pulsar
{
   friend class pulsarInitializer;
   public:

// mathematical constants
   static const double pi;
   static const double two_pi;
   static const double four_pi;
   static const double pi_by_two;
   static const double pi_square;

   static const double root_two;
   static const double root_three;

   static const double e;     // napier's constant
   static const double gamma; // euler constant

// physical constants
   static const double c;     // speed of light in vacuum (m/s)
   static const double ec;    // elementary charge (coulomb) 
   static const double N_A;   // avogadro constant (mol^-1)
   static const double m_u;   // atomic mass unit (kg)

   protected:
   private:
      static void Init();
};

// for the purpose of ensuring initialization
class pulsarInitializer
{
   public:
      pulsarInitializer();
      ~pulsarInitializer();
   protected:
   private:
      static short int pv_count;
};

static pulsarInitializer pulsar_initializer;

// include any inline code here

                              //                 
                              //      \\^//      
                              //     o(!_!)o     
                              // --m--  o  --m-- 
                              //                 

#endif   // _PULSAR_H_
