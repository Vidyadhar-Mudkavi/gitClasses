#ifndef _QUATROTATORNODE_
#define _QUATROTATORNODE_
/**

  *File: quatRotatorNode.h

  *Description:
   this defines a quaternion rotator node class. the handle quatRotator
   is attached to object of this class. derived from the aQuaternionNode,
   this class serves the special purpose of enabling one to rotate
   vectors in 3d space by a given angle about a given axis.
   
  *Version: 1.0 "@(#) quatRotatorNode. header. ver. 1.0. Premalatha and Vidyadhar, CTFD, NAL."

  *Dependencies:

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL.
  *Date:    September 15, 2000
  */

// system includes
// standard template
// local includes
#include "anAngle.h"
#include "aQuaternionNode.h"
#include "aVector.h"

// const declarations
// function prototypes
// forward declarations

// begin class declaration

class quatRotatorNode : public aQuaternionNode
{
   friend class aQuaternion;
   friend class quatRotator;

// LATER   friend std::ostream& operator<<(std::ostream& os, const aQuaternion& quat);

   public:
   protected:
   // constructors
      quatRotatorNode();
      quatRotatorNode(const quatRotatorNode& quat_rot_node);
      quatRotatorNode(anAngle a, const aVector& axis);

      quatRotatorNode(aQuaternionNode* ptr_quat_node);

   // assignment operator (no implementation for this)
      quatRotatorNode& operator=(const quatRotatorNode& quat_rot_node);

   // destructor
      virtual ~quatRotatorNode();

   // accessors
      void SetAngle(anAngle a);
      void SetAxis(const aVector& v);
      void Set(anAngle a, const aVector& v);
      
      void AddAngle(anAngle delta_a);
      void AddAxis(const aVector& delta_v);

      anAngle GetAngle() const;
      aVector GetAxis() const;

   // other functionality here
      double Norm() const;
      double NormSquare() const;

      void UpdateAngleAndAxis();       // need this to figure out axis and angle
      void RotateVector(aVector& v);   // rotates the vector
   private:
   // better to maintain this extra information
      aVector pv_axis;
      anAngle pv_angle;
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

#endif   // _QUATROTATORNODE_
