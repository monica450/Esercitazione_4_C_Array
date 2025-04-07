#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Utils.hpp" 
#include "ClassObj.hpp" 

using namespace std;

int main()
{
  string fileName_input = "data.txt";
  double S = 0.0;
  size_t n = 0;
  double* w = nullptr;
  double* r = nullptr;

  if (!ImportVectors(fileName_input, S, n, w, r))
  {
    cout<< "Errore con l'importazione dei dati"<< endl;
    return -1;
  }


  double rateOfReturn;
  double V;
  FunctionRateOfReturn(S, n, w, r, rateOfReturn, V);


  
  ExportResult(cout, S, n, w, r, rateOfReturn, V);


  
  string fileName_output = "result.txt";
  ofstream file;
  file.open(fileName_output);

  if (!file.fail())
  {
    ExportResult(file, S, n, w, r, rateOfReturn, V);
  }

  file.close();

  delete[] w;
  delete[] r;

  return 0;
}

