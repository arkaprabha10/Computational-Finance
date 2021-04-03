#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
// #include <iomanip.h>
#include <iomanip>

using namespace std;

void print_value(double s0,double u,double d,int n)
{
    if(n==0)
        return;
    if(n==1)
        cout<<fixed<<setprecision(6)<<s0<<" ";
    else if(n>1)
    {
        print_value(s0*d,u,d,n-1);
        print_value(s0*u,u,d,n-1);
    }
}

void func(double s0,double u,double d,int n)
{
     for(int i=1;i<=n+1;i++)
      {
          print_value(s0,u,d,i);
          cout<<endl;
      }  
    return;   
}

int main()
{
    double s0,u,d;
    int n;
    cin>>s0>>d>>u>>n;
    func(s0,u,d,n);
    return 0;
    
}
