// Copyright [2020] <LeeYesung>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

int main(int argc, char const *argv[]) {
    std::string input_path = argv[1];
    std::string output_path = argv[2];

    std::ifstream input_file;
    std::ofstream output_file;

    input_file.open(input_path);

    // Checking if input file exist.
    if (!input_file) {
        std::cerr << "입력 파일이 존재하지 않습니다.";
        return -1;
    }

    // ID, Score token vector
    std::vector<std::string> id_token;
    std::vector<std::string> score_token;

    if (input_file.is_open()) {
        std::string line;

        // Tokenizing id_token
        getline(input_file, line);
        std::stringstream id_stream(line);
        std::string id;
        while (id_stream >> id) {
            id_token.push_back(id);
        }

        // Tokenizing Score_token
        getline(input_file, line);
        std::stringstream score_stream(line);
        std::string score;
        while (score_stream >> score) {
            score_token.push_back(score);
        }

        // Checking if number of id and number of score is not same.
        if (id_token.size() != score_token.size()) {
            std::cerr << "학생의 수와 점수의 수가 일치하지 않습니다.";
            return -3;
        }

        std::ifstream output_file_check;
        output_file_check.open(output_path);

        // Checking if output file already exist.
        if (output_file_check) {
            std::cerr << "출력 파일이 이미 존재합니다.";
            return -2;
        }
        output_file.open(output_path);

        // Writing id and score in output file.
        if (output_file.is_open()) {
            for (int i = 0; i < id_token.size(); i++) {
                output_file << id_token[i] << " " << score_token[i] << std::endl;
            }
        }
        output_file.close();
    }
    input_file.close();
    return 0;
}
