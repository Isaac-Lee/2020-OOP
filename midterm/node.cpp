#include "node.h"

Node::Node(Value* value) : value_(value), left_(nullptr), right_(nullptr) {}
Node* Node::left() const {
  return this->left_;
}
Node* Node::right() const {
  return this->right_;
}
const Value& Node::value() const {
  return this->value();
}
void Node::AddLeft(Node* left) {
  this->left_ = left;
}
void Node::AddRight(Node* right) {
  this->left_ = right;
}
bool Node::operator<=(const Node& node) const {
  return this->value() <= node.value();
}
std::string Node::ToString() const {
  return this->value_->ToString();
}