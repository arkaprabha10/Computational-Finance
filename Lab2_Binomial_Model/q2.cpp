

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

vector<double>x;
void print_value(double s0,double u,double d,int n,vector<double>&x,double k)
{
    if(n==0)
        return ;
    if(n==1)
    {
        // cout<<fixed<<setprecision(6)<<s0<<" ";
        x.push_back(s0);
    }    
    else if(n>1)
    {
        print_value(s0*d,u,d,n-1,x,k);
        print_value(s0*u,u,d,n-1,x,k);   
    }
    return ;
}



int main()
{
    double s0,u,d,k,r,qu,qd;
    int n;
    cin>>s0>>d>>u>>k>>r>>n;
    qu=(d-(1+r))/(d-u);
    qd=1-qu;
    vector<double>temp,temp1;
    print_value(s0,u,d,n+2,x,k);
    // cout<<r<<endl; 
    for(int i=0;i<x.size();i++)
        cout<<x[i]<<" ";
    cout<<endl;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<x.size()-1;j+=2)
        {   double val=(qd*x[j]+qu*x[j+1])/(1+r);
            // cout<<val<<" ";
            if(i==0)
            {
                if(val-k>0)
                {
                    temp.push_back(val-k);
                    temp1.push_back(val-k);
                }
                else
                {
                    temp.push_back(0);
                    temp1.push_back(0);
                }
            }
            else
            {
                temp.push_back(val);
                temp1.push_back(val);
            }
            
            // cout<<(qu*x[j]+qd*x[j+1])/(1+r)<<" ";
        }
        x.clear();
        x=temp;
        temp.clear();
    }
    // for(int i=0;i<temp1.size();i++)
    //     cout<<temp1[i]<<" ";
    int k1=temp1.size()-1;
    for(int i=0;i<=n;i++)
    {
        for(int j=pow(2,i)-1;j>=0;j--)
        {
            cout<<fixed<<setprecision(6)<<temp1[k1-j]<<" ";
        }
        k1-=pow(2,i);
        cout<<endl;
    }
    return 0;
    
}
