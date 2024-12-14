#include <iostream>
#include <fstream>
#include <regex>

using namespace std;

int main()
{
    ifstream file("input.txt");
    string line;

    regex pattern("mul\\((\\d+),(\\d+)\\)");
    smatch res;

    long long result = 0;
    while (getline(file, line))
    {
        while (regex_search(line, res, pattern))
        {
            result += stoi(res[1]) * stoi(res[2]);
            line = res.suffix().str();
        }
    }

    cout << result << endl;

    return 0;
}