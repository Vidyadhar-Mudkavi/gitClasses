#ifndef _VECTORBASISNODE_
#define _VECTORBASISNODE_
/**

  *File: vectorBasisNode.h

  *Description:

   this file declares class vectorBasisNode

  *Version: 1.0

  *Dependencies:

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL

  *Date:
  */

// system includes
#include <iostream.h>

// local includes
#include "aVector.h"

// const declarations

// function prototypes

// forward declarations

// begin class declaration
class vectorBasisNode
{
   friend class aVectorBasis;
   friend ostream& operator<<(ostream& os, const aVectorBasis& basis);

   public:

   protected:

   private:
   // constructors
      vectorBasisNode(); // default
      vectorBasisNode( const aVector& v1,
                       const aVector& v2,
                       const aVector& v3 );

      vectorBasisNode(const vectorBasisNode& vb_node);

   // assignment operator
      vectorBasisNode& operator=(const vectorBasisNode& vb_node);

   // destructor
      ~vectorBasisNode();

   // other functionality here
      void Print(ostream& os);

   // accessor functions
      void Set( const aVector& v1,
                const aVector& v2,
                const aVector& v3 );

   // functions to transform given vectors between bases
      aVector ToOld(const aVector& v_new) const;
      aVector ToNew(const aVector& v_old) const;

   // data
      aVector pv_v1, pv_v2, pv_v3;  // the basis vectors
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

#endif //_VECTORBASISNODE_
