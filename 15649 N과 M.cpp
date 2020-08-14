/*
재귀는 항상 3step!
1. 함수 구성 (return type -> 인자)
2. base condition
3. 내가 무엇을 수행

vector에는 insert, delete 메소드 있음.
vector copy하려면 resize() 먼저 해야됨.
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/* 문제 정의
(N, M) -> 1부터 N까지 자연수 중 중복 없이 M개 고른 모든 수열 나열
 */

/* 해결 알고리즘 생각
순열 구현 문제
재귀
    1. 함수 구성 (return type: void(print 수행) -> 인자: depth (M이면 종료), 현재 순열)
    2. base condition: depth == M -> 현재 순열 print
    3. 내가 무엇을 수행: 현재 순열에 아직 추가되지 않은 숫자 추가해서 재귀호출
        현재 순열을 유지하는 것보다 추가되지 않은 순열을 유지하는 편이 편리하겠다!
    
    1. 인자: depth, 현재 순열, 남은 숫자들
*/

/* 의사코드
num 벡터에 숫자 1~n 입력
void permutation(depth, vector now (call by ref), vector remain (call by value)) {
    if (depth == 0) {
        print
        return
    }
    for i in remain:
        now.push_back(i)
        remain.erase(i)
        permutation(depth - 1, now, next_remain)
        remain.insert(i)
        now.pop_back()

    remain을 한 요소를 뺐다가 넣는 방법을 모르겠음. dfs 홀용하면 될거같은데..

main() {
    permutation(M, [], [1,2,3,4])
}
}
*/

void permutation(int depth, vector<int> &now, vector<int> remain)
{
    // cout << "permutation" << depth;
    if (depth == 0)
    {
        for (auto i : now)
        {
            cout << i << ' ';
        }
        cout << '\n';
        return;
    }
    vector<int> temp;
    for (int i = 0; i < remain.size(); i++)
    {
        // cout << "for" << i;
        now.push_back(remain[i]);
        temp.resize(remain.size());
        copy(remain.begin(), remain.end(), temp.begin());
        temp.erase(temp.begin() + i);
        permutation(depth - 1, now, temp);
        now.pop_back();
    }
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, M;
    cin >> N;
    cin >> M;
    vector<int> now;
    vector<int> remain;
    for (int i = 1; i <= N; i++)
    {
        remain.push_back(i);
    }
    permutation(M, now, remain);
    return 0;
}