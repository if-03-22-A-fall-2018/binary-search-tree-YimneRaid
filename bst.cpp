
/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: 2AHIF
 * ---------------------------------------------------------
 * Exercise Number: 4
 * File:			bst.h
 * Author:			Yimne Raid
 * Due Date:		16.3.2019
 * ----------------------------------------------------------
 * Description:
 * <Add description>
 * ----------------------------------------------------------
 */
#include <stdio.h>
#include "bst.h"
#include <stdlib.h>
#include "general.h"

struct Node{
  int element;
   struct Node* left;
   struct Node* right;
};

Bst new_bst(){
  Bst newBst=(Bst)malloc(sizeof(struct Node));
 newBst->left=0;
 newBst->right=0;
 newBst->element=0;
 newBst=0;
 return newBst;
}
void delete_bst(Bst bst){
  if(bst == 0)return;
  delete_bst(bst->left);
  delete_bst(bst->right);
  sfree(bst);
}

int get_depth(Bst bst){
  if (bst==0) {
    return 0;
  }
  else{
    int depth_left=get_depth(bst->left);
    int depth_right=get_depth(bst->right);
    if (depth_left>depth_right) {
      return (depth_left+1);
    }
    else{
      return (depth_right+1);
    }
  }
}

void add(Bst* bst, int value){
  if ((*bst)==0) { //took me 1 hour to find out that i should put bst in () with a star
    Bst temp=(Bst)malloc(sizeof(struct Node));
    temp->right=0;
    temp->left=0;
    temp->element=value;
    *bst=temp;
  }
  else if(value<=(*bst)->element  )
  {
    add(&(*bst)->left,value);
  }
  else {
    add(&(*bst)->right,value);
  }
}

int root_value(Bst bst){
  if (bst==0) {
    return 0;
  }
  return bst->element;
}

Bst left_subtree(Bst root){
if (root==0) {
  return 0;
}
  return root->left;
}

Bst right_subtree(Bst root){
  if (root==0) {
    return 0;
  }
    return root->right;
}

int traverse_pre_order(Bst bst, int *elements, int start){
  int count = 0;
    if(bst == 0){
      return 0;
    }
    elements[start] = bst->element;
    count += traverse_pre_order(bst->left, elements, start+1);
    count += traverse_pre_order(bst->right, elements, start+count+1);
    count++;
    return count;
}

int traverse_in_order(Bst bst, int *elements, int start){
  int count = 0;
    if(bst == 0){
      return 0;
    }
    count += traverse_in_order(bst->left, elements, start);
    elements[start+count] = bst->element;
    count+= traverse_in_order(bst->right, elements, start+count+1);
    count++;
    return count;
}

int traverse_post_order(Bst bst, int *elements, int start){
    if(bst == 0)return 0;
    int count = 0;
    count += traverse_post_order(bst->left, elements, start);
    count += traverse_post_order(bst->right, elements, start+count);
    elements[start+count] = bst->element;
    return count+1;
}

bool are_equal(Bst bst1, Bst bst2){
  if (bst1==0&&bst2==0) {
    return true;
  }
  else if (bst1==0&&bst2!=0) {
    return false;
  }
  else if (bst2==0&&bst1!=0) {
    return false;
  }
  else{
    if(bst1->element==bst2->element&& are_equal(bst1->left,bst2->left)!=0&& are_equal(bst1->right,bst2->right)!=0){
      return true;
    }
    else{
      return false;
    }
  }
}

void most_left_longest_branch(Bst bst, Bst* branch){
    if(bst == 0){
      return;
    }
    add(branch, bst->element);
    if (get_depth(bst->left)>=get_depth(bst->right)) {
      most_left_longest_branch(bst->left,branch);
    }
    else{
      most_left_longest_branch(bst->right, branch);
    }
}

int get_number_of_subtrees(Bst bst){
    if(bst == 0){
      return -1;
    }
    return 1+get_number_of_subtrees(bst->left)+get_number_of_subtrees(bst->right) +1;
}
