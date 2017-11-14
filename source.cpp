#include "morse_coder.h"

using namespace std;

int main(){
  morse_coder myCoder;
  const string in("... ___ ...");
  const string out("SOS");
  cout << "Original: "
	   << in
	   <<"\nDecoded: "
	   <<myCoder.decode(in) 
	   << endl;
  cout << "Original: "
	   << out
	   <<"\nEncoded: "
	   << myCoder.encode(out);

  system("pause");
  return 0;
}
