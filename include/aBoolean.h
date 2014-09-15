// Microsoft Compiler
// _MSC_VER 1000 is version 4.0, 1100 is 5.0, 1200 is 6.0
#if defined(_MSC_VER)
#  if _MSC_VER < 1100
#    define _NO_BOOL_TYPE_SUPPORTED
#  endif
#endif

#if defined(_NO_BOOL_TYPE_SUPPORTED)
#  ifndef _ABOOLEAN_
#  define _ABOOLEAN_

/**
  *File: aBoolean.h

  *Description:

   this is a boolean data type. it is similar to the bool
   type introduced in later version of C++.

   we have tried and implemented a complete class which
   does various tasks. these are described below:

   the class provides for logical operators using logical AND
   and OR. the following truth table is assumed. this is
   NOT fully tested:

                 AND                    OR
            +------------+        +------------+
            | && | T | F |        | || | T | F |
            +------------+        +------------+
            | T  | t | f |        | T  | t | t |
            |----|---|---|        |----|---|---|
            | F  | f | f |        | F  | t | f |
            +------------+        +------------+
            
   in this version, we implement a simple and a very compact
   boolean type. here, the value is stored as an int and a
   conversion operator is made use of to provide functionality
   of this type in a mixed logical expression.
  
  *Note: the values `true' and `false' are tagged as keywords
         for future use (when compiled using the MSDV). so
         also, the word `bool'. that is, the future c++ will
         support bool data type with values false and true.
         it is, therefore, not a good idea to use these in this
         program and as such they have been removed.
         (sccs version 1.1 still contains the false, true, bool)


  *Version: 1.4

  *Dependencies:
   none
         
  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL (in DLR)
  *Date:    18 Feb. 1998, 17 Jul. 1998, 31 Aug.1999
  */

// system includes
#include <iostream.h>

// application include

// #defines
enum enBool 
{
   FALSE = (0 == 1),    // must be false
   TRUE  = (1 == 1)     // must be true
};

enum enBoolSmall
{
   false = (0 == 1),    // must be false
   true  = (1 == 1)     // must be true
};

class aBoolean
{
   public:

   // constructors
      aBoolean() : pv_value(FALSE) {}
      aBoolean(int   i) : pv_value(i ? TRUE : FALSE) {}
      aBoolean(const enBool& eb) : pv_value(eb) {}
      aBoolean(const aBoolean& b) : pv_value(b.pv_value) {}

   // assignment operators
      aBoolean& operator=(const enBool& ebool) {
         pv_value = ebool;
         return *this;
      }

      aBoolean& operator=(int i) {
         pv_value = i ? TRUE : FALSE;
         return *this;
      }

      aBoolean& operator=(const aBoolean& b)
      {
         pv_value = b.pv_value;
         return *this;
      }

   // type conversion operator to int (this is all we need)
      operator int() const
      {
         return pv_value ? TRUE : FALSE;
      }

   // now for reading and writing the boolean object     
      friend ostream& operator<<(ostream& os, const aBoolean& b) {
            return ( os << ( b.pv_value ? "TRUE" : "FALSE" ) );
      }

      friend ostream& operator<<(ostream& os, const enBool&  eb) {
            return ( os << ( eb ? "TRUE" : "FALSE" ) );
      }
  
      friend istream& operator>>(istream& is, aBoolean& b) {
         return (is >> b.pv_value);
      }

      friend istream& operator>>(istream& is, enBool& eb) {
         int i;
         is >> i;
         eb = i ? TRUE : FALSE;
         return is;
      }

   protected:

   private:
      short int pv_value;
};

// sometimes, aBool may be bit more convenient to use. so typedef it
typedef aBoolean aBool;
typedef aBoolean bool;

#  endif // _ABOOLEAN_

#else    // this will give compatibility to our old codes too.

   typedef bool aBoolean;
   typedef bool enBool;
#  define  TRUE   1
#  define  FALSE  0

#endif
