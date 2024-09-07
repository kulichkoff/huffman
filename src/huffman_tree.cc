#include "huffman_tree.h"

void HuffmanTree::print_tree(const std::string &prefix, const Node *node,
                             bool isLeft) {
  if (node == nullptr) return;

  std::cout << prefix;

  std::cout << (isLeft ? "├──" : "└──");

  std::cout << node->Char << ":" << node->Frequency << std::endl;

  print_tree(prefix + (isLeft ? "│   " : "    "), node->Left, true);
  print_tree(prefix + (isLeft ? "│   " : "    "), node->Right, false);
}

void HuffmanTree::print_tree(const Node *node) { print_tree("", node, false); }

void HuffmanTree::serialize_tree(Node *root, std::ofstream &file) {
  if (root == nullptr) {
    return;
  }

  if (root->IsLeaf()) {
    file << 'L' << root->Char;
  } else {
    file << 'I';
  }

  serialize_tree(root->Left, file);
  serialize_tree(root->Right, file);
}

Node *HuffmanTree::deserialize_tree(std::istream &file) {
  char flag;
  if (!(file >> flag)) {
    return nullptr;
  }

  if (flag == 'L') {
    // Leaf node
    char ch;
    file >> ch;
    return new Node(ch, 0);  // Frequency is not needed for decoding
  } else if (flag == 'I') {
    // Internal node
    Node *left = deserialize_tree(file);
    Node *right = deserialize_tree(file);
    return new Node('\0', 0, left, right);  // Internal node with no character
  }

  return nullptr;
}

Node *HuffmanTree::build_huffman_tree(
    std::unordered_map<char, int32_t> &freq_table) {
  // priority queue to store nodes for huffman tree
  std::priority_queue<Node *, std::vector<Node *>, NodeComparator> queue;
  for (auto &[ch, freq] : freq_table) {
    queue.push(new Node(ch, freq, nullptr, nullptr));
  }

  // build a tree
  while (queue.size() > 1) {
    Node *left = queue.top();
    queue.pop();
    Node *right = queue.top();
    queue.pop();

    unsigned long total_freq = left->Frequency + right->Frequency;
    queue.push(new Node('\0', total_freq, left, right));
  }

  Node *root = queue.top();
  return root;
}

void HuffmanTree::build_huffman_codes(
    Node *node, std::unordered_map<char, std::string> &codes_table) {
  if (node == nullptr) return;
  build_huffman_codes(node, "", codes_table);
}

void HuffmanTree::build_huffman_codes(
    Node *node, std::string code,
    std::unordered_map<char, std::string> &codes_table) {
  if (node->IsLeaf()) {
    codes_table[node->Char] = code;
    return;
  }

  build_huffman_codes(node->Left, code + "1", codes_table);
  build_huffman_codes(node->Right, code + "0", codes_table);
}

void HuffmanTree::build_frequency_table(
    std::string &text, std::unordered_map<char, int32_t> &table) {
  for (char ch : text) {
    table[ch]++;
  }
}

void HuffmanTree::encode(std::string &in, std::string &out,
                         std::unordered_map<char, std::string> &codes_table) {
  for (char ch : in) {
    out.append(codes_table[ch]);
  }
}

void HuffmanTree::decode(std::string &in, std::string &out,
                         std::unordered_map<char, std::string> &codes_table) {
  std::string window_str;
  for (char ch : in) {
    window_str += ch;
    for (auto &[ch, code] : codes_table) {
      if (window_str == code) {
        out += ch;
        window_str.clear();
      }
    }
  }
}
