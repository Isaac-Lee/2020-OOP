// Copyright [2020] <LeeYesung>
#include <vector>

class Node {
 public:
  explicit Node(int value) : value_(value) {}
  Node(const Node& node) : value_(node.value_),
  left_(node.left_), right_(node.right_) {}
  ~Node() {
    delete this->right_;
    delete this->left_;
    delete this;
  }
  int value() {
    return value_;
  }
  Node* left() {
    return left_;
  }
  Node* right() {
    return right_;
  }
  const Node* left() const {
    return left_;
  }
  const Node* right() const {
    return right_;
  }
  void operator<<=(Node* left) {
    left_ = left;
  }
  void operator>>=(Node* right) {
    right_ = right;
  }

 private:
  int value_;
  Node* left_;
  Node* right_;
};


class TreeUtil {
 public:
  TreeUtil() {}
  static TreeUtil* GetTreeUtil() {
    return s_tree_util_;
  }
  int CalHeight(const Node* node) {
    int left_count, right_count;
    const Node* left_node = node->left();
    const Node* right_node = node->right();
    if ((left_node != NULL) | (right_node != NULL)) {
      left_count = CalHeight(left_node);
      right_count = CalHeight(right_node);
      if (left_count >= right_count) {
        return left_count;
      } else {
        return right_count;
      }
    } else {
      return 0;
    }
  }
  int CalTotalNumOfNodes(const Node* node) {
    const Node* left_node = node->left();
    const Node* right_node = node->right();
    if ((left_node != NULL) | (right_node != NULL)) {
      return 1 + CalTotalNumOfNodes(left_node) + CalTotalNumOfNodes(right_node);
    } else {
      return 1;
    }
  }
  std::vector<const Node*> GetLeaves(const Node* node) {
    std::vector<const Node*> leaf_nodes;
  }

 private:
  static TreeUtil* s_tree_util_;
};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
