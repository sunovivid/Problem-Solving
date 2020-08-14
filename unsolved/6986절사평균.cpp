#include <iostream>
#include <algorithm>

#define MAXLEN 100001
#define DIGIT 3 //반올림할 소수잠 자리 위치
using namespace std;

int *divide(int a, int b);

int main()
{
    int N, K;
    cin >> N, cin >> K;

    int a, b;
    char c;
    int arr[MAXLEN];
    for (int i = 0; i < N; i++)
    {
        scanf("%d%c%d", &a, &c, &b);
        arr[i] = 10 * a + b;
        cout << '\n'
             << arr[i];
    }
    cout << "sort 통과전";
    sort(arr, arr + N);
    cout << "sort 통과";
    int sum = 0;
    for (int i = K; i < N - K; i++)
    {
        sum += arr[i];
    }
    cout << "t";
    int *truncated_avg = divide(sum, N - K);
    int *corrected_avg = divide(sum + arr[K] * K + arr[N - K - 1] * K, N);

    cout << "t2";
    for (int i = 0; i <= DIGIT; i++)
    {
        cout << truncated_avg[i];
    }
    cout << '\n';
    for (int i = 0; i <= DIGIT; i++)
    {
        cout << corrected_avg[i];
    }
    /*
    for N번
        입력 a,b
        10a + b 저장
    정렬
    for i = 0 to K
        arr[i] = arr[K]
    for i = K to N
        arr[i] = arr[N-K]
    for i = K to N-K
        sum += arr[i]
    40 / 3 = 13
    1 * 10 = 10
    10 / 3 = 3
    10 / 3 = 3
    
    a / b 소수점 구하기 방법
    소수점 숫자 배열 int num[]
    for i = 0 to 3
        mok = a / b 
        nam = a % b
        a = nam * 10
    반올림할 자리 위치: p
    if num[p] >= 5
        해당 자릿수에 1 더하기
        10이 되면
    */
    return 0;
}

int *divide(int a, int b)
{
    cout << "devide" << a << b;
    int num[DIGIT + 1]; //num[0]: 정수부, num[1], ... : 소수 자릿수 하나
    int mok, nam;
    for (int i = 0; i <= DIGIT; i++)
    {
        mok = a / b;
        nam = a % b;
        a = nam * 10;
        num[i] = mok;
    }
    if (num[DIGIT] >= 5)
    {
        int i = DIGIT;
        while (1)
        {
            num[i] += 1;
            if (num[i] == 10)
            {
                num[i] = 0;
                i -= 1;
                if (i < 0)
                    break;
            }
            else
            {
                break;
            }
        }
    }
    return num;
}