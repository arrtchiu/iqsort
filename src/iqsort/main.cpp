#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main(int argc, const char* argv[]) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " path-to-line-delimited-file" << std::endl;
    return 1;
  }
  
  std::ifstream file{argv[1]};
  if (!file.good()) {
    std::cerr << "ERROR: Unable to open: " << argv[1] << std::endl;
    return 1;
  }
  
  std::vector<std::string> lines;
  {
    std::string line;
    while (std::getline(file, line)) {
      lines.push_back(line);
    }
  }
  
  std::sort(lines.begin(), lines.end(), [](auto const& a, auto const& b) {
    while (true) {
      std::string answer;
      std::cout << "is \"" << a << "\" ranked higher than \"" << b << "\"? [y/n]: " << std::flush;
      std::cin >> answer;
      
      if (answer.empty()) {
        continue;
      }
      
      switch (answer.at(0)) {
        case 'y':
        case 'Y':
          return true;
          
        case 'n':
        case 'N':
          return false;
      }
    }
  });
  
  for (auto const& line : lines) {
    std::cout << line << std::endl;
  }
  
  return 0;
}
