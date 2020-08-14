#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX 0

using namespace std;

/* 문제 정의
길이 n <= 15 자연수 수열 T, P -> 최대 수익
 */

/* 해결 알고리즘 생각
n = 15라서 완전탐색해도 2^15로 가능할듯

*/

/* 시간복잡도

*/
vector<int> t, p;
int n;

int consult(int day)
{
    // //base condition
    // if (day == n - 1)
    //     return;
    int ret = p[day];
    if (day + t[day] - 1 > n) //해당 상담을 끝낼 수 없는경우
        return 0;
    for (int next = day + t[day]; next <= n; next++)
    {
        ret = max(ret, p[day] + consult(next));
    }
    return ret;
}

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    ///////////////////solution//////////////////
    t.push_back(1);
    p.push_back(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t_in, p_in;
        cin >> t_in >> p_in;
        t.push_back(t_in);
        p.push_back(p_in);
    }
    cout << consult(0);
    ////////////////////output///////////////////

    return 0;
}