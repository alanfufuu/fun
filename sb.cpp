#include <iostream>
using namespace std;

enum Level {
    LOW,
    MEDIUM,
    HIGH
};




int main() {
  int a[] = {1, 2, 3, 4, 5};
  for (int i : a){
    cout << i;
  }
  
  return 0;
}