#include <iostream>

using namespace std;

string only_call_if_majorat(Date data)
{
    while(data.ora <= 24)
    { //Am pus asta aici pentru tine ;)
        if(data.ora != 24)
        {
            vreau_sa_beau_cu_fratii_mei(da_da_cu_fratii_mei);
            data.ora ++;
        }
        else
        {
            poti_fi_bagat_la_bulau = true;
            adu_tortu_si_sampania_ba = "acum";
            return "lma nebunul meu";
        }
    }
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
