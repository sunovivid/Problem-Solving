#include <iostream>
#include <vector>

using namespace std;

vector<char> arr = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};

void solve_recursive(int toPick, vector<int> &picked)
{
    if (toPick == 0)
    {
        for (auto c : picked)
            cout << arr[c];
        cout << endl;
    }
    int smallest = picked.empty() ? 0 : picked.back() + 1; //고를 수 있는 가장 작은 수 고르기
    for (int next = smallest; next < arr.size(); next++)
    {
        picked.push_back(next);
        solve_recursive(toPick - 1, picked);
        picked.pop_back();
    }
}

void solve_iterative() //only for 4
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            for (int k = j + 1; k < arr.size(); k++)
            {
                for (int l = k + 1; l < arr.size(); l++)
                {
                    cout << arr[i] << arr[j] << arr[k] << arr[l] << '\n';
                }
            }
        }
    }
}

int main()
{
    // solve_iterative();
    vector<int> picked;
    solve_recursive(4, picked);
}