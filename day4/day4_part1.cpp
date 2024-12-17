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

int find_xmas(int r, int c, int dr, int dc)
{
    point arr[] = {
        {r, c},
        {r + dr, c + dc},
        {r + 2 * dr, c + 2 * dc},
        {r + 3 * dr, c + 3 * dc}};
    char xmas[] = {'X', 'M', 'A', 'S'};

    for (int i = 0; i < 4; ++i)
    {
        int row = arr[i].r;
        int col = arr[i].c;
        if (inbounds(row, col) && map[row][col] == xmas[i])
            continue;
        return false;
    }
    return true;
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
            if (map[r][c] == 'X')
            {
                for (point dir : directions)
                {
                    count += find_xmas(r, c, dir.r, dir.c);
                }
            }
        }
    }
    cout << count << endl;
    return 0;
}