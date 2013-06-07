import sys;

def func (num):
    if(num-2 >= 0):
        return num + num-2
    else:
        return num
    
while 1:
    try:
        k = raw_input()
    except EOFError:
        break
    print func(int(k))

