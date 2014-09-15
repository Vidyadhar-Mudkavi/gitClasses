#ifndef _APOLYNOMIAL_
#define _APOLYNOMIAL_
/**
  *File: aPolynomial.h

  *Description:
   this file declares class aPolynomial which abstracts a polynomial
   with real (double precision) coefficients.

  *Version: 1.1 "@(#) aPolynomial. header. ver. 1.1. Premalatha, Vidyadhar Mudkavi, CTFD, NAL."

  *Dependencies:

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL.

  *Date:    May 15, 2001,
            Aug 10, 2001 (canonical form and a few changes in operators)
  */

// system includes
#include <iostream>

// standard template
#include <vector>
#include <valarray>

// local includes
// const declarations
// function prototypes
// forward declarations

// begin class declaration
class aPolynomial
{
   inline friend std::ostream& operator<<(std::ostream& os, const aPolynomial& p);
   public:
   // constructors
      aPolynomial();
      aPolynomial(int degree);
      aPolynomial(std::vector<double> coeffs);
      aPolynomial(std::valarray<double> coeffs);

      aPolynomial(const aPolynomial& p);

   // assignment operator
      aPolynomial& operator=(const aPolynomial& p);

   // destructor
      ~aPolynomial();

   // accessors
      void Set(std::vector<double> coeffs);
      void Set(std::valarray<double> coeffs);

      void Set(int degree);

      inline int Degree() const;

   // provide two function to access coefficients
   // one with bounds checked, the other not.
      inline double a(int index) const;      // breaking rule
      inline double BCa(int index) const;    // with bound check
      inline double operator[](int index) const;

   // other functionality
      inline double operator()(double x) const; // evaluates polynomial
      aPolynomial operator*(const aPolynomial& p) const;
      
      void Print(std::ostream& os) const;

   protected:
   private:
   // helper functions
      double Evaluate(double x) const;

   // data
      int     pv_degree;
      double* pv_coeff;
};

// include any inline code here

// *Purpose:   returns the value of the polynomial at x
inline double aPolynomial::operator()(double x) const
{
   return Evaluate(x);
}

// *Purpose:  returns the i-th coefficient
inline double aPolynomial::a(int i) const
{
   return pv_coeff[i];
}

// *Purpose:  returns i-th coefficient after checking bounds
inline double aPolynomial::BCa(int i) const
{
   return ( (i>=0) && (i<=pv_degree) ) ? pv_coeff[i] : 0.0;
}

// *Purpose:   returns the i-th coefficient via [] operator
inline double aPolynomial::operator[](int i) const
{
   return pv_coeff[i];
}


// *Purpose:   returns the degree of the polynomial
inline int aPolynomial::Degree() const
{
   return pv_degree;
}

// *Purpose: inserts the polynomial into ostream via << operator
inline std::ostream& operator<<(std::ostream& os, const aPolynomial& p)
{
   p.Print(os);
   return os;
}

                              //                 
                              //      \\^//    
                              //     o(!_!)o     
                              // __m__  o  __m__ 
                              //                 

#endif   // _APOLYNOMIAL_
