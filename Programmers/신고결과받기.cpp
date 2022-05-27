/****
 * 
 * Programmers 신고 결과 받기
 * 
 * Date : 2022-05-27 MON
 * Github : https://github.com/Amjong/APC
 * Problem : https://programmers.co.kr/learn/courses/30/lessons/92334?language=cpp
 * 2022 KAKAO BLIND RECRUITMENT 1번 문제
 ****/

#include <string>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;

#define ID_MAX 1000

vector<int> solution(vector<string> id_list, vector<string> report, int k)
{
    vector<int> answer;
    set<int> report_id_list[ID_MAX]; // report id list for each id
    map<string, int> m;              // each id -> index convert
    int id_count = (int)id_list.size();
    answer.resize(id_count);

    // 1. register map for each id (string -> index)
    for (int i = 0; i < id_count; i++)
    {
        m[id_list[i]] = i;
    }

    // 2. add report_id_list for each id (remove repeat case, so use set)
    for (auto str : report)
    {
        int pos = str.find(' ');
        string front_str = str.substr(0, pos);
        string back_str = str.substr(pos + 1);
        int front_str_idx = m[front_str];
        int back_str_idx = m[back_str];

        report_id_list[back_str_idx].insert(front_str_idx);
    }

    // 3. if reported count >= k, add count of report users
    for (auto s : report_id_list)
    {
        if (s.size() >= k)
        {
            for (auto i : s)
            {
                answer.at(i)++;
            }
        }
    }
    return answer;
}