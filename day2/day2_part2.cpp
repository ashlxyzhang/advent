#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

bool helper(vector<int> vec)
{
    bool inc = vec[1] - vec[0] > 0;
    bool good = true;
    for (int i = 0; i < vec.size() - 1; ++i)
    {
        int diff = vec[i + 1] - vec[i];
        if (inc && (diff >= 1 && diff <= 3))
            continue;
        if (!inc && (diff >= -3 && diff <= -1))
            continue;
        good = false;
        break;
    }
    return good;
}

int main()
{
    ifstream file("input.txt");
    string line;

    int safe = 0;
    while (getline(file, line))
    {
        stringstream ss(line);
        vector<int> vec;

        while (!ss.eof())
        {
            int temp;
            ss >> temp;
            vec.push_back(temp);
        }

        for (int i = 0; i < vec.size(); ++i)
        {
            vector<int> temp = vec;
            temp.erase(temp.begin() + i);
            if (helper(temp))
            {
                ++safe;
                break;
            }
        }
    }
    cout << safe << endl;
    return safe;
}