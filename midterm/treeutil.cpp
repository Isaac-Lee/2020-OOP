#include "treeutil.h"

TreeUtil* TreeUtil::GetInstance() {
  if (instance_ == NULL) {
    instance_ = new TreeUtil();
  }
  return instance_;
}
Node* TreeUtil::Balance(Node* node) {

}
bool TreeUtil::IsBinarySearchTree(const Node* node) {}
int TreeUtil::CalcHeight(const Node* node) {}