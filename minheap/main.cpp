#include <iostream>
#include "nodoh.h"
#include "heap.h"
#include "minheap.cpp"

using namespace std;

int main()
{
	Heap<int> mh;
	mh.insert(5);
	mh.insert(6);
	mh.insert(2);
	mh.insert(7);
	mh.insert(8);
	mh.insert(17);
	mh.insert(18);
	return 0;
}
