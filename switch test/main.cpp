#include <iostream>

using namespace std;

int main()
{
    int x;
    cin>>x;
    switch (x){
        case 1:
            x++;
            cout<<"case 1";
            break;
        case 2:
            x--;
            cout<<"case 2";
            break;
        default :
            cout<<"Default";
            cout<<"Default check";
            break;
    }
    return 0;
}
