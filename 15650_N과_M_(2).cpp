#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX

using namespace std;

/* 문제 정의
자연수 N, M -> 1부터 N까지 자연수 중 중복 없이 M개를 고른 수열 (수열은 길이 M, 오름차순)
M <= N <= 8
 */

/* 해결 알고리즘 생각
permutation
backtracking search
def permu(현재 수열, 남은 개수):
    if (남은 개수 == 0)
        print 현재 수열
        return
    for i = 현재 수열[마지막 원소] + 1 to n:
        현재 수열 = 현재 수열.append(i)
        permu(현재 수열, 남은 개수 - 1)
        현재 수열 = 현재 수열.pop()
*/

void permutation(vector<int> permu, int level, int n, int m)
{
    if (level == 0)
    {
        for (auto elem : permu)
            cout << elem << ' ';
        cout << '\n';
        return;
    }
    for (int i = permu.back() + 1; i <= n; i++)
    {
        permu.push_back(i);
        permutation(permu, level - 1, n, m);
        permu.pop_back();
    }
}

int main()
{
    ////////////////////input////////////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;

    ///////////////////solution//////////////////
    vector<int> permu;
    for (int i = 1; i <= n; i++)
    {
        permu.push_back(i);
        permutation(permu, m - 1, n, m);
        permu.pop_back();
    }
    ////////////////////output///////////////////

    return 0;
}

/*legacy



*/