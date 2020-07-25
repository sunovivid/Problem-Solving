#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX 10005

using namespace std;

/* 문제 정의
S,H로 이루어진 길이 N 문자열 -> 점수합(SSH=3,SHS=2,HSS=1)
 */

/* 해결 알고리즘 생각
앞에서부터 완전탐색
*/

/* 시간복잡도
O(3N)
*/

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, sum = 0;
    char arr[MAX];   
    cin >> n;
    arr[0] = arr[1] = arr[2] = 'X';
    for (int i = 0; i < n;i++) {
        cin >> arr[i];
    }
    ///////////////////solution//////////////////
    for (int i = 0; i < n-2; i++) {
        if (arr[i] == 'S' && arr[i+1] == 'S' && arr[i+2] == 'H')
            sum += 3;
        if (arr[i] == 'S' && arr[i+1] == 'H' && arr[i+2] == 'S')
            sum += 2;
        if (arr[i] == 'H' && arr[i+1] == 'S' && arr[i+2] == 'S')
            sum += 1;
    }
    ////////////////////output///////////////////
    cout << sum;
    return 0;
}