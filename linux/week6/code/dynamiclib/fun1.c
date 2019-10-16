int MAX(int *a,int n)
{
	int max;
	max=a[0];
	for(int i=0;i<n;i++)
		if(a[i]>max)
			max=a[i];
		return max;
}
