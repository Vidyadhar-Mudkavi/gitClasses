#ifndef _CPUCLOCK_
#define _CPUCLOCK_

/**
  *File: cpuClock.h

  *Description:

   this file declares class cpuClock. it provides two
   simple methods which start and stop the clock. one
   method is provided to display the time elapsed.

   1.2:  all functions inlined to avoid inclusion of implementation file.
         assignment and special construction removed (use default)

  *Version: 1.2 "@(#) cpuClock. header. ver. 1.2. Premalatha and Vidyadhar, CTFD, NAL."

  *Dependencies:
   none

  *Authors: Premalatha, Vidyadhar Mudkavi, CTFD, NAL

  *Date:    8 April   1999
           18 January 2000
           08 September 2000
  */

// system includes

// sgi does not provide <ctime> header in place of <time.h>
#if defined(__sgi) && !defined(__GNUC__)
#  include <time.h>
#else
#  include <ctime>
#endif

#include <iostream>

// stl
#include <string>
#include <iomanip>

// local includes
// const declarations
// function prototypes
// forward declarations

// begin class declaration
class cpuClock
{
   public:
   // constructors
      inline cpuClock(std::string id="");

   // methods to start, stop and display the clock
      inline void Display(std::ostream& out=std::cout) const;
      inline void PrintDate(std::ostream& out=std::cout) const;

      inline void Stop();
      inline void Start();

   // a method to access elapsed time in seconds
      inline double GetDuration() const;

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

   // and perhaps this may help
      std::string pv_id;
};

// include any inline code here
inline cpuClock::cpuClock(std::string id)
   : pv_duration(0.0),
     pv_days(0),
     pv_hours(0),
     pv_minutes(0),
     pv_seconds(0.0),
     pv_id(id)
{
// empty
}

/**
   this function starts the clock
  */
inline void cpuClock::Start()
{
   pv_start = clock();
}

/**
   this function stops the clock and computes the
   elapsed time (duration)
  */
inline void cpuClock::Stop()
{
   pv_stop = clock();
   pv_duration = double(pv_stop - pv_start)/CLOCKS_PER_SEC;

   if ( pv_duration < 60.0 )
   {
      pv_seconds = pv_duration;
      return;
   }

// now compute days, hours, minutes etc.
// first get number of days
   pv_days = int( pv_duration/double(60*60*24) );
   pv_duration -= pv_days*60*60*24;

// next get number of hours
   pv_hours = int( pv_duration/double(60*60) );
   pv_duration -= pv_hours*60*60;

// next get number of minutes
   pv_minutes = int( pv_duration/double(60) );
   pv_duration -= pv_minutes*60;

// what is left over is number of seconds
   pv_seconds = pv_duration;
}

/**
   this function displays the time in 
   days: hours: minutes: seconds format
  */
inline void cpuClock::Display(std::ostream& out) const
{
// we will change the formatting for this display.
// in order to restore the settings, do the following
   std::ios_base::fmtflags old_flags = out.flags();

   out.unsetf(std::ios::fixed | std::ios::scientific);
   out << std::left << std::noshowpos;

   std::streamsize old_ssize = out.precision();

   out.precision(8);

   if ( pv_id != std::string("") )
   {
      out << "  >>> " << pv_id.c_str() << " >>> ";
   }

   out << "** Elapsed time ** : ";

   if ( pv_days != 0 )
   {
      out << pv_days    << " d: "
          << pv_hours   << " h: "
          << pv_minutes << " m: "
          << pv_seconds << " s" << std::endl;
   }
   else if ( pv_hours != 0 )
   {
      out << pv_hours   << " h: "
          << pv_minutes << " m: "
          << pv_seconds << " s" << std::endl;
   }
   else if ( pv_minutes != 0 )
   {
      out << pv_minutes << " m: "
          << pv_seconds << " s" << std::endl;
   }
   else
   {
      out << pv_seconds << " s" << std::endl;
   }

   PrintDate(out);

#if 0
// print the date and local time as well
// see the PrintDate funciton

   time_t curr_time;
   ::time( &curr_time );
 
   out << ::asctime( ::localtime( &curr_time ) ) << std::endl;

#if 1 // will see this later. presently use the deprecated variant as above.
#if defined(_MSC_VER) && (_MSC_VER < 1400)   // spaces matter!!
   out << ::asctime( ::localtime( &curr_time ) ) << std::endl;
#else
   const size_t longLineSize = 1024;
   char currentTime[ longLineSize ];
   ::asctime_s( currentTime, ::localtime_s( &curr_time ) ); ::localtime_s(
   out << currentTime << std::endl;
#endif
#endif 
#endif
// restore the flags to old ones
   out.flags(old_flags);
   out.precision( old_ssize );
}

/**
   this function prints the date and time as a readable string.
   the code is described in msdn library. search under clock,
   time, localtime etc.
  */
inline void cpuClock::PrintDate(std::ostream& out) const
{
   ::time_t curr_time;
   ::time( &curr_time );   // get the current time in seconds

#if defined(__GNUC__) || (defined(_MSC_VER) && (_MSC_VER < 1400))   // spaces matter!!
   out << ::asctime( ::localtime( &curr_time ) ) << std::endl;
#else
   ::errno_t errorNumber;
   
   const size_t longLineSize = 48;     // 32 should be more than enough actually!
   char currentTime[ longLineSize ];   // string buffer to hold time
   ::tm timeStructure;

   ::localtime_s(&timeStructure, &curr_time);               // fills the time structure
   errorNumber = ::asctime_s(currentTime, &timeStructure);  // get string representation of time

   if ( errorNumber == 0 )
   {
      out << currentTime << std::endl;
   }
   else
   {
      out << "***************** Error in time print function. In cpuClock. ***************" << std::endl;
   }
#endif
}


/**
   this function returns the time elapsed.
  */
inline double cpuClock::GetDuration() const
{
   return pv_duration;
}

#endif //_CPUCLOCK_
