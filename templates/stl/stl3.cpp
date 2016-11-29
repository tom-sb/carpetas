#include <iostream>
//#include <set>
//#include <algorithm>

using namespace std;

struct UScurrency
{
	int dollars;
	int cents;
};

/*UScurrency a={2,50};
UScurrency b={1,75};
UScurrency c=a+b;*/

/*UScurrency operator+ (const UScurrency o)
{
	UScurrency tmp={0,0};
	tmp.cents=cents + o.cents;
	tmp.dollars=dollars + o.dollars;

	if(tmp.cents>=100)
	{
		tmp.dollars+=1;
		tmp.cents-=100;
	}
	return tmp;	
	
}*/

UScurrency operator+(const UScurrency m,const UScurrency o)
{
	UScurrency tmp={0,0};
	tmp.cents=m.cents + o.cents;
	tmp.dollars=m.dollars + o.dollars;
	
	if(tmp.cents>=100)
	{
		tmp.dollars+=1;
		tmp.cents-=100;
	}
	return tmp;
}

ostream& operator<<(ostream &output,const UScurrency &o)
{
	output<<"$"<<o.dollars<<"."<<o.cents;
	return output;
}

UScurrency operator-(const UScurrency m,const UScurrency o)
{
	UScurrency tmp={0,0};
	tmp.cents=m.cents - o.cents;
	tmp.dollars=m.dollars - o.dollars;
	
	if(tmp.cents<=0)
	{
		tmp.dollars-=1;
		tmp.cents+=100;
	}
	return tmp;
}

int main()
{
	UScurrency a={2,50};
	UScurrency b={1,75};

	UScurrency c=a+b;
	cout<<c<<endl;

	UScurrency d=a-b;
	cout<<d<<endl;

	return 0;
}
