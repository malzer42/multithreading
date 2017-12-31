// LogFile.h: Header file for the class LogFile
/*
  The LogFile class will be used to solve the data race problem in multithreading

  *\ Author(s): Pierre Abraham Mulamba
  *\ Date of creation (modification): 20171224
*/
/********************************************************************************
 Copyright (c) 2017, IOSS, inc.
 All rights reserved
********************************************************************************/

#ifndef LOGFILE_H
#define LOGFILE_H

#include <string>
#include <fstream>
#include <mutex> // synchronization primitive to protect shared data simultaneous access by multiple thread
#include <thread> // allow multiple functions to execute concurrently
#include <condition_variable> // synchronization primitive for threads execution sequence 
class LogFile
{
public:
	LogFile(); //! Default constructor
	virtual ~LogFile() noexcept; //! Destructor
	void shared_resource(const std::string& msg , int value);

protected:
private:
	//std::mutex guard_fout_mutex_;
	std::mutex mutex_;
	std::ofstream fout_;
	std::once_flag flag_;
	std::condition_variable condv;
};


#endif /* LOGFILE_H */
