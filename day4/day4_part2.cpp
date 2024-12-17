#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<vector<char>> map;

struct point
{
    int r;
    int c;
};

bool inbounds(int r, int c)
{
    if (r < 0 || c < 0 || r >= map.size() || c >= map[r].size())
        return false;
    return true;
}

int find_xmas(int r, int c)
{
    if (inbounds(r - 1, c - 1) && inbounds(r - 1, c + 1) && inbounds(r + 1, c - 1) && inbounds(r + 1, c + 1))
    {
        if (map[r - 1][c - 1] == 'M' && map[r + 1][c + 1] == 'S' || map[r - 1][c - 1] == 'S' && map[r + 1][c + 1] == 'M')
            if (map[r + 1][c - 1] == 'M' && map[r - 1][c + 1] == 'S' || map[r + 1][c - 1] == 'S' && map[r - 1][c + 1] == 'M')
                return true;
    }
    return false;
}

int main()
{
    ifstream file("input.txt");
    string line;

    while (getline(file, line))
    {
        vector<char> row;
        for (char s : line)
            row.emplace_back(s);
        map.push_back(row);
    }

    int count = 0;
    point directions[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
    for (int r = 0; r < map.size(); ++r)
    {
        for (int c = 0; c < map[r].size(); ++c)
        {
            if (map[r][c] == 'A')
            {
                count += find_xmas(r, c);
            }
        }
    }
    cout << count << endl;
    return 0;
}