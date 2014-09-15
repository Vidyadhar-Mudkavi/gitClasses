#ifndef _TPOLYNOMIAL_
#define _TPOLYNOMIAL_
/**
  *File: tPolynomial.h

  *Description:
   this file declares class tPolynomial. this is a template for
   abstracting a polynomial.

  *Version: 1.0 "@(#) tPolynomial. header. ver. 1.0. Premalatha, Vidyadhar Mudkavi, CTFD, NAL."

  *Dependencies:

  *NOTE: prototype for a friend function receiving the template class
         as its parameter is different in MSVC and unix (at least
         on SGI Irix). note the difference in the declaration of
         overloaded operator << for printing.

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL.

  *Date:    May 15, 2001,
            Aug 10, 2001 (canonical form and conversion to template)
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

template <class real>
class tPolynomial
{
#  if defined(_MSC_VER)
   inline friend std::ostream& operator<<(std::ostream& os, 
                                          const tPolynomial& p);
#  else
   template<class real>
   inline friend std::ostream& operator<<(std::ostream& os, 
                                          const tPolynomial& p);
#  endif

   public:
   // constructors
      tPolynomial();
      tPolynomial(int degree);
      tPolynomial(std::vector<real> coeffs);
      tPolynomial(std::valarray<real> coeffs);

      tPolynomial(const tPolynomial& p);

   // assignment operator
      tPolynomial& operator=(const tPolynomial& p);

   // destructor
      ~tPolynomial();

   // accessors
      void Set(std::vector<real> coeffs);
      void Set(std::valarray<real> coeffs);

      void Set(int degree);

      inline int Degree() const;

   // provide two function to access coefficients
   // one with bounds checked, the other not.
      inline real a(int index) const;     // breaking rule
      inline real BCa(int index) const;   // with bound check
      inline real operator[](int index) const;

   // other functionality
      inline real operator()(real x) const;
      tPolynomial operator*(const tPolynomial& p) const;
      
      void Print(std::ostream& os) const;

   protected:
      inline int&  Degree();
      inline real& operator[](int index);
   private:
   // helper functions
      real Evaluate(real x) const;

   // data
      int   pv_degree;
      real* pv_coeff;
};

// include any inline code here

// constructors

template<class real>
tPolynomial<real>::tPolynomial()
   : pv_degree( 0 ),
     pv_coeff( 0 )
{
// empty
}

template<class real>
tPolynomial<real>::tPolynomial(int degree)
   : pv_degree( degree ),
     pv_coeff( new real[degree+1] )
{
   int i;
   for (i=0; i<=degree; ++i)
   {
      pv_coeff[i] = 0.0;
   }
}

template<class real>
tPolynomial<real>::tPolynomial(std::vector<real> coeff)
{
   pv_degree = coeff.size() - 1;
  
   pv_coeff = new real[pv_degree+1];

   int i;
   for (i=0; i<=pv_degree; ++i)
   {
      pv_coeff[i] = coeff[i];
   }
}


template<class real>
tPolynomial<real>::tPolynomial(std::valarray<real> coeff)
{
   pv_degree = coeff.size() - 1;

   pv_coeff = new real[pv_degree+1];

   int i;
   for (i=0; i<=pv_degree; ++i)
   {
      pv_coeff[i] = coeff[i];
   }
}


// copy construction

template<class real>
tPolynomial<real>::tPolynomial(const tPolynomial& p)
   : pv_degree( p.pv_degree ),
     pv_coeff( new real[p.pv_degree+1] )
{
   int i;
   for (i=0; i<=pv_degree; ++i)
   {
      pv_coeff[i] = p.pv_coeff[i];
   }
}


// deletion

template<class real>
tPolynomial<real>::~tPolynomial()
{
   delete [] pv_coeff;
}


// assignement
template<class real>
tPolynomial<real>& tPolynomial<real>::operator=(const tPolynomial& p)
{
   pv_degree = p.pv_degree;
   
   pv_coeff  = new real[pv_degree+1];
   
   int i;
   for (i=0; i<=pv_degree; ++i)
   {
      pv_coeff[i] = p.pv_coeff[i];
   }

   return *this;
}

// accessors
template<class real>
void tPolynomial<real>::Set(std::vector<real> coeff)
{
// TODO
   throw "tPolynomial::Set(std::vector) is undefined!";
}

template<class real>
void tPolynomial<real>::Set(std::valarray<real> coeff)
{
   if ( pv_coeff != 0 )
   {
      delete [] pv_coeff;
   }
   
   pv_degree = coeff.size() - 1;

   pv_coeff = new real[pv_degree+1];

   int i;
   for (i=0; i<=pv_degree; ++i)
   {
      pv_coeff[i] = coeff[i];
   }
}

template<class real>
void tPolynomial<real>::Set(int degree)
{
// TODO
   throw "tPolynomial::Set(int degree) is undefined!";
}


template<class real>
inline int& tPolynomial<real>::Degree()
{
   return pv_degree;
}

template<class real>
inline real& tPolynomial<real>::operator[](int index)
{
   return pv_coeff[index];
}


template<class real>
tPolynomial<real> tPolynomial<real>::operator*(const tPolynomial& p) const
{
   int N = pv_degree;
   int M = p.pv_degree;
   
   const real* alpha = pv_coeff;
   const real* beta  = p.pv_coeff;
   
   std::vector<real> gamma;
   real gammaj;
   
   if ( M <= N )
   {
      int i, j;
      for (j=0; j<=M; ++j)
      {
         gammaj = 0.0;
         for (i=0; i<=j; ++i)
         {
            gammaj += alpha[j-i] * beta[i];
         }
         gamma.push_back(gammaj);
      }
      
      if ( M != N )
      {
         for (j=M+1; j<=N; ++j)
         {
            gammaj = 0.0;
            for (i=0; i<=M; ++i)
            {
               gammaj += alpha[j-i] * beta[i];
            }
         gamma.push_back(gammaj);
         }
      }
      
      for (j=N+1; j<=N+M; ++j)
      {
         gammaj = 0.0;
         for (i=j-N; i<=M; ++i)
         {
            gammaj += alpha[j-i] * beta[i];
         }
      gamma.push_back(gammaj);
      }

      return tPolynomial(gamma);
   }
   
   int i, j;
   
   for (j=0; j<=N; ++j)
   {
      gammaj = 0.0;
      for (i=0; i<=j; ++i)
      {
         gammaj += alpha[i] * beta[j-i];
      }
      gamma.push_back(gammaj);
   }
   
   for (j=N+1; j<=M; ++j)
   {
      gammaj = 0.0;
      for (i=0; i<=N; ++i)
      {
         gammaj += alpha[i] * beta[j-i];
      }
      gamma.push_back(gammaj);
   }
   
   for (j=M+1; j<=M+N; ++j)
   {
      gammaj = 0.0;
      for (i=j-M; i<=N; ++i)
      {
         gammaj += alpha[i] * beta[j-i];
      }
      gamma.push_back(gammaj);
   }
  
   return tPolynomial(gamma);
   
}

template<class real>
real tPolynomial<real>::Evaluate(real x) const
{
   int i;
   const int& n = pv_degree;
   
   real result = 0.0;
   const real* p = pv_coeff;
   
   result = p[n];
   
   for (i=n; i>0; --i)
   {
      result = p[i-1] + x * result;
   }
   
   return result;
}


template<class real>
void tPolynomial<real>::Print(std::ostream& os) const
{
   int i;
   
   char comma = ',';
   char space = ' ';
   
   for (i=0; i<pv_degree; ++i)
   {
      os << pv_coeff[i] << comma << space;
   }
   
   os << pv_coeff[pv_degree] << std::endl;
}


template<class real>
inline real tPolynomial<real>::operator()(real x) const
{
   return Evaluate(x);
}

template<class real>
inline real tPolynomial<real>::a(int i) const
{
   return pv_coeff[i];
}

template<class real>
inline real tPolynomial<real>::BCa(int i) const
{
   return ( (i>=0) && (i<=pv_degree) ) ? pv_coeff[i] : 0.0;
}

template<class real>
inline real tPolynomial<real>::operator[](int i) const
{
   return pv_coeff[i];
}


template<class real>
inline int tPolynomial<real>::Degree() const
{
   return pv_degree;
}

template<class real>
inline std::ostream& operator<<(std::ostream& os, const tPolynomial<real>& p)
{
   p.Print(os);
   return os;
}

/**
   declare any typedef statements here   (e.g.: typedef aVortex areVortices;)
  */
                              //                 
                              //      \\^//    
                              //     o(!_!)o     
                              // __m__  o  __m__ 
                              //                 

#endif   // _TPOLYNOMIAL_
