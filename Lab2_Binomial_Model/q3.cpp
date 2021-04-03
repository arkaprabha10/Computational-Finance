

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
    vector<double>temp,temp1,bank,stock;
    print_value(s0,u,d,n+1,x,k);
    // cout<<r<<endl; 
    // for(int i=0;i<x.size();i++)
    //     cout<<x[i]<<" ";
    // cout<<endl;
    for(int i=0;i<=n;i++)
    {   if(i==0)
        {
            for(int j=0;j<x.size();j++)
            {
                if(k-x[j]>0)
                {
                    temp.push_back(k-x[j]);
                    temp1.push_back(k-x[j]);
                }
                else
                {
                    temp.push_back(0);
                    temp1.push_back(0);
                }
            }
        }
        else
        {
            for(int j=0;j<x.size()-1;j+=2)
            {   double val=(qd*x[j]+qu*x[j+1])/(1+r);
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
    int k1=0;
    for(int i=n;i>=0;i--)
    {   x.clear();
        temp.clear();
       
        for(int j=pow(2,i)-1;j>=0;j--)
        {
            temp.push_back(temp1[k1+j]);
            // cout<<temp1[k1+j]<<" ";
        }   
        print_value(s0,u,d,i+1,x,k);
        // cout<<x.size()<<" "<<temp.size()<<" ";
        for(int j=0;j<temp.size()-1;j+=2)
        {   
            // cout<<temp[j]<<" "<<temp[j+1]<<" "<<x[temp.size()-1-j]<<" "<<x[temp.size()-2-j]<<" ";
            
            double delta=(temp[j]-temp[j+1])/(x[temp.size()-1-j]-x[temp.size()-2-j]);
            double bank_val=(temp[j]-(delta*x[temp.size()-1-j]))/(1+r);
            // cout<<x[temp.size()-1-j]<<" "<<temp[j]<<" ";
            // cout<<bank<<" ";
            // cout<<delta<<" ";
            stock.push_back(delta);
            bank.push_back(bank_val);
                    
        }
        temp.clear();
        x.clear();
        k1+=pow(2,i);
        // cout<<endl;
    }
    k1=stock.size()-1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<pow(2,i);j++)
        {   if(stock[k1-j]==-0.0)
                stock[k1-j]=0;
            cout<<fixed<<setprecision(6)<<stock[k1-j]<<" ";
        }
        k1-=pow(2,i);
        cout<<endl;
    }
    k1=bank.size()-1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<pow(2,i);j++)
        {
            if(bank[k1-j]==-0.0)
                bank[k1-j]=0;
            cout<<fixed<<setprecision(6)<<bank[k1-j]<<" ";
        }
        k1-=pow(2,i);
        cout<<endl;
    }
    return 0;
    
}
