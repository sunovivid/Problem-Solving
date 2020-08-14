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

int n, m;

void permutation(vector<int> permu, int level, int min)
{
    if (level == m)
    {
        for (int i = 0; i < m; i++) //classic for loop로
            cout << permu[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = min; i <= n; i++)
    {
        permu[level] = i; //같은 level에 덮어쓰기 (backtraking 효과)
        permutation(permu, level + 1, i + 1);
    }
}

int main()
{
    ////////////////////input////////////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;

    ///////////////////solution//////////////////
    vector<int> permu(8);
    permutation(permu, 0, 1);
    ////////////////////output///////////////////

    return 0;
}

/*legacy



*/