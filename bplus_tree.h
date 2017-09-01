#include <math.h>
#include<vector>
using namespace std;

    int m = 6; //6阶B树，除根节点外的节点关键字数目在2到5之间   
 
    typedef struct NodeType{ 
    	int Count;
     	bool isRoot;
     	bool isLeaf;
     	int keyNum;//关键字数目
     	int keys[m-1];
	int childnum;//子节点数
     	NodeType* child[m];
     	NodeType *parent; 
   }Node;

   typedef vector<NodeType*> vec;
class bptree{
  private:
	NodeType* root;
  	int nodeCount;
	int levelcount;
	int keycount;//树的关键字总数
	int key[keycount];
  
  public:
        /* 插入新的关键字  */   
   	void Insert_key(int key, bptree *tree){
     		if (tree -> nodeCount == 0){
         		NodeType *tempNode;
	 		tempNode -> isRoot = true;
                        tree -> levelcount = 1;
			tree -> keycount = 1;
			tree -> root = tempNode;
     			}
     
    		 else{
           		
     			}
   		}
        /* 按层次打印 */
  	void printTree(NodeType *tree, int layer){
		NodeType *temp;
		temp = tree;
  		if (tree -> nodeCount == 0){
			print("the tree has no nodes");
		}
		else{
			cout << "第" << layer << "层， " << temp -> keycount << " node : ";
			for(int i = 0;i < m - 1;i++){
				cout << temp -> keys[i];
			}
			cout << endl;
			++ layer;
			for(int i = 0;i <=node -> keyNum;i++){
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
			if(parent -> keyNum <= int(ceil(m / 2) - 1){
				
			}
		}
		else{
			return null;
		}
		
	}
	
	/* 释放内存 */
	void destroy(NodeType *node){
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
	NodeType* Recursive_search(NodeType *tree, int key, int* pos)
	{
		int i = 0;
		while(i < tree -> keyNum && key > tree -> keys[i]){
			i++;			
		}
		if(i < tree -> keyNum && key == tree -> keys[i])
		{
			*pos = i;
			return true;
		}
		if (tree -> isLeaf){
			return null;
		}
		return Recursive_search(tree -> child[i], key, pos);
		
	}
        
	/* 找到关键字所在的节点 */
        NodeType* search(int key, NodeType *node, int *pos){
		for (int i =0;i < node -> keyNum;i++){
			if(node ->keys[i] == key){
				return node;
			}
		}
		*pos = -1;
		Recursive_search(node, key, pos);
	}

	/* 对节点内的关键字二分查找 */
	int Binary_search(NodeType *node, int key){
		int left = 0;
		int right = node -> keyNum - 1;
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
  };

