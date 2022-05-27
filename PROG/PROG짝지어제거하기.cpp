/****
 * 
 * Programmers 짝지어 제거하기
 * 
 * Date : 2020-09-02 WED
 * Github : https://github.com/Amjong/APC
 * Problem : https://programmers.co.kr/learn/courses/30/lessons/12973
 * 
 ****/

#include <iostream>
#include <string>

using namespace std;

struct stack // stack 구현
{
    int s[1000001];
    int t = -1;

    void push(int p)
    {
        s[++t] = p;
    }

    int pop()
    {
        if (t == -1)
        {
            return -1;
        }
        return s[t--];
    }

    int top()
    {
        if (t == -1)
        {
            return -1;
        }
        return s[t];
    }

    int empty()
    {
        if (t == -1)
        {
            return 1;
        }
        return 0;
    }

} st;

int solution(string s)
{
    int size = s.size();
    for (int i = 0; i < size; i++)
    {
        if(st.empty()) // 비어있으면 push
        {
            st.push(s[i]);
        }
        else // 비어있지 않을 때
        {
            if(st.top() == s[i]) // stack의 top이 이번 문자와 같으면 짝지어 제거.
            {
                st.pop(); // 이번 문자를 push 안하고, stack의 top을 제거 (짝지어 제거)
            }
            else // 아니면 push
            {
                st.push(s[i]);
            }
            
        }        
    }
    if (st.empty()) // 다 마쳤을 때 stack에 남아있으면 0, 비었으면 1 반환.
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main(void)
{
    
}