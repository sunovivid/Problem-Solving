#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <string.h>
#include <string>
#include <cmath>

#define MAX 2550

using namespace std;

/* 문제 정의
0 ~ 127 정수로 이루어진 2차원 배열 -> 오차의 최솟값, 그 때의 영상
제약
    영상은 최대 2가지 값 가능
 */

/* 해결 알고리즘 생각
픽셀 정렬
모든 2개 분할 구해서 평균, 오차 구해보기 (구간합 이용)
*/

/* 시간복잡도
O(n^2)
*/

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m, temp;
    vector<int> input;
    vector<int> input_copy;
    cin >> n >> m;
    for (int i = 0; i < n * m; i++) {
        cin >> temp;
        input.push_back(temp);
        input_copy.push_back(temp);
    }
    ///////////////////solution//////////////////
    //정렬
    sort(input.begin(), input.end());
    long long psum[MAX], square_psum[MAX], min_error = 987654321, partition_num, opt_avg1, opt_avg2;
    psum[0] = input[0];
    square_psum[0] = input[0] * input[0];
    if (n * m == 1) {
        cout << 0 << '\n';
        cout << input[0];
        return 0;
    }
    for (int i = 1; i < n * m; i++)
    {
        psum[i] = psum[i - 1] + input[i];
        square_psum[i] = square_psum[i - 1] + input[i] * input[i];
    }

    //single avg case
    long long err_f = 0, err_c = 0, avg_f = 0, avg_c = 0;
    avg_f = psum[n * m - 1] / (n * m);
    avg_c = psum[n * m - 1] / (n * m) + 1;
    for (int i = 0; i < n * m - 1; i++)
    {
        err_f += (input[i] - avg_f) * (input[i] - avg_f);
        err_c += (input[i] - avg_c) * (input[i] - avg_c);
    }
    //double avg case
    for (int bar = 0; bar < n * m - 1; bar++)
    {
        long long err1_f, err2_f, err1_c, err2_c, avg1_f, avg2_f, avg1_c, avg2_c;
        err1_f = err2_f = err1_c = err2_c = 0;
        avg1_f = (psum[bar] / (bar + 1)), avg2_f = ((psum[n * m - 1] - psum[bar]) / (n * m - bar - 1));
        avg1_c = (psum[bar] / (bar + 1) + 1), avg2_c = ((psum[n * m - 1] - psum[bar]) / (n * m - bar - 1) + 1);
        for (int i = 0; i <= bar; i++) {
            err1_f += (input[i] - avg1_f) * (input[i] - avg1_f);
            err1_c += (input[i] - avg1_c) * (input[i] - avg1_c);
        }
        for (int i = bar + 1; i < n * m; i++) {
            err2_f += (input[i] - avg2_f) * (input[i] - avg2_f);
            err2_c += (input[i] - avg2_c) * (input[i] - avg2_c);
        }
        if (min(err1_f, err1_c) + min(err2_f, err2_c) < min_error)
        {
            min_error = min(err1_f, err1_c) + min(err2_f, err2_c);
            opt_avg1 = err1_f < err1_c ? avg1_f : avg1_c;
            opt_avg2 = err2_f < err2_c ? avg2_f : avg2_c;
            partition_num = input[bar];
        }
        // cout << "bar " << bar << " : " << avg1_f << ' ' << avg2_f << ' ' << err1_f << ' ' << err2_f << endl;
    }
    // cout << "partition: " << partition << endl;
    ////////////////////output///////////////////
    if (min_error < min(err_f, err_c)) { // double avg case
        cout << min_error << '\n';
        for (int i = 0; i < n*m; i++)
        {
            if (input_copy[i] <= partition_num)
                cout << opt_avg1 << ' ';
            else
                cout << opt_avg2 << ' ';
            if ((i + 1) % m == 0)
                cout << '\n';
        }
    }
    else { //single avg case
        cout << min(err_f, err_c);
        for (int i = 0; i < n*m; i++)
        {
            cout << ((err_f < err_c) ? avg_f : avg_c);
            if ((i + 1) % m == 0)
                cout << '\n';
        }
    }
    return 0;
}