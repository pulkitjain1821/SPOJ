#include <cstdio>
using namespace std;
/********qsort code modified. Original code used from internet***************/
void q_sort(int numbers[],int nums[], int left, int right)
{
  int pivot_1,pivot_2, l_hold, r_hold;
 
  l_hold = left;
  r_hold = right;
  pivot_1 = numbers[left];
  pivot_2 = nums[left];
  while (left < right)
  {
    while ((numbers[right] >= pivot_1) && (left < right))
      right--;
    if (left != right)
    {
      numbers[left] = numbers[right];
      nums[left] = nums[right];
      left++;
    }
    while ((numbers[left] <= pivot_1) && (left < right))
      left++;
    if (left != right)
    {
      numbers[right] = numbers[left];
      nums[right] = nums[left];
      right--;
    }
  }
  numbers[left] = pivot_1;
  nums[left] = pivot_2;
  pivot_1 = left;
  pivot_2 = right;
  left = l_hold;
  right = r_hold;
  if (left < pivot_1)
    q_sort(numbers, nums,left, pivot_1-1);
  if (right > pivot_1)
    q_sort(numbers, nums,pivot_1+1, right);
}


int main()
{
	int t;
	scanf("%d",&t);
	while(t)
		{
			t--;
			int n;
			scanf("%d",&n);
			int s[n];
			int e[n];
			for(int i=0;i<n;i++)
				scanf("%d%d",&s[i],&e[i]);
		
			q_sort(e,s,0,n-1);
		
			int ans=0;
			int prev=0;
			for(int i=0;i<n;i++)
				if(prev<=s[i])
					{
						ans++;
						prev = e[i];
					}
			printf("%d\n",ans);
		}
	return 0;	
}
