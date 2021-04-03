import random
# import numpy as np
import math


S0, K, B, T = input().split()
r, sigma = input().split()
N, s = input().split()

S0 = float(S0)
K = float(K)
B = float(B)
T =int(T)
r = float(r)
sigma  = float(sigma)
N = int(N)
s = int(s)

random.seed(s)

mean = (r - 0.5*sigma**2)/360
sd = sigma / math.sqrt(360)


down_in = 0
down_out = 0

for i in range(N):
    flag1 = 0
    flag2 = 1
    s_d_in = S0
    s_d_out =S0
    
    for j in range(1,T*30):
        s_d_in = s_d_in*math.exp(random.gauss(mean, sd))
        if(s_d_in<=B):
            flag1=1
            flag2=0
    print(abs(max(flag1*(s_d_in-K),0)*math.exp(-r)))
    print(abs(max(flag2*(s_d_in-K),0)*math.exp(-r)))
    down_in = down_in + max(flag1*(s_d_in-K),0)*math.exp(-r)
    down_out = down_out + max(flag2*(s_d_in-K),0)*math.exp(-r)
print(down_in/N)
print(down_out/N)
