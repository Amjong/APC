/****
 * 
 * BOJ 16637 괄호 추가하기
 * 
 * Date : 2020-08-17 MON
 * Github : https://github.com/Amjong/APC
 * Problem : https://www.acmicpc.net/problem/16637
 * 
 ****/

#include <iostream>
#include <limits.h>
#define SIZE 20
using namespace std;

int ans = INT32_MIN;
int N;
char equation[SIZE];

int compute(int a, char op, int b)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    }
}

void solve(int bracket, int idx)
{

    if (idx >= N - 2)
    {
        //compute
        int cur_ans = 0;
        int cur_idx = 0;
        int bef_num = 0;
        char bef_op = '+';

        while (cur_idx <= N - 1)
        {
            if ((bracket & (1 << cur_idx)) != 0)
            {
                int cur_num = compute(equation[cur_idx] - '0', equation[cur_idx + 1], equation[cur_idx + 2] - '0');

                cur_ans = compute(bef_num, bef_op, cur_num);
                if (N > cur_idx + 3)
                {
                    bef_op = equation[cur_idx + 3];
                }
                cur_idx += 4;
                bef_num = cur_ans;
            }
            else
            {
                cur_ans = compute(bef_num, bef_op, equation[cur_idx] - '0');
                if (N > cur_idx + 1)
                {
                    bef_op = equation[cur_idx + 1];
                }
                bef_num = cur_ans;
                cur_idx += 2;
            }
        }
        ans = (cur_ans > ans) ? cur_ans : ans;
        return;
    }
    solve(bracket, idx + 2); // No Bracket
    bracket |= (1 << idx);
    solve(bracket, idx + 4); // Bracket
}

int main(void)
{
    cin >> N >> equation;
    solve(0, 0);
    cout << ans;
}
