#include<stdio.h>
int main()
{
	int a1,a2,a3 = -1;
	while(1)
		{
		 scanf("%d %d %d",&a1,&a2,&a3);
		 if(a3==0 && a2==0 && a1==0)
		 	break;
		 if(a3-a2 == a2-a1 )
		 	printf("AP %d\n",a3+a3-a2);
		 else
		 	printf("GP %d\n",a3*a3/a2);
		}
	return 0;	
}

