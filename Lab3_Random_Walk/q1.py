import random

n,s=input().split()
n=int(n)
s=int(s)

random.seed(s)
count=0

for i in range(n):
    pos=0
    for j in range(10):
        val=random.randint(0,1)
        print(val)
        if(val==0):
            pos=pos+1
        else:
            pos=pos-1
        if(pos==4):
            count=count+1
            break
print()
print(count/n)