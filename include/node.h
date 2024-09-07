#ifndef HUFFMAN_NODE_H_
#define HUFFMAN_NODE_H_

#include <cstdint>

class Node {
 public:
  char Char;
  int32_t Frequency;

  Node *Left;
  Node *Right;

  Node(char ch, int32_t freq);
  Node(char ch, int32_t freq, Node *left, Node *right);
  
  ~Node();

  bool IsLeaf();
};

#endif  // HUFFMAN_NODE_H_
