#ifndef _MACHINECONSTANTS_
#define _MACHINECONSTANTS_

/** 

  *File: machineConstants.h

  *Description:

   This file declares a class named machineConstants which
   provides for four member functions which return the
   smallest and the largest machine constants for both double
   and float types.

   The constants are evaluated when the class is instantiated, i.e.
   the computations are done by the constructor and stored in
   the private variables.

  *IMPORTANT NOTE ON NAMING CONVENTION:
   
   we encountered an interesting bug in this implementation.
   notice that we happily declare variables in the public,
   protected or private blocks and modify them in the member
   functions. often, we declare variables within member functions
   to aid in computation. if is perfectly possible that the
   variable name used in the member functions is the same as that
   of the p/p/p variable (p/p/p meaning that it is either private,
   protected or public). then, the variable declared within the
   member function HIDES the p/p/p variable and any modification
   that are inteded for the p/p/p variable actually remain 
   unaffected. in this case the same thing happened. we had
   f_infinity and d_infinity both being hidden by local declerations
   within the constructor and as a result, the corresponding
   p/p/p variables did not store the correct values. to avoid this,
   we must follow a convention while naming the p/p/p variables.
   we adopt that we will append _PV to all the p/p/p variables
   signifying that it is either a private, protected or public
   variable. this way, we will never declare a similar variable in
   the member functions and when modifying data we will make sure
   that we are addressing the correct variable. this class makes
   use of such a convention.
  
   in addition, if need be we will use the prefix for the variables
   to indicate their type. for instance, we will use:

         this prefix    this type of variable
         ====================================
         ptr_           pointer variable
         bln_           boolean variable
         ref_           reference variable
         cref_          constant reference
         cptr_          constant pointer (rarely used)

         flt_           float variable
         dbl_           double variable
         chr_           a single character
         cstr_          a C string (char* )

   if this makes a user think that the p/p/p variables have
   incredibly ugly looking form, the purpose of data encapsulation
   is actually well served! the class user has no business
   to deal with these directly. direct access should anyway be
   made as difficult as possible. the naming convention will
   help provide a further protection layer. (this we have
   experienced now.)

  *Version: 1.1 "@(#) machineConstants. header. ver. 1.1. Premalatha, Vidyadhar Mudkavi, CTFD, NAL."

  *Dependencies: None

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL.
  *Date:    15 September 1997, 10 January 1999
            2004 May 06
  */


// system includes
// standard template
// local includes
// const declarations
// function prototypes
// forward declarations

// begin class declaration

class machineConstants
{
   public:
   // the constants are evaluated by the default constructor
      machineConstants();  

   // single precision constants
      float  GetMachineFloatSmall()    const;
      float  GetMachineFloatInfinity() const;
      float  GetMachineFloatEpsilon()  const;
      
   // alternate names for the same thing
      float  GetSmallestFloat() const;
      float  GetLargestFloat()  const;
      float  GetEpsilonFloat()  const;

   // double precision constants
      double GetMachineDoubleSmall()    const;
      double GetMachineDoubleInfinity() const;
      double GetMachineDoubleEpsilon()  const;

   // alternate names for the same thing
      double GetSmallestDouble() const;
      double GetLargestDouble()  const;
      double GetEpsilonDouble()  const;

   private:
   // variables that hold the single precision constants
      float  pv_flt_small, pv_flt_infinity, pv_flt_epsilon;

      // variables that hold the double precision constants
      double pv_dbl_small, pv_dbl_infinity, pv_dbl_epsilon;
};

// include inline code here
inline float machineConstants::GetMachineFloatSmall() const
{
   return pv_flt_small;
}

inline float machineConstants::GetMachineFloatInfinity() const
{
   return pv_flt_infinity;
}

inline float machineConstants::GetMachineFloatEpsilon() const
{
   return pv_flt_epsilon;
}

// functions with alternate names
inline float machineConstants::GetSmallestFloat() const
{
   return pv_flt_small;
}

inline float machineConstants::GetLargestFloat() const
{
   return pv_flt_infinity;
}

inline float machineConstants::GetEpsilonFloat() const
{
   return pv_flt_epsilon;
}


// functions to return double precision constants
inline double machineConstants::GetMachineDoubleSmall() const
{
   return pv_dbl_small;
}

inline double machineConstants::GetMachineDoubleInfinity() const
{
   return pv_dbl_infinity;
}

inline double machineConstants::GetMachineDoubleEpsilon() const
{
   return pv_dbl_epsilon;
}


inline double machineConstants::GetSmallestDouble() const
{
   return pv_dbl_small;
}

inline double machineConstants::GetLargestDouble() const
{
   return pv_dbl_infinity;
}

inline double machineConstants::GetEpsilonDouble() const
{
   return pv_dbl_epsilon;
}


/**
   declare any typedef statements here   (e.g.: typedef aVortex areVortices;)
  */
                              //                 
                              //      \\^//    
                              //     o(!_!)o     
                              // __m__  o  __m__ 
                              //                 

#endif   // _MACHINECONSTANTS_
