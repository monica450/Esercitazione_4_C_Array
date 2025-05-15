#include "Utils.hpp"

#include "iostream"
#include "fstream"
#include "sstream"

using namespace std;


bool ImportVectors(const string& inputFilePath,
                double& S,
                size_t& n,
                double*& w,
                double*& r) 
{   
    ifstream file;
   file.open(inputFilePath);
   if(file.fail())
   {
       cout<< "file open failed"<<endl;
       return false;
   }
   string w_fraction;
   string r_return;
   string togliere;
   string line;
   int i = 1;
   istringstream w_peso;
   istringstream r_tasso;

   while(!file.eof()) 
   {
      if(i==1)
      {
           getline(file,togliere, ';'); 
           getline(file,line);
           istringstream s_invest;
           s_invest.str(line);
           s_invest >> S;
      }
      else if(i==2)
      {
           getline(file,togliere, ';'); 
           getline(file,line);
           istringstream numero;
           numero.str(line);
           numero >> n;
           w = new double[n]; 
           r = new double[n];
      }

      else if(i==3) 
      {
          getline(file,togliere);
      }
      else
      {
           getline(file,w_fraction, ';');
           getline(file,r_return);
           w_peso.str(w_fraction);
           r_tasso.str(r_return);
           w_peso.clear();
           r_tasso.clear();
           w_peso >> w[i-4]; 
           r_tasso >> r[i-4];
      }
      i = i+1;

   }

   file.close();
   return true;
}
void FunctionRateOfReturn(const double& S,
                         const size_t& n,
                         const double* const& w,
                         const double* const& r,
                         double& rateOfReturn,
                         double& V)
{
    V=0;
    for (unsigned int i=0; i<n; i++)
    V += (1+r[i])*S*w[i]; 
    rateOfReturn = (V/S)-1; 
}

void ExportResult(ostream& out,
                const double& S,
                const size_t& n,
                const double* const& w,
                const double* const& r,
                const double& rateOfReturn,
                const double& V)
{

    cout<< fixed<< setprecision(2)<< "S = "<< S<< ", n = "<< n<< endl;

    cout<< "w = "<< ArrayToString(n,w)<< endl;

    cout<< "r = "<< ArrayToString(n,r)<< endl;

    cout<< fixed<< setprecision(4)<< "Rate of return: "<< rateOfReturn<< endl;
    cout<< fixed<< setprecision(2)<< "V: "<< V<< endl;

}

string ArrayToString(const size_t& n,
                     const double* const& v)
{

  ostringstream toString;
  toString << "[ ";
  for (unsigned int i = 0; i < n; i++)
    toString<< v[i]<< " ";
  toString << "]";

  return toString.str();

}


	
	
	
