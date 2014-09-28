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
#include <iomanip>

// local includes
#include "useCount.h"
#include "exceptionNode.h"
#include "exceptionHelpers.h"

// const declarations

// namespace

// forward declarations
class anException;

// function prototypes
namespace nal
{
   void Throw(const char*    c_string);
   void Throw(anException    e);
#if 0
   void Throw(exceptionNode* ptr_en);
   void Throw(exceptionNode& ref_en);
#endif
}

// begin class declaration
class anException
{
   friend std::ostream& operator<<(std::ostream& os, const anException& except);
   public:

   // constructors
      anException(); // default
      anException(const anException& except);
      anException(const char* message);
      anException(exceptionNode* ptr_en); // convert pointed object

   // destructor
      virtual ~anException();


   // string and basic data type insertion operators
      anException& operator<<(bool b);
      anException& operator<<(char c);
      anException& operator<<(const char* str);

      anException& operator<<(short int si);
      anException& operator<<(int i);
      anException& operator<<(long int li);
 
      anException& operator<<(unsigned short int usi);
      anException& operator<<(unsigned int ui);
      anException& operator<<(unsigned long int uli);
      anException& operator<<(float f);
      anException& operator<<(double d);
      anException& operator<<(long double ld);

   // insertion of manipulators
      anException& operator<<(std::basic_ostream<char>& (*manipulator)(std::basic_ostream<char>&));
      anException& operator<<(std::basic_ios<char>& (*manipulator)(std::basic_ios<char>&));
      anException& operator<<(std::ios_base& (*manipulator)(std::ios_base&));

   protected:
   // provide some access to writing to underlying string via a derived class
      virtual void Append() {};
      virtual void Prepend() {};

   // two stream objects which help insert messages into these
      exceptionHelper::aStream start_message; // violating convention
      exceptionHelper::aStream end_message;

   // pointer to node and use counter
      exceptionNode* pv_en;
      useCount       pv_uc;

   // assignment operator (disabled)
      anException& operator=(const anException& except);
   private:
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
