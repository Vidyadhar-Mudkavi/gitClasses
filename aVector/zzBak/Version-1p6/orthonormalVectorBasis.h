#ifndef _ORTHONORMALVECTORBASIS_
#define _ORTHONORMALVECTORBASIS_
/**

  *File: orthonormalVectorBasis.h

  *Description:

   this file declares class orthonormalVectorBasis

  *Version: 1.0 "@(#) orthonormalVectorBasis. header. ver. 1.0. Premalatha and Vidyadhar, CTFD, NAL."

  *Dependencies:

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL

  *Date:
  */

// system includes

// local includes
#include "abstractVectorBasisNode.h"
#include "aVector.h"

// const declarations

// function prototypes

// forward declarations

// begin class declaration
class orthonormalVectorBasis : public abstractVectorBasisNode
{
   friend class aVectorBasis;
   public:

   protected:
   // constructors
      orthonormalVectorBasis(); // default
      orthonormalVectorBasis(const aVector& v1, 
                             const aVector& v2, 
                             const aVector& v3);

   // copy constructor to be able to make own copies
      orthonormalVectorBasis(const orthonormalVectorBasis& onvb);

   // destructor
      ~orthonormalVectorBasis();

   // accessor functions (copies on write)
      void Set(const aVector& v1, const aVector& v2, const aVector& v3);
      void operator<<(const std::vector<aVector>& vec_arr);

      aVector ToLocal(const aVector& v_world) const;
      aVector ToWorld(const aVector& v_local) const;

   // copy an orthonormal basis
      abstractVectorBasisNode* Copy() const;

   // helper function
      void CheckForOrthonormality() const;

   // output
      void Print(std::ostream& os) const;

   private:
   // data is stored as the basis vectors themselves
      aVector pv_v1;
      aVector pv_v2;
      aVector pv_v3;
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

#endif //_ORTHONORMALVECTORBASIS_
