#include<iostream.h>

template<class Type>
inline void Swap(Type& a,Type& b)
{
	Type temp=a;
	a=b;
	b=temp;
}
template<class Type>
int partition(Type a[], int p, int r)
{
	int i = p,j = r + 1;
	Type x = a[p];
	while(true)
	{
		while(a[++i] <x && i < r);
		while(a[--j] > x);
		if(i >= j)
			break;
		Swap(a[i] , a[j]);
	}
	a[p] = a[j];
	a[j] = x;
	return j;
}

template<class Type>
void QuickSort(Type a[], int p, int r)
{
	if(p<r)
	{
		int q = partition(a, p, r);
		QuickSort(a, p, q-1);
		QuickSort(a, q+1, r);
	}
}

void main()
{
	int a[]={5,9,50,1,4,3,19,55,94,45,17,71};
	QuickSort(a,0,11);
	for(int i=0;i<12;i++)
		cout<<a[i]<<" ";
}