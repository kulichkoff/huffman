#include <iostream>
#include <map>
#include <string>

#include "huffman_tree.h"

int main() {
  std::string text = "Du. Du hast. Du hast micht";
  std::cout << text << "\n\n";


  std::unordered_map<char, int32_t> freq_table;
  HuffmanTree::build_frequency_table(text, freq_table);

  Node *root = HuffmanTree::build_huffman_tree(freq_table);

  std::unordered_map<char, std::string> huffman_codes_table;
  HuffmanTree::build_huffman_codes(root, huffman_codes_table);

  std::string encoded_str;
  HuffmanTree::encode(text, encoded_str, huffman_codes_table);

  HuffmanTree::print_tree(root);

  std::cout << std::endl << encoded_str << std::endl;

  return 0;
}
