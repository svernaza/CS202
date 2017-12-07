#include <iostream>
#include <fstream>

#include <vector>

#include "VectorRecursion.h"


int main(){

  // Vector creation
  std::vector<int> vecInt;
  
  // Vector population with input values
  std::ifstream fin("RandomData.txt");
  while(fin){
    int fin_in;
    fin >> fin_in;
    if (!fin)
      break;
    vecInt.push_back( fin_in );
  }

  // Vector indexing and output ( using operator[] or at() )
  for (size_t i=0; i<vecInt.size(); ++i){
    std::cout << vecInt[i] << " same as " << vecInt.at(i) << std::endl; 
  }
  
  // Vector indexing and output ( using iterator )
  for (std::vector<int>::iterator it=vecInt.begin(); it!=vecInt.end(); ++it){
    std::cout << *it << std::endl; 
  }

  return 0;
}
