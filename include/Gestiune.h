#ifndef GESTIUNE_H
#define GESTIUNE_H
#include"Apartament.h"
#include"Casa.h"
#include<vector>
template <class T>
class Gestiune{
private:
protected:
    std::vector<T> lista;
public:
    Gestiune();
    Gestiune(T *l, int n);
    Gestiune(const Gestiune<T> &G2);
    ~Gestiune();
    template <class Q>
    friend std::istream& operator >> (std::istream &input,Gestiune<Q> &a);
    template <class Q>
    friend std::ostream& operator << (std::ostream &output,Gestiune<Q> &a);
    Gestiune<T>& operator = (Gestiune<T> &a);
    std::ostream& display(std::ostream &output);
};
/*template <>
class Gestiune<char*>{
private:
protected:
    std::vector<char*> lista;
public:
    Gestiune();
    Gestiune(char **l, int n);
    Gestiune(const Gestiune<char*> &G2);
    ~Gestiune();
    template <>
    friend std::istream& operator >> (std::istream &input,Gestiune<char*> &a);
    template <>
    friend std::ostream& operator << (std::ostream &output,Gestiune<char*> &a);
    void operator = (Gestiune<char*> &a);
    std::ostream& display(std::ostream &output);
};*/
template<class T>
Gestiune<T>::Gestiune()
{
    lista.clear();
}
template<class T>
Gestiune<T>::Gestiune(T *l, int n)
{
    for(int i=0;i<n;i++)
        lista.push_back(l[i]);
}
template<class T>
Gestiune<T>::Gestiune(const Gestiune<T> &G2)
{
    lista=G2.lista;
}
template<class T>
Gestiune<T>::~Gestiune()
{
    lista.clear();
}
template<class T>
std::istream& operator >> (std::istream &input,Gestiune<T> &a)
{
    T x;
    int n;
    input>>n;
    for(int i=0;i<n;i++)
    {
        input>>x;
        a.lista.push_back(x);
    }
}
template<class T>
std::ostream& operator << (std::ostream &output,Gestiune<T> &a)
{
    return a.display(output);
}
template<class T>
Gestiune<T>& Gestiune<T>::operator = (Gestiune<T> &a)
{
    if(&a==this)
        return a;
    lista.clear();
    lista=a.lista;
}
template<class T>
std::ostream& Gestiune<T>::display(std::ostream &output)
{
    for(T i:lista)
        output<<i<<"\n";
    return output;
}
#endif // GESTIUNE_H
