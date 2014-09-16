/**
   we cannot encapsulate this because this is intended to be
   included within a namespace and such inclusions can be many
   in number within a same traslation unit. the guarding is
   governed by the header file which includes this file.
#ifndef _TRACEABLE_
#define _TRACEABLE_
  */
/**

  *File: traceable.h

  *Description:

   this file declares class traceable. those classes which need a 
   facility to trace should be derived from this class. therefore
   this acts as an interface.

   Ref: Ruminations on C++. Koenig and Moo, 1996. Chapter 27.

  *Version: 1.0

  *Dependencies:
   none

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL

  *Date: 21 February 2000
         February 14, 2001
  */

// begin class declaration
class traceable
{
   public:
   // constructors
      traceable(char* object_name = "<<SomeObjectBeingTraced>>") 
         : pv_object_id( ++pv_total_objects )
      {
         ++pv_live_objects;
         pv_constructed.push_front(pv_object_id);
         pv_object_name = object_name;
      }

      traceable(const traceable& ot) 
         : pv_object_id( ++pv_total_objects ) 
      {
         ++pv_live_objects;
         pv_constructed.push_front(pv_object_id);
      }

#if 0 // assignment does nothing. remove it.
      traceable& operator=(const traceable& ft) {
         return *this;
      }
#endif

   // destructor
      virtual ~traceable() 
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
               std::cout << pv_object_name.c_str() << ": " 
                         << *itc << " Constructed" << std::endl;
               std::cout << pv_object_name.c_str() << ": " 
                         << *itd << " Destroyed" << std::endl;
            }
         }
      }

   protected:

   private:
   // static tracerInfo    pv_info;
      long int             pv_object_id;

      static std::list<long int>  pv_constructed;
      static std::list<long int>  pv_destroyed;
      static long int             pv_live_objects;
      static long int             pv_total_objects;
      static std::string          pv_object_name;
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
/**
   see comments above
#endif   // _TRACEABLE_
  */
