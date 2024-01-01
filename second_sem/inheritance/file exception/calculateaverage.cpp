#include <iostream>

#include <fstream>

#include <string>

// Function to display the content of a file
void displayFileContent(const std::string & filename) {
  std::ifstream file(filename);
  std::string line;

  if (file.is_open()) {
    std::cout << "File content:" << std::endl;
    while (std::getline(file, line)) {
      std::cout << line << std::endl;
    }
    file.close();
  } else {
    std::cout << "Failed to open the file." << std::endl;
  }
}


double calculateAverage(const std::string & filename) {
  std::ifstream file(filename);
  double sum = 0.0;
  double count = 0.0;

  if (file.is_open()) {
    double number;

    while (file >> number) {
      sum += number;
      count++;
    }

    file.close();
  } else {
    std::cout << "Failed to open the file." << std::endl;
    return 0.0;
  }

  if (count > 0) {
    return sum / count;
  } else {
    std::cout << "No numbers found in the file." << std::endl;
    return 0.0;
  }
}

int main() {
  std::string filename = "sample.txt"; // File containing numbers
  displayFileContent("sample.txt");
  std::cout << std::endl;
  double average = calculateAverage(filename);
  std::cout << "Average: " << average << std::endl;
  
}
