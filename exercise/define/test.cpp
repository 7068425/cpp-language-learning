#include<iostream>
using namespace std;
#define fuck(a,b) a++; b++; for(int i=0; i<=10; i++) cout<<a<<" "<<b<<endl;
 
int main()
{
	int a=6,b=2; 
	fuck(a,b);
} 

#include<iostream>
using namespace std;
#define MAX(a,b) (a<b)? b:a 
 
int main(){
	int a=6,b=2; 
	int c=MAX(a,b);
	cout<<c<<endl;
} 

#define  M(y)  ((y)*(y)+3*(y))            /*宏定义*/
int k = M(5);             /*宏调用*/