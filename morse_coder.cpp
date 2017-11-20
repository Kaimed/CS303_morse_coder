#include "morse_coder.h"

//INIT
morse_coder::morse_coder(){
  std::ifstream fin("morse.txt");
  Root = new MBTNode<char>(NULL,NULL,'\0');
  build_Mtree(Root, fin);
  std::string in;
  fin.open("morse.txt");
  while(fin.good()){
    std::getline(fin,in);
    char key = in[0];
    std::string morse = in.substr(1);
    encoder_dict[tolower(key)] = morse;
  }
 

  fin.close();
};


//WILL TAKE A STRING INPUT IN MORSE CODE (WITH SPACE DELIMITERS)
//WILL TRANSLATE MORSE CODE INPUT TO ENGLISH OUTPUT
//BIG-O = O(N^2)
std::string morse_coder::decode(const std::string& input){
    std::string holder;
    std::istringstream token(input);
    while(token>>holder){
	char letter = NULL;
        find_in_tree(letter,holder, Root);
        result += letter;
    }
  return result;
};
//helper function for "decode()"
void morse_coder::find_in_tree(char& resultt,std::string& input,MBTNode<char>* local_root){
    if(input.length() == 0)
        resultt += local_root->data;
    else if(input[0] == '.'){
        input = input.substr(1);
        find_in_tree(resultt,input, local_root->left);
    }
    else if(input[0] == '_'){
        input = input.substr(1);
        find_in_tree(resultt,input, local_root->right);
    }
    else{
        throw std::invalid_argument("Non-Morse Code Char Encountered...");
    }
}



//BIG-O = O(N*M) WHERE N == morse.size() and M == # of lines in file
//will set the morse_coder Root to the root of the tree.
void morse_coder::build_Mtree(MBTNode<char>* local_root, std::ifstream& fin){
    if(!fin.good())
        throw std::invalid_argument("Input file must be open for this function: build_Mtree()");
    std::string hold;
    while(fin.good()){
		std::getline(fin, hold);
        char letter = hold[0];
        std::string morse = hold.substr(1);
        place_Node(letter,local_root, morse);
    }
	fin.close();
}

//BIG-O = O(N) WHERE N == input.size()
//helper function for "build_Mtree()
void morse_coder::place_Node(const char value,MBTNode<char>* local_root,std::string& input){
    if(input == ""){
        local_root->data = value;
        return;
    }
    else{
        if(input[0] == '.'){
			if (local_root->left != NULL) {
				input = input.substr(1); //cuts off the first dot
				place_Node(value, local_root->left, input); //call with local root as left child because code was '.'
			}
			else {
				local_root->left = new MBTNode<char>;
				input = input.substr(1);
				place_Node(value, local_root->left, input);
			}
        }else if(input[0] == '_'){
			if (local_root->right != NULL) {
				input = input.substr(1); //cuts off the first dot
				place_Node(value, local_root->right, input); //call with local root as left child because code was '.'
			}
			else {
				local_root->right = new MBTNode<char>;
				input = input.substr(1);
				place_Node(value, local_root->right, input);
			}
        }
        
    }
}


//COMPLEXITY:
//BIG-O = O(NLOG(N)) WHERE N == # OF LETTERS IN CODE
std::string morse_coder::encode(const std::string& input){
	std::string result;
	std::istringstream tokens(input);
	char c;
	while (tokens >> c) {
		//std::cout << c << '\t' << encoder_dict[tolower(c)]<<'\n';

		result += encoder_dict[tolower(c)];
	}

	return result;
}



//THIS IS FOR FUN:
/*
	I WANT TO IMPLEMENT A FUNCTION THAT CAN READ
	AN INPUT STRING WHICH IS A MIX OF MORSE CODE
	AND NORMAL ENGLISH LETTERING

	@ASSUMPTION: all chars are separated by spaces.
*/
std::string morse_coder::translate(const std::string input) {
	std::string holder;
	std::istringstream tokens(input);
	std::string s;
	while (tokens >> s) {
		if (s.length() == 1 && s[0] != '.' && s[0] != '_')
			holder += encode(s);
		else
			holder += decode(s);
		holder += ' ';
	}
	return holder;
}
