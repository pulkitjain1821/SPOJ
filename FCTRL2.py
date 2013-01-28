import sys;
def fact(x):
    res = 1
    for i in range (1,x+1):
        res=res*i
    return res;

t = int(raw_input());
for i in range (0,t):
    print fact(int(raw_input()));
