#ifndef _VECTOROPTIONS_
#define _VECTOROPTIONS_
/**
   
  *File: vectorOptions.h

  *Description:

   this file essentially contains some of the header information
   we maintain. 

   each definition is encapsulated in the following form:

   #if ** either 0 or 1 **
   #ifndef OPTION
   #define OPTION
   #endif
   #endif

   to simply turn on an option, change the first line to #if 1
   otherwise make it zero

  *Version: 1.6

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD Division, NAL
  *Date:    20 July 1998

  */


// turn this on for debug messages etc. this is a global flag
// i.e., all classes will have one like this
#if 1
#ifndef DEBUG_ON
#define DEBUG_ON
#endif
#endif

// this debug one is local. applies only to the vector class
#if 1
#ifndef VECTOR_DEBUG_ON
#define VECTOR_DEBUG_ON
#endif
#endif

// turn this on for bounds checking
#if 1
#ifndef VECTOR_CHECKBOUNDS_ON
#define VECTOR_CHECKBOUNDS_ON
#endif
#endif

// when we decide to stop on errors instead of raising exceptions
#if 1
#ifndef VECTOR_STOP_ON_ERROR
#define VECTOR_STOP_ON_ERROR
#endif
#endif

/**
   the standard language does not have NULL. it is only in
   the microsoft implementation as an extension. therefore,
   we must not use this as far as possible. we introduce,
   for readability, NULL_PTR instead. but, where possible,
   we use zero for null pointer.
  */
#if 1
#ifndef NULL_PTR
#define NULL_PTR 0
#endif
#endif

#endif // _VECTOROPTIONS_
