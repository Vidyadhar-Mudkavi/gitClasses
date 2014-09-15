#ifndef _CPPDOCUMENTOR_
#define _CPPDOCUMENTOR_
/**

  *File: cppDocumentor.h

  *Description:

   this class declares a documentor class which takes a .h
   or a .cpp file as its input and prepares an html or
   a TeX file as the output.

   this forms the base class and acts as an envelope class
   which can be used to hold a letter class which in this case 
   is a converter class. this converter class converts a c++
   document to either TeX or HTML.
  
  *Notes:
   
   an application based on this
   class will be using the following convention
   for naming of the files:

     input file name   || output file name

     aClass.h          ->  aClass_h.html
     aClass.cpp        ->  aClass_cpp.html

    for conversion to HTML files.

     input file name   || output file name

     aClass.h          ->  aClass_h.tex
     aClass.cpp        ->  aClass_cpp.tex

    for conversion to TeX files. we many need to shorten the
    file string since TeX understands only eight characters.
  
    however, this class will take default input as cin and
    default output as cout unless the input and output file
    names are set (no naming convention is used here).

  *Version: 2.0

   now we have capability to process code lines and comment 
   lines separately.

  *Dependencies:

   cppConvertor, aString

   the class cppConvertor is derived from this class

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, Division, NAL
  *Date:    10 Aug. 1998, 4 March 1999
  */

#include "cppDocSwitches.h"
#include "aString.h"

/**
   we need a base constructor to resolve the invocation
   of the constructor by the derived classes. this is
   best done via a intermediate object constructed just for
   this purpose. see page 138 of ``Advanced C++ Programming
   Styles and Idioms'' by James O. Coplien, Addison Wesley 1992''
  */

struct cppDocBaseConstructor
{
// empty
};

enum enConvertTo
{
   HTML, TeX
};

class cppDocumentor
{
   public:
      
   // constructors
      cppDocumentor(const enConvertTo& convert_to = HTML);
      cppDocumentor(const aString& in_file_name,
                    const enConvertTo& convert_to = HTML);
      cppDocumentor(const aString& in_file_name, 
                    const aString& out_file_name,
                    const enConvertTo& convert_to = HTML);
      cppDocumentor(const cppDocumentor& cpp_doc);

   // the assignment operator
      cppDocumentor& operator=(const cppDocumentor& cpp_doc);

   // destructor
      ~cppDocumentor();

   // other functionality here

   // the main task is done by this
      virtual void StartDocumentation();

   // accessor member functions
      virtual void SetInputFileName(const  aString& in_file_name);
      virtual void SetOutputFileName(const aString& out_file_name);

   // for color scheme manipulation
     	virtual void SetKeywordColor(const aString& s);
   	virtual void SetInlineCommentColor(const aString& s);
   	virtual void SetBlockCommentColor(const aString& s);

#if 0 // will do this later. needs more work
   // give control for setting conversion
   // this will shift the pv_converter pointer appropriately
      void ConvertTo(const aString& convert_to);
      void ConvertTo(const enConvertTo convert_to);
#endif

   protected:

   // the following is a helper constructor mainly for resolution
      cppDocumentor(cppDocBaseConstructor b)
      {
      // empty
      };
      
   private:
   // this holds a pointer to itself to delegate responsibility
      cppDocumentor* pv_converter;
};

#endif // _CPPDOCUMENTOR_
