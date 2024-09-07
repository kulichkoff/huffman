#ifndef HUFFMAN_NODE_COMPARATOR_H_
#define HUFFMAN_NODE_COMPARATOR_H_

#include "node.h"

class NodeComparator {
 public:
    bool operator()(Node *first, Node *second);
};

#endif  // HUFFMAN_NODE_COMPARATOR_H_
