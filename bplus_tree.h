#ifndef BPLUS_NODE
#define BPLUS_NODE

#define NULL 0
namespace bptree{
  NodeType root*;
  int m;//子节点的最大数目
  int nodeCount;

  class bplusTree{  
   tydef struct { 
     int Count;
     boolean isRoot;
     boolean isLeaf;
     int keyNum;//关键字数目
     int childNum;//子节点数目
     ItemType Key[4];
     long Branch[5];
     NodeType* parent;
     NodeType* children[4];
      
   }NodeType;
   
   void buildTree(){
   
   }
   
   void deleteNode(){
   
   }
   
   void insertNode(){
     if (nodeCount == 0){
     }
   }

  void printTree(){
  
  }

 }
}
