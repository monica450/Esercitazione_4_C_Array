#pragma once


#include "ClassObj.hpp"
#include <iostream>

using namespace std;

int foo(ClassObj obj);


//  ImportVectors reads the input data from the data file
//  inputFilePath: path name of the input file
//  S: the resulting initial wealth
//  n: the resulting number of assets
//  w: the resulting vector of the weights
//  r: the resulting vector of the rates of return
//  the result of the reading: true is success, false is error

bool ImportVectors(const string& inputFilePath,
                double& S,
                size_t& n,
                double*& w,
                double*& r) 


//  FunctionRateOfReturn computes the rate of return of the portfolio and the final amount of wealth
//  S: the initial wealth
//  n: the number of assets
//  w: the vector of the weights of assets
//  r: the vector of the rates of return of assets
//  rateOfReturn: the resulting rate of return
//  V: the resulting final wealth

void FunctionRateOfReturn(const double& S,
                         const size_t& n,
                         const double* const& w,
                         const double* const& r,
                         double& rateOfReturn,
                         double& V)

//  ExportResult prints data on an output stream
//  out: object of type ostream
//  S: the initial wealth
//  n: the number of assets
//  w: the vector of the weights of assets
//  r: the vector of the rates of return of assets
//  rateOfReturn: the rate of return
//  V: the final wealth

void ExportResult(ostream& out,
                const double& S,
                const size_t& n,
                const double* const& w,
                const double* const& r,
                const double& rateOfReturn,
                const double& V)


// Export a vector in a string
// n: size of the vector
// v: vector
// the resulting string
string ArrayToString(const size_t& n,
                     const double* const& v)

