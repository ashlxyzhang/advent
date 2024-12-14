#include <iostream>
#include <fstream>
#include <regex>

using namespace std;

int main()
{
    ifstream file("test.txt");
    string line;

    regex do1("do\\(\\)");
    regex dont("don't\\(\\)");
    regex pattern("mul\\((\\d+),(\\d+)\\)");

    smatch res;

    long long result = 0;
    string all = "";

    while (getline(file, line))
        all += line;

    int do_idx = 0;
    int dont_idx;

    while (true)
    {
        if (regex_search(all, res, dont))
            dont_idx = res.position();
        else
            dont_idx = all.size();

        string temp = all.substr(0, dont_idx);

        while (regex_search(temp, res, pattern))
        {
            result += stoi(res[1]) * stoi(res[2]);
            temp = res.suffix().str();
        }

        if (dont_idx != all.size())
            all = all.substr(dont_idx + 1);
        else
            break;

        if (regex_search(all, res, do1))
            do_idx = res.position();
        else
            break;

        all = all.substr(do_idx);
    }

    cout << result << endl;

    return 0;
}