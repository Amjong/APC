/****
 * 
 * Programmers 실패율
 * 
 * Date : 2020-09-07 MON
 * Github : https://github.com/Amjong/APC
 * Problem : https://programmers.co.kr/learn/courses/30/lessons/42889
 * 
 ****/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<double, int> a, pair<double, int> b) // 실패율 내림차순, 스테이지 번호 오름차순 
{
    if (a.first == b.first) 
    {
        return a.second < b.second;
    }
    else
    {
        return a.first > b.first;
    }    
}
vector<int> solution(int N, vector<int> stages) {
    vector<pair<double, int>> rate; // <실패율, 스테이지 번호>
    for (int i = 0; i <= N; i++)
    {
        rate.push_back({ 0.0, i }); // 실패율 0으로 초기화 (stages에 한번도 등장하지 않은 스테이지는 실패율 0)
                                    // 아무도 도달하지 못했거나 (0 / 0), 도달한 모두가 클리어했거나 (1 / 1)
    }
    
    sort(stages.begin(), stages.end()); // 정렬 후
    int size = stages.size();
    int cur = stages[0];
    int cur_num = 0;
    for (int i = 0; i < size; i++) // 스테이지 번호 같은 숫자를 세어준다.
    {                              // 같은 숫자 갯수 => 현재 스테이지에 도달했지만 클리어하지 못한 사람 수
        if (stages[i] != cur)      // 그 숫자 마지막 인덱스로부터 그 스테이지를 클리어한 사람 수를 알 수 있다.
        {
            rate[cur] = {((double)cur_num / (cur_num + size - i)), cur}; // 실패율 = (도달 O 클리어 X) / (도달 O 클리어 X + 도달 O 클리어 O)
            cur = stages[i];
            cur_num = 1;
        }
        else
        {
            cur_num++;
        }        
    }
    if (cur != N + 1) // 마지막 남아있는 숫자가 N + 1일 경우에는 N번째 스테이지의 실패율은 0.
    {
        rate[cur] = { 1.0, cur }; // N + 1이 아닐 경우, 그 스테이지 번호 다음 번호가 없으므로 클리어 한 사람 X, 고로 실패율 1
    }
    sort(rate.begin(), rate.end(), comp);
    vector<int> answer;
    for (int i = 0; i <= N; i++)
    {
        if(rate[i].second == 0) continue;
        answer.push_back(rate[i].second);
    }
    return answer;
}

int main(void)
{
    
}