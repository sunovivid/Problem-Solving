#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX 5000

using namespace std;

/* 문제 정의
x1, y1, x2, y2 -> 오른쪽 또는 밑으로 내려올 때, 다른 sum 가짓수

 */

/* 해결 알고리즘 생각

*/
unsigned short dp[MAX * 2][MAX] = {
    0,
};

int combination(int n, int r)
{
    // cout << "combi: " << n << r << endl;
    if (n < MAX * 2 && r < MAX && dp[n][r] != 0)
    {
        // cout << "dp found";
        return dp[n][r];
    }

    if (n == r || r == 0)
    {
        // cout << "basic case" << endl;
        return 1;
    }
    // cout << "next" << endl;
    return dp[n][r] = combination(n - 1, r - 1) + combination(n - 1, r);
}
int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t, x1, y1, x2, y2, n, m, shorter;
    cin >> t;
    ///////////////////solution//////////////////
    while (t--)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        n = x2 - x1, m = y2 - y1;
        shorter = min(n, m);
        cout << combination(n + m, shorter) << '\n';
    }
    ////////////////////output///////////////////

    return 0;
}

/*legacy



*/