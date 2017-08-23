#ifndef BPLUS_NODE
#define BPLUS_NODE

#define NULL 0

#include<vector>
extern "C"

namespace bptree{
  NodeType root*;
  int m;//子节点的最大数目
  int nodeCount;
  typedef vector<NodeType*> vec;
  typedef long int li;

  class bplusTree{  
   tydef struct { 
     int Count;
     boolean isRoot;
     boolean isLeaf;
     int keyNum;//关键字数目
     int childNum;//子节点数目
     NodeType* parent;
     vec children;
     li  keys;
      
   }NodeType;
   
   
   void deleteNode(){
   
   }
   
   void insertNode(li key, bplusTree tree){
     if (tree -> nodeCount == 0){
         NodeType *tempNode;
	 tempNode -> isRoot = true;

     }
   }

  void printTree(){
  
  }

 }
}
