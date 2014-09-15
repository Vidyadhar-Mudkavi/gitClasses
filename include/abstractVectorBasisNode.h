#ifndef _ABSTRACTVECTORBASISNODE_
#define _ABSTRACTVECTORBASISNODE_
/**

  *File: abstractVectorBasisNode.h

  *Description:

   this file declares class abstractVectorBasisNode

   this class provides a simple framework for creating vector bases.
   currently we only handle orthonormal bases.

  *Version: 1.0 "@(#) abstractVectorBasisNode. header. ver. 1.0. Premalatha and Vidyadhar, CTFD, NAL."

  *Dependencies:

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL

  *Date:
  */

// system includes
#include <vector>
#include <iostream>

// local includes

// const declarations

// function prototypes

// forward declarations
class aVector;
class aVectorBasis;


// begin class declaration
class abstractVectorBasisNode
{
   friend class aVectorBasis;
   friend std::ostream& operator<<(std::ostream& os, const aVectorBasis& vb);

   public:

   protected:
   // constructors
      abstractVectorBasisNode(); // default

#  if 0  // no copy or assignment      
      abstractVectorBasisNode(const abstractVectorBasisNode& vb);

   // assignment operator
      abstractVectorBasisNode& operator=(const abstractVectorBasisNode& vb);
#  endif

   // destructor
      virtual ~abstractVectorBasisNode();

   // other functionality here
   
   // accessor functions (copies on write)
      virtual void Set(const aVector& v1, const aVector& v2, const aVector& v3) = 0;
      virtual void operator<<(const std::vector<aVector>& vec_arr) = 0;

      virtual aVector ToLocal(const aVector& v_world) const = 0;
      virtual aVector ToWorld(const aVector& v_local) const = 0;

   // need to be able to make copies of any object
      virtual abstractVectorBasisNode* Copy() const = 0;

   // output
      virtual void Print(std::ostream& os) const = 0;
   
   protected:

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

#endif //_ABSTRACTVECTORBASISNODE_
