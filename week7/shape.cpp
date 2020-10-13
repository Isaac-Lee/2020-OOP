// Copyright [2020] <LeeYesung>
#include <iostream>
#include <optional>

class Shape {
 public:
  Shape(int width, int depth) : width_(width), depth_(depth) {}
  virtual double GetArea() const = 0;
  int width() const {
    return width_;
  }
  int depth() const {
    return depth_;
  }
 protected:
  const int width_;
  const int depth_;
};

class Rectangle : public Shape {
 public:
  Rectangle(int width, int depth) : Shape(width, depth) {}
  double GetArea() const {
    return width_ * depth_;
  }
  const Rectangle operator+(const Rectangle& rect) const {
    return Rectangle(this->width_ + rect.width(), this->depth_ + rect.depth());
  }
  const std::optional<Rectangle> operator-(const Rectangle& rect) const {
    int width = abs(this->width_ - rect.width());
    int depth = abs(this->depth_ - rect.depth());
    if (width == 0 || depth == 0) {
      return std::nullopt;
    } else {
      return Rectangle(width, depth);
    }
  }
  const Rectangle operator*(const Rectangle& rect) const {
    return Rectangle(this->width_ * rect.width(), this->depth_ * rect.depth());
  }
};

class Triangle : public Shape {
 public:
  Triangle(int width, int depth) : Shape(width, depth) {}
  double GetArea() const {
    return (width_ * depth_) / 2;
  }
  const Triangle operator+(const Triangle& tri) const {
    return Triangle(this->width_ + tri.width(), this->depth_ + tri.depth());
  }
  const std::optional<Triangle> operator-(const Triangle& tri) const {
    int width = abs(this->width_ - tri.width());
    int depth = abs(this->depth_ - tri.depth());
    if (width == 0 || depth == 0) {
      return std::nullopt;
    } else {
      return Triangle(width, depth);
    }
  }
  const Triangle operator*(const Triangle& tri) const {
    return Triangle(this->width_ * tri.width(), this->depth_ * tri.depth());
  }
};

class Circle : public Shape {
 public:
  explicit Circle(int width) : Shape(width, width) {}
  double GetArea() const {
    return width_ * depth_ * 3.14;
  }
  const Circle operator+(const Circle& circ) const {
    return Circle(this->width_ + circ.width());
  }
  const std::optional<Circle> operator-(const Circle& circ) const {
    int width = abs(this->width_ - circ.width());
    if (width == 0) {
      return std::nullopt;
    } else {
      return Circle(width);
    }
  }
  const Circle operator*(const Circle& circ) const {
    return Circle(this->width_ * circ.width());
  }
};

class ShapeUtil {
 public:
  static ShapeUtil* GetInstance() {
    if (s_instance_ == NULL) {
      s_instance_ = new ShapeUtil();
    }
    return s_instance_;
  }
  double CalVolume(const Shape* shape, int height) {
    return shape->GetArea() * height;
  }
 private:
  ShapeUtil() {}
  static ShapeUtil* s_instance_;
};

ShapeUtil* ShapeUtil::s_instance_ = nullptr;

int main(int argc, char const *argv[]) {
  return 0;
}
