#include <iostream>
#include "List.h"

using namespace std;

int main()
{
    List<int> L;
    L.print();
	L.addHead(30);
	L.print();
	L.addHead(13);
	L.print();
	L.addHead(40);
	L.print();
	L.addHead(50);
	L.print();
	List<int> N(L);
	N.print();

	List<int> R;
	R.print();
	if(R.empty())
		cout << "List R empty" << endl;

	L.delHead();
	L.print();
	L.delHead();
	L.print();
	if(L.empty())
		cout << "List L empty" << endl;

	else{
		cout << "List L contains " << L.length() << " nodes" << endl;
		cout << "Head element of list L is: " << L.headElement() << endl;
	}
	N.print();
	if(N.empty())
		cout << "List N empty" << endl;

	else{
		cout << "List N contains " << N.length() << " nodes" << endl;
		cout << "Head element of list N is: " << N.headElement() << endl;
	}

    return 0;
}
