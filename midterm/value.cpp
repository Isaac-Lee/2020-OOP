#include "value.h"
#include <iostream>

String::String(std::string value) : value_(value) {}
bool String::operator<=(const Value& value) const {
  return value < *this;
}
bool String::operator<(const String& str_v) const {
  if (value_.compare(str_v.value()) > 0) {
    return 1;
  } else {
    return 0;
  }
}
bool String::operator<(const Integer& int_v) const {
  return 0;
}
bool String::operator<(const Float& float_v) const {
  return 0;
}
const std::string& String::value() const {
  return this->value_;
};
std::string String::ToString() const {
  return this->value_;
};

Integer::Integer(int value) : value_(value) {}
bool Integer::operator<=(const Value& value) const {
  return value < *this;
}
bool Integer::operator<(const String& str_v) const {
  return 1;
}
bool Integer::operator<(const Integer& int_v) const {
  return this->value() <= int_v.value();
}
bool Integer::operator<(const Float& float_v) const {
  return this->value() <= float_v.value();
}
int Integer::value() const {
  return this->value_;
}
std::string Integer::ToString() const {
  return std::to_string(this->value_);
}

Float::Float(float value) : value_(value) {}
bool Float::operator<=(const Value& value) const {
  return value < *this;
}
bool Float::operator<(const String& str_v) const {
  return 1;
}
bool Float::operator<(const Integer& int_v) const {
  return this->value() <= int_v.value();
}
bool Float::operator<(const Float& float_v) const {
  return this->value() <= float_v.value();
}
float Float::value() const {
  return this->value_;
}
std::string Float::ToString() const {
  return std::to_string(this->value_);
}