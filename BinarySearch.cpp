#include<iostream.h>

template<class Type>
int BinarySearch(Type a[],const Type& x,int n)
{
	int left = 0;
	int right = n-1;
	while(left<=right)
	{
		int middle = (left + right)/2;
		if(x == a[middle])
			return middle;
		if(x > a[middle])
			left = middle + 1;
		else
			right = middle - 1;
	}
	return -1;
}
void main()
{
	int a[]={1,2,3,4,5,6,7,9};
	cout<<BinarySearch(a,5,8)<<endl;
}