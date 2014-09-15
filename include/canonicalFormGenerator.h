#ifndef _CANONICALFORMGENERATOR_
#define _CANONICALFORMGENERATOR_
/**

  *File: canonicalFormGenerator.h

  \Brief
   this file declares class canonicalFormGenerator
   this file declares a canonicalFormGenerator class.

   the canonical form for orthdox classes is described by
   James O. Coplien in his book entitled "Advanced C++ Programming
   Styles and Idioms." This class generates a template for such
   a class definition and implementation.

  \Version  1.2

  *Dependencies:
   aString

  \Authors  Premalatha, Vidyadhar Mudkavi, CTFD, NAL

  \Date     22 Sep. 1998,
            22 Apr  1999 (conversion to canonical form)
            28 Nov  2003  (use of std::string)
  */

// system includes
#include <iostream>
#include <fstream>

// standard template
#include <string>

// local includes

// const declarations

// function prototypes

// forward declarations

// begin class declaration
class canonicalFormGenerator
{
   friend std::ostream& operator<<(std::ostream& os, std::string& text);
   public:

   // constructors
      canonicalFormGenerator(const std::string& class_name,
                             const std::string& appln_name);

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

      void MakeHeaderVersionString();
      void MakeImplementationVersionString();
      void MakeApplicationVersionString();
      
      std::string GetStringTail( const std::string& s,   // gets last part of string
                                 int no_of_chars         // a maximum of no_of_chars
                               ) const;

      void GenerateHeaderFile();
      void GenerateTemplateFile();
      void GenerateImplementationFile();
      void GenerateTestFile();

      void InitializeFileStreams();
      void CloseFileStreams();

      void PrintErrorMessage(const std::string& msg);
      void PrintDebugMessage(const std::string& msg);
      void PrintErrorMessageAndQuit(const std::string& msg);

   // to check if a template is needed
      bool wantATemplate() const;

   private:
   // helper function
      std::string NewString(size_t size) const;

   private:
   // strings to hold file names
      std::string pv_h_file_name;
      std::string pv_cpp_file_name;
      std::string pv_test_file_name;

   // strings that holds the class name, application name etc
      std::string pv_class_name;  // same as file name
      std::string pv_appln_name;  // derived from class name for this case

   // other data such as file guard etc
      std::string pv_file_guard_string;
      std::string pv_class_var_name;
      std::string pv_h_version_string;
      std::string pv_cpp_version_string;
      std::string pv_app_version_string;

   // file streams to write to
      std::ofstream pv_h_file_out;
      std::ofstream pv_cpp_file_out;
      std::ofstream pv_test_file_out;

   // for error handling
      std::string pv_error_message;
      std::string pv_debug_message;

   // tabspace as a string
      std::string pv_tab;

   // strings that holds list of authors etc (supplied on command line)
      std::string pv_author_list;
      std::string pv_affiliation;

      std::string pv_NMITLI_team_list; // this is only temporary

   // other information
      std::string pv_version;

   // some flags
      bool pv_need_app_file;
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
