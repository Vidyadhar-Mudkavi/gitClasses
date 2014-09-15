#ifndef _CANONICALFORMGENERATOR_
#define _CANONICALFORMGENERATOR_
/**

  *File: canonicalFormGenerator.h

  *Description:

   this file declares class canonicalFormGenerator
   this file declares a canonicalFormGenerator class.

   the canonical form for orthdox classes is described by
   James O. Coplien in his book entitled "Advanced C++ Programming
   Styles and Idioms." This class generates a template for such
   a class definition and implementation.

  *Version: 1.1

  *Dependencies:
   aString

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL

  *Date:    22 Sep. 1998,
            22 April 1999 (conversion to canonical form)
  */

// system includes
#include <fstream.h>

// local includes
#include "aString.h"

// const declarations

// function prototypes

// forward declarations

// begin class declaration
class canonicalFormGenerator
{
   public:

   // constructors
      canonicalFormGenerator(const aString& class_name);

   // destructor
      ~canonicalFormGenerator();

   // this function does all the work
      void Start();

   protected:
   // default and copy construction and assignement are disabled
      canonicalFormGenerator(); // default
      canonicalFormGenerator(const canonicalFormGenerator& cfg);

   // assignment operator
      canonicalFormGenerator& operator=(const canonicalFormGenerator& cfg);

   // these are the various helper functions
      void MakeFileGuardString();
      void MakeClassVarName();
      
      aString GetStringTail(const aString& s,      // gets last part of string
                            int no_of_chars) const;// a maximum of no_of_chars

      void GenerateHeaderFile();
      void GenerateImplementationFile();
      void GenerateTestFile();

      void InitializeFileStreams();
      void CloseFileStreams();

      void PrintErrorMessage(const aString& msg);
      void PrintDebugMessage(const aString& msg);
      void PrintErrorMessageAndQuit(const aString& msg);

   private:
   // strings to hold file names
      aString pv_h_file_name;
      aString pv_cpp_file_name;
      aString pv_test_file_name;

   // string that holds the class name (same as pv_file_name)
      aString pv_class_name;

   // other data such as file guard etc
      aString pv_file_guard_string;
      aString pv_class_var_name;

   // file streams to write to
      ofstream pv_h_file_out;
      ofstream pv_cpp_file_out;
      ofstream pv_test_file_out;

   // for error handling
      aString pv_error_message;
      aString pv_debug_message;

   // tabspace as a string
      aString pv_tab;

   // string that holds list of authors (supplied on command line)
      aString pv_author_list;
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
                              // --m--  o  --m-- 
                              //                 

#endif //_CANONICALFORMGENERATOR_
