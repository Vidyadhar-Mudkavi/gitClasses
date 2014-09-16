#ifndef _TRACEABLE_
#define _TRACEABLE_
/**
  *File: traceable.h

  *Description:

   this file declares class traceable. this is a template class and
   the template argument is used to merely provide an independent
   tracing mechanism for the classes that use this feature.
   
   Ref: Ruminations on C++. Koenig and Moo, 1996. Chapter 27.

  *Version: 1.1 "@(#) traceable. header. ver. 1.1. Premalatha and Vidyadhar, CTFD, NAL."

   version 1.1 is changed to a template to resolve types

  *Note:
      tested with Visual C++ 6.0, GNU g++.

  *Dependencies:
   none

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL

  *Date: February 21, 2000
         February 15, 2001
  */

// system includes
#include <list>
#include <string>
#include <iostream>

// begin class declaration
template<class T>
class traceable
{
   public:
   // constructors
      traceable(char* type_name = "<<SomeTypeBeingTraced>>");
      traceable(const traceable& ot);

   // destructor
      virtual ~traceable();

   // other functionality here
   protected:
      void SetTypeName(char* type_name);

   private:
   // data consists of trace information
      long int                    pv_object_id;       // track objects by id

      static std::list<long int>  pv_constructed;
      static std::list<long int>  pv_destroyed;
      static long int             pv_live_objects;
      static long int             pv_total_objects;
      static std::string          pv_type_name;       // user supplied name
};


// include any inline code here

/**
  *Purpose: 
      constructs an object with a given name
      the name is used to distinguish object types.
      name is supplied by the user. uses a
      default when name is not supplied.
  */
template<class T>
traceable<T>::traceable(char* type_name)
   : pv_object_id( ++pv_total_objects )
{
   ++pv_live_objects;
   pv_constructed.push_front(pv_object_id);
   pv_type_name = type_name;
}


/**
  *Purpose:
      copy construction
  */
template<class T>
traceable<T>::traceable(const traceable& t)
   : pv_object_id( ++pv_total_objects )
{
   ++pv_live_objects;
   pv_constructed.push_front(pv_object_id);
}

/**
  *Purpose:
      destruction. the last object to be destroyed
      will print out the necessary information about
      all the objects that were created and systematically
      destroyed.
  */
template<class T>
traceable<T>::~traceable()
{
   pv_destroyed.push_front(pv_object_id);
// before destroying the last object
   if ( --pv_live_objects == 0 )  
   {
      pv_constructed.sort();
      pv_destroyed.sort();

      std::list<long int>::iterator itc    = pv_constructed.begin();
      std::list<long int>::iterator itcend = pv_constructed.end();

      std::list<long int>::iterator itd    = pv_destroyed.begin();
      std::list<long int>::iterator itdend = pv_destroyed.end();

      for ( ; itc != itcend || itd != itdend; ++itc, ++itd )
      {
         std::cout << pv_type_name.c_str() << ": " 
                   << *itc << " Constructed" << std::endl;
         std::cout << pv_type_name.c_str() << ": " 
                   << *itd << " Destroyed" << std::endl;
      }
   }
}

/**
  *Purpose:
      a protected member which allows one to set the
      type name. this may be used by the user more
      conveniently.
  */
template<class T>
void traceable<T>::SetTypeName(char* type_name)
{
   pv_type_name = type_name;
}

// initialization of the static data is done here
// this is the correct way to initialize the static data
// in a template class.
template<class T>
std::list<long int>  traceable<T>::pv_constructed;

template<class T>
std::list<long int>  traceable<T>::pv_destroyed;

template<class T>
long int             traceable<T>::pv_live_objects = 0;

template<class T>
long int             traceable<T>::pv_total_objects = 0;

template<class T>
std::string          traceable<T>::pv_type_name = "<<SomeType>>";

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
#endif   // _TRACEABLE_
