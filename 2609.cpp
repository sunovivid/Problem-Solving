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
 n, m -> 최대공약수, 최소공배수
 */

/* 해결 알고리즘 생각
gcd(a,b) = (가능한 경우) gcd(a/i, b/i) * i 또는 (불가능한 경우) 1
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

	int n, m;
	cin >> n >> m;
    ///////////////////solution//////////////////
	int gcd_temp = gcd(n, m);
	cout << gcd_temp << '\n' << (n * m) / gcd_temp;
    ////////////////////output///////////////////

    return 0;
}