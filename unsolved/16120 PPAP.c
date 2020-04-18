#include <stdio.h>

/* 문제 정의
A,P로 이루어진 문자열 -> 'PPAP 문자열' 여부
PPAP 문자열: 재귀적으로 정의
Base case: P
Recursive: PPAP 문자열에서 P하나를 PPAP로 바꾼 문자열
 */

/* 해결 알고리즘 생각
PPAP를 괄호처럼 하나의 덩어리로 생각할 수 있지 않을까? => 스택 문제
PPAP를 만나면 P로 압축.
계속 압축해서 P만 남으면 PPAP 문자열
아니면 NP


*/
int main()
{
    return 0;
}