#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX

using namespace std;

/* 문제 정의
n, 순열 a -> 나가는 최대 할머니 수
순열 a에서 매번 할머니 동시 선택
    i번째 할머니는 할머니 수가 a(i) 이상이어야만 나감
 */

/* 해결 알고리즘 생각
최적화 문제

할머니 순열 정렬
처음 할머니부터 하나씩
    a[i]가 현재 인덱스(지금까지 나오기로 한 할머니 수)보다 작으면 다음 인덱스로
    아니면 할머니 나오기
*/

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    vector<int> arr;
    int t, n, a;
    cin >> t;
    ///////////////////solution//////////////////
    while (t--)
    {
        cin >> n;
        arr.clear();
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            arr.push_back(a);
        }
        sort(arr.begin(), arr.end());
        int max_index = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] - 1 <= i)
                max_index = i + 1;
        }
        cout << max_index + 1 << '\n';
    }
    ////////////////////output///////////////////
    return 0;
}

/*legacy



*/