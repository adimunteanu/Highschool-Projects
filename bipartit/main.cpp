#include <fstream>
#include <iostream>

using namespace std;

ifstream fin("bipartit.in");
ofstream fout("bipartit.out");

int muchii[101][2], n, a[101], b[101], k, l = 0, m;
bool global_is_bipartit = true;

int main()
{
    fin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        fin >> muchii[i][0] >> muchii[i][1];
    }

    fin >> k;
    for(int i = 1; i <= k; i++){
        fin >> a[i];
    }

    for(int i = 1; i <= n ; i++){
        bool is_in_a = false;
        for(int j = 1; j <= k; j++)
            if(a[j] == i)
                is_in_a = true;
        if(!is_in_a){
            l++;
            b[l] = i;
        }
    }

    for(int i = 1; i <= m; i++)
    {
        bool has_first_end_in_a = false;
        for(int j = 1; j <= k; j++)
            if(muchii[i][0] == a[j])
            {
                has_first_end_in_a = true;
                bool is_bipartit = false;
                for(int x = 1; x <= l; x++){
                    if(muchii[i][1] == b[x]){
                        is_bipartit = true;
                        break;
                    }
                }

                if(!is_bipartit)
                    global_is_bipartit = false;
            }
        if(!has_first_end_in_a)
            for(int j = 1; j <= l; j++)
                if(muchii[i][0] == b[j])
                {
                    bool is_bipartit = false;
                    for(int x = 1; x <= k; x++){
                        if(muchii[i][1] == a[x]){
                            is_bipartit = true;
                            break;
                        }
                    }

                    if(!is_bipartit)
                        global_is_bipartit = false;
                }
    }

    if(global_is_bipartit)
        cout << "DA";
    else
        cout << "NU";
    return 0;
}
