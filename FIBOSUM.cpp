#include<cstdio>
typedef long long LL;
const int MOD =(int)(1e9+7);
void multiply(LL a[2][2],LL b[2][2])
{
	LL c[2][2];
	for (int i=0;i<2;i++)
	for (int j=0;j<2;j++)
	{
		c[i][j]=0;
		for (int k=0;k<2;k++)
			c[i][j]=(c[i][j]+a[i][k]*b[k][j])%MOD;
	}
	for(int i=0;i<2;i++)for(int j=0;j<2;j++)a[i][j]=c[i][j];
}
LL solve(int X)
{
	if (X==-1) return 0;
	if (X<=2)return X;
	LL x[2][2],y[2][2];
	//F[i]=F[i-1]+F[i-2]
	//F[i-1]=F[i-1]
	x[0][0]=x[0][1]=x[1][0]=1;
	x[1][1]=0;
	y[0][0]=y[1][1]=1;
	y[1][0]=y[0][1]=0;
	// Fn        A^(n-2)+2 *| 1 |
	// Fn-1                 | 1 |
	while(X>0)
	{
		if (X&1)
			multiply(y,x);
		multiply(x,x);
		X>>=1;
	}
	return ((y[0][0]+y[0][1])%MOD-1+MOD)%MOD;
}
int main()
{
	// 1,1,2,3,5,8,13,21,34,55,89
	// 1,2,4,7,12,20,33,54,88
	// S[i]=S[i-1]+S[i-2]+1
	// S[i]=F[i+2]-1
	int t,I,J;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&I,&J);
		//printf("%lld %lld\n",solve(J),solve(I-1));
		printf("%lld\n",(solve(J)-solve(I-1)+MOD)%MOD);
	}
	return 0;	
}
