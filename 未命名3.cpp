#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
int main() {
  int* test = new int[5];
  for (
    int i = 0; i < 5; i++)
  {
    test[i] = i+1;
  }
  cout<<test[5];
      cout<<(*test)++<<endl;
  
  for (size_t i = 0; i < 5; i++)
  {
    cout<<*test<<endl;
  }
  
  

  
  return 0;
}
