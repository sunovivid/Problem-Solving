#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>
#include <string.h>
#include <string>
#include <set>

#define MAX

using namespace std;

/* 문제 정의
 ->
 */

/* 해결 알고리즘 생각

*/

/* 시간복잡도

*/

int n;
vector<int> russia, korea;

int maxKoreaWinCnt()
{
    int wins = 0;
    multiset<int> ratings(korea.begin(), korea.end());
    for (int rus = 0; rus < n; rus++)
    {
        if (*ratings.rbegin() < russia[rus])
        {
            ratings.erase(ratings.begin());
        }
        else
        {
            ratings.erase(ratings.lower_bound(russia[rus]));
            wins++;
        }
    }
    return wins;
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
        cin >> n;
        russia.clear();
        korea.clear();
        for (int x, i = 0; i < n; i++)
        {
            cin >> x;
            russia.push_back(x);
        }
        for (int x, i = 0; i < n; i++)
        {
            cin >> x;
            korea.push_back(x);
        }
        cout << maxKoreaWinCnt() << '\n';
    }
    ////////////////////output///////////////////

    return 0;
}