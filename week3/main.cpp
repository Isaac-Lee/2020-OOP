// Copyright [2020] <LeeYesung>
#include <iostream>
#include <vector>
#include <sstream>

class NamingConventionCorrector {
 public:
    // Making words to type name style.
    std::string ToTypeName(std::string* inputLine,
    int size) {
      std::string result = "";

      for (int i = 0; i < size; i++) {
        // Making first letter of word to capital letter.
        std::transform(inputLine[i].begin(), inputLine[i].begin()+1,
        inputLine[i].begin(), toupper);
        result += inputLine[i];
        // Restoring first letter of word.
        std::transform(inputLine[i].begin(), inputLine[i].begin()+1,
        inputLine[i].begin(), tolower);
      }

      return result;
    }

    // Making words to variable name style.
    std::string ToVariableName(std::string* inputLine,
    int size) {
      std::string result = inputLine[0];

      // Inserting "_" in front of words.
      for (int i = 1; i < size; i++) {
       result += "_" + inputLine[i];
      }

      return result;
    }

    // Making words to class member name style.
    std::string ToClassMemberName(std::string* inputLine, int size) {
      std::string result = inputLine[0];

      for (int i = 1; i < size; i++) {
       result += "_" + inputLine[i];
      }

      // Insert "_" at the end of the result.
      return result + "_";
    }

    // Making words to struct member name style.
    std::string ToStructMemberName(std::string* inputLine, int size) {
      std::string result = inputLine[0];

      for (int i = 1; i < size; i++) {
       result += "_" + inputLine[i];
      }

      return result;
    }

    // Making words to constant name style.
    std::string ToConstantName(std::string* inputLine, int size) {
      // Inserting letter "k" in front of result.
      std::string result = "k";

      for (int i = 0; i < size; i++) {
        std::transform(inputLine[i].begin(), inputLine[i].begin()+1,
        inputLine[i].begin(), toupper);
       result += inputLine[i];
        std::transform(inputLine[i].begin(), inputLine[i].begin()+1,
        inputLine[i].begin(), tolower);
      }

      return result;
    }

    // Making words to function name style.
    std::string ToFunctionName(std::string* inputLine, int size) {
      std::string result = "";

      for (int i = 0; i < size; i++) {
        std::transform(inputLine[i].begin(), inputLine[i].begin()+1,
        inputLine[i].begin(), toupper);
       result += inputLine[i];
        std::transform(inputLine[i].begin(), inputLine[i].begin()+1,
        inputLine[i].begin(), tolower);
      }

      return result;
    }
};


int kArraySize = 3;

int main(int argc, char const *argv[]) {
  NamingConventionCorrector corrector;

  std::string* str_list = new std::string[kArraySize];
  str_list[0] = "apple";
  str_list[1] = "steve";
  str_list[2] = "jobs";

  std::string type_name = corrector.ToTypeName(str_list, kArraySize);
  std::string variable_name = corrector.ToVariableName(str_list, kArraySize);
  std::string class_member_name = corrector.ToClassMemberName(str_list,
  kArraySize);
  std::string struct_member_name = corrector.ToStructMemberName(str_list,
  kArraySize);
  std::string constant_name = corrector.ToConstantName(str_list, kArraySize);
  std::string function_name = corrector.ToFunctionName(str_list, kArraySize);

  // Printng results.
  std::cout << std::endl;
  std::cout << "Type           :  " << type_name << std::endl
  << std::endl;
  std::cout << "Variable       :  " << variable_name << std::endl
  << std::endl;
  std::cout << "Class member   :  " << class_member_name << std::endl
  << std::endl;
  std::cout << "Struct member  :  " << struct_member_name << std::endl
  << std::endl;
  std::cout << "Constant       :  " << constant_name << std::endl
  << std::endl;
  std::cout << "Function       :  " << function_name << std::endl
  << std::endl;

  return 0;
}
