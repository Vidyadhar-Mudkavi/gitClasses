#ifndef _CPUCLOCK_
#define _CPUCLOCK_
/**

  *File: cpuClock.h

  *Description:

   this file declares class cpuClock. it provides two
   simple methods which start and stop the clock. one
   method is provided to display the time elapsed.

  *Version: 1.1

  *Dependencies:
   none

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL

  *Date:    8 April   1999
           18 January 2000
  */

// system includes
#include <time.h>
#include <iostream>

// local includes

// const declarations

// function prototypes

// forward declarations

// begin class declaration
class cpuClock
{
   public:

   // constructors
      cpuClock(); // default
      cpuClock(const cpuClock& class_var);

   // assignment operator
      cpuClock& operator=(const cpuClock& class_var);

   // destructor
      ~cpuClock();

   // methods to start, stop and display the clock
      void Display(std::ostream& out=std::cout);
      void PrintDate(std::ostream& out=std::cout);

      void Stop();
	   void Start();

   // a method to access elapsed time in seconds
      double GetDuration();

   protected:

   private:
   // we need start and stop values
      clock_t pv_start;
      clock_t pv_stop;
      double pv_duration;  // duration in seconds

   // for display purpose we need these
      double pv_seconds;
      int    pv_minutes;
      int    pv_hours;
      int    pv_days;
};

// include any inline code here

#endif //_CPUCLOCK_
