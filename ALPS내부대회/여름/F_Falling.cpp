#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <string.h>
#include <string>

#define MAX_W 11
#define MAX_N 6
using namespace std;

/* 문제 정의
Si, 방어력 W 수열, 설치 비용 P 수열 -> 각 Si를 방어할 수 있는 (방어블럭 설치 비용의 최솟값), 해당 조합의 수
 */

/* 해결 알고리즘 생각
각 열이 독립적이다. 주어진 최댓값들이 작다. => Si 0~10까지 완탐으로 구하고 각 열마다 재활용?

for 모든 블럭 조합에 대해
    방어력, 비용 계산
    for 낙하물 = 0 to 방어력
        if 비용 < 최소비용[낙하물]
            최소비용[낙하물] 갱신
            조합수[낙하물] 갱신
*/

/* 시간복잡도
O(k^3 * 10)
*/


int min_cost[11], num_combination[11];

void update_min(int defence, int cost) { //한 블럭 조합의 방어력, 비용
    for (int w=0;w<=defence;w++) {
        if (cost < min_cost[w]) {
            min_cost[w] = cost;
            num_combination[w] = 1;
        }
        else if (cost == min_cost[w]) {
            num_combination[w] += 1;
        }
    }
}

int main()
{
    /////////////input&preprocessing/////////////
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, k, s[MAX_N], w[MAX_N], p[MAX_N]; 
    cin >> n >> k;
    for (int i=0;i<n;i++)
        cin >> s[i];
    for (int i=0;i<k;i++)
        cin >> w[i] >> p[i];
    ///////////////////solution//////////////////

    
    fill(min_cost, min_cost + MAX_W, 987654321);
    //중복조합 재귀함수 구현 다시 찾아보자..
    switch (n) {
    case 5:
        //5블럭 쓰는 경우
        for (int a=0;a<k;a++)
            for (int b=a;b<k;b++)
                for (int c=b;c<k;c++)
                    for (int d=c;d<k;d++)
                        for (int e=d;e<k;e++)
                            update_min(w[a] + w[b] + w[c] + w[d] + w[e], p[a] + p[b] + p[c] + p[d] + p[e]);

    case 4:
        //4블럭 쓰는 경우
        for (int a=0;a<k;a++)
            for (int b=a;b<k;b++)
                for (int c=b;c<k;c++)
                    for (int d=c;d<k;d++)
                    update_min(w[a] + w[b] + w[c] + w[d], p[a] + p[b] + p[c] + p[d]);
    
    case 3:
        //3블럭 쓰는 경우
        for (int a=0;a<k;a++)
            for (int b=a;b<k;b++)
                for (int c=b;c<k;c++)
                    update_min(w[a] + w[b] + w[c], p[a] + p[b] + p[c]);
    case 2:
        //2블럭 쓰는 경우
        for (int a=0;a<k;a++)
            for (int b=a;b<k;b++)
                update_min(w[a] + w[b], p[a] + p[b]);
    case 1:
        //1블럭 쓰는 경우
        for (int a=0;a<k;a++)
            update_min(w[a], p[a]);
    }

    ////////////////////output///////////////////
    for (int i=0;i<n;i++) {
        cout << min_cost[s[i]] << ' ' << num_combination[s[i]] << '\n';
    }
    return 0;
}