#include "node_comparator.h"

bool NodeComparator::operator()(Node* first, Node* second) {
  return first->Frequency > second->Frequency;
}
