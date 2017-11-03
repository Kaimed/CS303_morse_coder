#include "morse_coder.h"

using namespace std;

int main(){
  morse_coder myCoder;
  const string in(".._. .._ _._. _._");
  cout<<myCoder.decode(in);
  cin.get();
  return 0;
}
