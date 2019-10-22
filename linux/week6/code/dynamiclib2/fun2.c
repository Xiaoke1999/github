int max(int *a,int n)
{
	int max;
	max=a[0];
	for(int i=0;i<n;i++)
		if(a[i]>max)
			max=a[i];
		return max;

}
int sum(int *a,int n)
{
	int sum=0;
   	for(int i=0;i<n;i++)
			sum+=a[i];
	return sum;
}

