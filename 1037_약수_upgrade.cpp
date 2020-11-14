#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX 52

using namespace std;

/* 문제 정의
N의 약수 -> N
약수 정의: N은 A의 배수이고 A != 1, N
*/


/* 해결 알고리즘 생각
약수 목록에서 서로 양쪽 끝끼리 곱하면 원래 수가 됨
ex) 2, 3, 6, 9 -> 2 * 9 = 3 * 6 = 18
ex) 2, 4, 8 -> 2 * 8 = 4 * 4 = 16

n/2개 까지만 입력을 받고 arr[(n-1)/2] * arr[n/2]
*/

/* 시간복잡도
O(n/2)
*/

/* 
정답 보고 개선
최대, 최소만 구할 때는 전체값 유지할 필요없이 최소, 최대값만 유지해도 됨
정렬하지 않으므로 시간복잡도도 감소 ( O(nlgn) -> O(n) )
*/

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
    ///////////////////solution//////////////////
	int max = 0, min = 1'000'005;
	for (int i=0;i<n;i++) {
		int temp;
		cin >> temp;
		if (temp < min)	min = temp;
		if (temp > max) max = temp;
	}
	cout << min * max;
    ////////////////////output///////////////////

    return 0;
}