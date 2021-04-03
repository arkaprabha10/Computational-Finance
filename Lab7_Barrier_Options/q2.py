import random
# import numpy as np
import math


S0, K, B, T = input().split()
r, sigma = input().split()
N, s = input().split()

S0 = int(S0)
K = int(K)
B = int(B)
T =int(T)
r = float(r)
sigma  = float(sigma)
N = int(N)
s = int(s)
# print(S0,K,B,T,r,sigma,N,s)
random.seed(s)

mean = (r - 0.5*sigma**2)/360
sd = sigma / math.sqrt(360)

# down_in = np.zeros(N)
# down_out = np.zeros(N)

down_in = 0
down_out = 0


for i in range(N):
    flag1 = 0
    flag2 = 1
    flag1_1=0
    flag2_1=1
    s_d_in = S0
    s_d_in1 = S0 
    
    for j in range(1,T*30):
        temp = random.gauss(mean, sd)
        s_d_in = s_d_in*math.exp(temp)
        s_d_in1 = s_d_in1*math.exp(2*mean-temp)
        
        if(s_d_in<=B):
            flag1=1
            flag2=0
        if(s_d_in1<=B):
            flag1_1=1
            flag2_1=0
    temp1 = abs(0.5*math.exp(-r)*(flag1*max((s_d_in-K),0.0) + flag1_1*max(s_d_in1-K,0.0)))
    temp2 =  abs(0.5*math.exp(-r)*(flag2*max((s_d_in-K),0.0) + flag2_1*max(s_d_in1-K,0.0)))
    print(temp1)
    print(temp2)
    down_in = down_in + temp1
    down_out = down_out + temp2
print(down_in/N)
print(down_out/N)
