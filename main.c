#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
  int data;
  struct tree *parent;
  struct tree *left;
  struct tree *right;
} tree;

// Prototypes
void add_to_tree(tree *root_node, int data);
tree *find(tree *root_node, int data);

// Codez
tree *find(tree *root_node, int data) {
  if (root_node == NULL) { return NULL; }
  if (root_node->data == data) { 
    return root_node; 
  }
    
  if (data > root_node->data) {
    return find(root_node->right, data);
  } else {
    return find(root_node->left, data);
  }
}

void add_to_tree(tree *root_node, int data) {
  if(data < root_node->data) {
    if(NULL == root_node->left) {
      tree *new_node;
      new_node = malloc(sizeof(tree)); // Give me some memory, bitch!

      root_node->left = new_node;
      new_node->parent = root_node;
      new_node->data = data;
    } else {
      add_to_tree(root_node->left, data); // Monkey down the tree
    }
  } else {
    if(NULL == root_node->right) {
      tree *new_node;
      new_node = malloc(sizeof(tree)); // Give me some memory, bitch!

      root_node->right = new_node;
      new_node->parent = root_node;
      new_node->data = data;
    } else {
      add_to_tree(root_node->right, data); // Monkey down the tree
    }
  }

}

int main (int argc, char const *argv[]) {
  tree root;
  int node_1_data = 1;
  int node_2_data = 2;
  
  // Adding stuff
  add_to_tree(&root, node_1_data);
  add_to_tree(&root, node_2_data);
  
  // Search
  int find_data = 2;
  tree *result;
  result = find(&root, find_data);    
  
  return 0;
}