#include <array>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define WHITE "\x1b[37m"

using namespace std;

std::string exec(const char *cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

void printFile(string fileName, int beam) {
    ifstream file(fileName);
    string line;
    int lineNum = 1;
    if (beam == 1) {
        while (getline(file, line)) {
            if (lineNum < 10) {
                cout << CYAN << lineNum << WHITE << "   | " << line << endl;
                lineNum++;
                continue;
            } else if (lineNum >= 10) {
                cout << CYAN << lineNum << WHITE << "  | " << line << endl;
                lineNum++;
                continue;
            } else if (lineNum >= 100) {
                cout << CYAN << lineNum << WHITE << "| " << line << endl;
                lineNum++;
                continue;
            } else {
                cout << CYAN << lineNum << WHITE << "| " << line << endl;
                lineNum++;
                continue;
            }
        }
    } else {
        while (getline(file, line)) {
            if (lineNum < 10) {
                cout << CYAN << lineNum << WHITE << "    " << line << endl;
                lineNum++;
                continue;
            } else if (lineNum >= 10) {
                cout << CYAN << lineNum << WHITE << "   " << line << endl;
                lineNum++;
                continue;
            } else if (lineNum >= 100) {
                cout << CYAN << lineNum << WHITE << " " << line << endl;
                lineNum++;
                continue;
            } else {
                cout << CYAN << lineNum << WHITE << " " << line << endl;
                lineNum++;
                continue;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    int b = 0;
    if (argc == 1) {
        cout << "No file name given!" << endl;
        return 1;
    }
    cout << "====================[" << GREEN << argv[1] << WHITE
         << "]====================" << endl;
    printFile(argv[1], b);
    cout << "====================[" << RED << "END OF FILE" << WHITE
         << "]====================" << endl;
    /* print file size in bytes */
    ifstream file(argv[1], ios::binary | ios::ate);
    streamsize size = file.tellg();
    file.close();
    cout << "File size: " << size << " bytes" << endl;
    string command = "file -b ";
    command += argv[1];
    cout << "File type: " << exec(command.c_str());
    command = "md5sum ";
    command += argv[1];
    cout << "MD5: " << exec(command.c_str());
    return 0;
}
