#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<string> out;

void process(string line)
{
    for (int i = 0; i < line.length(); ++i)
    {
        if (i & 1)
            out.insert(out.end(), line[i] - '0', ".");
        else
            out.insert(out.end(), line[i] - '0', to_string(i / 2));
    }
}

int main()
{
    ifstream file("input.txt");
    string line;
    getline(file, line);

    process(line);

    int start = 0, end = out.size() - 1;
    while (out[start] != ".")
        start += 1;
    while (out[end] == ".")
        end -= 1;
    while (start < end)
    {
        if (out[start] == "." && out[end] != ".")
            swap(out[start], out[end]), ++start, --end;
        else if (out[start] != ".")
            ++start;
        else
            --end;
    }

    long long int checksum = 0;
    for (int i = 0; i < out.size(); ++i)
    {
        if (out[i] == ".")
            break;
        checksum += (stoi(out[i])) * i;
    }
    cout << checksum << endl;
    return 0;
}