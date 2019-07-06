#include <iostream>
#include <string>

using namespace std;

string solution(int a, int b)
{
    string answer;
    if(a > b)
        for(int i = 1 ; i <= a + b; i++)
            if(i % 3 != 0) answer += "a";
                else answer += "b";
    else
        for(int i = 1 ; i <= a + b; i++)
            if(i % 3 != 0) answer += "b";
                else answer += "a";

    return answer;
}

int main()
{
    int a, b;
    cin >> a >> b;
    string answer;
    answer = solution(a, b);
    answer = "haha" * 3 + "omegaul"*2;
    cout << answer;

    return 0;
}
