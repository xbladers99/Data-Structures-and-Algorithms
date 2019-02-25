#include <iostream>
using namespace std;
#include<algorithm>

int main() {
	
	cout<<"enter the no. of denominations"<<endl;
	int n;
	cin>>n;
	int a[n]={0};
	cout<<"enter the denomiantions "<<endl;
	for(int i=0;i<n;i++)
	{
	    cin>>a[i];
	}
	
	sort(a,a+n,greater<int>());
	
	int b[n]={0};
	
	int money;
	cout<<"enter the amount"<<endl;
	cin>>money;
	
	int j=0;
	
	while(money!=0)
	{
	    if(money>=a[j])
	    {
	        int x=money/a[j];
	        b[j]=x;
	        money=money%a[j];
	        j++;
	    }
	    else
	    {
	        j++;
	    }
	}
	
	for(int i=0;i<n;i++)
	{
	    cout<<a[i]<<" -> "<<b[i]<<endl;
	}
	
	return 0;
}