#include "Gestiune.h"
#include<fstream>
int main()
{
    std::ifstream f("date.in");
    f>>Locuinta::pret>>Casa::pret_curte;
    Gestiune<Casa> l;
    f>>l;
    Gestiune<Casa> n=l,m;
    m=n;
    std::cout<<l<<n<<m;
    return 0;
}
