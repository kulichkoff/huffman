#ifndef HUFFMAN_BINARY_H_
#define HUFFMAN_BINARY_H_

#include <fstream>
#include <string>
#include <sstream>

#include "huffman_tree.h"
#include "node.h"

namespace HuffmanBinary {


void write_binary_file(std::string &encoded_str, const char *file_name,
                       Node *tree_root);

Node *read_binary_file(std::string &code_str, const char *file_name);

};  // namespace HuffmanBinary

#endif  // HUFFMAN_BINARY_H_
