#ifndef _USECOUNT_
#define _USECOUNT_
/**

  *File: useCount.h

  *Description:

   this file declares class useCount. instances of this class
   are used by handle classes. this is modelled based on the
   discussions and examples provided in "Ruminations on C++" by
   Andrew Koenig and Barbara Moo. See Chapter 7.

   the basic idea is to add a variable of type useCount in
   the handles that you wish to write. the handle class has
   to worry about delete, assignment and access operations
   of the objects to which it is attached. when deleting,
   the useCount object is queried for "isOnlyInstance".
   when assigning, we query for "isAttachingTo". and when
   modifying the object contents, we query for "createCopy" and
   make a copy if true.

   being a tiny class, and for want of efficiency, all functions
   are inline. thus, the cpp file is empty (not needed).

   also note that we do not use aBoolean as the return value
   for the boolean functions to keep the implementation as
   tiny as possible. in later versions of C++, bool may be used
   instead.

  *Version: 1.0

  *Dependencies:
   none

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL

  *Date: 27 august 1999
  */

// system includes

// local includes

// const declarations

// function prototypes

// forward declarations

// begin class declaration
class useCount
{
   public:

   // constructors
      useCount() : pv_use(new int(1)) {}

      useCount(const useCount& uc) : pv_use(uc.pv_use) {
         ++*pv_use;
      }

   // assignment operator (never to be used. in private)

   // destructor
      ~useCount() {
         if (--*pv_use == 0)
            delete pv_use;
      }

   // other functions
   // if only one instance exists, returns true
      int isOnlyInstance() {
         return *pv_use == 1;
      }

   // if the object is attaching to new one, returns true
      int isAttachingTo(const useCount& uc) {
         ++*uc.pv_use;
         if ( --*pv_use == 0 )
         {
            delete pv_use;
            pv_use = uc.pv_use;
            return (1==1);    // simulated true
         }

         pv_use = uc.pv_use;
         return (1==0);       // simulated false
      }

   // if a new copy is to be created, returns true
      int CreateCopy() {
         if ( *pv_use == 1 )
            return (1==0);    // simulated false

         --*pv_use;
         pv_use = new int(1);
         return (1==1);       // simulated true
      }

   protected:
   // assignment is never used
      useCount& operator=(const useCount& uc) {
         throw "Assignment invoked!";
         return *this;
      }

   private:
   // the use counter
      int* pv_use;
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

#endif //_USECOUNT_
