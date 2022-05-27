/****
 * 
 * Programmers k진수에서 소수 개수 구하기
 * 
 * Date : 2022-05-27 MON
 * Github : https://github.com/Amjong/APC
 * Problem : https://programmers.co.kr/learn/courses/30/lessons/92335
 * 2022 KAKAO BLIND RECRUITMENT 2번 문제
 ****/
#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool is_prime(long n)
{
    if (n <= 1)
    {
        return false;
    }
    if (n <= 3)
    {
        return true;
    }
    for (long i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int solution(int n, int k)
{
    int answer = 0;
    // 1. n의 1의 자리부터 0이 나올 때 까지의 수 찾고 소수인지 판별
    long cur_tot_num = 0;
    long cur_k_pow = 1;
    long cur_ten_pow = 1;
    int cur_k_num = 0;
    int flag_final = 0;
    while (true)
    {
        if (flag_final)
        {
            // P0 case
            if (is_prime(cur_tot_num))
            {
                answer++;
            }
            break;
        }
        // n의 뒤에서 k번째 자리수 구하기
        if (n < cur_k_pow * k)
        {
            flag_final = 1;
        }
        cur_k_num = ((n % (cur_k_pow * k)) / cur_k_pow);
        if (cur_k_num == 0)
        {
            if (is_prime(cur_tot_num))
            {
                answer++;
            }
            cur_tot_num = 0;
            cur_k_num = 0;
            cur_ten_pow = 1;
            cur_k_pow *= k;
            continue;
        }
        cur_tot_num += cur_ten_pow * cur_k_num;
        cur_k_pow *= k;
        cur_ten_pow *= 10;
    }

    return answer;
}
