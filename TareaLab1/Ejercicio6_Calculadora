#include <iostream>

using namespace std;

int modulo(int a, int n)
{
    int q=a/n;
    int r= a-(q*n);
    if(r<0)
        return n-r;
    return r;

}

int euclides(int a, int b)
{
    int r;
    while(b!= 0)
    {
        r= modulo(a,b);
        a=b;
        b=r;
    }
    return a;
}
int modinv( int u,int v)
{
    int inv, u1, v1, t1, t3, q;
    int it;
    u1 = 1;
    v1 = 0;
    it = 1;
    while (v != 0)
    {
        q = u / v;
        t3 = modulo(u,v);
        t1 = u1 + q * v1;

        u1 = v1;
        v1 = t1;
        u = v;
        v = t3;
        it = -it;
    }

    if (u != 1)
        return 0;
    if (it < 0)
        inv = v - u1;
    else
        inv = u1;
    return inv;
}

int operaciones(int a, char c, int b, int mod)
{
    int resul, sum;
    switch(c)
    {
    case '*':
        sum=a*b;
        break;
    case '+':
        sum=a+b;
        break;
    case '-':
        sum=a-b;
        break;
    }
    resul=modulo(sum, mod);
    return resul;

}

int main()
{
    int a, b, m;
    char op;
    cout<< "1. inverso modular"<<endl;
    cout<<"2. operaciones " <<endl;
    int resp;
    cin>>resp;
    if(resp==1)
    {
        cin>>a;
        cout<<"modulo:";
        cin>>b;
        cout<< "inverso: " << modinv(a,b);
    }
    else if(resp==2)
    {
        cin>> a;
        cin>>op;
        cin>>b;
        cout<< "modulo: ";
        cin>>m;
        cout<<operaciones(a,op,b,m)<<" modulo " << m;
    }

}
