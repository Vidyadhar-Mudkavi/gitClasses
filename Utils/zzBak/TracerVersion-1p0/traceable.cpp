/**

  *File: traceable.cpp

  *Description:

   This file contains the implementation code the traceable interface.

  *Version: 1.0 "@(#) traceable. header. ver. 1.0. Premalatha and Vidyadhar, CTFD, NAL."

  *Dependencies: none

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL

  *Date:    February 13, 2001
  */

// system includes
// local includes
//#include "traceable.h"

// const declarations
//const char* traceable_id = 
//   "@(#) traceable. implementation. ver. 1.0. Premalatha and Vidyadhar, CTFD, NAL.";

// function prototypes
// forward declarations
// begin class implementation

// static data initialization
#if 0
std::list<long int> traceable::pv_constructed;
std::list<long int> traceable::pv_destroyed;
long int            traceable::pv_live_objects = 0;
long int            traceable::pv_total_objects = 0;
std::string         traceable::pv_object_name = "<<SomeObjectBeingTraced>>";
#endif


//#if 1
//namespace eatc
//{
std::list<long int> traceable::pv_constructed;
std::list<long int> traceable::pv_destroyed;
long int            traceable::pv_live_objects = 0;
long int            traceable::pv_total_objects = 0;
std::string         traceable::pv_object_name = "<<SomeObjectBeingTraced>>";
//}
//#endif
   ////////////////////////////////////////
   //                                      
   //    implement constructors here       
   //                                      
   //                                      

/**
  *Purpose:
  */
#if 0
traceable::traceable()
{
}
#endif

