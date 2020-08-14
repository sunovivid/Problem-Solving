//n이 작으므로 linked list의 원소 삭제를 배열 밀기로 구현해도 무방
//O(n^2)

#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX 16000

using namespace std;

/* 문제 정의
N, K -> 요세푸스 순열
 */

/* 해결 알고리즘 생각
O(n^2) N이 작아서 이렇게 구현하는 게 더 빠를수도
*/

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;

    int arr[n];
    for (int i = 0; i < n; i++)
        arr[i] = i + 1;
    ///////////////////solution//////////////////
    cout << '<';
    for (int size = n, index = 0; size > 0; size--)
    {
        index = (index + k - 1) % size; //현재 index 구하기 (% size는 원순열로 만들어줌)
        cout << arr[index];             //현재 index 번호 출력 (kill)
        for (int i = index; i < size - 1; i++)
            arr[i] = arr[i + 1]; //한 칸씩 당기기 (size--와 결합해서 kill하고 배열에서 없애는 효과)
        // linked list의 노드 삭제(O(1))을 배열 밀기(O(n))로 구현한 것
        if (size > 1)
            cout << ", ";
    }
    cout << ">";
    return 0;
}

/*legacy



*/