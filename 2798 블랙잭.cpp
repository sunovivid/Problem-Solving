#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 100
/*
N개 숫자 배열로 받아서 오름차순 sort
for i = 1 to N
    for j = i+1 to N
        for k = j+1 to N
            if (i + j + k > M)
                break
            max 갱신
return max  
*/
int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N, M;
    cin >> N;
    cin >> M;
    int num[MAX];
    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
    }
    sort(num, num + N);
    int max = -987654321;
    int sum;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            for (int k = j + 1; k < N; k++)
            {
                sum = num[i] + num[j] + num[k];
                if (sum > M)
                    break;
                max = sum > max ? sum : max;
            }
        }
    }
    cout << max;
    return 0;
}