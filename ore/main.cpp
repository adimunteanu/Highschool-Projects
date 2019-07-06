#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("ore.in");
ofstream fout("ore.out");

struct timp {
    int h;
    int m;
    int s;
} t1, t2, tf;

int main()
{
    fin >> t1.h >> t1.m >> t1.s;
    fin >> t2.h >> t2.m >> t2.s;
    fout << t1.h << ": " << t1.m << ": " << t1.s << endl;
    fout << t2.h << ": " << t2.m << ": " << t2.s << endl;
    fout << t1.h * 3600 + t1.m * 60 + t1.s << endl;
    fout << t2.h * 3600 + t2.m * 60 + t2.s << endl;
    if(t1.s + t2.s > 59){
        tf.s = t1.s + t2.s - 60;
        tf.m += 1;
    }
    if(t1.m + t2.m + tf.m > 60){
        tf.m += t1.m + t2.m - 60;
        tf.h +=1;
    }
    tf.h += t1.h + t2.h;
    fout << tf.h << ": " << tf.m << ": " << tf.s << endl;
    return 0;
}
