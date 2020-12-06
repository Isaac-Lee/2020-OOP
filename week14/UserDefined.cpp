#include <iostream>
#include <fstream>
#include <string>

class NonExistFileExption : public std::runtime_error {
  public:
  NonExistFileExption(std::string msg) : std::runtime_error(msg){}
};

class NoContentException : public std::runtime_error {
  public:
  NoContentException(std::string msg) : std::runtime_error(msg) {}
};

std::string ReadFile(std::string path) {
  std::string content;
  std::ifstream f(path);

  if (!f.is_open()) {
    throw NonExistFileExption("File not found " + path);
  }
  if (f.peek() == std::ifstream::traits_type::eof()) {
    throw NoContentException("File not found " + path);
  }
  std::string line = "";
  while (getline(f, line)) {
    content += line + "\n";
  }
  f.close();
  return content;
}

void ReadAndPrintFile(std::string path) {
  std::cout << "File: " << path << std::endl;
  try {
    std::string content = ReadFile(path);
    std::cout << content << std::endl;
  } catch (NonExistFileExption& e) {
    std::cerr << e.what() << '\n';
    std::cerr << "Type: " << typeid(e).name() << '\n';
  } catch (NoContentException& e) {
    std::cerr << e.what() << '\n';
    std::cerr << "Type: " << typeid(e).name() << '\n';
  }
}

int main() {
  std::string file_name = "input2.txt";
  ReadAndPrintFile(file_name);
  return 0;
}