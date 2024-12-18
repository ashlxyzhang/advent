#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

struct point
{
    int x;
    int y;

    bool operator<(const point &other) const
    {
        return (x < other.x) || (x == other.x && y < other.y);
    }
};

vector<vector<char>> graph;
unordered_map<char, vector<point>> ant_map;

bool inbounds(int x, int y)
{
    if (x < 0 || y < 0 || x >= graph.size() || y >= graph[0].size())
        return false;
    return true;
}

int main()
{
    ifstream file("input.txt");
    string line;

    int i = 0;
    while (getline(file, line))
    {
        vector<char> row;
        for (int j = 0; j < line.length(); ++j)
        {
            char s = line[j];
            row.emplace_back(s);
            if (s != '.')
            {
                ant_map[s].push_back({i, j});
            }
        }
        graph.push_back(row);
        ++i;
    }

    set<point> ans;
    for (const auto &pair : ant_map)
    {
        vector<point> vec = pair.second;
        for (int i = 0; i < vec.size(); ++i)
        {
            for (int j = 0; j < vec.size(); ++j)
            {
                if (j == i)
                    continue;
                int dx = vec[j].x - vec[i].x;
                int dy = vec[j].y - vec[i].y;
                if (inbounds(vec[j].x + dx, vec[j].y + dy))
                    ans.insert({vec[j].x + dx, vec[j].y + dy});
            }
        }
    }
    cout << ans.size() << endl;
    return 0;
}