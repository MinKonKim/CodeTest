#include <string>
#include <vector>

using namespace std;

int solution(int M, int N) {
    int answer = 0;
    
    int garo = 0;
    int sero = 0;
    if (M > 1)
    {
        sero = M-1;
    }

    if (N > 1)
    {
        garo = (N - 1) * M;
    }

    answer = sero + garo;

    return answer;
}