#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    string line;
    ifstream file("input.txt");

    vector<int> list1;
    vector<int> list2;

    while (getline(file, line))
    {
        stringstream ss(line);
        int l1, l2;
        ss >> l1 >> l2;

        list1.push_back(l1);
        list2.push_back(l2);
    }

    sort(list1.begin(), list1.end());
    sort(list2.begin(), list2.end());

    int diff = 0;

    for (int i = 0; i < list1.size(); ++i)
    {
        diff += abs(list1[i] - list2[i]);
    }

    cout << diff << "\n";
}