#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX 2550

using namespace std;

/* 문제 정의
0 ~ 127 정수로 이루어진 2차원 배열 -> 오차의 최솟값, 그 때의 영상
제약
    영상은 최대 2가지 값 가능
 */

/* 해결 알고리즘 생각
픽셀 정렬
모든 2개 분할 구해서 평균, 오차 구해보기 (구간합 이용) (1개 분할 고려? )
*/

/* 시간복잡도
O(n^2)
*/

typedef pair<int, int> pii; //value, index(1d)

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m, temp;
    vector<pii> input;
    cin >> n >> m;
    for (int i = 0; i < n * m; i++)
    {
        cin >> temp;
        input.push_back({temp, i});
    }
    ///////////////////solution//////////////////
    //정렬
    sort(input.begin(), input.end());
    //전처리 (구간합)
    int psum[MAX], square_psum[MAX], var1, var2, avg1, avg2, partition, min_score = 987654321;
    psum[0] = input[0].first;
    square_psum[0] = input[0].first * input[0].first;
    for (int i = 1; i < n * m; i++)
    {
        psum[i] = psum[i - 1] + input[i].first;
        square_psum[i] = square_psum[i - 1] + input[i].first * input[i].first;
    }

    cout << "psum: ";
    for (int i = 0; i < n * m; i++) 
        cout << psum[i] << ' ';
    cout << endl << "psquare: ";
    for (int i = 0; i < n * m; i++) 
        cout << square_psum[i] << ' ';
    cout << endl << "avg1 avg2 var1 var2";

    //구간마다 오차 합 구하기
    for (int i = 0; i < n * m - 1; i++)
    {
        avg1 = psum[i] / (i + 1);
        avg2 = (psum[n - 1] - psum[i]) / (n - 1 - i);
        var1 = (square_psum[i]) / (i + 1) - avg1 * avg1;
        var2 = (square_psum[n - 1] - square_psum[i]) / (n - 1 - i) - avg2 * avg2;
        if (var1 + var2 < min_score)
        {
            min_score = var1 + var2;
            partition = i;
        }
        cout << avg1 << ' ' << avg2 << ' ' << var1 << ' ' << var2;
    }
    cout << "partition: " << partition << endl;
    ////////////////////output///////////////////
    cout << min_score << '\n';
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << avg << ' ';
    //     }
    //     cout << '\n';
    // }
    return 0;
}