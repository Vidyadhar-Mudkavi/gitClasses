#ifndef _FUNCTIONTRACER_
#define _FUNCTIONTRACER_
/**

  *File: functionTracer.h

  *Description:

   this file declares class functionTracer. instances of this class
   are used by functions which can be traced (their invocation and destruction).

   Ref: Ruminations on C++. Koenig and Moo, 1996. Chapter 27.

  *Version: 1.0

  *Dependencies:
   none

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL

  *Date: 10 February 2000
  */

// system includes
#include <string>

// local includes
#include "outputChannel.h"

// const declarations
// function prototypes
// forward declarations

// begin class declaration
class functionTracer
{
   public:

   // constructors
      functionTracer(char* name, outputChannel& oc) 
         : pv_function_name( name ), pv_ptr_output_channel( &oc ) {
         if ( pv_ptr_output_channel->pv_ptr_trace_stream )
         {
            *pv_ptr_output_channel->pv_ptr_trace_stream << " Entering function " 
                                                        << "<" << name
                                                        << ">" << std::endl;
         }
      }

   // destructor
      ~functionTracer() {
         if ( pv_ptr_output_channel->pv_ptr_trace_stream )
         {
            *pv_ptr_output_channel->pv_ptr_trace_stream << " Leaving function " 
                                                        << "<" 
                                                        << pv_function_name.c_str()
                                                        << ">" << std::endl;
         }
      }

   // insertion (to insert additional message etc)
   // insert a c string
      functionTracer& operator<<(char* c_string) {
         if ( pv_ptr_output_channel->pv_ptr_trace_stream )
         {
            *pv_ptr_output_channel->pv_ptr_trace_stream << c_string;
         }
         return *this;
      }

   // insert a char
      functionTracer& operator<<(char c) {
         if ( pv_ptr_output_channel->pv_ptr_trace_stream )
         {
            *pv_ptr_output_channel->pv_ptr_trace_stream << c;
         }
         return *this;
      }

   // insert short int
      functionTracer& operator<<(short int i) {
         if ( pv_ptr_output_channel->pv_ptr_trace_stream )
         {
            *pv_ptr_output_channel->pv_ptr_trace_stream << i;
         }
         return *this;
      }

   // insert an int
      functionTracer& operator<<(int i) {
         if ( pv_ptr_output_channel->pv_ptr_trace_stream )
         {
            *pv_ptr_output_channel->pv_ptr_trace_stream << i;
         }
         return *this;
      }

   // insert long int
      functionTracer& operator<<(long int i) {
         if ( pv_ptr_output_channel->pv_ptr_trace_stream )
         {
            *pv_ptr_output_channel->pv_ptr_trace_stream << i;
         }
         return *this;
      }
   // insert unsigned short int
      functionTracer& operator<<(unsigned short int i) {
         if ( pv_ptr_output_channel->pv_ptr_trace_stream )
         {
            *pv_ptr_output_channel->pv_ptr_trace_stream << i;
         }
         return *this;
      }

   // insert unsigned int 
      functionTracer& operator<<(unsigned int i) {
         if ( pv_ptr_output_channel->pv_ptr_trace_stream )
         {
            *pv_ptr_output_channel->pv_ptr_trace_stream << i;
         }
         return *this;
      }

   // insert unsigned long int 
      functionTracer& operator<<(unsigned long int i) {
         if ( pv_ptr_output_channel->pv_ptr_trace_stream )
         {
            *pv_ptr_output_channel->pv_ptr_trace_stream << i;
         }
         return *this;
      }

   // insert float 
      functionTracer& operator<<(float f) {
         if ( pv_ptr_output_channel->pv_ptr_trace_stream )
         {
            *pv_ptr_output_channel->pv_ptr_trace_stream << f;
         }
         return *this;
      }

   // insert double d
      functionTracer& operator<<(double d) {
         if ( pv_ptr_output_channel->pv_ptr_trace_stream )
         {
            *pv_ptr_output_channel->pv_ptr_trace_stream << d;
         }
         return *this;
      }

   // insert long double 
      functionTracer& operator<<(long double ld) {
         if ( pv_ptr_output_channel->pv_ptr_trace_stream )
         {
            *pv_ptr_output_channel->pv_ptr_trace_stream << ld;
         }
         return *this;
      }

   // insert bool 
      functionTracer& operator<<(bool b) {
         if ( pv_ptr_output_channel->pv_ptr_trace_stream )
         {
            *pv_ptr_output_channel->pv_ptr_trace_stream << b;
         }
         return *this;
      }

   // insert a manipulator
      functionTracer& operator<< ( std::basic_ostream<char>& (*ptr_manipulator) (std::basic_ostream<char>&) ) {
         if ( pv_ptr_output_channel->pv_ptr_trace_stream )
         {
            *pv_ptr_output_channel->pv_ptr_trace_stream << ptr_manipulator;
         }
         return *this;
      }

   // insert a manipulator for boolean type (this is different!!!!)
      functionTracer& operator<< ( std::ios_base& (*ptr_manipulator) (std::ios_base&) ) {
         if ( pv_ptr_output_channel->pv_ptr_trace_stream )
         {
            *pv_ptr_output_channel->pv_ptr_trace_stream << ptr_manipulator;
         }
         return *this;
      }

   protected:

   private:
   // assignment and default disabled
      functionTracer& operator=(const functionTracer& ft) {
         return *this;
      }

      functionTracer() {}

   private:
   // the name of the function being traced and the channel
      const std::string pv_function_name;
      outputChannel* pv_ptr_output_channel;
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

#endif //_FUNCTIONTRACER_
