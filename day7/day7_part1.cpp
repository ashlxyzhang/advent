#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
#include <vector>

using namespace std;

vector<int> parse(string s)
{
    stringstream ss(s);
    vector<int> vec;
    int num;

    while (ss.good())
    {
        ss >> num;
        vec.push_back(num);
    }
    return vec;
}

bool dfs(vector<int> vec, int i, long sum, long total)
{
    if (i == vec.size() && sum == total)
        return true;
    if (i >= vec.size())
        return false;
    if (dfs(vec, i + 1, sum + vec[i], total))
        return true;
    return dfs(vec, i + 1, sum * vec[i], total);
}

int main()
{
    ifstream file("input.txt");
    string line;

    regex pattern("(\\d+)\\: (.+)");
    smatch match;

    long ans = 0;

    while (getline(file, line))
    {
        regex_search(line, match, pattern);
        long total = stol(match[1]);
        string nums = match[2];
        vector<int> vec = parse(nums);

        if (dfs(vec, 1, vec[0], total))
            ans += total;
    }
    cout << ans << endl;
    return 0;
}