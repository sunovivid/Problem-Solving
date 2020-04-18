//재귀함수, 벡터를 이용한 조합 생성법

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, sum, num[100];

void f(vector<int> &p)
{
    if (p.size() == 3)
    {
        int temp = 0;
        for (int i = 0; i < p.size(); i++)
            temp += num[p[i]];
        if (temp > M)
            return;
        if (temp > sum)
            sum = temp;
        return;
    }
    /* 조합 생성의 핵심! begin*/
    int i = p.empty() ? 0 : p.back() + 1;
    //중복이 허용되지 않으므로 p.back() + 1 부터 넣어보기 (안 넣은 원소들)
    for (; i < N; i++)
    {
        p.push_back(i);
        f(p);
        p.pop_back();
    }
    /* 조합 생성의 핵심! end*/
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N;
    cin >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
    }
    vector<int> path;
    f(path);
    cout << sum;
    return 0;
}