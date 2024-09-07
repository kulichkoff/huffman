#include "node.h"

Node::Node(char ch, int32_t freq) {
  Char = ch;
  Frequency = freq;
}

Node::Node(char ch, int32_t freq, Node* left, Node* right) {
  Char = ch;
  Frequency = freq;
  Left = left;
  Right = right;
}

Node::~Node() {
  if (Left != nullptr) delete Left;
  if (Right != nullptr) delete Right;
}

bool Node::IsLeaf() { return Left == nullptr && Right == nullptr; }
