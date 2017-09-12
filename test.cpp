#include "bplus_tree.h"

int main(){
	bptree *T = (bptree*)malloc(1*sizeof(bptree));
	T -> keycount = 0;
	Insert_key(20, T);
	cout << T -> keycount << endl;
	return 0;
}
