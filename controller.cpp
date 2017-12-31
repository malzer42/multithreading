// helloThread.cpp: program to test the concurrent programming in C++ with multithreading
/*
  1. Thread creation: std::thread t(object , )
  2. Thread management:
  3. Data race and mutex:
  4. Deadlock
  5. Unique lock and lazy initialization
  6.
  compiling: g++-6 -std=c++1z -o thred.exe helloThread.cpp -lpthread
  compiling: Makefile provided. From the command line run make

  *\ Author(s) : Pierre Abraham Mulamba, Ph.D.
  *\ Date of creation (modification) : 20171027 (20171028)
*/
/********************************************************************************
 Copyright (c) 2017, IOSS, inc.
 All rights reserved

********************************************************************************/

#include <chrono>
#include <future>
#include "Functions.h"
#include <time.h>

int main(int argc, char* argv[])
{

	try {

		auto begin = clock();
		
		LogFile log;
		
		log.shared_resource(std::string("Falcon nThreads: "),
							std::thread::hardware_concurrency());
		log.shared_resource(std::string("Main tid: "),
							std::thread::hardware_concurrency());


		
		//! Creation of a thread with a factorial function
		int nFactorial_ = 10;
		//condv.wait(loker);
		std::thread t2(factorial, std::ref(log), std::ref(nFactorial_));

		int nFibonacci_ = 10000;
		std::thread t4(fibonacci, std::ref(log), std::ref(nFibonacci_));

		//! Creation of a thread with async
		std::future<int> fut_ = std::async(std::launch::async|std::launch::deferred,
										   factorial, std::ref(log), std::ref(nFactorial_));

		int result_ = 0;		
		result_ = fut_.get();
		log.shared_resource(std::string("Controller tid: ") , std::ref(result_));

		//! creation of a thread with a Lamba funtion that compute x*x*
		std::thread t3([](LogFile& logfile, int& x){logfile.shared_resource(std::string("Lambda2: "), x*x);},
					   std::ref(log), std::ref(result_));
		//	std::thread t4(factorial, std::ref(log));

		//! creation of a thread with a Lamba funtion that compute x*x*x
		std::thread t1([](LogFile& logfile, int& x){logfile.shared_resource(std::string("Lambda3: "),
																			x*x*x);},
					   std::ref(log), std::ref(nFactorial_));

		
		t1.join();
		t2.join();
		t3.join();
		t4.join();

		auto end = clock();
		auto elapsed_seconds = double(end -begin)/CLOCKS_PER_SEC;
		std::cout << "elapsed: " << elapsed_seconds << '\n';
		
	} catch (...) {
		
	}
	return 0;
}
