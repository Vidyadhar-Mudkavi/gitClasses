#ifndef _TSTREAMUTIL_
#define _TSTREAMUTIL_
/**
  *File: tStreamUtil.h

  \details
   this file declares class tStreamUtil. this class is used to handle stream related
   operations, such as skipping a commentline, opening a file, formatting numeric output etc.

   the template parameter is type of input stream. it can be
   std::ifstream or std::fstream, or std::iostream

   default comment character is '#'

   implemented exclusively inline.

  \Version  1.0 "@(#) tStreamUtil. header. ver. 1.0. Premalatha, Vidyadhar Mudkavi, CTFD, NAL."

  \Authors
          - Premalatha, Vidyadhar Mudkavi, CTFD, NAL
  \Date
          - 2010-03-01
  */

// system includes
#include <iostream>

// standard template
// local includes
// const declarations
// function prototypes
// forward declarations

// begin class declaration
namespace plume
{
   template <typename TYPE>
   class tStreamUtil
   {
   // friends are declared differently!
#  if defined(_MSC_VER)
      inline friend std::ostream& operator<<(std::ostream& os,
                                             const tStreamUtil<TYPE>& fu)
      {
         os << "*** tStreamUtil ***" << std::endl
            << "    comment character is set to:   " << fu.pv_commentChar << std::endl
            << "    comment line length is set to: " << fu.pv_longLineLength << std::endl
            << "    File stream is valid?          " << (fu.pv_isStreamValid ? "true" : "false") << std::endl; 
         return os;
      }
#  else
      template <class TYPE>
      inline friend std::ostream& operator<<(std::ostream& os,
                                             const tStreamUtil<TYPE>& fu)
      {
         os << "*** fFileUtil ***" << std::endl
            << "    comment character is set to:   " << fu.pv_commentChar << std::endl
            << "    comment line length is set to: " << fu.pv_longLineLength << std::endl
            << "    File stream is valid?          " << (fu.pv_isStreamValid ? "true" : "false") << std::endl; 
         return os;
      }
#  endif
      public:
      // constructors
         tStreamUtil();                     // default
         tStreamUtil(TYPE& fs);             // sets file stream to fstream
         tStreamUtil(const tStreamUtil& fu);  // copy

      // assignment operator
         tStreamUtil& operator=(const tStreamUtil& fu);

      // destructor
         ~tStreamUtil();

      // accessors

      // other functionality
         inline bool SkipCommentLine();
         inline void SkipTillEndOfLine();
         inline void SkipNextCommentLines();
         inline void PrintCommentLine(std::ostream& os);

      protected:
      private:
         TYPE* pv_pFStream;   // points to file stream fstream

         char  pv_commentChar;
         bool  pv_isStreamValid;

         int   pv_longLineLength;
         char* pv_longLine;
   };

   // template implementation code starts here
   // begin template implementation
      ////////////////////////////////////////
      //                                      
      //    implement constructors here       
      //                                      
      //                                      

   /**
    \brief  provides default constructor
     */
   template <typename TYPE>
   tStreamUtil<TYPE>::tStreamUtil()
      : pv_commentChar( '#' ),
        pv_pFStream( 0 ),
        pv_longLineLength( 1024 ),
        pv_isStreamValid( false )
   {
      pv_longLine = new char[pv_longLineLength];
   }

   template <typename TYPE>
   tStreamUtil<TYPE>::tStreamUtil(TYPE& fs)
      : pv_commentChar( '#' ),
        pv_pFStream( &fs ),
        pv_longLineLength( 1024 ),
        pv_isStreamValid( false )
   {
      pv_longLine = new char[pv_longLineLength];

      if ( fs.is_open() == false )
      {
         pv_isStreamValid = false;
         std::cout << "*** in plume::tStreamUtil::tStreamUtil(TYPE& fs) ***" << std::endl
                   << "*** file stream is NOT OPEN! ***" << std::endl;
      }
      else
      {
         pv_isStreamValid = true;
      }
   }


   /**
     \brief  provides copy constructor
     \note
       - contents of comment line (held in pv_longLine) is not copied.
     */
   template <typename TYPE>
   tStreamUtil<TYPE>::tStreamUtil(const tStreamUtil<TYPE>& fu)
      : pv_commentChar( fu.pv_commentChar ),
        pv_pFStream( fu.pv_pFStream ),
        pv_isStreamValid( fu.pv_isStreamValid ),
        pv_longLineLength( fu.pv_longLineLength )
   {
      pv_longLine = new char[pv_longLineLength];
   }


   /**
     \brief  provides assignment operator
     */
   template <class TYPE>
   tStreamUtil<TYPE>& tStreamUtil<TYPE>::operator=(const tStreamUtil<TYPE>& fu)
   {
      pv_commentChar       = fu.pv_commentChar;
      pv_pFStream          = fu.pv_pFStream;
      pv_isStreamValid     = fu.pv_isStreamValid;
      pv_longLineLength    = fu.pv_longLineLength;

      pv_longLine = new char[pv_longLineLength];

      return *this;
   }


   /**
     \brief  provides destructor
     */
   template <typename TYPE>
   tStreamUtil<TYPE>::~tStreamUtil()
   {
      delete [] pv_longLine;
   }

   ////////////////////////////////////////////
   //                                          
   //   implement other member functions here  
   //                                          
   //                                          
   template <typename TYPE>
   inline bool tStreamUtil<TYPE>::SkipCommentLine()
   {
      if ( pv_isStreamValid == false )
      {
         std::cout << "*** in fileUtil::SkipCommentLine()  ***" << std::endl
                   << "*** Stream is not valid. No action. ***" << std::endl;
         return false;
      }

      char c;

      TYPE& fStream = *pv_pFStream;

      fStream >> c;
#if 0
      std::cout << "**** character read = " << c << std::endl;
#endif
      if ( c == pv_commentChar )
      {
         fStream.putback( c );
         fStream.getline(pv_longLine, pv_longLineLength);
#if 0
         std::cout << "*** comment line read: ***" << std::endl
                   << pv_longLine << std::endl;
#endif
         return true;
      }

      fStream.putback( c );
      return false;
   }

   template <typename TYPE>
   inline void tStreamUtil<TYPE>::SkipTillEndOfLine()
   {
      TYPE& fStream = *pv_pFStream;

      fStream.getline(pv_longLine, pv_longLineLength);
   }

   template <typename TYPE>
   inline void tStreamUtil<TYPE>::SkipNextCommentLines()
   {
      while ( SkipCommentLine() == true )
      {
      // empty
      }
   }

   template <typename TYPE>
   inline void tStreamUtil<TYPE>::PrintCommentLine(std::ostream& os)
   {
      os << pv_longLine << std::endl;
   }

   ////////////////////////////////////////////
   //                                          
   //   implement friend functions here  
   //                                          
   //                                          
#if 0
   template <class TYPE>
   inline std::ostream& operator<<(std::ostream& os, const tStreamUtil<TYPE>& p)
   {
   // TODO
      p.Print(os);
      return os;
   }
#endif
   // follow this pattern for function comments

   /**
     \brief   
     \Return  
     \Param   
     \Throws  
     */

   // here is an example
#  if 0 // here is an example
   /**
     \brief
       - this function add the matrix passed as arg.

     \Return
       - matrixNode* ... pointer to a matrix node

     \Param
       - ptr_mn -- a const pointer to matrix node
       - gmn    -- general matrix node

     \Throws
       - aMatrix::exception object
     */
   matrixNode* aMatrix::Add(const matrixNode* ptr_mn, ...)
#  endif // end of example

}

/**
   declare any typedef statements here   (e.g.: typedef aVortex areVortices;)
  */
                              //                 
                              //      \\^//      
                              //     o(!_!)o     
                              // __m__  o  __m__ 
                              //                 

#endif   // _TSTREAMUTIL_
