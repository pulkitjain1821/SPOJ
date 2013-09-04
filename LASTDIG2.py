import sys
t = int(raw_input())
l = [[0,0,0,0],[1,1,1,1],[2,4,8,6],[3,9,7,1],[4,6,4,6],[5,5,5,5],[6,6,6,6],[7,9,3,1],[8,4,2,6],[9,1,9,1]]
for i in  range (0,t):
	a,b = map(int,sys.stdin.readline().split())
	a=a%10;
	if b==0:
		print(1)
	else:	
		print(l[a][(b+3)%4])
