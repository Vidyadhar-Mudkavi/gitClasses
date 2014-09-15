#ifndef _AQUATERNIONNODE_
#define _AQUATERNIONNODE_
/**

  *File: aQuaternionNode.h

  *Description:
   this defines a quaternion node class. the handle aQuaternion is attached
   to object of this class. it stores the four values of a 
   quaternion as an array.
   
   the components are stored as: (p, v), where v is a vector with three
   components.

  *Version: 1.0 "@(#) aQuaternionNode. header. ver. 1.0. Premalatha and Vidyadhar, CTFD, NAL."

  *Dependencies:

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL.
  *Date:    September 14, 2000
  */

// system includes
#include <iostream>

// standard template
// local includes
#include "aVector.h"

// const declarations
// function prototypes
// forward declarations
class aQuaternion;
class quatRotator;

// begin class declaration

class aQuaternionNode
{
   friend class aQuaternion;
   friend class quatRotator;
   friend class quatRotatorNode;

   friend std::ostream& operator<<(std::ostream& os, const aQuaternion& quat);
   friend std::ostream& operator<<(std::ostream& os, const quatRotator& quat);

   public:
   protected:
   // constructors
      aQuaternionNode();
      aQuaternionNode(const aQuaternionNode& quat_node);
      aQuaternionNode(double p, const double& v1, const double& v2, const double& v3);

   // assignment operator (no implementation for this)
      aQuaternionNode& operator=(const aQuaternionNode& quat_node);

   // destructor
      virtual ~aQuaternionNode();

   // accessors
      void SetReal(double p);
      void SetImag(double v1, double v2, double v3);
      void SetImag(const aVector& v);
      void Set(double p, double v1, double v2, double v3);
      void Set(double p, const aVector& v);

      double GetComponent(int index) const;

   // other functionality here
      aQuaternionNode* Plus(const aQuaternionNode& q) const;
      void Add(const aQuaternionNode& q);
      aQuaternionNode* Minus(const aQuaternionNode& q) const;
      void Subtract(const aQuaternionNode& q);

      aQuaternionNode* Times(double alpha) const;
      void MultiplyBy(double alpha);

      aQuaternionNode* Slash(double alpha) const;
      void DivideBy(double alpha);

      aQuaternionNode* Cross(const aQuaternionNode& q) const;
      void MultiplyBy(const aQuaternionNode& q);

      aQuaternionNode* Conjugate() const;
      void MakeConjugate();

      virtual double Norm() const;
      virtual double NormSquare() const;

      void PrintNode(std::ostream& os);

   private:
   // data
      double* pv_value;    // will be of size [4];
      static const int pv_size;
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

#endif   // _AQUATERNIONNODE_
