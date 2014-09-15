#ifndef _ACOMPLEX_
#define _ACOMPLEX_

/** 
 
  *File: acomplex.h

  *Description: 
   the mathematical complex number class

  *Version: 1.2

  *Notes:

   version 1.1 contains java style operations. these are 
   replaced by C++ operations

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD Division, NAL
  *Date:    May 15, 1998, 13 Aug 1998
  */


#include <iostream.h>

class aComplex
{
   public:

   // constructors
      aComplex();                    // the default constructor (zero)
      aComplex(double x, double y);  // typical constructor
      aComplex(const aComplex& z);   // the special constructor

   // assignment operator
      aComplex& operator=(const aComplex& z);
      
   // destructor
      ~aComplex() { /* empty */}

   // accessor methods
      double GetRealPart() const;
      double GetImagPart() const;

      void   SetRealPart(double x);
      void   SetImagPart(double y);
      void   SetComplex(double x, double y);

   // other things meaningful for complex numbers
      double GetMag() const;
      double GetArg() const;
      double GetMagSquare() const;

   // operations to add, subtract etc
      aComplex operator+(const aComplex& z);
      aComplex operator-(const aComplex& z);
      aComplex operator*(const aComplex& z);
      aComplex Conj() const;
      aComplex operator/(double alpha);
      aComplex operator/(const aComplex& z);

   // friend operators
      friend aComplex operator+(const aComplex& z, double alpha);
      friend aComplex operator+(double alpha,      const aComplex& z);

      friend aComplex operator-(const aComplex& z, double alpha);
      friend aComplex operator-(double alpha,      const aComplex& z);
      
      friend aComplex operator*(const aComplex& z, double alpha);
      friend aComplex operator*(double alpha,      const aComplex& z);

   // operators to do io
      friend ostream& operator<<(ostream& os, const aComplex& z);
      friend istream& operator>>(istream& is, aComplex& z);

   protected:

   private:
      double x;   // the real part
      double y;   // the imaginary part
};

#endif //  _ACOMPLEX_
