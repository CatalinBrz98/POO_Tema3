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
    Gestiune<T>& operator = (const Gestiune<T> &a);
    std::ostream& display(std::ostream &output);
};
template <>
class Gestiune<char*>{
private:
protected:
    std::vector<char*> lista;
public:
    Gestiune();
    Gestiune(char **l, int n);
    Gestiune(const Gestiune<char*> &G2);
    ~Gestiune();
    friend std::istream& operator >> (std::istream &input,Gestiune<char*> &a);
    friend std::ostream& operator << (std::ostream &output,Gestiune<char*> &a);
    Gestiune<char*>& operator = (const Gestiune<char*> &a);
    std::ostream& display(std::ostream &output);
};
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
    return input;
}
template<class T>
std::ostream& operator << (std::ostream &output,Gestiune<T> &a)
{
    return a.display(output);
}
template<class T>
Gestiune<T>& Gestiune<T>::operator = (const Gestiune<T> &a)
{
    if(&a==this)
        return *this;
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
//char* specialization
template<>
Gestiune<char*>::Gestiune()
{
    lista.clear();
}
template<>
Gestiune<char*>::Gestiune(char **l, int n)
{
    for(int i=0;i<n;i++)
    {
        char* aux=new char[strlen(l[i]+1);
        strcpy(aux,l[i]);
        lista.push_back(aux);
    }
}
template<>
Gestiune<char*>::Gestiune(const Gestiune<char*> &G2)
{
    for(char* i:G2.lista)
    {
        char* aux=new char[strlen(i)+1];
        strcpy(aux,i);
        lista.push_back(aux);
    }
}
template<>
Gestiune<char*>::~Gestiune()
{
    for(char* i:G2.lista)
        delete[] i;
    lista.clear();
}
template<>
std::istream& operator >> (std::istream &input,Gestiune<char*> &a)
{
    int n;
    char s[100];
    input>>n;
    for(int i=0;i<n;i++)
    {
        input>>s;
        char *aux=new char[strlen(s)+1];
        a.lista.push_back(aux);
    }
    return input;
}
template<>
std::ostream& operator << (std::ostream &output,Gestiune<char*> &a)
{
    return a.display(output);
}
template<>
Gestiune<char*>& Gestiune<T>::operator = (const Gestiune<char*> &a)
{
    if(&a==this)
        return *this;
    for(char* i:G2.lista)
        delete[] i;
    lista.clear();
    for(char* i:a.lista)
    {
        char* aux=new char[strlen(i)+1];
        strcpy(aux,i);
        lista.push_back(aux);
    }
}
template<char>
std::ostream& Gestiune<char*>::display(std::ostream &output)
{
    for(T i:lista)
        output<<i<<"\n";
    return output;
}
#endif // GESTIUNE_H
