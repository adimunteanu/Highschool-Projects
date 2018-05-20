#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("snooker1.in");
ofstream fout("snooker1.out");

int a[1002];
int pctDan = 0;
int pctPaul = 0;
int lovitura;
bool turaLuiDan = true;
bool seLovesteBilaRosie = true;
int maxLovConsec = 0;
int lovConsec = 0;

int main()
{
    int n;
    fin >> n;
    for(int i = 1; i <= n; i++)
        fin >> a[i];
    for(int i = 1; i <= n; i++)
    {
        lovitura = a[i];
        if(lovitura > 0){
            lovConsec++;
            if(turaLuiDan){
                pctDan += lovitura;
            } else {
                pctPaul += lovitura;
            }
        } else {
            if(lovitura == 0){
                turaLuiDan = !turaLuiDan;
                if(lovConsec > maxLovConsec)
                    maxLovConsec = lovConsec;
                lovConsec = 0;
            }
            else {
                lovConsec = 0;
                if(turaLuiDan)
                    pctDan -= 5;
                else
                    pctPaul -= 5;
                turaLuiDan = !turaLuiDan;
            }
        }
    }
    if(pctDan > pctPaul)
        cout << 1 << endl;
    else
        cout << 2 << endl;
    cout << maxLovConsec;
    return 0;
}
