/**

  *File: exceptionNode.cpp

  *Description:

   this file implements the class exceptionNode

  *Version: 1.0

  *Dependencies:

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL

  *Date:
  */

// system includes
#include <iostream>
#include <strstream>

// local includes
#include "exceptionNode.h"

// const declarations

// function prototypes

// forward declarations

// begin class implementation
   ////////////////////////////////////////
   //                                      
   //    implement constructors here       
   //                                      
   //                                      

/**
   default constructor
  */
exceptionNode::exceptionNode()
   : pv_message("")
{
// empty
}

/**
   copy constructor
  */
exceptionNode::exceptionNode(const exceptionNode& en)
   : pv_message(en.pv_message)
{
// empty
}

exceptionNode::exceptionNode(const char* message)
   : pv_message(message)
{
// empty
}



   ////////////////////////////////////////
   //                                      
   //    implement assignment operators    
   //                                      
   //                                      

   ////////////////////////////////////////
   //                                      
   //    implement the destructor          
   //                                      
   //                                      

exceptionNode::~exceptionNode()
{
// empty
}

   ////////////////////////////////////////////
   //                                          
   //   implement other member functions here  
   //                                          
   //                                          

exceptionNode* exceptionNode::Copy()
{
   return new exceptionNode(*this);
}

void exceptionNode::Print(std::ostream& os, 
                          std::string start_message,
                          std::string end_message)
{
   os << start_message.c_str()
      << pv_message.c_str()
      << end_message.c_str();
}

void exceptionNode::Append(bool b)
{
   std::ostrstream buff;
   buff << b << std::ends;
   pv_message += buff.str();
}

void exceptionNode::Append(char c)
{
   pv_message += c;
}

void exceptionNode::Append(const char* str)
{
   pv_message += str;
}


void exceptionNode::Append(short int si)
{
   std::ostrstream buff;
   buff << si << std::ends;
   pv_message += buff.str();
}

void exceptionNode::Append(int i)
{
   std::ostrstream buff;
   buff << i << std::ends;
   pv_message += buff.str();
}

void exceptionNode::Append(long int li)
{
   std::ostrstream buff;
   buff << li << std::ends;
   pv_message += buff.str();
}

void exceptionNode::Append(unsigned short int usi)
{
   std::ostrstream buff;
   buff << usi << std::ends;
   pv_message += buff.str();
}

void exceptionNode::Append(unsigned int ui)
{
   std::ostrstream buff;
   buff << ui << std::ends;
   pv_message += buff.str();
}

void exceptionNode::Append(unsigned long int uli)
{
   std::ostrstream buff;
   buff << uli << std::ends;
   pv_message += buff.str();
}

void exceptionNode::Append(float f)
{
   std::ostrstream buff;
   buff << f << std::ends;
   pv_message += buff.str();
}

void exceptionNode::Append(double d)
{
   std::ostrstream buff;
   buff << d << std::ends;
   pv_message += buff.str();
}

void exceptionNode::Append(long double ld)
{
   std::ostrstream buff;
   buff << ld << std::ends;
   pv_message += buff.str();
}

void exceptionNode::InsertManipulator(std::basic_ostream<char>& (*manipulator)(std::basic_ostream<char>&))
{
   std::ostrstream buff;
   buff << manipulator << std::ends;
   pv_message += buff.str();
}

void exceptionNode::InsertManipulator(std::basic_ios<char>& (*manipulator)(std::basic_ios<char>&))
{
   std::ostrstream buff;
   buff << manipulator << std::ends;
   pv_message += buff.str();
}

void exceptionNode::InsertManipulator(std::ios_base& (*manipulator)(std::ios_base&))
{
   std::ostrstream buff;
   buff << manipulator << std::ends;
   pv_message += buff.str();
}
