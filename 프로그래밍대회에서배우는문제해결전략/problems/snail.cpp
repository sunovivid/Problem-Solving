#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX 1001

using namespace std;

/* 문제 정의
 ->
 */

/* 해결 알고리즘 생각

*/

/* 시간복잡도

*/
int n, m;
double dp[MAX][MAX];

double climb(int days, int climbed) //days일 동안 climbed 미터를 올라왔을 때 n일 안에 m미터 올라갈 수 있는 확률
{
    if (climbed >= n)
    {
        if (days <= m)
            return 1;
        return 0;
    }

    double &ret = dp[days][climbed];
    if (ret != -1)
        return ret;
    return ret = 0.75 * climb(days + 1, climbed + 2) + 0.25 * climb(days + 1, climbed + 1);
}

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int c;
    cin >> c;
    ///////////////////solution//////////////////
    while (c--)
    {
        cin >> n >> m;
        fill(&dp[0][0], &dp[0][0] + (MAX - 1) * MAX, -1);
        char *str = (char *)malloc(sizeof(char) * 60);
        sprintf(str, "%.10f\n", climb(0, 0));
        cout << str;
        free(str);
    }
    ////////////////////output///////////////////

    return 0;
}