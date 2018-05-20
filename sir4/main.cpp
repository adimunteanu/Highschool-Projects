#include <iostream>

using namespace std;

int firstKOfNGroup;
int n, p, k, nGroupWithKSum = 1, sum = 0, rec[10];
int halfPal[200], halfPalIndex = 0;
bool sumExists = false, doubleDigitExists = true;

void ExtractDigits(int num)
{
    while(num){
        rec[num % 10]++;
        num /= 10;
    }
}

int main()
{
    cin >> p >> n >> k;

    cout << p / 2 + 1 << endl; //Punctul a

    //Inceput punct b
    firstKOfNGroup = (n * (n - 1)) / 2;
    for(int i = firstKOfNGroup; i < firstKOfNGroup + n; i++)
        ExtractDigits(i * 2 + 1);

    while(doubleDigitExists){
        bool hasFoundDoubleDigit = false;

        for(int i = 9; i >= 0; i--)
            if(rec[i] > 1){
                halfPalIndex++;
                halfPal[halfPalIndex] = i;
                rec[i] -= 2;
                hasFoundDoubleDigit = true;
                break;
            }

        if(!hasFoundDoubleDigit)
            doubleDigitExists = false;
    }

    for(int i = 1; i <= halfPalIndex; i++)
        cout << halfPal[i];

    bool hasFoundLargestDigit = false;
    int largestDigit = 9;
    while(!hasFoundLargestDigit){
        if(rec[largestDigit] == 1)
            hasFoundLargestDigit = true;
        else
            largestDigit--;
    }
    cout << largestDigit;

    for(int i = halfPalIndex; i >= 1; i--)
        cout << halfPal[i];
    cout << endl;

    //Sfarsit punct b

    //Inceput punct c
    n = 1;

    while(sum <= k){
        if(sum == k){
            n--;
            sumExists = true;
            break;
        } else {
            firstKOfNGroup = (n * (n - 1)) / 2;
            sum = (firstKOfNGroup + n) * (firstKOfNGroup + n) - firstKOfNGroup * firstKOfNGroup;
            n++;
        }
    }

    if(sumExists)
        cout << n;
    else
        cout << 0;

    //Sfarsit punct c
    return 0;
}
