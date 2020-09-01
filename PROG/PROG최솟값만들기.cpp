/****
 * 
 * Programmers 최솟값 만들기
 * 
 * Date : 2020-09-01 TUE
 * Github : https://github.com/Amjong/APC
 * Problem : https://programmers.co.kr/learn/courses/30/lessons/12941
 * 
 ****/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    int size = A.size();
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int A_sum = 0, B_sum = 0;
    for (int i = 0; i < size; i++)
    {
        A_sum += A[i] * B[size - 1 - i];
        B_sum += B[i] * A[size - 1 - i];
    }
    answer = (A_sum < B_sum) ? A_sum : B_sum;

    return answer;
}