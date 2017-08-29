
#include<vector>
using namespace std;
extern "C"
   
    typedef long int li;
 
    typedef struct NodeType{ 
     int Count;
     bool isRoot;
     bool isLeaf;
     int keyNum;//关键字数目
     int childNum;//子节点数目
     li  keys;
      NodeType *parent; 
   }Node;

   typedef vector<NodeType*> vec;
  class bptree{
  NodeType* root;
  int m;//子节点的最大数目
  int nodeCount;
  
  public:
  void leftRotation(){
  
  }

  void rightRotation(){
  
  }
  
   void deleteNode(){
   
   }
   
   void insertNode(li key, bptree *tree){
     if (tree -> nodeCount == 0){
         NodeType *tempNode;
	 tempNode -> isRoot = true;

     }
     
     else{
           
     }
   }

  void printTree(){
  
  }
 
  };

