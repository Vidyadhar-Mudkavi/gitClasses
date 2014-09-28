/**

  *File: anException.cpp

  *Description:

   this file implements the class anException

  *Version: 1.0

  *Dependencies:

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL

  *Date:
  */

// system includes
#include <string>
#include <strstream>


// local includes
#include "anException.h"
#include "exceptionNode.h"
#include "exceptionHelpers.h"

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
anException::anException()
   : pv_en( new exceptionNode() )
{
// empty
}

/**
   copy constructor
  */
anException::anException(const anException& except)
   : pv_en( except.pv_en ), pv_uc( except.pv_uc )
{
// empty
}


anException::anException(const char* message)
   : pv_en( new exceptionNode(message) )
{
// empty
}

/**
   this constructor builds anException object from a pointer
   to the exception node. this is used in conjuction with Copy.
  */
anException::anException(exceptionNode* ptr_en)
   : pv_en( ptr_en )
{
// empty
}

   ////////////////////////////////////////
   //                                      
   //    implement assignment operators    
   //                                      
   //                                      

anException& anException::operator=(const anException& except)
{
// disabled

   return *this;
}

   ////////////////////////////////////////
   //                                      
   //    implement the destructor          
   //                                      
   //                                      

anException::~anException()
{
   if ( pv_uc.isOnlyInstance() )
   {
      delete pv_en;
   }
}

   ////////////////////////////////////////////
   //                                          
   //   implement other member functions here  
   //                                          
   //                                          


/**
   this function is used to insert a character string into the
   object
  */
anException& anException::operator<<(bool b)
{
   pv_en->Append(b);

   return *this;
}

anException& anException::operator<<(char c)
{
   pv_en->Append(c);

   return *this;
}

anException& anException::operator<<(const char* str)
{
   pv_en->Append(str);

   return *this;
}

anException& anException::operator<<(short int si)
{
   pv_en->Append(si);

   return *this;
}

anException& anException::operator<<(int i)
{
   pv_en->Append(i);

   return *this;
}

anException& anException::operator<<(long int li)
{
   pv_en->Append(li);

   return *this;
}

anException& anException::operator<<(unsigned short int usi)
{
   pv_en->Append(usi);

   return *this;
}

anException& anException::operator<<(unsigned int ui)
{
   pv_en->Append(ui);

   return *this;
}

anException& anException::operator<<(unsigned long int uli)
{
   pv_en->Append(uli);

   return *this;
}

anException& anException::operator<<(float f)
{
   pv_en->Append(f);

   return *this;
}

anException& anException::operator<<(double d)
{
   pv_en->Append(d);

   return *this;
}

anException& anException::operator<<(long double ld)
{
   pv_en->Append(ld);

   return *this;
}


/**
   the following functions insert the io manipulators
  */
#if 0
anException& anException::operator<<(std::basic_ostream& (*manipulator)(std::basic_ostream&))
{
   pv_en->InsertManipulator(manipulator);

   return *this;
}
#endif
anException& anException::operator<<(std::basic_ostream<char>& (*manipulator)(std::basic_ostream<char>&))
{
   pv_en->InsertManipulator(manipulator);

   return *this;
}

anException& anException::operator<<(std::basic_ios<char>& (*manipulator)(std::basic_ios<char>&))
{
   pv_en->InsertManipulator(manipulator);

   return *this;
}

anException& anException::operator<<(std::ios_base& (*manipulator)(std::ios_base&))
{
   pv_en->InsertManipulator(manipulator);

   return *this;
}

  
/**
   this function outputs the exeption to the ostream
  */

std::ostream& operator<<(std::ostream& os, const anException& except)
{
   std::cout << "start message is: " << except.start_message() << std::endl;

   except.pv_en->Print(os, except.start_message(), except.end_message() );
   return os;
}

namespace nal
{
   void Throw(const char* c_string)
   {
      throw anException(c_string);
   }

   void Throw(anException e)
   {
      throw e;
   }

#if 0
   void Throw(exceptionNode* ptr_en)
   {
      throw anException( ptr_en->Copy() );
   }

   void Throw(exceptionNode& ref_en)
   {
      throw anException( ref_en.Copy() );
   }
#endif

}
