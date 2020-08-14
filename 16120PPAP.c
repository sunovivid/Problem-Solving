#include <stdio.h>
#define MAX 1000000
/* 문제 정의
A,P로 이루어진 문자열 -> 'PPAP 문자열' 여부
문자열 길이: 10^6 O(n)이하
PPAP 문자열: 재귀적으로 정의
Base case: P
Recursive: PPAP 문자열에서 P하나를 PPAP로 바꾼 문자열
 */

/* 해결 알고리즘 생각
PPAP를 괄호처럼 하나의 덩어리로 생각할 수 있지 않을까? => 스택 문제
PPAP를 만나면 P로 압축.
계속 압축해서 P만 남으면 PPAP 문자열
아니면 NP

만나는 문자 차례로 입력
개념적으로 P스택과 A스택이 존재
P만날때마다 p+=1
    if a >= 1 and p >= 3
        PPAP! -> P문자 하나로 취급
        p -= 2 (하나로 취급)
        a -= 1
A만날때마다 a+=1
    if p >= 2
        OK!
    else
        PPAP 아님
*/
int main()
{
    int p = 0, a = 0, is_ppap = 1;
    char str[1000000];
    scanf("%s", &str);
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == 'P')
        {
            p += 1;
            if (a >= 1 && p >= 3)
            {
                p -= 2;
                a -= 1;
            }
        }
        else if (str[i] == 'A')
        {
            a += 1;
            if (p < 2)
            {
                is_ppap = 0;
                break;
            }
        }
        // printf("p:%d, a:%d\n", p, a);
    }

    if (is_ppap && p != 1)
        is_ppap = 0;

    if (is_ppap)
        printf("PPAP");
    else
        printf("NP");

    return 0;
}

/*
그리디?
*/