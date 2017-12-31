// Functions.h: header file for signatures of functions used in the controller
/*


  *\ Author(s): Pierre Abraham Mulamba
  *\ Date of creation (modification): 20171224
*/
/********************************************************************************
 Copyright (c) 2017, IOSS, inc.
 All rights reserved
********************************************************************************/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include "LogFile.h"

int factorial(LogFile& logfile, int& nFactorial);
void fibonacci(LogFile& logfile, int& nFibonacci);
void print(LogFile& logfile);
int recursive_fibonacci(int nFibonacci);

#endif /* FUNCTIONS_H */


