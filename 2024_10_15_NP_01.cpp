#include <iostream>
#include <filesystem>
#include <string>

using namespace std;
namespace fs = filesystem;

int main(int argc, char* argv[]) {
    /// Checks if the correct number of command line arguments are provided.
    /// If not, prints the expected usage and returns an error code.
    if (argc != 2) {
        cerr << "Uso: " << argv[0] << " <extensao>" << endl;
        return 1;
    }

    /// Checks if the provided file extension starts with a period, and adds one if it does not.
    /// This ensures the file extension is in the expected format for comparison.
    string extensao = argv[1];
    if (extensao[0] != '.') {
        extensao = "." + extensao;
    }

    /// Iterates through the files in the current directory and prints the filename of each file that matches the provided file extension.
    /// The file extension is expected to be provided as a command line argument.
    /// This code is part of the implementation of the main function and is not an exported API.
    for (const auto& entry : fs::directory_iterator(".")) {
        if (entry.is_regular_file() && entry.path().extension() == extensao) {
            cout << entry.path().filename() << endl;
        }
    }

    return 0;
}
