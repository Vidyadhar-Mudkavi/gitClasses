#ifndef _RANDOMNUMBER_
#define _RANDOMNUMBER_
/**
  *File: randomNumber.h

  *Description:
   this file declares class randomNumber and several other derived
   classes. an object of derived class may be used to generate
   specific type of random numbers. the code is based on 
   www.mathtools.net

   to use any of the random numbers, create an object, set the
   seed and invoke Next() to generate a sequence of random numbers.

  *Version: 1.1 "@(#) randomNumber. header. ver. 1.1. Premalatha, Vidyadhar Mudkavi, CTFD, NAL."

  *Dependencies:

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL.

  *Date:    May 17, 2001,
            Aug 08, 2001 (canonical form)
  */

// system includes
#include <cmath>

// standard template
#include <string>

// local includes
// const declarations
// function prototypes
// forward declarations

// begin class declaration
class randomNumber
{
   public:
   // constructor
      randomNumber();
      randomNumber(const std::string& name);

   // destructor
      virtual ~randomNumber();

   // accessors
      static void SetSeed(double seed);   // sets the seed
                                          // 0 <= seed <= 1
      virtual double Next();              // gets the next random number

      std::string Name() const;
      std::string Type() const;

   // other functionality
      inline virtual double Density(double) const;

   protected:
      inline void Set(const std::string& name);

   private:
   // helper functions
      static double GetRaw();             // gets raw uniform rand.
      static bool   isSeeded();
   
   // data
      static double  pv_seed;
      static int     pv_buffer_size;
      static double* pv_buffer;           // of size 128
      
      static bool    pv_is_seeded;        // check if seed is set

   // Name or Type of the random number
      std::string    pv_name;

   // disabled functionality
      randomNumber(const randomNumber& rn);
      randomNumber& operator=(const randomNumber& rn);
};



// CLASS defining uniform random numbers

class uniformRandomNumber : public randomNumber
{
   public:
   // constructor
      uniformRandomNumber();

      static inline void SetSeed(double seed);      
      inline double Next();   // gets the next unif. rand. num.
   protected:
   private:
   // disabled
      uniformRandomNumber& operator=(const uniformRandomNumber& urn);
};
   


// CLASS defining positive random numbers
// this is used only as a generator

class positiveRandomNumber : public randomNumber
{
   public:
   // constructor
      positiveRandomNumber();
  
      virtual ~positiveRandomNumber();
      
      double Next();       // generates the desired numbers
   protected:
   // helper function
      void Build(bool b);  // this is invoked on first call to Next()
      
   // some data here too (TODO: move to private)
      double  pv_xi;
      
      int     pv_ssize;    // size of sx and sfx
      double* pv_sx;
      double* pv_sfx;
      
   private:
   // data
      double pv_value;     // this is the value returned
      bool   pv_not_ready; // status indicator
   // disabled
      positiveRandomNumber& operator=(const positiveRandomNumber& prn);
};



// CLASS to define exponential random numbers

class exponentialRandomNumber : public positiveRandomNumber
{
   public:
      exponentialRandomNumber();

   // merely defines the density function
      inline double Density(double) const;
      
   protected:
   private:
   // disabled
      exponentialRandomNumber& operator=(const exponentialRandomNumber& ern);
};


// CLASS to define gaussian random numbers (trying)

class gaussianRandomNumber : public positiveRandomNumber
{
   public:
      gaussianRandomNumber();

   // merely defines the density function
      inline double Density(double) const;
      
   protected:
   private:
   // disabled
      gaussianRandomNumber& operator=(const gaussianRandomNumber& grn);
};


// include any inline code here

/**
  *Purpose: checks if the object is seeded.
  */
inline bool randomNumber::isSeeded()
{
   return pv_is_seeded;
}

/**
  *Purpose: defines the density function. interface function.
     derived class must provide a redefinition for this.
  */
inline double randomNumber::Density(double) const
{
   throw "randomNumber::Density(). function is undefined!";
}


/**
  *Purpose: sets the type name.
  */
inline void randomNumber::Set(const std::string& name)
{
   pv_name = name;
}

/**
  *Purpose: generates the next random number. interface function.
     must be redefined by the derived class.
  */
inline double uniformRandomNumber::Next()
{
   return randomNumber::Next();
}

/**
  *Purpose: sets the seed. this must be done foremost.
  */
inline void uniformRandomNumber::SetSeed(double seed)
{
   if ( (seed >= 1.0) || (seed <= 0.0) )
   {
      throw "uniformRandomNumber::SetSeed(). seed out of range!";
   }

   randomNumber::SetSeed(seed);
}

/**
  *Purpose: density function for the exponential random numbers
  */
inline double exponentialRandomNumber::Density(double x) const
{
   return (x > 40.0 || x < 0.0) ? 0.0 : ::exp(-x);
}


/**
  *Purpose: density function for the gaussian random numbers
  */
inline double gaussianRandomNumber::Density(double x) const
{
   return (x > 40.0 || x < -40.0) ? 0.0 : ::exp(-x*x);
}


// typedefs to introduce short names
typedef randomNumber            randNum;
typedef uniformRandomNumber     uniformRN;
typedef exponentialRandomNumber expRN;
typedef positiveRandomNumber    positiveRN;
typedef gaussianRandomNumber    gaussianRN;

                              //                 
                              //      \\^//    
                              //     o(!_!)o     
                              // __m__  o  __m__ 
                              //                 

#endif   // _RANDOMNUMBER_
