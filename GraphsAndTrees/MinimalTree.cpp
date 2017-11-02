/*
 * MinimalTree.cpp
 *
 *  Created on: Sep 1, 2017
 *      Author: chivora
 */

#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include "require.h"

using namespace std;

/*
 * Given a sorted (increasing order) array with unique integer elements,
 * write an algorithm to create a binary search tree with minimal height.
 */

/* A Binary Tree node */
struct TNode
{
    int data;
    struct TNode* left;
    struct TNode* right;
};

struct TNode* newNode(int data);

/*
 * Algorithm
 * Constructing from sorted array in O(n) time is simpler as we can get the middle
 * element in O(1) time. Following is a simple algorithm where we first find the
 * middle node of list and make it root of the tree to be constructed.

	1) Get the Middle of the array and make it root.
	2) Recursively do same for left half and right half.
		  a) Get the middle of left half and make it left child of the root
			  created in step 1.
		  b) Get the middle of right half and make it right child of the
			  root created in step 1.
 */
/* A function that constructs Balanced Binary Search Tree from a sorted array */
struct TNode* sortedArrayToBST(int arr[], int start, int end)
{
    /* Base Case */
    if (start > end)
      return NULL;

    /* Get the middle element and make it root */
    int mid = (start + end)/2;
    struct TNode *root = newNode(arr[mid]);

    /* Recursively construct the left subtree and make it
       left child of root */
    root->left =  sortedArrayToBST(arr, start, mid-1);

    /* Recursively construct the right subtree and make it
       right child of root */
    root->right = sortedArrayToBST(arr, mid+1, end);

    return root;
}


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

/* A utility function to print preorder traversal of BST */
void preOrder(struct TNode* node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}

/* Driver program to test above functions */
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    /* Convert List to BST */
    struct TNode *root = sortedArrayToBST(arr, 0, n-1);
    printf("\n PreOrder Traversal of constructed BST ");
    preOrder(root);

    return 0;
}


