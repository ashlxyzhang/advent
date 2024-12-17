#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include <algorithm>

#include <regex>

using namespace std;

int main()
{
    ifstream file("input.txt");
    string line;

    unordered_map<int, set<int>> map;
    regex pattern("(\\d+)\\|(\\d+)");
    smatch match;

    while (getline(file, line) && line != "")
    {
        regex_search(line, match, pattern);
        int a = stoi(match[1]);
        int b = stoi(match[2]);
        map[a].insert(b);
    }

    int sum = 0;

    while (getline(file, line))
    {
        stringstream ss(line);
        set<int> seq;
        vector<int> vec_seq;
        bool good = true;

        while (ss.good())
        {
            string substr;
            int curr_page;
            set<int> intersect;

            getline(ss, substr, ',');
            curr_page = stoi(substr);

            set_intersection(map[curr_page].begin(), map[curr_page].end(), seq.begin(), seq.end(), inserter(intersect, intersect.begin()));
            if (!intersect.empty())
            {
                good = false;
                break;
            }
            seq.insert(curr_page);
            vec_seq.push_back(curr_page);
        }

        if (good)
            sum += vec_seq[vec_seq.size() / 2];
    }

    cout << sum << endl;
    return 0;
}