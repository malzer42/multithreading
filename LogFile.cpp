// LogFile.cpp: Implementation of the class LogFile
/*
  The LogFile class will be used to solve the data race problem in multithreading

  *\ Author(s): Pierre Abraham Mulamba
  *\ Date of creation (modification): 20171224
*/
/********************************************************************************
 Copyright (c) 2017, IOSS, inc.
 All rights reserved
********************************************************************************/
#include "LogFile.h"

LogFile::LogFile()
{
	// fout.open("log.txt");
}

LogFile::~LogFile()
{
	fout_.close();
}

void LogFile::shared_resource(const std::string& msg, int value){
	std::call_once(flag_, [&](){fout_.open("log.txt");});
	//std::lock_guard<std::mutex> guard(guard_fout_mutex_);
	std::unique_lock<std::mutex> locker(mutex_, std::defer_lock);
	fout_ << msg  << " " << value <<". TID --> " << std::this_thread::get_id() << '\n';
    //locker.unlock();
	condv.notify_all();
}
