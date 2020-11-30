#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX

using namespace std;

/* 문제 정의
링의 반지름들 -> 첫 번째 링을 한 바퀴 돌리면 나머지 링은 몇 바퀴 돌아가는지?
*/

/* 해결 알고리즘 생각
rotation(firstR, lastR) = firstR/lastR;
*/

/* 시간복잡도

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

	int n, first_r, r;
	cin >> n >> first_r;
    ///////////////////solution//////////////////
	while (--n) {
		cin >> r;
		int gcd_temp = gcd(first_r, r);
		cout << first_r / gcd_temp << '/' << r / gcd_temp << '\n';
	}
    ////////////////////output///////////////////

    return 0;
}