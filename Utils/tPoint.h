#ifndef _TPOINT_
#define _TPOINT_
/**
  *File: tPoint.h

  *Description:

   this file declares template class tPoint.
   this class will be used to store a three dimensional point.
   the components of the point use the standard name x and y.
   the function to retrieve the values are X() and Y(). the
   same ones with arguments will store the values.

   the class provides the following functionality:
      tPoint p1, p2, p3;
      REAL     alpha;
      p1 = p1 + p1;
      p1 = alpha * p2;  p2 = p2 * alpha;
      p3 = p2  - p1;
      p2 += p1;   p1 -= p2;
      p3 *= alpha;

   the operator () returns a const pointer to the array containing the two values.
   this is usefule in OpenGL applications.


  *Version: 1.0 "@(#) tPoint. header. ver. 1.0. Premalatha, Vidyadhar Mudkavi, CTFD, NAL."

  *Dependencies:

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL.

  *Date:    Aug 20, 2001
  */

// system includes
#include <iostream>

// standard template
// local includes
// const declarations
// function prototypes
// forward declarations

// begin class declaration
template <typename REAL>
class tPoint
{
// friends are declared differently!
#if defined(_MSC_VER)
   inline friend std::ostream& operator<<( std::ostream& os,
                                           const tPoint<REAL>& p )
   {
      p.FancyPrint(os);
      return os;
   }
   inline friend std::istream& operator>>( std::istream& is, 
                                           tPoint<REAL>& p )
   {
      is >> p.pv_x >> p.pv_y >> p.pv_z;
      return is;
   }

   inline friend tPoint< REAL > operator*( const REAL& alpha, 
                                           const tPoint<REAL>& p )
   {
      return tPoint< REAL >( alpha*p.pv_x, alpha*p.pv_y, alpha*p.pv_z );
   }

   inline friend tPoint< REAL > operator/( const tPoint<REAL>& p, 
                                           const REAL& alpha
                                         )
   {
      return tPoint< REAL >(p.pv_x/alpha, p.pv_y/alpha, p.pv_z/alpha);
   }
#else
   template <typename REAL_T>
   inline friend std::ostream& operator<<( std::ostream& os,
                                           const tPoint<REAL_T>& p );
   template <typename REAL_T>
   inline friend std::istream& operator>>( std::istream& is,
                                           tPoint<REAL_T>& p );
   template <typename REAL_T>
   inline friend tPoint< REAL_T > operator*( const REAL_T& alpha, 
                                             tPoint<REAL_T>& p );
#endif
   public:
   // constructors
      tPoint(REAL x=0, REAL y=0, REAL z=0) : pv_x( x ), pv_y( y ), pv_z( z ) {
      // empty
      }
      tPoint(const tPoint& p) : pv_x( p.pv_x ), pv_y( p.pv_y ), pv_z( p.pv_z ) {
      // empty
      }

   // assignment operator
      inline tPoint& operator=(const tPoint& p);

   // destructor
      ~tPoint() { /* empty */ }

   // accessors
      inline void X(const REAL& x);
      inline void Y(const REAL& y);
      inline void Z(const REAL& z);
      inline void Set(const REAL& x, const REAL& y, const REAL& z);

      inline REAL X() const;
      inline REAL Y() const;
      inline REAL Z() const;

      inline REAL& X();
      inline REAL& Y();
      inline REAL& Z();

      inline REAL operator()(int index) const;  // get method (by index)
      inline REAL& operator[](int index);       // set method (by index)

      inline const REAL* operator()() const;    // for OpenGL
      int Size() const {                        // also for OpenGL
         return 3;
      }
      
   // operations
      inline tPoint operator+(const tPoint& p) const {
         return tPoint( (pv_x + p.pv_x), (pv_y + p.pv_y), (pv_z + p.pv_z) );
      }

      inline tPoint operator-(const tPoint& p) const {
         return tPoint( (pv_x - p.pv_x), (pv_y - p.pv_y), (pv_z - p.pv_z) ); 
      }

      inline tPoint& operator+=(const tPoint& p);
      inline tPoint& operator-=(const tPoint& p);
      inline tPoint& operator*=(const REAL& alpha);
      inline tPoint operator*(const REAL& alpha) const {
         return tPoint( alpha*pv_x, alpha*pv_y, alpha*pv_z ); 
      }

      inline tPoint& operator/=(const REAL& alpha);

   // output
      inline void FancyPrint(std::ostream& os) const;
      inline void Print(std::ostream& os, char* sep=", ") const;

   protected:
   // helpers
      inline void CheckBounds(int index) const;
   private:
      REAL pv_x, pv_y, pv_z;
};

// template implementation code starts here


// *Purpose:   provides assignement operator
template <typename REAL>
inline tPoint<REAL>& tPoint<REAL>::operator=(const tPoint<REAL>& p)
{
   pv_x = p.pv_x; pv_y = p.pv_y; pv_z = p.pv_z;
   return *this;
}

   ////////////////////////////////////////////
   //                                          
   //   implement other member functions here  
   //                                          
   //                                          

// *Purpose:   sets the first coordinate to x
template <typename REAL>
inline void tPoint<REAL>::X(const REAL& x) 
{
   pv_x = x;
}

// *Purpose:   sets the second coordinate to y
template <typename REAL>
inline void tPoint<REAL>::Y(const REAL& y) 
{
   pv_y = y;
}

// *Purpose:   sets the third coordinate to z
template <typename REAL>
inline void tPoint<REAL>::Z(const REAL& z) 
{
   pv_z = z;
}

// *Purpose:   sets the coordinates to x and y
template <typename REAL>
inline void tPoint<REAL>::Set(const REAL& x, const REAL& y, const REAL& z)
{
   pv_x = x;   pv_y = y;   pv_z = z;
}

// *Purpose:   returns the first coordinate
template <typename REAL>
inline REAL tPoint<REAL>::X() const 
{
   return pv_x;
}

// *Purpose:   returns the second coordinate
template <typename REAL>
inline REAL tPoint<REAL>::Y() const 
{
   return pv_y;
}

// *Purpose:   returns the third coordinate
template <typename REAL>
inline REAL tPoint<REAL>::Z() const 
{
   return pv_z;
}

///////////////////////////////////
//
// access by context
template <typename REAL>
inline REAL& tPoint<REAL>::X()
{
   return pv_x;
}

// *Purpose:   returns the second coordinate
template <typename REAL>
inline REAL& tPoint<REAL>::Y()
{
   return pv_y;
}

// *Purpose:   returns the third coordinate
template <typename REAL>
inline REAL& tPoint<REAL>::Z()
{
   return pv_z;
}



// *Purpose:   access by index (useful in tensor notation)
template <typename REAL>
inline REAL tPoint<REAL>::operator()(int index) const 
{
   if ( index == 0 ) return pv_x;
   if ( index == 1 ) return pv_y;
   if ( index == 2 ) return pv_z;
   std::cout << "**** Index out of bounds in tPoint::operator()(int index) ***" << std::endl;
   ::exit(-1);
   return REAL(-99999.0);  // a dummy return. sgi compiler complains.
}

// *Purpose:   set access by index (useful in tensor notation)
template <typename REAL>
inline REAL& tPoint<REAL>::operator[](int index) 
{
   if ( index == 0 ) return pv_x;
   if ( index == 1 ) return pv_y;
   if ( index == 2 ) return pv_z;
   std::cout << "**** Index out of bounds in tPoint::operator()(int index) ***" << std::endl;
   ::exit(-1);
   REAL dummy(-99999.0);
   return dummy;  // a dummy return. sgi compiler complains.
}


// *Purpose:   returns an array containing the coordinates.
//             this is usefule in OpenGL applications
template <typename REAL>
inline const REAL* tPoint<REAL>::operator()() const 
{
   REAL* ret_val = new REAL[3];
   ret_val[0] = pv_x; ret_val[1] = pv_y;  ret_val[2] = pv_z;
   return ret_val;
}

// *Purpose:   increments this point with p (translation)
template <typename REAL>
inline tPoint<REAL>& tPoint<REAL>::operator+=(const tPoint<REAL>& p) 
{
   pv_x += p.pv_x;  pv_y += p.pv_y;    pv_z += p.pv_z;
   return *this;
}

// *Purpose:   decrements this point with p (translation)
template <typename REAL>
inline tPoint<REAL>& tPoint<REAL>::operator-=(const tPoint<REAL>& p) 
{
   pv_x -= p.pv_x;  pv_y -= p.pv_y;    pv_z -= p.pv_z;
   return *this;
}

// *Purpose:   scales this point by alpha
template <typename REAL>
inline tPoint<REAL>& tPoint<REAL>::operator*=(const REAL& alpha) 
{
   pv_x *= alpha;  pv_y *= alpha;   pv_z *= alpha;
   return *this;
}

// *Purpose:   scales this point by 1/alpha
template <typename REAL>
inline tPoint<REAL>& tPoint<REAL>::operator/=(const REAL& alpha)
{
   pv_x /= alpha; pv_y /= alpha; pv_z /= alpha;
   return *this;
}

// *Purpose:   prints this point (fancy output of form (x,y,z))
template <typename REAL>
inline void tPoint<REAL>::FancyPrint(std::ostream& os) const
{
   os << " (" << pv_x << ", " << pv_y << ", " << pv_z << ") ";
}
 
// *Purpose:   simple character separated print
template <typename REAL>
inline void tPoint<REAL>::Print(std::ostream& os, char* sep) const
{
   os << pv_x << sep << pv_y << sep << pv_z;
}


   ////////////////////////////////////////////
   //                                          
   //   implement friend functions here  
   //                                          
   //                                          

// for MSC compiler, the friends had to be declared inline
#if !defined(_MSC_VER)
template <typename REAL_T>
inline std::ostream& operator<<( std::ostream& os,
                                 const tPoint<REAL_T>& p )
{
   p.FancyPrint(os);
   return os;
}

template <typename REAL_T>
inline std::istream& operator>>( std::istream& is,
                                 tPoint<REAL_T>& p )
{
   is >> p.pv_x >> p.pv_y >> p.pv_z;
   return is;
}

template <typename REAL_T>
inline tPoint< REAL_T > operator*( const REAL_T& alpha, 
                                   tPoint<REAL_T>& p )
{
   return tPoint< REAL_T >( alpha*p.pv_x, alpha*p.pv_y, alpha*p.pv_z );
}
#endif


// *Purpose:   scales the point by alpha
//#if !defined(_MSC_VER)
#if 0
template <typename REAL_t >
inline tPoint< REAL_t > operator*( const REAL_t& alpha, 
                                   const tPoint<REAL_t >& p )
{
   return tPoint< REAL_t >( alpha*p.pv_x, alpha*p.pv_y, alpha*p.pv_z );
}
#endif
//#endif


// *Purpose:   prints point p via << operator
#if 0
template <typename REAL>
inline std::ostream& operator<<(std::ostream& os, const tPoint<REAL>& p)
{
   p.FancyPrint(os);
   return os;
}
#endif

#if 0
template <typename REAL_t >
inline std::istream& operator>>( std::istream& is, 
                                 tPoint<REAL_t >& p )
{
   is >> p.pv_x >> p.pv_y >> p.pv_z;
   return is;
}
#endif

/**
   declare any typedef statements here   (e.g.: typedef aVortex areVortices;)
  */
                              //                 
                              //      \\^//    
                              //     o(!_!)o     
                              // __m__  o  __m__ 
                              //                 

#endif   // _TPOINT_
