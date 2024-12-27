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

    // ������ ���ȴ��� Ȯ��
    if (!file) {
        std::cerr << "������ �� �� �����ϴ�: " << path << endl;
    }

    // ���� ������ �� �پ� �о� ����ϱ�
    vector<string> body;
    string line;
    while (getline(file, line)) {
        body.push_back(line);
    }

    // ���� �ݱ�
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