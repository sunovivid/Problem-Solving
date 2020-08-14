#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX

using namespace std;

/* 문제 정의
그늘이 생기는 높이차 M, 나무를 못 뽑게 되는 날 K, N개의 나무 높이 H 수열
 -> 나무를 심을 때 생기는 빈 칸의 수

나무 심기 규칙
왼쪽부터
    심을 수 있으면 심는다
    햇빛을 받을 수 없으면
        현재 K일 미만이면 뽑고 가장 왼쪽 빈 칸부터 다시 시도
        현재 K일 이상이면 한 칸 띄워서 심기
 */

/* 해결 알고리즘 생각
for i = 1 to n
    if arr[i-1] >= arr[i] + T
        if i < k
    else
...

스택 : (심은 나무 높이, 날짜)가 순서대로 저장
    for i = 1 to n
        while stack.top.h >= arr[i] + T
            if i >= stack.top.day + k //못 뽑는경우
                cnt++
                break
            else //뽑을 수 있는 경우
                stack.pop
        stack.push(arr[i])
*/  

/* 시간복잡도

*/
typedef struct {
    int h;
    int day;
} Tree;

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;
    ///////////////////solution//////////////////
    int cnt = 0;
    stack<Tree> stack;
    //init
    int first;
    cin >> first;
    stack.push({first,0});
    //iterate
    for (int i=1;i<n;i++) {
        int h;
        cin >> h;
        // cout << stack.top().h << ' ' << h << ' ' << m;
        while (!stack.empty() && stack.top().h >= h + m) { //햇빛 못 받는 경우
            // cout << "그림자!";
            if (i >= stack.top().day +k ) { //뽑을 수 있는 날짜를 지난 경우
                // cout << " 뽑을 수 없음" << endl;
                cnt++;
                break;
            }
            //뽑을 수 있으면
            // cout << " 뽑기" << endl;
            stack.pop();
        }
        // cout << "햇빛 받음";
        stack.push({h,i});
    }
    ////////////////////output///////////////////
    cout << cnt;
    return 0;
}