//나눗셈 처리 문제조건 읽기 => 반올림하라고 함

#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <string.h>
#include <math.h>

#define MAXINPUT 500001
#define MAXNUM 8001

using namespace std;

/* 문제 정의
 ->
 */

/* 해결 알고리즘 생각

*/

int main()
{
    ////////////////////input////////////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, arr[MAXINPUT], sum = 0, count[MAXNUM], num, max_count = 0;
    vector<int> same_mode_max;
    cin >> n;
    memset(count, 0, sizeof(count));
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        sum += num;
        arr[i] = num;
        count[num + 4000]++;
    }

    ///////////////////solution//////////////////
    //산술평균
    int mean = (floor)(sum / (double)n + 0.5);

    //중앙값
    sort(arr, arr + n);

    int median = arr[n / 2];

    //최빈값
    int mode = -9999;
    max_count = -1;
    for (int i = 0; i < MAXNUM; i++)
    {
        // cout << endl
        //  << "index: " << i - 4000 << ", max_count: " << max_count << ", count: " << count[i] << endl;
        if (max_count < count[i])
        {
            max_count = count[i];
            mode = i - 4000;
            same_mode_max.clear();
            same_mode_max.push_back(mode);
        }
        else if (max_count == count[i])
        {
            mode = i - 4000;
            same_mode_max.push_back(mode);
        }
    }
    if (same_mode_max.size() == 1)
        mode = same_mode_max[0];
    else
    {
        sort(same_mode_max.begin(), same_mode_max.end());
        mode = same_mode_max[1];
    }
    assert(mode != -9999);

    //범위
    int range = arr[n - 1] - arr[0];

    ////////////////////output///////////////////
    cout << mean << endl
         << median << endl
         << mode << endl
         << range;

    return 0;
}

/*legacy



*/