#include "Util.h"

string Util::set_resource_path(string filename)
{
    string path = ".\\" + filename + ".txt";
    return path;
}

vector<string> Util::read_text(string path)
{
    string filepath = set_resource_path(path);
    ifstream file(filepath);

    // 파일이 열렸는지 확인
    if (!file) {
        std::cerr << "파일을 열 수 없습니다: " << path << endl;
    }

    // 파일 내용을 한 줄씩 읽어 출력하기
    vector<string> body;
    string line;
    while (getline(file, line)) {
        body.push_back(line);
    }

    // 파일 닫기
    file.close();

    return body;
}
string Util::get_longest_string(vector<string>& text)
{
    string longest;
    for (const string& str : text) {
        if (str.size() > longest.size()) {
            longest = str;
        }
    }
    return longest;
}