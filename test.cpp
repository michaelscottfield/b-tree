#include "bplus_tree.h"

using namespace std;

int main(){
	int keys[10] = {22,13,6,7,8,3,12,37,89,20};
        bptree *T;//声明树
	for(int i = 0;i < 10;i++){
       	  T->insertNode(keys[i], T);
	}
	return 0;
}
