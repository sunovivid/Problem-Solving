//search의 시작을 간결하게. 시작점을 기준으로 재귀함수를 설계하라

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

int n, m, permu[8];

void permutation(int index, int min)
{
    if (index == m)
    {
        for (int i = 0; i < index; i++)
            cout << permu[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = min; i <= n; i++)
    {
        permu[index] = i;
        permutation(index + 1, i + 1);
    }
}

int main()
{
    ////////////////////input////////////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;

    ///////////////////solution//////////////////
    permutation(0, 1);
    ////////////////////output///////////////////

    return 0;
}

/*legacy



*/