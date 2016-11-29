#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
	set<int> iset;
	iset.insert(5);
	iset.insert(9);
	iset.insert(1);
	iset.insert(8);
	iset.insert(3);

	cout<<"iset contains: ";
	
	set<int>::iterator it;
	for(it=iset.begin();it!=iset.end();it++)
		cout<<" "<<*it;
	cout<<endl;
	
	int searchfor;
	cin>>searchfor;
	if(binary_search(iset.begin(),iset.end(),searchfor))
		cout<<"found"<<searchfor<<endl;
	else
		cout<<"didn't find"<<searchfor<<endl;
	
	return 0;
}
