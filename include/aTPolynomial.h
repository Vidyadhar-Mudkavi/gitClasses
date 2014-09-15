#ifndef _ATPOLYNOMIAL_
#define _ATPOLYNOMIAL_
/**
  *File: aTPolynomial.cpp

  *Description:

  *Version: 1.0 "@(#) aTPolynomial. header. May 15, 2001. ver. 1.0. vm,pl., CTFD, NAL."

  *Authors: Vidyadhar Mudkavi
  *Date:    May 15, 2001
  */

// system includes
// standard template
#include <vector>
#include <valarray>

// local includes
// const declarations
// function prototypes
// forward declarations

// begin class declaration

template <class real>
class aTPolynomial
{
   template<class T>
   inline friend std::ostream& operator<<(std::ostream& os, 
                                          const aTPolynomial<T>& p);

   public:
   // constructors
      aTPolynomial();
      aTPolynomial(int degree);
      aTPolynomial(std::vector<real> coeffs);
      aTPolynomial(std::valarray<real> coeffs);

      aTPolynomial(const aTPolynomial& p);

   // destruction
      virtual ~aTPolynomial();

   // assigment
      aTPolynomial& operator=(const aTPolynomial& p);

   // accessors
      void Set(std::vector<real> coeffs);
      void Set(std::valarray<real> coeffs);

      void Set(int degree);

      inline int Degree() const;

   // provide two function to access coefficients
   // one with bounds checked, the other not.
      inline real a(int index) const;     // breaking rule
      inline real bca(int index) const;   // with bound check
      inline real operator()(int index) const;

   // other functionality
      inline real operator()(real x) const;
      aTPolynomial operator*(const aTPolynomial& p) const;
      
      void Print(std::ostream& os) const;

   protected:
      inline int& Degree();
      inline real& operator[](int index);
   private:
   // helper functions
      real Evaluate(real x) const;

   // data
      int   pv_degree;
      real* pv_coeff;
};


// inline implementation. all are inline (template)

// constructors

template<class real>
aTPolynomial<real>::aTPolynomial()
   : pv_degree( 0 ),
     pv_coeff( 0 )
{
// empty
}

template<class real>
aTPolynomial<real>::aTPolynomial(int degree)
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
aTPolynomial<real>::aTPolynomial(std::vector<real> coeff)
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
aTPolynomial<real>::aTPolynomial(std::valarray<real> coeff)
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
aTPolynomial<real>::aTPolynomial(const aTPolynomial& p)
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
aTPolynomial<real>::~aTPolynomial()
{
   delete [] pv_coeff;
}


// assignement
template<class real>
aTPolynomial<real>& aTPolynomial<real>::operator=(const aTPolynomial& p)
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
void aTPolynomial<real>::Set(std::vector<real> coeff)
{
// TODO
   throw "aTPolynomial::Set(std::vector) is undefined!";
}

template<class real>
void aTPolynomial<real>::Set(std::valarray<real> coeff)
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
void aTPolynomial<real>::Set(int degree)
{
// TODO
   throw "aTPolynomial::Set(int degree) is undefined!";
}


template<class real>
inline int& aTPolynomial<real>::Degree()
{
   return pv_degree;
}

template<class real>
inline real& aTPolynomial<real>::operator[](int index)
{
   return pv_coeff[index];
}


template<class real>
aTPolynomial<real> aTPolynomial<real>::operator*(const aTPolynomial& p) const
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

      return aTPolynomial(gamma);
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
  
   return aTPolynomial(gamma);
   
}


template<class real>
real aTPolynomial<real>::Evaluate(real x) const
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
void aTPolynomial<real>::Print(std::ostream& os) const
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
inline real aTPolynomial<real>::operator()(real x) const
{
   return Evaluate(x);
}

template<class real>
inline real aTPolynomial<real>::a(int i) const
{
   return pv_coeff[i];
}

template<class real>
inline real aTPolynomial<real>::bca(int i) const
{
   return ( (i>=0) && (i<=pv_degree) ) ? pv_coeff[i] : 0.0;
}

template<class real>
inline real aTPolynomial<real>::operator()(int i) const
{
   return pv_coeff[i];
}


template<class real>
inline int aTPolynomial<real>::Degree() const
{
   return pv_degree;
}

template<class real>
inline std::ostream& operator<<(std::ostream& os, const aTPolynomial<real>& p)
{
   p.Print(os);
   return os;
}

                              //                 
                              //      \\^//      
                              //     o(!_!)o     
                              // --m--  o  --m-- 
                              //                 

#endif   // _ATPOLYNOMIAL_

