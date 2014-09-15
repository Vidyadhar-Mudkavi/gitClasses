#ifndef _AQUATERNION_
#define _AQUATERNION_
/**

  *File: aQuaternion.h

  *Description:
   this defines a quaternion class. this is a HANDLE using VALUE SEMANTICS.
   

  *Version: 1.0 "@(#) aQuaternion. header. ver. 1.0. Premalatha and Vidyadhar, CTFD, NAL."

  *Dependencies:
   aVector

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL.
  *Date:    September 14, 2000
  */

// system includes
// standard template
// local includes
#include "aVector.h"
#include "aQuaternionNode.h"

// const declarations
// function prototypes
// forward declarations

// begin class declaration

class aQuaternion
{
   friend class aQuaternionNode;

   friend std::ostream& operator<<(std::ostream& os, const aQuaternion& quat) {
      quat.pv_ptr_quat_node->PrintNode(os);
      return os;
   }
   friend aQuaternion operator*(double alpha, const aQuaternion& q) {
      return q * alpha;
   }

   public:
   // constructors
      inline aQuaternion();
      inline aQuaternion(const aQuaternion& quat);

      inline aQuaternion(double p, const aVector& v);
      inline aQuaternion(double p, const double& v1, const double& v2, const double& v3);

   // assignment operator
      inline aQuaternion& operator=(const aQuaternion& quat);

   // destructor
      inline ~aQuaternion();

   // accessors
      inline void SetReal(double p);
      inline void SetImag(double v1, double v2, double v3);
      inline void SetImag(const aVector& v);
      inline void Set(double p, double v1, double v2, double v3);
      inline void Set(double p, const aVector& v);

      inline double operator[](int index) const;

   // other functionality here
      inline aQuaternion  operator+(const aQuaternion& q) const;
      inline aQuaternion  operator-(const aQuaternion& q) const;

      inline aQuaternion& operator+=(const aQuaternion& q);
      inline aQuaternion& operator-=(const aQuaternion& q);

      inline aQuaternion  operator*(double alpha) const;
      inline aQuaternion& operator*=(double alpha);
      inline aQuaternion  operator/(double alpha) const;
      inline aQuaternion& operator/=(double alpha);

      inline aQuaternion  operator^(const aQuaternion& q) const;  // cross prod
      inline aQuaternion& operator^=(const aQuaternion& q);       // like *=

      inline aQuaternion  Conjugate() const;
      inline aQuaternion& MakeConjugate();

      inline double Norm() const;
      inline double NormSquare() const;

   protected:
   // build from a node
      inline aQuaternion(aQuaternionNode* ptr_quat_node);

   private:
      aQuaternionNode* pv_ptr_quat_node;
      useCount         pv_uc;
};


// include any inline code here
inline aQuaternion::aQuaternion()
   : pv_ptr_quat_node( new aQuaternionNode )
{
// empty
}

inline aQuaternion::aQuaternion(const aQuaternion& quat)
   : pv_ptr_quat_node( quat.pv_ptr_quat_node ),
     pv_uc( quat.pv_uc )
{
// empty
}

inline aQuaternion::aQuaternion(double p, const aVector& v)
   : pv_ptr_quat_node( new aQuaternionNode(p, v[0], v[1], v[2]) )
{
// empty
}

inline aQuaternion::aQuaternion(double p, const double& v1, const double& v2, const double& v3)
   : pv_ptr_quat_node( new aQuaternionNode(p, v1, v2, v3) )
{
// empty
}

inline aQuaternion::aQuaternion(aQuaternionNode* ptr_quat_node)
   : pv_ptr_quat_node( ptr_quat_node )
{
// empty
}


inline aQuaternion& aQuaternion::operator=(const aQuaternion& quat)
{
   if ( pv_uc.isAttachingTo(quat.pv_uc) )
   {
      delete pv_ptr_quat_node;
   }

   pv_ptr_quat_node = quat.pv_ptr_quat_node;

   return *this;
}


inline aQuaternion::~aQuaternion()
{
   if ( pv_uc.isOnlyInstance() == true )
   {
      delete [] pv_ptr_quat_node;
   }
}


/**
   the following are accessors that modify the object
  */
inline void aQuaternion::Set(double p, const aVector& v)
{
   if ( pv_uc.makeCopy() == true )
   {
      pv_ptr_quat_node = new aQuaternionNode( *pv_ptr_quat_node );
   }
   pv_ptr_quat_node->Set(p, v);
}

inline void aQuaternion::Set(double p, double v1, double v2, double v3)
{
   if ( pv_uc.makeCopy() == true )
   {
      pv_ptr_quat_node = new aQuaternionNode( *pv_ptr_quat_node );
   }
   pv_ptr_quat_node->Set(p, v1, v2, v3);
}

inline void aQuaternion::SetImag(const aVector& v)
{
   if ( pv_uc.makeCopy() == true )
   {
      pv_ptr_quat_node = new aQuaternionNode( *pv_ptr_quat_node );
   }
   pv_ptr_quat_node->SetImag(v);
}

inline void aQuaternion::SetImag(double v1, double v2, double v3)
{
   if ( pv_uc.makeCopy() == true )
   {
      pv_ptr_quat_node = new aQuaternionNode( *pv_ptr_quat_node );
   }
   pv_ptr_quat_node->SetImag(v1, v2, v3);
}

inline void aQuaternion::SetReal(double p)
{
   if ( pv_uc.makeCopy() == true )
   {
      pv_ptr_quat_node = new aQuaternionNode( *pv_ptr_quat_node );
   }

   pv_ptr_quat_node->SetReal(p);
}

inline double aQuaternion::operator[](int index) const
{
   return pv_ptr_quat_node->GetComponent(index);
}


inline aQuaternion aQuaternion::operator+(const aQuaternion& q) const
{
   return pv_ptr_quat_node->Plus(*q.pv_ptr_quat_node);
}

/**
   this one modifies the object. it adds the quantity q to the object
   on the left hand side. since we are using value semantics, we must
   make a copy first (if need be).
  */
inline aQuaternion& aQuaternion::operator+=(const aQuaternion& q) 
{
   if ( pv_uc.makeCopy() == true )
   {
      pv_ptr_quat_node = new aQuaternionNode( *pv_ptr_quat_node );
   }
// now do the sum
   pv_ptr_quat_node->Add(*q.pv_ptr_quat_node);
   return *this;
}

inline aQuaternion aQuaternion::operator-(const aQuaternion& q) const
{
   return pv_ptr_quat_node->Minus(*q.pv_ptr_quat_node);
}

inline aQuaternion& aQuaternion::operator-=(const aQuaternion& q)
{
   if ( pv_uc.makeCopy() == true )
   {
      pv_ptr_quat_node = new aQuaternionNode( *pv_ptr_quat_node );
   }
// now subtract
   pv_ptr_quat_node->Subtract(*q.pv_ptr_quat_node);

   return *this;
}

inline aQuaternion aQuaternion::operator*(double alpha) const
{
   return pv_ptr_quat_node->Times(alpha);
}

inline aQuaternion& aQuaternion::operator*=(double alpha)
{
   if ( pv_uc.makeCopy() == true )
   {
      pv_ptr_quat_node = new aQuaternionNode( *pv_ptr_quat_node );
   }

// now multiply by alpha (scales the object itself)
   pv_ptr_quat_node->MultiplyBy(alpha);

   return *this;
}


inline aQuaternion aQuaternion::operator/(double alpha) const
{
   return pv_ptr_quat_node->Slash(alpha);
}


inline aQuaternion& aQuaternion::operator/=(double alpha)
{
   if ( pv_uc.makeCopy() == true )
   {
      pv_ptr_quat_node = new aQuaternionNode( *pv_ptr_quat_node );
   }

// now divide by alpha (scales the object itself)
   pv_ptr_quat_node->DivideBy(alpha);

   return *this;
}


inline aQuaternion aQuaternion::operator^(const aQuaternion& q) const
{
   return pv_ptr_quat_node->Cross( *q.pv_ptr_quat_node );
}

inline aQuaternion& aQuaternion::operator^=(const aQuaternion& q)
{
   if ( pv_uc.makeCopy() == true )
   {
      pv_ptr_quat_node = new aQuaternionNode( *pv_ptr_quat_node );
   }
// now take the cross product
   pv_ptr_quat_node->MultiplyBy( *q.pv_ptr_quat_node );

   return *this;
}


double aQuaternion::Norm() const
{
   return pv_ptr_quat_node->Norm();
}

double aQuaternion::NormSquare() const
{
   return pv_ptr_quat_node->NormSquare();
}

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

#endif   // _AQUATERNION_
