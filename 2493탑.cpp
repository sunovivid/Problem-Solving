//내 풀이가 틀렸을 수 있음을 항상 인정하자!
//문제를 단순하고 간결하게 풀자!!
//이 문제에서는 index를 저장했으면 복잡하게 풀 필요 없었다!


#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

/* 문제 정의
탑의 높이 수열 -> 각 탑의 신호를 받는 탑 번호
신호를 받는 탑? 왼쪽에 있는 탑 중에서 자신보다 높거나 같은 탑 중 가장 가까운 탑
N <= 5*10^5 O(NlgN)
탑의 높이 <= 10^8
 */

/* 해결 알고리즘 생각

스택에 push할때
스택 top이 자신보다 작으면 => 가려지는 애들. pop해도 무방.
자신보다 큰 애 나올 때까지 pop. 나오면 걔가 수신탑.
스택 top이 자신보다 크거나 같으면 => 내 레이저 수신하는 탑. push하고 수신탑 출력.
*/

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, k, count;
    stack<pair<int, int>> height; //자신의 인덱스, 탑의 높이 //legacy: 왼쪽으로 갈 때 자기보다 크거나 같은 탑이 나올 때까지 만난 자기보다 작은 탑의 개수, 자신의 높이
    cin >> n;
    cin >> k;
    height.push({1, k});
    cout << 0 << ' ';
    for (int i = 2; i <= n; i++)
    {
        cin >> k;
        //탑이 stack top보다 크면
        //  stack top보다 작거나 같을 때까지 pop
        //  empty면 0출력하고 종료
        //비었으면 0 출력
        //아니면 해당 탑의 인덱스 출력
        while (height.top().second < k)
        {
            height.pop();
            if (height.empty())
                break;
        }
        if (height.empty())
            cout << 0 << ' ';
        else
        {
            cout << height.top().first << ' ';
        }
        height.push({i, k});
    }
    return 0;
}

/*legacy

//count = 0;
//탑이 stack top보다 크면
//  stack top보다 작거나 같을 때까지 pop
//  count++
//  empty면 0출력하고 종료
//i-1 - count 출력 (자기보다 크거나 스택이 빈 상황)
//자기보다 크면 i-1 - count 출력
//비었으면 0 출력

/*
        if (height.top() < k) //탑이 stack top보다 크면
        {
            count = 0;
            // 
            do
            {
                height.pop();
                cout << "pop ";
                count++;
                if (height.empty())
                {
                    cout << 0 << ' ';
                    break;
                }
            } while (height.top() < k);
            cout << i - 1 - count << ' ';
            height.push(k);
        }
        else
        {
            // printf("02\n");
            height.push(k);
            cout << i - 1 << ' ';
        }
*/