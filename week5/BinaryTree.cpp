// Copyright [2020] <LeeYesung>
#include <iostream>
#include <vector>

class Node {
 public:
  explicit Node(int value) : value_(value) {}
  Node(const Node& node) : value_(node.value_),
  left_(node.left_), right_(node.right_) {}
  ~Node() {
    if (left_ != NULL) {
      delete left_;
    }
    if (right_ != NULL) {
      delete right_;
    }
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
  void operator <<=(Node* left) {
    if (left_ != NULL) {
      delete left_;
    }
    left_ = left;
  }
  void operator >>=(Node* right) {
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
    if (s_tree_util_ == NULL) {
      s_tree_util_ = new TreeUtil();
    }
    return s_tree_util_;
  }
  int CalHeight(const Node* node) {
    int left_count = 0, right_count = 0;
    const Node* left_node = node->left();
    const Node* right_node = node->right();
    // If right or left node exist serch the height of left and right sub tree.
    // If left sub tree height is more bigger return it.
    // If right sub tree height is more bigger return it.
    // If right and left node don't exixt, retun 0.
    if (left_node != NULL) {
      left_count = CalHeight(left_node) + 1;
    }
    if (right_node != NULL) {
      right_count = CalHeight(right_node) + 1;
    }
    if (left_count >= right_count) {
      return left_count;
    } else {
      return right_count;
    }
    return 0;
  }
  int CalTotalNumOfNodes(const Node* node) {
    int count = 0;
    const Node* left_node = node->left();
    const Node* right_node = node->right();
    // Count all subtree's node.
    // If right or left node don't exist, return 1.
    if (left_node != NULL) {
      count += CalTotalNumOfNodes(left_node);
    }
    if (right_node != NULL)  {
      count += CalTotalNumOfNodes(right_node);
    }
    return count + 1;
  }
  std::vector<const Node*> GetLeaves(const Node* node) {
    std::vector<const Node*> leaf_nodes;
    const Node* left_node = node->left();
    const Node* right_node = node->right();
    // If right or left node don't exist, it is leaf node, so return it.
    if ((left_node == NULL) && (right_node == NULL)) {
      leaf_nodes.push_back(node);
      return leaf_nodes;
    }
    // if left or right node exist, insert the nodes and return it.
    if (left_node != NULL) {
      std::vector<const Node*> left_leaf_nodes = GetLeaves(left_node);
      leaf_nodes.insert(leaf_nodes.end(), left_leaf_nodes.begin(),
      left_leaf_nodes.end());
    }
    if (right_node != NULL)  {
      std::vector<const Node*> right_leaf_nodes = GetLeaves(right_node);
      leaf_nodes.insert(leaf_nodes.end(), right_leaf_nodes.begin(),
      right_leaf_nodes.end());
    }
    return leaf_nodes;
  }
  bool IsFullBinaryTree(const Node* node) {
    const Node* left_node = node->left();
    const Node* right_node = node->right();
    if ((left_node != NULL) && (right_node != NULL)) {
      bool is_left_full = IsFullBinaryTree(left_node);
      bool is_right_full = IsFullBinaryTree(right_node);
      // If left sub-tree is full binary tree and right sub-tree is
      // full binary tree, return true;
      // Else if left sub-tree and right sub-tree do'nt exist cuerrent tree
      // is full binary tree, so return true;
      // Otherwise, return false.
      if (is_left_full && is_right_full) {
        return true;
      } else if (!is_left_full && !is_right_full) {
        return true;
      } else {
        return false;
      }
    } else {
      return false;
    }
  }

 private:
  TreeUtil() {}
  static TreeUtil* s_tree_util_;
};

TreeUtil* TreeUtil::s_tree_util_ = nullptr;