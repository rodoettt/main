#include <iostream>
#include <sstream>
#include <string>
#include <regex>
using namespace std;

struct File {
    string name;
    string creationDate;
    int size;
};

bool parseFile(const string& input, File& file) {
    regex pattern(R"re(File\s+"([^"]+)"\s+(\d{2}\.\d{2}\.\d{4})\s+(\d+))re");
    smatch matches;

    if (regex_match(input, matches, pattern)) {
        file.name = matches[1];
        file.creationDate = matches[2];
        file.size = stoi(matches[3]);
        return true;
    }
    return false;
}

int main() {
    string input;
    getline(cin, input);

    File file;

    if (parseFile(input, file)) {
        cout << "Имя файла: " << file.name << endl;
        cout << "Дата создания: " << file.creationDate << endl;
        cout << "Размер: " << file.size << " байт" << endl;
    } else {
        cout << "Ошибка формата входной строки!" << endl;
    }

    return 0;
}
