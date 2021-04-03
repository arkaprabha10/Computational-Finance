import random

n1,n2,s=input().split()
n1=int(n1)
n2=int(n2)
s=int(s)
random.seed(s)
count=0

for i in range(n1):
    pos1=0
    pos2=0
    for j in range(n2):
        val1=random.randint(0,1)
        val2=random.randint(0,1)
        if(val1==0):
            pos1=pos1+1
            if(val2==0):
                pos2=pos2+1
            else:
                pos2=pos2-1
        else:
            pos1=pos1-1
            if(val2==0):
                pos2=pos2+1
            else:
                pos2=pos2-1
        print(str(val1)+" "+str(val2))
        if(pos1==0 and pos2==0):
            count=count+1
            break 
print()
print(count/n1)

