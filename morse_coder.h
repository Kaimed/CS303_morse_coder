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
  but key lookup will be very useful for encoding/decoding
*/


//"MBTNode" stands for Morse Bin Tree
template <typename T>
class MBTNode{
public:
  MBTNode* root;
  MBTNode* left;
  MBTNode* right;

  T data;

  MBTNode(){
    root = NULL;
    left = NULL;
    right = NULL;
    data = NULL;
  };
  MBTNode(MBTNode* leftChild,MBTNode* rightChild,T datum){
    root = NULL;
    left = leftChild;
    right = rightChild;
    data = datum;
  }
};



class morse_coder{
  std::map<char,std::string> encoder_dict;
  std::map<std::string,char> decoder_dict;
  //encoded or decoded result
  std::string result;

public:
  morse_coder();

  std::string decode(const std::string& input);
  std::string encode(const std::string& input);

  void build_Mtree();


};
