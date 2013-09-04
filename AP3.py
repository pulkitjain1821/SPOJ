import math, sys 
T = input()
for line in sys.stdin:
        l = line.split()
        x, y, z = int(l[0]), int(l[1]), int(l[2])
        b = 7.0*x + 5.0*y + 2.0*z
        di = math.sqrt(b*b - 48.0*z*(x+y))
        n1 = int(round((b+di)/(2*(x+y))))
        n2 = int(round((b-di)/(2*(x+y))))#print (n1, n2)
        d1 = d2 = a1 = a2 = 0
        if n1 >= 7:
                d1 = (y-x)/(n1-6)
                a1 = x - 2*d1
        if n2 >= 7:
                d2 = (y-x)/(n2-6)
                a2 = x - 2*d2
        n = 0
        d = 0
        a = 0
        if (n1*(x+y+d1) == 2*z and a1>0 and a1 + (n1-1)*d1 > 0):
                d = d1
                n = n1
                a = a1
        else:
                d = d2
                a = a2
                n = n2
        out = ""
        f = a;
        print (n)
        for i in range(n):
                X = f
                f = f + d
                out += str(X) + " "
        print(out[:-1])

