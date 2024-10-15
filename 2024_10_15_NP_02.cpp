#include <iostream>
#include <filesystem>
#include <string>
#include <iomanip>

using namespace std;
namespace fs = filesystem;

int main(int argc, char* argv[]) {
    /// Checks if the correct number of command line arguments are provided.
    /// If not, prints the expected usage and returns an error code.
    ///
    /// @param argc The number of command line arguments.
    /// @param argv The array of command line arguments.
    /// @return 0 on success, 1 on error.
    if (argc != 2) {
        cerr << "Uso: " << argv[0] << " <extensao>" << endl;
        return 1;
    }

    /// Ensures the file extension provided as a command line argument starts with a period.
    /// If the extension does not start with a period, it is prepended.
    /// This is done to normalize the file extension format for the file size listing.
    string extensao = argv[1];
    if (extensao[0] != '.') {
        extensao = "." + extensao;
    }

    /// Prints a header row with the column names "Nome do Arquivo" and "Tamanho (bytes)", followed by a separator row of dashes.
    /// This header is intended to be used in a table-like output to display file names and their sizes.
    cout << left << setw(40) << "Nome do Arquivo" << "Tamanho (bytes)" << endl;
    cout << string(60, '-') << endl;

    for (const auto& entry : fs::directory_iterator(".")) {
        if (entry.is_regular_file() && entry.path().extension() == extensao) {
            uintmax_t fileSize = fs::file_size(entry.path());
            cout << left << setw(40) << entry.path().filename().string() 
                 << right << setw(15) << fileSize << endl;
        }
    }

    return 0;
}

