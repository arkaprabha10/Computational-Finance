import random
import numpy as np
import matplotlib.pyplot as plt
import math
import pandas as pd


s0,k=input().split()
mu,sigma = input().split()
t,runs,seed = input().split()
s0=float(s0)
k=float(k)
mu=float(mu)
sigma=float(sigma)
t=float(t)
runs=int(runs)
seed=float(seed)


N=1
r=mu
random.seed(seed)
t=t*30
x_axis=np.linspace(0,t,int(t*N))
# option_price_pred = np.zeros(len(x_axis))
s_final=[]
s=np.zeros(int(t*N))        
for j in range(runs):
    ans=np.zeros(int(t*N))
    for i in range(1,int(t*N)):
        ans[i]=ans[i-1]+random.normalvariate(0,1)
    for i in range(int(t*N)):
        s[i]=s[i] + s0*math.exp((mu-sigma*sigma/2)*x_axis[i] + sigma*ans[i])
    s_final.append(s[-1])
s=s/runs
# print(s)
# print(runs)
option_price_pred = np.zeros(len(s))
for i in range(len(x_axis)):
    option_price_pred[i] = option_price_pred[i] + math.exp(-r * (t-x_axis[i]))*max(s[i] - k,0)
    print(option_price_pred[i])

