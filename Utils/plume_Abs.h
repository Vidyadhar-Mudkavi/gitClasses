#ifndef _PLUME_ABS_
#define _PLUME_ABS_
/**

  *File: plume_Abs.h

  *Description:
   this file defines functions to evaluate absolute values.
   
  *Version: 1.0 "@(#) Abs. header. ver. 1.0. Premalatha and Vidyadhar, CTFD, NAL."

  *Dependencies:

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL.
  *Date:    January 01, 2003
  */

// system includes
// standard template
// local includes

// const declarations
// function prototypes
// forward declarations

// begin class declaration
namespace plume
{
   template <typename P> P Abs(const P& p)
   {
      return (p < 0) ? -p : p;
   }
}


// include any inline code here
                              //                 
                              //      \\^//      
                              //     o(!_!)o     
                              // --m--  o  --m-- 
                              //                 

#endif   // _PLUME_ABS_
