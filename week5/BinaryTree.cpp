// Copyright [2020] <LeeYesung>
#include <vector>

class Node {
 public:
  explicit Node(int value) : value_(value) {}
  Node(const Node& node) : value_(node.value_),
  left_(node.left_), right_(node.right_) {}
  ~Node() {
    delete right_;
    delete left_;
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
    if (left_ != NULL) {
      delete left_;
    }
    left_ = left;
  }
  void operator>>=(Node* right) {
    if (right_ != NULL) {
      delete right_;
    }
    right_ = right;
  }

 private:
  int value_;
  Node* left_;
  Node* right_;
};


class TreeUtil {
 public:
  static TreeUtil* GetTreeUtil() {
    return s_tree_util_;
  }
  int CalHeight(const Node* node) {
    int left_count, right_count;
    const Node* left_node = node->left();
    const Node* right_node = node->right();
    if ((left_node != NULL) || (right_node != NULL)) {
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
     int count;
    const Node* left_node = node->left();
    const Node* right_node = node->right();
    if (left_node != NULL) {
      count = CalTotalNumOfNodes(left_node);
    }
    if (right_node != NULL)  {
      count = CalTotalNumOfNodes(right_node);
    }
    return count + 1;
  }
  std::vector<const Node*> GetLeaves(const Node* node) {
    std::vector<const Node*> leaf_nodes;
    const Node* left_node = node->left();
    const Node* right_node = node->right();
  }
  bool IsFullBinaryTree(const Node* node) {
    const Node* left_node = node->left();
    const Node* right_node = node->right();
    if ((left_node != NULL) && (right_node != NULL)) {
      bool is_left_full = IsFullBinaryTree(left_node);
      bool is_right_full = IsFullBinaryTree(right_node);
      if (is_left_full && is_right_full) {
        return true;
      } else {
        return false;
      }
    } else {
      return false;
    }
  }

 private:
  static TreeUtil* s_tree_util_;
};
