#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX 501

using namespace std;

/* 문제 정의
수열 -> 최대 순증가 부분 수열
 */

/* 해결 알고리즘 생각
dp
*/

/* 시간복잡도

*/

int lis(const vector<int> v)
{
    /**
     * 주어진 수열의 0..n번째에서 시작 원소 하나 선택
     * 선택한 원소 뒤의 원소들 중 더 큰 원소들 선택해서 수열 만들기
     *  만든 수열로 다시 lis 호출
     * */
    if (v.size() == 0)
        return 0;

    int ret = 0;
    for (int i = 0; i < v.size(); i++)
    {
        int selected = v[i];
        vector<int> next;
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[j] > v[i])
                next.push_back(v[j]);
        }
        ret = max(ret, 1 + lis(next));
    }
    return ret;
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
        int n;
        cin >> n;
        vector<int> v;
        while (n--)
        {
            int in;
            cin >> in;
            v.push_back(in);
        }
        cout << lis(v) << '\n';
    }
    ////////////////////output///////////////////

    return 0;
}