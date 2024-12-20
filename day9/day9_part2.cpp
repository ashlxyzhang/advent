#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<pair<int, int>> out;

void process(string line)
{
    for (int i = 0; i < line.length(); ++i)
    {
        if (i & 1 && line[i] - '0' != 0)
            out.push_back(make_pair(-1, line[i] - '0'));
        else if (line[i] - '0' != 0)
            out.push_back(make_pair(i / 2, line[i] - '0'));
    }
}

void print()
{
    for (auto &pair : out)
    {
        cout << pair.first << ":" << pair.second << " ";
    }
    cout << endl;
}

int main()
{
    ifstream file("input.txt");
    string line;
    getline(file, line);

    process(line);

    int start = 1, end = out.size() - 1;
    while (out[end].first == -1)
        end -= 1;

    while (end >= 1)
    {
        int temp = start;

        while (temp < end)
            if (out[temp].first != -1 || out[end].second > out[temp].second)
                temp += 1;
            else
                break;

        if (temp < end && out[temp].first == -1 && out[end].second <= out[temp].second)
        {
            if (out[temp].second == out[end].second)
                out[temp].first = out[end].first;
            else
            {
                out[temp].second -= out[end].second;
                out.insert(out.begin() + temp, out[end]);
                ++end;
            }

            out[end].first = -1;
        }
        while (start < out.size() && out[start].first != -1)
            start += 1;
        end -= 1;
        while (end >= 0 && out[end].first == -1)
            end -= 1;
    }

    long long int checksum = 0;
    int idx = 0;
    for (int i = 0; i < out.size(); ++i)
    {
        if (out[i].second == 0)
            continue;
        if (out[i].first != -1)
        {
            int next = idx + out[i].second;
            while (idx < next)
                checksum += out[i].first * idx++;
        }
        else
            idx += out[i].second;
    }
    cout << checksum << endl;
    return 0;
}