#include "morse_coder.h"

morse_coder::morse_coder(){
  std::ifstream fin("morse.txt");
  build_Mtree(Root, fin);
  std::string in;
  while(fin.good()){
    std::getline(fin,in);
    char key = in[0];
    std::string morse = in.substr(1);
    encoder_dict[key] = morse;
    decoder_dict[morse] = key;

  }
 

  fin.close();
};

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
void morse_coder::find_in_tree(char resultt,std::string& input,MBTNode<char>* local_root){
    if(input.length() == 0)
        resultt += local_root->data;
    else if(input[0] == '.' && input.length() == 1){
        resultt += local_root->left->data;
    }
    else if(input[0] == '_' && input.length() == 1){
        resultt += local_root->right->data;
    }
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




//will set the morse_coder Root to the root of the tree.
void morse_coder::build_Mtree(MBTNode<char>* local_root, std::ifstream& fin){
    if(!fin.good())
        throw std::invalid_argument("Input file must be open for this function: build_Mtree()");
    std::string hold;
    while(std::getline(std::cin,hold)){
        char letter = hold[0];
        std::string morse = hold.substr(1);
        place_Node(letter,local_root, morse);
    }
    Root = local_root;
}
//helper function for "build_Mtree()
void morse_coder::place_Node(const char value,MBTNode<char>* local_root,std::string& input){
    if(input == ""){
        local_root->data = value;
        return;
    }
    else{
        if(input[0] == '.'){
            local_root->left = new MBTNode<char>;
            input = input.substr(1); //cuts off the first dot
            place_Node(value,local_root->left, input); //call with local root as left child because code was '.'
        }else if(input[0] == '_'){
            local_root->right = new MBTNode<char>;
        }
        
    }
}
