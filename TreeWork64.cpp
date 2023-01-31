#include "pt4.h"
#include <string>
#include <fstream>
using namespace std;

int MaxLVL = 0;
int j = 0;

void searchMaxLvl(PNode p, int k)
{
    if (!p) return;

    if (k > MaxLVL) MaxLVL = k;

    searchMaxLvl(p->Left, k+1);
    searchMaxLvl(p->Right, k+1);
}

void searchLvl(PNode P, int LVL, int k, ofstream& fout)
{
    if (!P) return;

    if (LVL == k) 
    {
        j == 0 ? fout << P->Data : fout << ' ' << P->Data;
        j += 1;
        return;
    }

    searchLvl(P->Left, LVL, k+1,fout );
    searchLvl(P->Right, LVL, k+1,fout);
}


void Solve()
{
    Task("TreeWork64");
    PNode P;
    string name;

    pt >> P >> name;

    ofstream fout(name.c_str());

    searchMaxLvl(P, 0);

    for (int i = MaxLVL; i >= 0; i--)
    {
        searchLvl(P, i, 0, fout);
        j = 0;
        fout << '\n';
    }

    fout.close();
}
