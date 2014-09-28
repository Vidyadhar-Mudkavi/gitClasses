#ifndef _EXCEPTIONNODE_
#define _EXCEPTIONNODE_
/**

  *File: exceptionNode.h

  *Description:

   this file declares class exceptionNode

  *Version: 1.0

  *Dependencies:

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL

  *Date:
  */

// system includes
#include <string>
#include <iostream.h>

// local includes

// const declarations

// function prototypes

// forward declarations
class exceptionNode;
class anException;

// namespaces
namespace nal
{
   extern void Throw(const char* c_string);
   extern void Throw(exceptionNode* ptr_en);
   extern void Throw(exceptionNode& ref_en);
   extern void Throw(anException    e);
}

class anException;

// begin class declaration
class exceptionNode
{
   friend class anException;
   friend void nal::Throw(const char* c_string);
   friend void nal::Throw(exceptionNode* ptr_en);
   friend void nal::Throw(exceptionNode& ref_en);
   friend void nal::Throw(anException    e);

   friend ostream& operator<<(ostream& os, const anException& except);

   public:

   protected:
   // constructors
      exceptionNode(); // default
      exceptionNode(const exceptionNode& en);
      exceptionNode(const char* message);

   // destructor
      virtual ~exceptionNode();

   // other functionality here
      virtual exceptionNode* Copy();
      virtual void Print(ostream& os);

   // insertion
      void Append(const char* str);
      void Append(int i);
      void Append(float f);
      void Append(double d);

   protected:
   // the message
      std::string pv_message;

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

#endif //_EXCEPTIONNODE_
