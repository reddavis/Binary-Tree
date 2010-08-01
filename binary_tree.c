#include <stdio.h>

typedef struct tree {
  int data;
  struct tree *parent;
  struct tree *left;
  struct tree *right;
} tree;

// Prototypes
void add_to_tree(tree *root_node, tree *node);

void add_to_tree(tree *root_node, tree *node) {
  /*



  */
  if(node->data < root_node->data) {
    if(NULL == root_node->left) {
      root_node->left = node;
      node->parent = root_node;
    } else {
      add_to_tree(root_node->left, node); // Monkey down the tree
    }
  } else {
    if(NULL == root_node->right) {
      root_node->right = node;
      node->parent = root_node;
    } else {
      add_to_tree(root_node->right, node); // Monkey down the tree
    }
  }

}

int main (int argc, char const *argv[]) {
  tree root, new_node, new_node_2;
  new_node.data = 1;
  new_node_2.data = 2;

  add_to_tree(&root, &new_node);
  add_to_tree(&root, &new_node_2);

  return 0;
}