#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX 131079

using namespace std;

/* 문제 정의
문자열 -> 문자열을 'a'-good 문자열로 만드는 최소 replace 횟수
c-good 문자열:
    if len(s) == 1
        'c'
    else
        왼쪽 또는 오른쪽 절반이 c로 이루어지고 나머지 절반이 (c+1)-good 문자열
 */

/* 해결 알고리즘 생각
모든 경우 비교하기

dp[i] = (level i일때 문자열을 'a'-good 문자열로 만드는 최소)
*/

/* 시간복잡도

*/

int find_min(char s[MAX], int begin, int end, int level) {
    if (end - begin == 1) {
        if (s[begin] != 'a' + level)
            return 1;
        return 0;
    }
 
    int left_count = 0;
    for (int i=begin; i < begin + (end - begin + 1)/2; i++) {
        if (s[i] != 'a' + level)
            left_count++;
    }
    int right_count = 0;
    for (int i= begin + (end - begin + 1)/2; i < end; i++) {
        if (s[i] != 'a' + level)
            right_count++;        
    }
 
    return min(left_count + find_min(s, begin + (end - begin + 1)/2, end, level + 1),
                right_count + find_min(s, begin, begin + (end - begin + 1)/2, level + 1));
}

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int t;
    cin >> t;
    ///////////////////solution//////////////////
    while (t--) {
        int n;
        cin >> n;
        char s[MAX];
        cin >> s;
        cout << find_min(s, 0, n, 0) << '\n';
    }
    ////////////////////output///////////////////

    return 0;
}