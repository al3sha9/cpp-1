// #include<iostream>
// #include<string>
// #include<fstream>
// using namespace std;

// int main(){
//     int count = 0;
//     string line, write;
//     fstream linecountFile;

//     linecountFile.open("lineCount.txt", ios::out |ios::in);
//     cout<<"Write something: ";
//     cin>>line;
//     linecountFile<<write;
//     while (getline(linecountFile, line))
//     {
//         count++;
//     }
//     cout<<"The number of lines are: "<<count<<endl;
//     linecountFile.close();
// }

#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string filename;
    std::cout << "Enter the name of the file: ";
    std::getline(std::cin, filename);

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Unable to open file." << std::endl;
        return 1;
    }

    int lineCount = 0;
    std::string line;
    while (std::getline(file, line)) {
        lineCount++;
    }

    std::cout << "The file '" << filename << "' has " << lineCount << " lines." << std::endl;

    file.close();
    return 0;
}
