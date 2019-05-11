#include "Gestiune.h"
#include<fstream>
int main()
{
    std::ifstream f("date.in");
    f>>Locuinta::pret>>Casa::pret_curte;
    Gestiune<Apartament> l;
    f>>l;
    Gestiune<Apartament> n=l,m;
    m=n;
    std::cout<<l<<n<<m;
    return 0;
}
