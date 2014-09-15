#ifndef _A2DVECTOR_INLINE_
#define _A2DVECTOR_INLINE_

/** 
  *File: a2DVector.inl

  *Description:

   This file implements the inline functions associated
   with a2DVector. mostly these would be the accessor member
   functions.

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL
  *Date:    19 February 1997, 08 June 1998, 8 June 1998
            21 July 1998, 17 March 1999
  */

// get the first component
inline double a2DVector::Get1stComponent() const
{
   return pv_p[0];
}

// get the second component
inline double a2DVector::Get2ndComponent() const
{
   return pv_p[1];
}

#endif // _A2DVECTOR_INLINE_
