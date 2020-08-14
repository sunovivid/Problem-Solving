//테크닉: isDisabled 벡터를 별개로 만들어 next_permutation을 이용해 계속 바꿔서 활성화된 숫자들만 가지고 출력

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
수열 -> 수열 중 6개 부분 수열 만드는 경우의 수
 */

/* 해결 알고리즘 생각
정답 보고 개선: https://www.acmicpc.net/source/4407799
    permutation 사용
*/

/* 시간복잡도

*/

// void pick(vector<int> from, vector<int> &picked, int rangeBegin, int toPick)
// {
//     //base case
//     if (toPick == 0)
//     {
//         for (auto num : picked)
//             cout << num << ' ';
//         cout << '\n';
//     }
//     //어디서부터 뽑을지 결정하는 rangeBegin이 필요하다
//     for (int i = rangeBegin; i < from.size(); i++)
//     {
//         picked.push_back(from[i]);
//         pick(from, picked, i + 1, toPick - 1);
//         picked.pop_back();
//     }
// }

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    ///////////////////solution//////////////////
    while (true)
    {
        int k;
        cin >> k;
        if (k == 0)
            return 0;
        vector<int> v;
        vector<bool> isDisabled;
        for (int i = 0; i < k; i++)
        {
            int in;
            cin >> in;
            v.push_back(in);
            isDisabled.push_back(i < 6 ? false : true);
        }

        do
        {
            for (int i = 0; i < k; i++)
            {
                if (!isDisabled[i])
                    cout << v[i] << ' ';
            }
            cout << '\n';
        } while (next_permutation(isDisabled.begin(), isDisabled.end()));
        cout << '\n';
    }
    ////////////////////output///////////////////

    return 0;
}