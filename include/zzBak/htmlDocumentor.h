#ifndef _HTMLDOCUMENTOR_
#define _HTMLDOCUMENTOR_
/**

  *File: htmlDocumentor.h

  *Description:

   this class declares a documentor class which takes a .h
   or a .cpp file as its input and prepares an html file as
   the output.

  *Notes:
   
   an application based on this
   class will be using the following convention
   for naming of the files:

     input file name   || output file name

     aClass.h          ->  aClass_h.html
     aClass.cpp        ->  aClass_cpp.html

    however, this class will take default input as cin and
    default output as cout unless the input and output file
    names are set (no naming convention is used here).

  *Version: 1.3

   this version attempts to treat block and inline comments
   separately.

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, Division, NAL
  *Date:    10 Aug. 1998
  */


#include <aString.h>
#include <fstream.h>
#include "colorScheme.h"

static const int LINESIZE = 1024;
static const int MAX_KEYWORDS_PER_LINE = 30;

class htmlDocumentor
{
   public:
	void SetBlockCommentColor(const aString& s);
      
   // constructors
      htmlDocumentor();
      htmlDocumentor(const aString& in_file_name);
      htmlDocumentor(const aString& in_file_name, 
                     const aString& out_file_name);
      htmlDocumentor(const htmlDocumentor& html_doc);

   // the assignment operator
      htmlDocumentor& operator=(const htmlDocumentor& html_doc);

   // destructor
      ~htmlDocumentor();

   // other functionality here

   // the main task is done by this
      void StartDocumentor();

   // accessor member functions
      void SetInputFileName(const  aString& in_file_name);
      void SetOutputFileName(const aString& out_file_name);

   // for color scheme manipulation
     	void SetKeywordColor(const aString& s);
   	void SetInlineCommentColor(const aString& s);

   protected:

   private:
	
   // helper functions
      void      WriteHeader(ostream& os=cout);
      void      WriteTrailer(ostream& os=cout);
      aBoolean  ReadALine(istream& is=cin);
      void      WriteALine(ostream& os=cout);
  	   void      StartNewLine(ostream& os=cout);
      void      InitKeywords();
      void      LookForKeywords();
      void      BeautifyKeywords();
      void      ReplaceAmpersand();  // must do this first
      void      ReplaceLeftangle();  // and this next
      void      SplitLine();

      void      ProcessCodeLine();
      void      ProcessLineComment();
      void      ProcessBlockComment();

      void      ExamineLineForBeginBlockComment();
	   void      ExamineLineForEndBlockComment();
	   void      ExamineLineForLineComment();

    	void      CutLineAtIndex();

      aBoolean  lineHasBeginBlockComment();
   	aBoolean  lineHasEndBlockComment();
	   aBoolean  lineHasLineComment();

   private:

   // an enumerated type to check line status (code, comment etc).
      enum enLineStatus
      {
         CODE,
         BLOCK_COMMENT,
         INLINE_COMMENT
      };

      enLineStatus pv_line_status;
      enLineStatus pv_next_line_status;

      aString  pv_in_file_name;
      aString  pv_out_file_name;
      aString  pv_entire_line;    // this has one full line
      aString  pv_line;           // this has either comment line
                                 // or only code line in it

      aString* pv_keywords;      // array holding all keywords
      int      pv_no_of_keywords;
      aBoolean pv_bln_line_has_keywords;

      int      pv_keyword_indices[MAX_KEYWORDS_PER_LINE][2];
      int      pv_keywords_per_line;

      aBoolean pv_time_to_start_newline;
      aBoolean pv_more_remains_to_process;

      aBoolean pv_line_has_begin_block_comment;
   	aBoolean pv_line_has_end_block_comment;
	   aBoolean pv_line_has_line_comment;
      aBoolean pv_entering_block_comment;
      aBoolean pv_leaving_block_comment;

      int      pv_cut_location;

   // need to take care of color scheme
      colorScheme pv_cs;

   // input and output stream pointers
      istream* pv_in;
      ostream* pv_out;
};


#endif // _HTMLDOCUMENTOR_
