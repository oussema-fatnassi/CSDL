#include <iostream>
#include <fstream>
#include <string>

int main() {
  std::ifstream inputFile("text_file.txt");  // Open the file in read mode

  if (inputFile.is_open()) {  // Checking if the file was successfully opened
    std::string line;  // Declaring a string variable to store each line of text

    while (std::getline(inputFile, line)) {  // Loop through each line in the file
      std::cout << line << std::endl;  // Output the content of 'line' to the console
    }

    inputFile.close();  // Closing the file after reading
  } else {
    std::cout << "Failed to open the file." << std::endl;  // Display an error message if file opening failed
  }

  std::ofstream outputFile("text_file.txt", std::ios::app);  // Open the file in append mode

  if (outputFile.is_open()) {  // Checking if the file was successfully opened
    outputFile << "hello" << std::endl;  // Write "hello" to the file
    outputFile.close();  // Closing the file after writing
  } else {
    std::cout << "Failed to open the file." << std::endl;  // Display an error message if file opening failed
  }

  std::ifstream inputFile2("text_file.txt");  // Open the file in read mode
  if (inputFile2.is_open()) {  // Checking if the file was successfully opened
    std::string line;  // Declaring a string variable to store each line of text

    while (std::getline(inputFile2, line)) {  // Loop through each line in the file
      std::cout << line << std::endl;  // Output the content of 'line' to the console
    }

    inputFile2.close();  // Closing the file after reading
  } else {
    std::cout << "Failed to open the file." << std::endl;  // Display an error message if file opening failed
  }

  return 0;  // Return 0 to indicate successful execution
}
