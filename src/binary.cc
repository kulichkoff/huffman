#include "binary.h"

void HuffmanBinary::write_binary_file(std::string& encoded_str,
                                      const char* file_name, Node* tree_root) {
  std::ofstream out_file(file_name, std::ios::binary);

  unsigned char bom[] = {0xEF, 0xBB, 0xBF};
  HuffmanTree::serialize_tree(tree_root, out_file);  // write tree to file
  out_file.write((char*)bom, sizeof(bom));           // add bom as separator

  std::string padded_str = encoded_str;
  if (padded_str.size() % 8 != 0) {
    padded_str.append(8 - padded_str.size() % 8, '0');  // Pad with '0's
  }

  for (size_t i = 0; i < padded_str.size(); i += 8) {
    std::string byte_str = padded_str.substr(i, 8);
    unsigned char byte =
        static_cast<unsigned char>(std::bitset<8>(byte_str).to_ulong());
    out_file.write(reinterpret_cast<const char*>(&byte), sizeof(byte));
  }
  out_file.close();
}

Node* HuffmanBinary::read_binary_file(std::string& code_str,
                                      const char* file_name) {
  std::ifstream encoded_file(file_name, std::ios::binary);

  // Read until BOM is found
  const std::string BOM = "\xEF\xBB\xBF";
  std::string buffer;
  char ch;
  while (encoded_file.get(ch)) {
    buffer += ch;
    if (buffer.size() >= 3 && buffer.substr(buffer.size() - 3) == BOM) {
      buffer.resize(buffer.size() - 3);  // Remove BOM from buffer
      break;
    }
  }

  // Deserialize the tree from the buffer
  std::istringstream tree_stream(buffer);
  Node* root = HuffmanTree::deserialize_tree(tree_stream);
  if (!root) {
    throw std::runtime_error("Error: cannot deserialize tree from file");
  }

  unsigned char byte;
  while (encoded_file.read(reinterpret_cast<char*>(&byte), sizeof(byte))) {
    // Convert each byte to a string of '0's and '1's
    code_str += std::bitset<8>(byte).to_string();
  }
  encoded_file.close();
  return root;
}
