#include "morse_coder.h"

using namespace std;

int main(){
  morse_coder myCoder;
  const string in(".._. .._ _._. _._");
  const string out("Fuck");
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
