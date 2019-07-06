#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("secventauniforma.in");
ofstream fout("secventauniforma.out");

int main()
{
    int x, maxSeqLen = 1, maxSeqNum,currentSeqLen = 1, y;
    fin >> x;

    maxSeqNum = x;
    while(fin >> y)
    {
        if(x == y)
            currentSeqLen++;
        else{
            if(currentSeqLen > maxSeqLen){
                maxSeqLen = currentSeqLen;
                maxSeqNum = x;
            }
        }
        x = y;
    }
    for(int i = 1; i <= maxSeqLen; i++)
        cout << maxSeqNum << " ";
    return 0;
}
