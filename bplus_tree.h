#include <math.h>

using namespace std;

    int m = 6; //6阶B树，除根节点外的节点关键字数目在2到5之间   
 
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

class bptree{
  private:
	NodeType* root;
  	int nodecount;
	int levelcount;
	int keycount;//树的关键字总数
	int key[keycount];
  
  public:
        /* 插入新的关键字  */   
   	void Insert_key(int key, bptree *tree){
     		if (tree -> count == 0){//节点数为0
         		NodeType *tempnode;
	 		tempnode -> isroot = true;
			tempnode -> isleaf = true;
			tempnode -> keynum = 1;
			tempnode -> keys[0] = key;
                        tree -> levelcount = 1;
			tree -> keycount = 1;
			tree -> root = tempnode;
     			}
     
    		 else{
           		
     			}
   		}
        /* 按层次打印 */
  	void printTree(Nodetype *tree, int layer){
		NodeType *temp;
		temp = tree;
  		if (tree -> nodecount == 0){
			print("the tree has no nodes");
		}
		else{
			cout << "第" << layer << "层， " << temp -> keycount << " node : ";
			for(int i = 0;i < m - 1;i++){
				cout << temp -> keys[i];
			}
			cout << endl;
			++ layer;
			for(int i = 0;i <=node -> keynum;i++){
				if(node -> child[i]){
					printTree(node -> child[i], layer);
				}
			}
		}
  	}

	/* 删除B-树中的关键字 */
	void Remove(bptree* tree, int key){
		if(search(key, tree -> root, -1)){//关键字存在于树的节点中
			NodeType *node = search(key, tree -> root, -1);
			NodeType *temp = node -> parent;
			if(parent -> keynum <= int(ceil(m / 2) - 1){
				
			}
		}
		else{
			return null;
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
        
	/* 根据数据集创建树 */
	void create(bptree* tree, int* data,int length ){
		for (int i = 0;i < length;i++){
			tree -> Insert_node(data[i], tree);
		}
	}

	/* 递归搜索 */
	NodeType* Recursive_search(Nodetype *tree, int key, int* pos)
	{
		int i = 0;
		while(i < tree -> keynum && key > tree -> keys[i]){
			i++;			
		}
		if(i < tree -> keynum && key == tree -> keys[i])
		{
			*pos = i;
			return true;
		}
		if (tree -> isleaf){
			return null;
		}
		return Recursive_search(tree -> child[i], key, pos);
		
	}
        
	/* 找到关键字所在的节点 */
        NodeType* search(int key, Nodetype *node, int *pos){
		for (int i =0;i < node -> keyNum;i++){
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

	/* 对结点进行分裂,将一半元素给新建的节点，并且将分裂节点的中间关键字元素上移至父节点中 */
	void Splitchild(Nodetype* parent, int index, Nodetype* node){
		int i,j;
		Nodetype* temp;
		int pnum = parent -> keynum;
		int nnum = node -> keynum;
		i = 0;
		while(parent -> keys[i] < node -> keys[floor(nnum / 2)  + 1]){//寻找中间关键字元素的插入位置
				i++;
		}	
		if(i < floor(num / 2) + 1){//将key放到前半部分关键字
			for(j = 0; j < floor(nnum / 2) + 1; j++){
				temp -> keys[j] = node -> keys[j];	
			}
			for(j = 0; j < floor(nnum / 2) + 1; j++){
				node -> keys[j] = node -> keys[j + floor(num / 2) + 2];
			}
		}
		else{//将key放到后半部分关键字
			for(j = 0; j < floor(nnum / 2) + 1; j++){
				temp -> keys[j] = node -> keys[j + floor(num / 2) + 2];
			}
		}
		node -> keynum = floor(nnum / 2);//原节点只保留一半的关键字
		
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
				Splitchild(node, i, node -> child[i]);
				if (key > node -> keys[i]){
					++i;
				}	
			}	
			Insert_nonfull(node -> child[i], key);
		}
	}
  };

