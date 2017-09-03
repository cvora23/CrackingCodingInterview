/*
 * BstSequence.cpp
 *
 *  Created on: Sep 3, 2017
 *      Author: chivora
 */

#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<list>
#include "require.h"

using namespace std;

/* A Binary Tree node */
struct TNode
{
    int data;
    struct TNode* left;
    struct TNode* right;
};

struct TNode* newNode(int data);

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct TNode* newNode(int data)
{
    struct TNode* node = (struct TNode*)
                         malloc(sizeof(struct TNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void insert(struct TNode **q,int num)
{
     if(*q==NULL)
     {
		 *q = (struct TNode *)malloc(sizeof(struct TNode));
		 (*q)->left = NULL;
		 (*q)->data = num;
		 (*q)->right = NULL;
     }
     else
     {
         if(num<((*q)->data))
        	 insert(&((*q)->left),num);
         else
        	 insert(&((*q)->right),num);
     }
     return;
}

// A utility function to print inorder traversal of a Binary Tree
void printInorder (TNode* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

std::list< std::list<int> > allSequences(TNode* node){

	std::list< std::list<int> > result =
			new std::list< std::list<int> >();

	if(node == NULL){
		result.insert(new std::list<int>());
		return result;
	}

	std::list<int>prefix = new std::list<int>();
	prefix.insert(node->data);

	/*
	 * Recurse on left and right subtree
	 */
	std::list< std::list<int> > leftSeq =
			new std::list< std::list<int> >();
	std::list< std::list<int> > rightSeq =
			new std::list< std::list<int> >();

	/*
	 * Weave together each list from left and right side
	 */
	for(int i=0;i<leftSeq.size();i++){

	}
}

int main(){

    srand((unsigned)time(0));
    struct TNode *p;
    p =NULL;
   // cout<<p<<endl;
    int data [10] = {50, 20, 60, 10, 25,70, 5, 15, 65, 8};
    for(int i=0;i<10;i++)
    {
          insert(&p,data[i]);
     //     cout<<p<<endl;
    }

    printInorder(p);

	return 0;

}




