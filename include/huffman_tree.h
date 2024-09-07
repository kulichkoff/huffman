#ifndef HUFFMAN_HUFFMAN_TREE_H_
#define HUFFMAN_HUFFMAN_TREE_H_

#include <cstdint>
#include <fstream>
#include <iostream>
#include <queue>
#include <unordered_map>

#include "node.h"
#include "node_comparator.h"

namespace HuffmanTree {

Node *build_huffman_tree(std::unordered_map<char, int32_t> &freq_table);
void build_huffman_codes(Node *node,
                         std::unordered_map<char, std::string> &codes_table);
void build_huffman_codes(Node *node, std::string code,
                         std::unordered_map<char, std::string> &codes_table);

void build_frequency_table(std::string &text,
                           std::unordered_map<char, int32_t> &table);

void serialize_tree(Node *root, std::ofstream &file);
Node *deserialize_tree(std::istream &file);

void print_tree(const std::string &prefix, const Node *node, bool isLeft);
void print_tree(const Node *node);

void encode(std::string &in, std::string &out,
            std::unordered_map<char, std::string> &codes_table);
void decode(std::string &in, std::string &out,
            std::unordered_map<char, std::string> &codes_table);

};  // namespace HuffmanTree

#endif  // HUFFMAN_HUFFMAN_TREE_H_