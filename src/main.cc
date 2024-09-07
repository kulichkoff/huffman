#include <fstream>
#include <iostream>
#include <map>
#include <string>

#include "binary.h"
#include "huffman_tree.h"

int main() {
  std::string text = "Du. Du hast. Du hast micht";
  std::cout << text << "\n";

  std::unordered_map<char, int32_t> freq_table;
  HuffmanTree::build_frequency_table(text, freq_table);

  Node *root = HuffmanTree::build_huffman_tree(freq_table);

  std::unordered_map<char, std::string> huffman_codes_table;
  HuffmanTree::build_huffman_codes(root, huffman_codes_table);

  std::string encoded_str;
  HuffmanTree::encode(text, encoded_str, huffman_codes_table);

  HuffmanBinary::write_binary_file(encoded_str, "encoded.hft", root);
  delete root;

  std::string encoded_text;

  Node *tree_root =
      HuffmanBinary::read_binary_file(encoded_text, "encoded.hft");

  std::unordered_map<char, std::string> codes_table;
  HuffmanTree::build_huffman_codes(tree_root, codes_table);
  delete tree_root;

  std::string decoded;
  HuffmanTree::decode(encoded_text, decoded, codes_table);

  std::ofstream result_file("decoded.txt");
  result_file << decoded;
  result_file.close();

  return 0;
}
