/****
 * 
 * Programmers 구명보트
 * 
 * Date : 2020-08-19 WED
 * Github : https://github.com/Amjong/APC
 * Problem : https://programmers.co.kr/learn/courses/30/lessons/42885
 * 
 ****/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
    
}

int solution(vector<int> people, int limit)
{
    int answer = 0;
    sort(people.begin(), people.end());

    while (1)
    {
        if (people.empty())
        {
            break;
        }
        int now = people.front();
        int high = people.back();
        people.erase(people.begin());
        if (people.empty())
        {
            answer++;
            break;
        }
        if ((people.front() + now) > limit)
        {
            answer++;
        }
        int left = 0;
        int right = (int)people.size() - 1;
        int mid;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (people[mid] + now > limit)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        if (right != -1) // match couple
        {
            cout << "now : " << now << " matched : " << people[mid] << "\n";             
            people.erase(people.begin() + mid);
        }
        answer++;
        cout << answer << people.size() << "\n";
    }
    return answer;
}