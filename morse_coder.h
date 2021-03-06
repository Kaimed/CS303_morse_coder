#ifndef morse_coder_h
#define morse_coder_h
#endif

#include <iostream> //for reporting on operations
#include <string> //for encoding from the file -> getline(istream,string)
#include <sstream> //parse the strings from morse.txt
#include <fstream> //for reading from morse.txt
#include <map>
/*
  im familiar calling it a dictionary,
  but key lookup will be very useful for encoding
*/
#include <locale> //for tolower()


//"MBTNode" stands for Morse Bin Tree
template <typename T>
class MBTNode{
public:
	
  //data fields
  MBTNode* left;
  MBTNode* right;
  T data;
  //constructors
  MBTNode(){
	  left = NULL;
	  right = NULL;
  };
  MBTNode(MBTNode* leftChild,MBTNode* rightChild,T datum){
    left = leftChild;
    right = rightChild;
    data = datum;
  }
};



class morse_coder{
  //private data fields
  std::map<char,std::string> encoder_dict;
  std::map<std::string,char> decoder_dict;
  //encoded or decoded result
  std::string result;
  MBTNode<char>* Root;
public:
  //constructor
  morse_coder();
  
  //converts english to morse code
  std::string decode(const std::string& input);
    //decode helper function
    void find_in_tree(char& result,std::string& input,MBTNode<char>* local_root);
    
    std::string translate(const std::string input);

  //converts morse code to english variant
  std::string encode(const std::string& input);
    
  //returns a pointer to the root
    void build_Mtree(MBTNode<char>* local_root,std::ifstream& fin);
    void place_Node(const char value,MBTNode<char>* local_root,std::string& input);


};
