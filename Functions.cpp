// Functions.cpp: Implementation of the functions 
/*
  The LogFile class will be used to solve the data race problem in multithreading

  *\ Author(s): Pierre Abraham Mulamba
  *\ Date of creation (modification): 20171224
*/
/********************************************************************************
 Copyright (c) 2017, IOSS, inc.
 All rights reserved
********************************************************************************/

#include "Functions.h"

int factorial(LogFile& logfile, int& nFactorial)
{
	int result = 1;
	logfile.shared_resource(std::string("Yield: ") , result);
	for (int i = nFactorial; i > 1; i--) {
		result *= i;
		logfile.shared_resource(std::string("Yield: ") , result);
	}
	
	return result;
}

void fibonacci(LogFile& logfile, int& nFibonacci)
{
	int a = 1;
	int b = 1;
	
	logfile.shared_resource(std::string("Fib: "), a);
	while (b < nFibonacci) {
		logfile.shared_resource(std::string("Fib: "), b);
		b = b + a;
		a = b - a;
	}
	
}


void print(LogFile& log)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(2));
	log.shared_resource(std::string("PrintMessage tid: "),
						std::thread::hardware_concurrency() );
}

int recursive_fibonacci(int nFibonacci)
{
	if (nFibonacci < 2) return  nFibonacci;
	return recursive_fibonacci(nFibonacci - 1) + recursive_fibonacci(nFibonacci -2);
}
