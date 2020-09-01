/****
 * 
 * Programmers 위장
 * 
 * Date : 2020-09-01 TUE
 * Github : https://github.com/Amjong/APC
 * Problem : https://programmers.co.kr/learn/courses/30/lessons/42578
 * 
 ****/

#include <iostream>
#include <string>
#include <vector>

using namespace std;
int twopow[21];
int clothset[31][2];
int f = 0;

int main(void)
{
 
}

int pow(int n) // 2^n 반환
{
    if (twopow[n] != 0)
    {
        return twopow[n];
    }
    if (n == 0)
    {
        return twopow[0] = 1;
    }
    else
    {
        return twopow[n] = pow(n - 1) * 2;
    }
}

int hashfunc(string str) // 1 ~ 20자의 문자열을 int값으로 반환
{
    int size = str.size();
    int ret = 0;
    for (int i = 0; i < size; i++)
    {
        ret += pow(i) * str[i]; // i번째 인덱스 문자 * 2^i를 더해감
    }
    return ret;
}

int solution(vector<vector<string>> clothes)
{
    int size = clothes.size();
    int clothset_idx = 0;
    int isfind = 0;
    for (int i = 0; i < size; i++)
    {
        int hash = hashfunc(clothes[i][1]); // 각각의 cloth 종류에 대해서
        isfind = 0;
        for (int j = 0; j < clothset_idx; j++)
        {
            if (clothset[j][0] == hash) // 이미 나왔던 종류면
            {
                clothset[j][1]++; // 그 종류 갯수 + 1
                isfind = 1;
                break;
            }
        }
        if (!isfind) // 나오지 않았던 종류면
        {
            clothset[clothset_idx][0] = hash; // clothset에 새로 추가
            clothset[clothset_idx][1] = 1; // 갯수 1개
            clothset_idx++; // set 갯수 추가
        }
    }
    f = clothset_idx;
    int answer = 1;
    for (int i = 0; i < f; i++) 
    {
        answer *= (clothset[i][1] + 1); // (종류 별 갯수 + 1)을 곱한 것이 모든 경우의 수
                                        // 그 종류 각각의 옷을 입거나, 모두 안입거나 => 종류 갯수 + 1  
    }

    return answer - 1; // 아예 옷을 안입는 경우는 없으므로 -1
}
