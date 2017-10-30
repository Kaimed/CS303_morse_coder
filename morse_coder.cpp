#include "morse_coder.h"

morse_coder::morse_coder(){
	std::cout << "Creating decoder....." << '\n';
	std::ifstream fin("morse.txt");
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
  std::istringstream is(input);
  std::string letter;
  while(is>>letter){
    //std::cout<<"Letter: "<<decoder_dict[letter] <<std::endl<< "MORSE: "<<letter<<std::endl;
    result += decoder_dict[letter];
  }

  return result;
};
