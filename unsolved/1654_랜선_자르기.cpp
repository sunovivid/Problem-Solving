#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX 10005

using namespace std;

/* 문제 정의
정수 k개, 랜선 길이 n개 -> n개 만들 수 있는 랜선 최대 길이
 */

/* 해결 알고리즘 생각
랜선 길이 parametric search로 찾기
처음 시작: 1 or 입력된 랜선 길이의 최솟값
목표: 조건 만족하는 랜선 길이의 최댓값
조건: 정수 k개를 현재 search값으로 나눈 몫의 합이 n보다 크거나 같음
*/

/* 시간복잡도
랜선의 길이 범위: 최소 1 ~ 최대 min(주어진 랜선 길이)
O(lg(min(주어진 랜선 길이)))
*/

/**
* 0% -> 탐색범위 최댓값은 내가 짠 이분탐색에선 무조건 조건 만족하지 않는 곳에서부터 시작해야 -> min(vector) + 1;
5% -> 이상하게 안 돼서 탐색범위 최댓값을 987654321, long long으로 바꾸 1 << 31 - 1로
52%
2의 거듭제곱 연산: 1 << 31 (2 << 아님)
**/

vector<int> v;
long long k, n;

bool is_satisfying(long long length) {
	long long sum = 0;
	for (auto elem: v) {
		sum += elem / length;
	}
	return sum >= n;
}

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	
	cin >> k >> n;
	v.resize(k);
	// long long minElem = 1 << 31 - 1;
	for (auto &elem : v) {
		cin >> elem;
		// minElem = min(minElem, elem);
	}
	
    ///////////////////solution//////////////////
	long long low = 1, high = 1 << 31 - 1, mid, answer = 0;
	//조건 만족 길이의 최댓값
	while (low <= high) {
		mid = (low + high) / 2;
		if (is_satisfying(mid)) {
			low = mid + 1;
			answer = max(mid, answer);
		}
		else
			high = mid - 1;
	}
	
	//while (low <= high) {
	// 	mid = (low + high) / 2;
	// 	if (!is_satisfying(mid))
	// 		high = mid - 1; //조건 만족 안하는 최솟값으로 수렴
	// 	else
	// 		low = mid + 1; //조건 만족하는 최댓값으로 수렴
	// }
    ////////////////////output///////////////////
	cout << answer;
    return 0;
}