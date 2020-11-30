#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>
#include <string.h>
#include <string>
#include <numeric>

#define MAX 505

using namespace std;

/* 문제 정의
n!의 낮은 자리수부터 0의 개수
*/

/* 해결 알고리즘 생각
n!의 인수 중 2와 5의 개수를 구함
g2(n) : n의 인수 중 2의 개수
G2(n) : n!의 인수 중 2의 개수
f(n) = min(G2(n), G5(n))
g2(n) = g2(n/2) + 1
g2(1) = 0
G2(n) = g2(1) + g2(2) + ... + g2(n) (누적합)
*/

/* 시간복잡도

*/

/**
*memset 순서바꿔써서 결과값헷갈림
*/
int gcd(int a, int b) {
	for (int i=2;i<=min(a,b);i++)
		if (a % i == 0 && b % i == 0)
			return gcd(a/i, b/i) * i;
	return 1;
}

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
    ///////////////////solution//////////////////
	int numOfFactor2[MAX];
	memset(numOfFactor2, 0, sizeof(numOfFactor2));//TODO:확인
	for (int i=1;i<MAX;i++) {
		if (numOfFactor2[i] == 0) {
			for (int j=i;(j<<1)<MAX;j=j<<1) {
				numOfFactor2[j<<1] = numOfFactor2[j] + 1;
			}
		}
	}
	
	int numOfFactor5[MAX];
	memset(numOfFactor5, 0, sizeof(numOfFactor5));//TODO:확인
	for (int i=1;i<MAX;i++) {
		if (numOfFactor5[i] == 0) {
			for (int j=i;(j*5)<MAX;j*=5) {
				numOfFactor5[j*5] = numOfFactor5[j] + 1;
			}
		}
	}

	cout << min(accumulate(numOfFactor2 + 1, numOfFactor2 + n + 1, 0), 									accumulate(numOfFactor5 + 1, numOfFactor5 + n + 1, 0));
    ////////////////////output///////////////////

    return 0;
}