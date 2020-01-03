#include <iostream>
#include "btree.h"

int main()
{
	BTree btree(3);
	btree.insert(10);
	btree.insert(20);
	btree.insert(30);
	btree.insert(40);
	btree.insert(50);
	btree.insert(60);
	btree.insert(70);
	btree.insert(80);
	btree.insert(90);

	std::cout << "Tree traversal: ";
	btree.traverse();
	std::cout << '\n';

	int nKey = 30;
	std::cout << nKey << ' ' << (btree.search(nKey) ? "is" : "is not") << " present in tree\n";

	nKey = 15;
	std::cout << nKey << ' ' << (btree.search(nKey) ? "is" : "is not") << " present in tree\n";
}
