#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <set>
#include <regex>

void printUsage() {
  std::cout << "Usage : spellchecker [dictionary txt file] [txt file to check]" << std::endl;
}

void error_exit(std::string s) {
  std::cout << s << std::endl;
  exit(EXIT_FAILURE);
}

int main(int argc, char** argv){
  using is_str_itr = std::istream_iterator<std::string>;

  if (argc != 3) {
    printUsage();
    return 1;
  }

  // Reading in dictionary file.
  std::ifstream dict_ifs(argv[1]);
  if (!dict_ifs) error_exit("File not found! Check input!");
  std::set<std::string> dictionary{
     (is_str_itr(dict_ifs)),  //input iterator
     (is_str_itr())};    //input sentinel

  // Checking the to-be-checked file.
  std::ifstream spellchecked_ifs(argv[2]);
  if (!spellchecked_ifs) error_exit("File not found! Check input!");
  std::set<std::string>::const_iterator end_of_dict = dictionary.end();

  /* Somehow not working. "No match for operator!= found." No idea why.
  for (is_str_itr file_itr(spellchecked_ifs), file_sentinel(); file_itr != file_sentinel; ++file_itr) {
    if (dictionary.find(*file_itr) == end_of_dict) std::cout << std::endl << *file_itr;
  }*/

  std::string current_word;
  while(spellchecked_ifs.good()) {
    spellchecked_ifs >> current_word;

    //replace some unnecessary symbols
    //not implemented... bwuaaa.
    /*
    current_word = std::regex_replace(current_word, std::regex("[^A-Za-z]"), "");
    */

    std::string special_characters = ".,!?\"';,-";
    for (int i = 0, l = special_characters.length(); i < l; ++i)
      current_word.erase(std::remove(current_word.begin(), current_word.end(), special_characters[i]), current_word.end());

    if (dictionary.find(current_word) == end_of_dict) {
      std::cout << std::endl << current_word;
    }
  }

  std::cout << std::endl;

  return 0;
}
