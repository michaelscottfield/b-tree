#include <math.h>
#include <iostream>
using namespace std;

#define m 6 //6阶B树，除根节点外的节点关键字数目在2到5之间   
 
    typedef struct Nodetype{ 
    	int count;
     	bool isroot;
     	bool isleaf;
     	int keynum;//关键字数目
     	int keys[m-1];
	    int childnum;//子节点数
     	Nodetype* child[m];
     	Nodetype *parent; 
   }Node;

	typedef struct binarytree{
		Nodetype *root;
		int levelcount;
		int keycount;//树的关键字总数
		int *key = new int[keycount];
	
	}bptree;
       
	bool Keyinnode(Nodetype *node, int key){//判断关键字是否在node中
			if(node -> keys[0] <= key && key <= node-> keys[node -> keynum - 1]){
				return true;
			}
			return false;
	}
        /* 按层次打印 */
  	void printTree(Nodetype *tree){
		int i;
		Nodetype *pnode = tree -> parent; 
		if(tree){
			for(i = 0; i < tree -> keynum; i ++){
				cout << "关键字" << (i + 1) << ":" << tree -> keys[i];  
			}
			if((tree -> isroot) || (tree = pnode -> child[pnode -> childnum - 1])){
				cout << "本层节点已全部输出" << endl;
			}
			for(i = 0; i < tree -> childnum; i++){
				printTree(tree -> child[i]);
			}
			return ;
		}
		else{
			return ;
			}
  	}

	/* 释放内存 */
	void destroy(Nodetype *node){
	        if(node){
			for(int i = 0;i < node -> childnum;i++){
				destroy(node -> child[i]);
			}
			free(node);	
		}	
	}
    
	/* 递归搜索 */
	Nodetype* Recursive_search(Nodetype *tree, int key, int* pos)//pos代表关键字在节点中的索引
	{
		int i = 0;
		while(i < tree -> keynum && key > tree -> keys[i]){
			i++;			
		}
		if(i < tree -> keynum && key == tree -> keys[i])
		{
			*pos = i;//关键字索引
			return tree;//在该节点中找到关键字
		}
		if (tree -> isleaf){//如果没有在叶子节点找到该关键字
			return NULL;
		}
		//如果tree是中间节点，则需要去子节点中找
		return Recursive_search(tree -> child[i], key, pos);//去child[i]中查找关键字
	
	}
        
	/* 找到关键字所在的节点 */
	Nodetype* search(int key, Nodetype *node, int *pos)
	{
		for (int i =0;i < node -> keynum;i++){
			if(node ->keys[i] == key){
				return node;
			}
		}
		*pos = -1;
		Recursive_search(node, key, pos);
	}

	/* 对节点内的关键字二分查找 */
	int Binary_search(Nodetype *node, int key){
		int left = 0;
		int right = node -> keynum - 1;
		while(left <= right){
			int mid = (left + right) / 2;
			if(node -> keys[mid] == key){
				return mid;
			}
			else if(node -> keys[mid] < key){
				left = mid + 1;
			}
			else{
				right = mid - 1;
			}
		}
		return -1;
	}

	/* 删除B-树中的关键字 */
	void Remove(bptree* tree, int key){
		int i = 0;
		int index,j;
		int pos = -1;
		if(search(key, tree -> root, &pos)){//关键字存在于树的节点中
			Nodetype *node = search(key, tree -> root, &pos);
			Nodetype *pnode = node -> parent;
			if(node -> isleaf){//如果关键字在叶子节点内部
				if(node -> keynum > int(ceil(m / 2) - 1)){//需要把所删除节点后面的节点向前移动
					i = Binary_search(node, key);
					for(; i < node -> keynum - 1; i++){
						node -> keys[i] = node -> keys[i + 1];
					}
					pnode -> childnum --;
				}
					
				else{//虽然在叶子节点中但删除元素后不满足最小元素数量
					i = 0;
					while(pnode -> child[i] != node){
						i ++;
					}
					if(pnode -> child[i - 1] -> keynum > int(ceil(m / 2) - 1)){//考虑向相邻节点借元素
						Nodetype *leftbro = pnode -> child[i - 1];
						index = 0;
						int tempkey = leftbro -> keys[leftbro -> keynum - 1];
						leftbro -> keynum --;
						//把这个元素放到父节点中去
						i = Binary_search(pnode, tempkey);
						index = Binary_search(node, key);
						for(j = index; j > 0; j --){
							node -> keys[j] = node -> keys[j - 1];
						}
						node -> keys[0] = pnode -> keys[i];
						pnode -> keys[i] = tempkey;
					}
					else if(pnode -> child[i + 1] -> keynum > int(ceil(m / 2) - 1)){//考虑向相邻节点借元素
						Nodetype *rightbro = pnode -> child[i + 1];
						index = 0;
						int tempkey = rightbro -> keys[0];
						rightbro -> keynum --;
						//把这个元素放到父节点中去
						i = Binary_search(pnode, tempkey);
						index = Binary_search(node, key);
						for(j = index; j < node -> keynum - 1; j ++){
							node -> keys[j] = node -> keys[j + 1];
						}
						node -> keys[node -> keynum - 1] = pnode -> keys[i];
						pnode -> keys[i] = tempkey;
					}
					else{//如果相邻节点都没有元素可借
						//需要和左边的兄弟节点合并节点

					}
				}
			}
			else{//关键字在中间节点中找到
				//需要找到该关键字的继承者
				for(i = 0; i < node -> childnum; i ++){
					if(node ->child[i] -> keys[0] > key){
						break;
					}
				}
				index = i;
				//继承者在child[i]的第一个关键字
				if(node -> child[i] -> keynum > int(ceil(m / 2) - 1)){
					i = Binary_search(node, key);
					node -> keys[i] = node -> child[index] -> keys[0];
					for(j = 0; j < node -> child[index] -> keynum - 1; j ++){
						node -> child[index] -> keys[j] = node -> child[index] -> keys[j + 1]; 
					}
				}
				else{//继承者所在节点关键字数量不足

				}
			}
		}
		else{
			return ;
		}
		
	}

	/* 对结点进行分裂,将一半元素给新建的节点，并且将分裂节点的中间关键字元素上移至父节点中 */
	void Splitchild(Nodetype* parent, int index, Nodetype* node){//index是node在父节点的孩子节点索引
		int i,j;
		Nodetype* temp;
		int pnum = parent -> keynum;
		int nnum = node -> keynum;
		i = 0;
		while(parent -> keys[i] < node -> keys[int(floor(nnum / 2))  + 1]){//寻找中间关键字元素在父节点中的插入位置
				i++;
		}	
		//将中间关键字元素上移至父节点中
		parent -> keynum ++;
		for(j = i; j < parent -> keynum - 1; j ++){
			parent -> keys[j + 1] = parent -> keys[j];
		}
		parent -> keys[i] = node -> keys[int(floor(nnum / 2))  + 1];
		parent -> childnum ++;//父节点的子节点数增加了一个
		if(i < int(floor(nnum / 2)) + 1){//将key放到前半部分关键字
			for(j = 0; j < int(floor(nnum / 2)) + 1; j++){
				temp -> keys[j] = node -> keys[j];	
			}
			for(j = 0; j < int(floor(nnum / 2)) + 1; j++){
				node -> keys[j] = node -> keys[j + int(floor(nnum / 2)) + 2];
			}
			//temp成为了parent的child[index]
			parent -> child[index] = temp;
			for(j = index + 2; j < parent -> childnum; j ++){
				parent -> child[j] = parent -> child[j - 1];
			}
			parent -> child[index + 1] = node;
		}
		else{//将key放到后半部分关键字
			for(j = 0; j < floor(nnum / 2) + 1; j++){
				temp -> keys[j] = node -> keys[j + int(floor(nnum / 2)) + 2];
			}
			//temp成为了parent的child[index + 1]
			for(j = index + 2; j < parent -> childnum; j ++){
				parent -> child[j] = parent -> child[j - 1];
			}
			parent -> child[index + 1] = temp;
		}
		node -> keynum = floor(nnum / 2);//原节点只保留一半的关键字
		return ;
	}

	/* 把关键字插入到尚未饱和的节点中*/
	void Insert_nonfull(Nodetype *node, int key){
		int i;
		if(node -> isleaf){//如果是叶子节点
			i = node -> keynum - 1;
			while(i >= 0 && key < node -> keys[i]){
				node -> keys[i + 1] = key;
				--i;
			}	
			node -> keys[i + 1] = key;
			++node->keynum;	
		}
		else{//节点是内部节点
			i = node -> keynum - 1;
			while(i >= 0 && key < node -> keys[i]){
				--i;
			}	
			++i;
			
			if(node -> child[i] -> keynum == m - 1){//如果该孩子节点已满
				Splitchild(node, i, node -> child[i]);//分裂该孩子节点
				if (key > node -> keys[i]){
					++i;
				}	
			}	
			Insert_nonfull(node -> child[i], key);//插入到分裂产生的未饱和孩子节点中
		}
	}

	/* 插入新的关键字  */   
	 void Insert_key(int key, bptree *tree){
		Nodetype *root = tree -> root;
		Nodetype *node;
		if (tree -> keycount == 0){//节点数为0
			Nodetype *tempnode = (Nodetype*)malloc(1*sizeof(Nodetype));
			tempnode -> isroot = true;
			tempnode -> isleaf = true;
			tempnode -> keynum = 1;
			tempnode -> keys[0] = key;
			tree -> levelcount = 1;
			tree -> keycount = 1;
			tree -> root = tempnode;
		}
		if(root -> keynum == (m -1)){//根节点已饱和，插入前需要进行分裂调整
			Nodetype *newnode = (Nodetype*)malloc(1*sizeof(Nodetype));
			if(!newnode){//内存分配失败
				cout<< "out of memory" << endl;
			}
			tree -> root = newnode;
			newnode -> isleaf = false;
			newnode -> isroot = true;
			newnode -> keynum = 0;
			newnode -> child[0] = root;
			Splitchild(newnode, 0, root);
			Insert_nonfull(newnode, key);
		}
		else{//根节点未满，在当前节点中插入
			Insert_nonfull(root, key);
		}
	}

	/* 根据数据集创建树 */
	void create(bptree* tree, int* data,int length ){
		for (int i = 0;i < length;i++){
			Insert_key(data[i], tree);
		}
	}

  

