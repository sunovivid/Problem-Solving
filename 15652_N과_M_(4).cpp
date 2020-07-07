#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX

using namespace std;

/* 문제 정의
자연수 N, M -> 자연수 M 개 고른 수열 (비감소 수열)
 */

/* 해결 알고리즘 생각

*/
int n, m;

void permutation(vector<int> permu, int index, int min)
{
    if (index == m)
    {
        for (auto elem : permu)
            cout << elem << ' ';
        cout << '\n';
        return;
    }
    for (int i = min; i <= n; i++)
    {
        permu[index] = i;
        permutation(permu, index + 1, i);
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
    permutation(permu, 0, 1);

    ////////////////////output///////////////////

    return 0;
}

/*legacy



*/