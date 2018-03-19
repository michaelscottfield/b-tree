//
//  bplustree.h
//  
//
//  Created by mike on 2018/3/19.
//

#ifndef bplustree_h
#define bplustree_h

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int M = 3;
class Node
{
    public:
        int numofkeys;//非叶节点都只存索引
        bool isRoot;
        bool isLeaf;
        int *keys;
        Node* parent;//指向父节点的指针
        Node* children[];
        void SplitNodes(){
            
        }
    
        void InsertKey(int key){
            int i,temp,temp2,j;
            numofkeys ++;
            for(i = 0; i < numofkeys; i ++){
                if(keys[i] < key && key < keys[i+1]){
                    temp = keys[i+1];
                    keys[i + 1] = key;
                    break;
                }
            }
            
            //temp2 = Node->keys[i + 2];
            //Node->keys[i+2] = temp;
            for(j = i+2;j < numofkeys; j ++){
                temp2 = keys[j];
                keys[j] = temp;
                temp = temp2;
            }
        }
    
        void DeleteKey(int key){
            int i;
            for(i = 0; i < numofkeys; i ++){
                if(key == keys[i]){
                    break;
                }
            }
            for(int j = i; j < numofkeys; j++){
                keys[j] = keys[j + 1];
            }
            numofkeys--;
        }
    
        void BuildAsRoot(int kkeys[]){
            int i;
            
            //for(i = 0; i < M - 1; i ++){
                
            //}
        }
    
        ~Node(){
            
        }
};

class Bptree
{
    public:
        Node* root;
        Node* leaf;
    
    void CreateBptree(int kkeys[]){
        
    }
        ~Bptree(){
            
        }
};

void mergeTwoNodes(){
    
}



/*
 *创建一棵B+树
 */
//void CreateBptree(int keys[]){
    
//}


#endif /* bplustree_h */
