#include "Apartament.h"
#include "Casa.h"
#include<fstream>
int main()
{
    std::ifstream f("date.in");
    f>>Locuinta::pret>>Casa::pret_curte;
    //Locuinta a;
    Apartament b;
    Casa c;
    f>>b>>c;
    std::cout<<b<<c<<b.cost()<<" "<<c.cost();
    return 0;
}
