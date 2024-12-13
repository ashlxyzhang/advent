#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    string line;
    ifstream file("input.txt");

    vector<int> list1;
    unordered_map<int, int> list2;

    while (getline(file, line))
    {
        stringstream ss(line);
        int l1, l2;
        ss >> l1 >> l2;

        list1.push_back(l1);
        list2[l2]++;
    }

    int similarity = 0;

    for (int i = 0; i < list1.size(); ++i)
    {
        int freq = (list2.find(list1[i]) != list2.end()) ? list2.at(list1[i]) : 0;
        similarity += list1[i] * freq;
    }

    cout << similarity << "\n";
}