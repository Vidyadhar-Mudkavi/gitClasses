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
#include <iostream>

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

   friend std::ostream& operator<<(std::ostream& os, const anException& except);

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
      virtual void Print(std::ostream& os,
                         std::string start_string, std::string end_string);

   // insertion of basic types
      void Append(bool b);
      void Append(char c);
      void Append(const char* str);

      void Append(short int si);
      void Append(int i);
      void Append(long int li);

      void Append(unsigned short int usi);
      void Append(unsigned int ui);
      void Append(unsigned long int uli);

      void Append(float f);
      void Append(double d);
      void Append(long double ld);

      void InsertManipulator(std::basic_ostream<char>& (*manipulator)(std::basic_ostream<char>&));
      void InsertManipulator(std::basic_ios<char>& (*manipulator)(std::basic_ios<char>&));
      void InsertManipulator(std::ios_base& (*manipulator)(std::ios_base&));

   // insertion of manipulators
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
