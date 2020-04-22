/*
1. 길이를 모르는 문자열 입력받기
scanf("%s",CHAR_ARR)
for (int i=0;CHAR_ARR[i]!='\0';i++)
    CHAR_ARR[i]

2. 중위 -> 후위표기법 변환
우선순위가 높은 연산자일수록 후위표기법의 앞에 옴.
따라서, 새로운 연산자를 만나면  
    스택 top의 연산자보다 우선순위가 높으면 -> push
    우선순위가 같거나 top보다 낮으면 -> "자신보다 우선순위 큰" 애들은 모두 pop (즉, precedence보다 크거나 같은)
이 "자신보다 큰" 을 확인하지 않아서 시간 잡아먹음.

탑은 스택에 내림차순 정렬이었는데 얘는 오름차순 정렬.
탑: 자기가 top보다 작으면 push, 크면 자기보다 크거나 같은 애 만날 때까지 pop
후위표기법: 자기 우선순위가 top보다 크면 push, 작으면 자기보다 작은 애 만날 때까지 pop
막대그래프 생각하자
*/

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

#define MAX 105

using namespace std;

/* 문제 정의
중위표기식 -> 후위표기식
 */

/* 해결 알고리즘 생각
문자 -> 그대로 출력
연산자 -> 스택에 넣어서 우선순위 높은 게 먼저 출력되도록.
*/

int main()
{
    // cin.tie(NULL);
    // ios_base::sync_with_stdio(false);

    char infix[MAX], c;
    scanf("%s", infix);
    char op_char[6] = {'+', '-', '*', '/', '(', ')'};
    int precedence[6] = {0, 0, 1, 1, -1, -1};
    stack<int> op_stack;
    for (int i = 0; infix[i] != '\0'; i++)
    {
        char c = infix[i];
        int op = 0;
        switch (c)
        {
        case '+':
            op = 0;
            break;

        case '-':
            op = 1;
            break;

        case '*':
            op = 2;
            break;

        case '/':
            op = 3;
            break;

        case '(':
            op = 4;
            break;

        case ')':
            op = 5;
            break;

        default:
            printf("%c", c);
            continue;
        }
        /*연산자 우선순위가 높은 게 먼저 나오도록!
            top보다 우선순위 높으면 그대로 넣고 (일찍 나오도록)
            같으면 기존에 있는 것 먼저 나오고 (우선순위 같으면 먼저 들어간 게 우선순위 높음) push
            낮으면 기존에 있는 것 먼저 나오고 push
            예외: 여는 괄호는 무조건 push (이후 들어올 연산자는 기존의 것들보다 무조건 먼저 나오므로)
        
        괄호의 처리:
            여는 괄호가 나오면 무조건 push.
            닫는 괄호가 나오면 여는 괄호까지 모두 pop
        */
        if (op_stack.empty() || op == 4)
        {
            op_stack.push(op);
            continue;
        }
        if (precedence[op] > precedence[op_stack.top()])
        {
            op_stack.push(op);
        }
        else
        {
            /*
            연산자가 top보다 우선순위가 같거나 낮은 경우
                연산자가 )면 (까지 pop
                아니면 empty까지 pop .. 하면 안됨!! 괄호 안일 수 있으므로 (까지 pop
            */
            if (op == 5)
            {
                while (op_stack.top() != 4)
                {
                    printf("%c", op_char[op_stack.top()]);
                    op_stack.pop();
                }
                op_stack.pop();
            }
            else
            {
                while (!op_stack.empty() && op_stack.top() != 4 && precedence[op_stack.top()] >= precedence[op])
                {
                    printf("%c", op_char[op_stack.top()]);
                    op_stack.pop();
                }
                op_stack.push(op);
            }
        }
    }
    while (!op_stack.empty())
    {
        printf("%c", op_char[op_stack.top()]);
        op_stack.pop();
    }
    return 0;
}