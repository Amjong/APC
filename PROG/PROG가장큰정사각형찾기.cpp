/****
 * 
 * Programmers 최솟값 만들기
 * 
 * Date : 2020-09-01 TUE
 * Github : https://github.com/Amjong/APC
 * Problem : https://programmers.co.kr/learn/courses/30/lessons/12905
 * 
 ****/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1001][1001];
int solution(vector<vector<int>> board)
{
    int answer = 0;
    int r = board.size();
    int c = board[0].size();
    if (r < 2 || c < 2) // 가로/세로 중 길이가 2보다 작은 경우, 점화식 자체가 성립이 안되므로 따로 체크.
    {
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if(board[i][j] == 1)
                {
                    return 1;
                }
            }
        }
    }
    for (int i = 0; i < r; i++) // 맨 왼쪽, 맨 위쪽 줄은 dp 미리 채워주기.
    {
        dp[i][0] = board[i][0];
    }
    for (int i = 0; i < c; i++)
    {
        dp[0][i] = board[0][i];
    }
    for (int i = 1; i < r; i++)
    {
        for (int j = 1; j < c; j++)
        {
            if (board[i][j] == 0)
            {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + 1;
            // 왼쪽 대각선 위, 왼쪽, 위 세칸 중 가장 작은 값 + 1 (이유는 잘 모르겠음..)
            answer = (answer < dp[i][j]) ? dp[i][j] : answer;
        }
    }

    return answer * answer;
}