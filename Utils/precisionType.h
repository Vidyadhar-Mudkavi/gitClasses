#ifndef _PRECISIONTYPE_
#define _PRECISIONTYPE_
/**

  *File: precisionType.h

  *Description:
   this class is used to introduce a name into the programs. the
   main aim is to have a central control of the precision by a given application.
   the application uses objects of many classes which contain data. the type
   of the data (only with respect to the float or double) is left undetermined.
   we use a standard name real for this purpose. 

   the name real is used as a synonym for precision and the precision may
   be set to float or double by a given application.

   since the standard name real is a typedef for precision, we need a dummy class
   precision. this class serves that purpose.

  *Version: 1.0 "@(#) precision. header. ver. 1.0. Premalatha and Vidyadhar, CTFD, NAL."

  *Dependencies:

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL.
  *Date:    August 23, 2000
  */

// local includes
// begin class declaration
struct precisionType
{
// empty
};

/**
   declare any typedef statements here
     ex: typedef aVortex areVortices;
   so that we can declare
     areVortices v1, v2, v3;
  */
typedef precisionType precision;
                              //                 
                              //      \\^//      
                              //     o(!_!)o     
                              // --m--  o  --m-- 
                              //                 

#endif   // _PRECISIONTYPE_
