#include <iostream>
#include <cstring>

using namespace std;

int strpozitie (char v[20], char a)
{
    int n=strlen(v);
    for (int i=0; i<n; i++)
        if (a==v[i]) return i+2;
}

int main()
{
    int n, i, p1, p2, p3, px;
    char v[20]="23456789TJQKA";
    char a, b, c, x;
    cin >> n;
    cin >> a;
    cin >> b;
    cin >> c;
    i=0;
    while (n < 99)
    {
        cin >> x;
        p1=strpozitie(v, a);
        p2=strpozitie(v, b);
        p3=strpozitie(v, c);
        px=strpozitie(v, x);
        if (i%2==0) if ((p1 >= p2) && (p1 >= p3)) {if (p1==9) a=x;
                                                       else if (p1==10) { n=n-10; a=x; }
                                                            else if (p1==14) if (n+p1 < 99) { a=x; n=n+14; }
                                                                             else { a=x; n=n+1; }
                                                                 else { n=n+p1; a=x; } }
                         else if ((p2 >= p3) && (p2 >= p1)) {if (p2==9) b=x;
                                                             else if (p2==10) { n=n-10; b=x; }
                                                                  else if (p2==14) if (n+p2 < 99) { b=x; n=n+14; }
                                                                                   else { b=x; n=n+1; }
                                                                       else { n=n+p2; b=x; } }
                              else {if (p3==9) c=x;
                                    else if (p3==10) { n=n-10; c=x; }
                                         else if (p3==14) if (n+p3 < 99) { c=x; n=n+14; }
                                                          else { c=x; n=n+1; }
                                              else { n=n+p3; c=x; } }
        else if (px==9) n=n;
                else if (px==10) n=n-10;
                     else if (px==14) if (n+px < 99) n=n+14;
                                      else n=n+1;
                          else n=n+p3;
        i++;
    }
    cout << n;
    if (i % 2==0) cout<<" dealer";

        else cout<<" player";

    return 0;
}
