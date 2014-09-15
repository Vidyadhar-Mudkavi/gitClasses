#ifndef _ANEXCEPTION_
#define _ANEXCEPTION_
/**

  *File: anException.h

  *Description:

   this file declares class anException

  *Version: 1.0

  *Dependencies:

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL

  *Date:
  */

// system includes
#include <iostream>
#include <string>

// local includes
#include "useCount.h"

// const declarations

// namespace

// forward declarations
class exceptionNode;
class anException;

// function prototypes
namespace nal
{
   void Throw(const char*    c_string);
   void Throw(exceptionNode* ptr_en);
   void Throw(exceptionNode& ref_en);
   void Throw(anException    e);
}

// begin class declaration
class anException
{
   friend std::ostream& operator<<(std::ostream& os, const anException& except);
   friend void nal::Throw(const char* c_string);
   friend void nal::Throw(exceptionNode* ptr_en);
   friend void nal::Throw(exceptionNode& ref_en);
   friend void nal::Throw(anException    e);

   public:

   // constructors
      anException(); // default
      anException(const anException& except);
      anException(const char* message);
      anException(exceptionNode* ptr_en); // convert pointed object

   // destructor
      virtual ~anException();


   // string and basic data type insertion operators
      anException& operator<<(const char* str);
      anException& operator<<(int i);
      anException& operator<<(float f);
      anException& operator<<(double d);

   protected:

   private:
   // pointer to node and use counter
      exceptionNode* pv_en;
      useCount       pv_uc;

   // assignment operator (disabled)
      anException& operator=(const anException& except);
};

// include any inline code here

/**
   declare any typedef statements here
     ex: typedef aVortex areVortices;
   so that we can declare
     areVortices v1, v2, v3;
  */
                              //                 
                              //      \\^//      
                              //     o(!_!)o     
                              // __m__  o  __m__ 
                              //                 

#endif //_ANEXCEPTION_
