#include <bits/stdc++.h>

using namespace std;

ifstream fin("as2-test.txt");

char input[100000], output[100000];
struct
{
    int fr;
    char sir[10000];
} v[800];
int vIndex = 0;
int freq, rec[27], maxFreq = 0;

void deleteElement(int i)
{
    for(int j = i; j < vIndex; j++)
    {
        v[j].fr = v[j + 1].fr;
        strcpy(v[j].sir, v[j + 1].sir);
    }
    vIndex --;
}

void insertElement(int k, int frequency, char sir[])
{
    vIndex++;
    for(int i = vIndex; i > k; i--)
    {
        v[i].fr = v[i - 1].fr;
        strcpy(v[i].sir, v[i - 1].sir);
    }
    v[k].fr = frequency;
    strcpy(v[k].sir, sir);
}

int main()
{
    for(int index = 1; index <= 10; index++)
    {
        fin >> input >> freq;
        bool hasFoundOutput = false;
        for(int j = 0; j < strlen(input); j++){
            rec[input[j] - 64]++;
            if(rec[input[j] - 64] > maxFreq)
                maxFreq = rec[input[j] - 64];
        }
        for(int i = 1; i <= maxFreq; i++)
        {
            for(int j = 1; j <= 26; j++)
                if(rec[j] == i){
                    vIndex++;
                    v[vIndex].fr = i;
                    v[vIndex].sir[0] = char(j + 64);
                    v[vIndex].sir[1] = '\0';
                }
        }

        int vIndexMax = vIndex;

        while(vIndex > 1)
        {
            //Verificare
            for(int i = 1; i <= vIndex; i++)
                if(v[i].fr == freq && strstr(output, v[i].sir) == NULL){
                    hasFoundOutput = true;
                    strcat(output, v[i].sir);
                }
            //cout << output << endl;
            //Get first 2 elements
            int freq1 = v[1].fr;
            char sir1[1000];
            sir1[0] = '\0';
            strcpy(sir1, v[1].sir);

            int freq2= v[2].fr;
            char sir2[1000];
            sir2[0] = '\0';
            strcpy(sir2, v[2].sir);

            //Delete the first 2 elements;
            deleteElement(1);
            deleteElement(1);

            //Calculates the new element
            int finalFreq = freq1 + freq2;
            char finalSir[1000];
            finalSir[0] = '\0';
            strcat(finalSir, sir1);
            strcat(finalSir, sir2);

            sort(finalSir, finalSir + strlen(finalSir));


            //Finds the right position for the element created
            int k = 1;
            while(finalFreq > v[k].fr && k <= vIndex)
                k++;
            while(finalSir[0] > v[k].sir[strlen(v[k].sir) - 1] && finalFreq == v[k].fr && k <= vIndex)
                k++;

            //Inserts the element
            insertElement(k, finalFreq, finalSir);


        }

        sort(output, output + strlen(output));

        cout << index << ". ";
        if(hasFoundOutput){
            for(int i = 0; i < strlen(output); i++){
                if(i == strlen(output) - 1 && output[i - 1] != output[i])
                    cout << output[i];
                else
                    if(output[i] != output[i + 1])
                        cout << output[i];
            }
        } else
            cout << "NONE";
        cout << endl;
        //for(int j = 1; j <= vIndex; j++)
          //  cout << v[j].fr << v[j].sir << " ";
        //cout << endl;

        for(int j = 1; j <= vIndexMax; j++){
            v[j].fr = 0;
            v[j].sir[0] = '\0';
        }
        vIndex = 0;

        for(int j = 1; j <= 26; j++)
            rec[j] = 0;
        maxFreq = 0;
        input[0] = '\0';
        output[0] = '\0';
    }
    return 0;
}
