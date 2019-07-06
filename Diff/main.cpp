#include <bits/stdc++.h>

using namespace std;

ifstream fin("input.txt");

char a[256], b[256], a2b[256], b2a[256], common[256];
int rec[4][150];
int a2bL2RLen = 0, b2aL2RLen = 0, a2bR2LLen = 0, b2aR2LLen = 0;
int maxLengths[120];

char* removePair(char c[])
{
    for(int i = 0; i < strlen(c) - 1; i++)
        if(c[i] == c[i+1]){
            strcpy(c + i, c + i + 1);
            i--;
        }
    return c;
}

void addToRecurrence(char word[], int recIndex)
{
    for(int i = 0; i < strlen(word); i++)
        rec[recIndex][word[i] - 96]++;
}

int main()
{
    for(int index = 1; index <= 5; index++)
    {
        fin >> a >> b;
        char a2bL2R[256], a2bR2L[256], b2aL2R[256], b2aR2L[256];
        int lenA = strlen(a), lenB = strlen(b);
        bool ok1 = 0, ok2 = 0, ok3 = 0, ok4 = 0; // dont remove this pls
        char auxB[256];
        strcpy(auxB, b);
        for(int i = 0; i < lenA; i++)
            for(int j = 0; j < lenB; j++)
                if(a[i] == b[j]){
                    ok1 = true;
                    a2bL2R[a2bL2RLen] = b[j];
                    a2bL2RLen++;
                    a2bL2R[a2bL2RLen] = '\0';
                    strcpy(b, b+j+1);
                    lenB = strlen(b);
                    break;
                }
        strcpy(b, auxB);
        lenB = strlen(b);
        for(int i = lenA - 1; i >= 0; i--)
            for(int j = lenB - 1; j >= 0; j--)
                if(a[i] == b[j]){
                    ok2 = true;
                    a2bR2L[a2bR2LLen] = b[j];
                    a2bR2LLen++;
                    a2bR2L[a2bR2LLen] = '\0';
                    strcpy(b + j, b + lenB);
                    lenB = strlen(b);
                    break;
                }
        strcpy(b, auxB);
        lenB = strlen(b);
        strcpy(auxB, a);
        for(int i = 0; i < lenB; i++)
            for(int j = 0; j < lenA; j++)
                if(b[i] == a[j]){
                    ok3 = true;
                    b2aL2R[b2aL2RLen] = a[j];
                    b2aL2RLen++;
                    b2aL2R[b2aL2RLen] = '\0';
                    strcpy(a, a+j+1);
                    lenA = strlen(a);
                    break;
                }
        strcpy(a, auxB);
        lenA = strlen(a);
        for(int i = lenB - 1; i >= 0; i--)
            for(int j = lenA - 1; j >= 0; j--)
                if(b[i] == a[j]){
                    ok4 = true;
                    b2aR2L[b2aR2LLen] = a[j];
                    b2aR2LLen++;
                    b2aR2L[b2aR2LLen] = '\0';
                    strcpy(a + j, a + lenA);
                    lenA = strlen(a);
                    break;
                }
        strcpy(a, auxB);
        if(ok1 || ok2 || ok3 || ok4){
            sort(a2bL2R, a2bL2R + strlen(a2bL2R));
            sort(a2bR2L, a2bR2L + strlen(a2bR2L));
            sort(b2aL2R, b2aL2R + strlen(b2aL2R));
            sort(b2aR2L, b2aR2L + strlen(b2aR2L));
            strcpy(a2bL2R, removePair(a2bL2R));
            strcpy(a2bR2L, removePair(a2bR2L));
            strcpy(b2aL2R, removePair(b2aL2R));
            strcpy(b2aR2L, removePair(b2aR2L));

            addToRecurrence(a2bL2R, 0);
            addToRecurrence(a2bR2L, 1);
            addToRecurrence(b2aL2R, 2);
            addToRecurrence(b2aR2L, 3);

        }
        bool hasCommon = false;
        for(int i = 1; i <= 26; i++)
            if(rec[0][i] == rec[1][i] && rec[1][i] == rec[2][i] && rec[2][i] == rec[3][i] && rec[0][i] == 1){
                cout << char(i + 96);
                hasCommon = true;
            }
        if(!hasCommon)
            cout << "NONE";
        cout << endl;
        for(int i = 0; i <= 3; i++)
            for(int j = 1; j <= 26; j++)
                rec[i][j] = 0;
        a2bL2RLen = 0;
        a2bR2LLen = 0;
        b2aL2RLen = 0;
        b2aR2LLen = 0;
    }
    return 0;
}
