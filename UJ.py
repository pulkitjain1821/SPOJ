import sys
for line in sys.stdin:
    x,y = line.split(' ');
    x = int(x);
    y = int(y);
    if(x==0 and y==0):
        break
    print(pow(x,y))
