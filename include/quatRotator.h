#ifndef _QUATROTATOR_
#define _QUATROTATOR_
/**

  *File: quatRotator.h

  *Description:
   this defines a quaternion rotator class. 
   this is a HANDLE using VALUE SEMANTICS.
   
   this class builds a special quaternion with the property
   that its real part is cosine of half angle and its imaginary
   part is the product of sine of half angle and a unit vector about
   which the rotation is desired.

   the angle is the amount of rotation imparted on a vector. the class
   provides a member function to do this.

   for this special quaternion, it does not make any sense to add and 
   subtract. multiplication or division by scalar are also not sensible.
   only the product of two quaternions is supported 
   (it is the only sensible operation).

   PRODUCT AND COMBINED ROTATION:
   product of two quaternions is also a quaternion which represents combined
   rotation. if 
      q3 = q1 * q2 where q1, q2 and q3 are quaternions, 
   then q3 is the rotation which results from rotating 
   about the axis of q1 by corresponding angle 
   followed by rotation about the axis of q2 by corresponding angle. 
   
   thus, ... q5 * q4 * q3 * q2 * q1  represents an operator on a given vector
   which rotates it by q1 followed by q2 followed by q3 ... and so on.

   clearly, q2 * q1 represents a different rotation altogether.

   the class provides means to add (or increment) angle. this is useful in animating
   motion of a vector. similarly, means to add axis is also provided. 

  *Version: 1.0 "@(#) quatRotator. header. ver. 1.0. Premalatha and Vidyadhar, CTFD, NAL."

  *Dependencies:
   aVector, anAngle

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL.
  *Date:    September 14, 2000
  */

// system includes
// standard template
// local includes
#include "aVector.h"
#include "anAngle.h"
#include "quatRotatorNode.h"

// const declarations
// function prototypes
// forward declarations

// begin class declaration

class quatRotator
{
   friend class quatRotatorNode;

   friend std::ostream& operator<<(std::ostream& os, const quatRotator& quat) {
      quat.pv_ptr_quat_node->PrintNode(os);
      return os;
   }

   public:
   // constructors
      inline quatRotator();
      inline quatRotator(const quatRotator& quat);
      inline quatRotator(const anAngle& a, const aVector& axis);

   // assignment operator
      inline quatRotator& operator=(const quatRotator& quat);

   // destructor
      inline ~quatRotator();

   // accessors
      inline void SetAngle(anAngle a);
      inline void SetAxis(const aVector& v);
      inline void Set(anAngle a, const aVector& v);

      inline void AddAngle(anAngle delta_a);
      inline void AddAxis(const aVector delta_v);
      
      inline aVector GetAxis() const;
      inline anAngle GetAngle() const;

   // other functionality here
      inline quatRotator  operator^(const quatRotator& q) const;  // cross prod
      inline quatRotator& operator^=(const quatRotator& q);       // like *=

      inline quatRotator  Conjugate() const;
      inline quatRotator& MakeConjugate();

      inline double Norm() const;         // these should be trivial
      inline double NormSquare() const;

      inline void RotateVector(aVector& v);  // rotates the given vector

   protected:
   // build from a node
      inline explicit quatRotator(aQuaternionNode* ptr_quat_node);
      inline explicit quatRotator(quatRotatorNode* ptr_quat_rot_node);

   private:
      quatRotatorNode* pv_ptr_quat_rot_node;
      aQuaternionNode* pv_ptr_quat_node;
      useCount         pv_uc;
};


// include any inline code here

/**
  */
inline quatRotator::quatRotator()
   : pv_ptr_quat_rot_node( new quatRotatorNode )
{
   pv_ptr_quat_node = pv_ptr_quat_rot_node;
}


/**
  */
inline quatRotator::quatRotator(const quatRotator& quat)
   : pv_ptr_quat_node( quat.pv_ptr_quat_node ),
     pv_ptr_quat_rot_node( quat.pv_ptr_quat_rot_node ),
     pv_uc( quat.pv_uc )
{
// empty
}

/**
  */
inline quatRotator::quatRotator(const anAngle& a, const aVector& axis)
   : pv_ptr_quat_rot_node( new quatRotatorNode(a, axis) )
{
   pv_ptr_quat_node = pv_ptr_quat_rot_node;
}

/**
  */
inline quatRotator::quatRotator(quatRotatorNode* ptr_quat_rot_node)
//   : pv_ptr_quat_rot_node( ptr_quat_rot_node )
{
   pv_ptr_quat_node = pv_ptr_quat_rot_node;
}


/**
   this will be called by some of the funcitons like cross product,
   conjugate etc. we will be required to convert a object of type
   aQuaternionNode to that of a quatRotorNode. no need to copy
   underlying data.
  */
inline quatRotator::quatRotator(aQuaternionNode* ptr_quat_node)
{
   pv_ptr_quat_rot_node = new quatRotatorNode( ptr_quat_node );
   pv_ptr_quat_node     = pv_ptr_quat_rot_node;
}


/**
  */
inline quatRotator& quatRotator::operator=(const quatRotator& quat)
{
   if ( pv_uc.isAttachingTo(quat.pv_uc) )
   {
      delete pv_ptr_quat_rot_node;
      pv_ptr_quat_node = 0;
   }

   pv_ptr_quat_node     = quat.pv_ptr_quat_node;
   pv_ptr_quat_rot_node = quat.pv_ptr_quat_rot_node;

   return *this;
}


/**
  */
inline quatRotator::~quatRotator()
{
   if ( pv_uc.isOnlyInstance() == true )
   {
      delete pv_ptr_quat_rot_node;
      pv_ptr_quat_node = 0;
   }
}


/**
   the following are the accessors
  */
inline void quatRotator::SetAngle(anAngle a)
{
   if ( pv_uc.makeCopy() )
   {
      pv_ptr_quat_rot_node = new quatRotatorNode( *pv_ptr_quat_rot_node );
      pv_ptr_quat_node = pv_ptr_quat_rot_node;
   }
   pv_ptr_quat_rot_node->SetAngle(a);
}

/**
  */
inline void quatRotator::SetAxis(const aVector& new_axis)
{
   if ( pv_uc.makeCopy() )
   {
      pv_ptr_quat_rot_node = new quatRotatorNode( *pv_ptr_quat_rot_node );
      pv_ptr_quat_node = pv_ptr_quat_rot_node;
   }
   pv_ptr_quat_rot_node->SetAxis(new_axis);
}

/**
  */
inline void quatRotator::Set(anAngle a, const aVector& axis)
{
   if ( pv_uc.makeCopy() )
   {
      pv_ptr_quat_rot_node = new quatRotatorNode( *pv_ptr_quat_rot_node );
      pv_ptr_quat_node = pv_ptr_quat_rot_node;
   }
   pv_ptr_quat_rot_node->Set(a, axis);
}

/**
  */
inline void quatRotator::AddAngle(anAngle delta_a)
{
   if ( pv_uc.makeCopy() )
   {
      pv_ptr_quat_rot_node = new quatRotatorNode( *pv_ptr_quat_rot_node );
      pv_ptr_quat_node = pv_ptr_quat_rot_node;
   }
   pv_ptr_quat_rot_node->AddAngle(delta_a);
}

/**
  */
inline void quatRotator::AddAxis(const aVector delta_v)
{
   if ( pv_uc.makeCopy() )
   {
      pv_ptr_quat_rot_node = new quatRotatorNode( *pv_ptr_quat_rot_node );
      pv_ptr_quat_node = pv_ptr_quat_rot_node;
   }
   pv_ptr_quat_rot_node->AddAxis(delta_v);
}

/**
  */
inline aVector quatRotator::GetAxis() const
{
   return pv_ptr_quat_rot_node->GetAxis();
}

/**
  */
inline anAngle quatRotator::GetAngle() const
{
   return pv_ptr_quat_rot_node->GetAngle();
}


/**
  */
inline quatRotator quatRotator::operator^(const quatRotator& q) const
{
   return quatRotator(pv_ptr_quat_node->Cross( *q.pv_ptr_quat_node ));
}


/**
   this one modifies the object. it adds the quantity q to the object
   on the left hand side. since we are using value semantics, we must
   make a copy first (if need be).
  */

inline quatRotator& quatRotator::operator^=(const quatRotator& q)
{
   if ( pv_uc.makeCopy() == true )
   {
      pv_ptr_quat_rot_node = new quatRotatorNode( *pv_ptr_quat_rot_node );
      pv_ptr_quat_node     = pv_ptr_quat_rot_node;
   }
// now take the cross product
   pv_ptr_quat_node->MultiplyBy( *q.pv_ptr_quat_rot_node );
   pv_ptr_quat_rot_node->UpdateAngleAndAxis();

   return *this;
}


/**
  */
inline double quatRotator::Norm() const
{
   return pv_ptr_quat_node->Norm();
}

/**
  */
inline double quatRotator::NormSquare() const
{
   return pv_ptr_quat_node->NormSquare();
}


/**
  */
inline void quatRotator::RotateVector(aVector& v)
{
   pv_ptr_quat_rot_node->RotateVector(v);
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

#endif   // _QUATROTATOR_
