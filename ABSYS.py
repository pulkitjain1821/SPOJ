import sys;

t = int(raw_input());
for i in range (0,t):
    u,x,y,z = map(int,sys.stdin.readline().split())
    
    n = int((2*z)/(x+y))
    d = (y-x)/(n-5)
    a = x-(2*d)
    print n
    for j in range(0,n):
        sys.stdout.write(a+j*d)
        sys.stdout.write(' ')
    print' '
