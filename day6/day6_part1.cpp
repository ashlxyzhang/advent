#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<vector<char>> map;
int guard_x, guard_y;

struct point
{
    int x;
    int y;

    bool operator==(const point &other) const
    {
        return x == other.x && y == other.y;
    }
};

bool inbounds(int x, int y)
{
    if (x < 0 || y < 0 || x >= map.size() || y >= map[0].size())
        return false;
    return true;
}

int main()
{
    ifstream file("input.txt");
    string line;
    int row = 0;

    while (getline(file, line))
    {
        vector<char> char_line;
        for (int i = 0; i < line.size(); ++i)
        {
            if (line[i] == '^')
            {
                guard_x = row;
                guard_y = i;
            }
            char_line.emplace_back(line[i]);
        }
        map.push_back(char_line);
        row += 1;
    }

    int steps = 0;
    point direction = {-1, 0};

    while (inbounds(guard_x, guard_y))
    {
        if (map[guard_x][guard_y] != 'X')
            steps += 1;

        map[guard_x][guard_y] = 'X';

        int temp_x = guard_x + direction.x, temp_y = guard_y + direction.y;
        if (inbounds(temp_x, temp_y) && map[temp_x][temp_y] == '#')
        {
            if (direction.x == -1 && direction.y == 0)
                direction = {0, 1};
            else if (direction.x == 1 && direction.y == 0)
                direction = {0, -1};
            else if (direction.x == 0 && direction.y == 1)
                direction = {1, 0};
            else if (direction.x == 0 && direction.y == -1)
                direction = {-1, 0};
        }
        guard_x += direction.x;
        guard_y += direction.y;
    }
    cout << steps << endl;
    return 0;
}