#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX

using namespace std;

/* 문제 정의
자연수 N, M -> 자연수 M 개 고른 수열 (중복 허용)
중복수열 만들기 문제
 */

/* 해결 알고리즘 생각

*/
int n, m;

void permutation(vector<int> permu, int index)
{
    if (index == m)
    {
        for (auto elem : permu)
            cout << elem << ' ';
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        permu[index] = i;
        permutation(permu, index + 1);
    }
}

int main()
{
    ////////////////////input////////////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;

    vector<int> permu(m);
    ///////////////////solution//////////////////
    permutation(permu, 0);

    ////////////////////output///////////////////

    return 0;
}

/*legacy



*/