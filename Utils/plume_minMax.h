#ifndef _PLUME_MINMAX_
#define _PLUME_MINMAX_
/**

  *File: plume_minMax.h

  *Description:
   this class defines a place holder to store min and max of a typical ranged
   variable.

   a template is also provided for using with other data types.
   they must define < and > operators for this to be usable.

  *Version: 1.0 "@(#) minMax. header. ver. 1.0. Premalatha and Vidyadhar, CTFD, NAL."

  *Dependencies:

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL.
  *Date:    September 11, 2000
            August    07, 2002
            April     20, 2006
  */

// system includes
#include <iostream>

// standard template
// local includes

// const declarations
// function prototypes
// forward declarations

// begin class declaration
namespace plume
{
   class minMax      // a simple storage class
   {
      friend std::ostream& operator<<(std::ostream& os, const minMax& mm)
      {
         os << "(" << mm.Min() << ", " << mm.Max() << ") ";
         return os;
      }

      public:
         minMax() : pv_min( 10000000 ), pv_max( -10000000 ) {};
         void operator<<(const minMax& mm)
         {
            if (pv_min > mm.pv_min) pv_min = mm.pv_min;
            if (pv_max < mm.pv_max) pv_max = mm.pv_max;
         }

         void operator<<(double val)
         {
            if (pv_min > val) pv_min = val;
            if (pv_max < val) pv_max = val;
         }

         double Min() const { return pv_min; }
         double Max() const { return pv_max; }
         double Mid() const { return pv_min + 0.5*(pv_max-pv_min); }

         void Min(double min) { pv_min = min; }
         void Max(double max) { pv_max = max; }

         void Reset() { pv_min = 10000000, pv_max = -10000000; }

      protected:
      private:
         double pv_min;
         double pv_max;
   };

// a template as well
   template <typename T>
   class tMinMax      // a simple storage class
   {
      friend std::ostream& operator<<(std::ostream& os, const tMinMax& mm)
      {
         os << "(" << mm.Min() << ", " << mm.Max() << ") ";
         return os;
      }

      public:
         tMinMax() : pv_min( 10000000 ), pv_max( -10000000 ) {};
         void operator<<(const tMinMax& mm)
         {
            if (pv_min > mm.pv_min) pv_min = mm.pv_min;
            if (pv_max < mm.pv_max) pv_max = mm.pv_max;
         }

         void operator<<(double val)
         {
            if (pv_min > val) pv_min = val;
            if (pv_max < val) pv_max = val;
         }

         T Min() const { return pv_min; }
         T Max() const { return pv_max; }
         T Mid() const { return pv_min + 0.5*(pv_max-pv_min); }

         void Min(T min) { pv_min = min; }
         void Max(T max) { pv_max = max; }

         void Reset() { pv_min = 10000000, pv_max = -10000000; }

      protected:
      private:
         T pv_min;
         T pv_max;
   };

}


// include any inline code here
                              //                 
                              //      \\^//      
                              //     o(!_!)o     
                              // --m--  o  --m-- 
                              //                 

#endif   // _PLUME_MINMAX_
