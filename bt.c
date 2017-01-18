#include "stdlib.h"

#include "bt.h"

void bst_insert(bst_tree_t *tree, bst_node_t *z, int (*compare)(const void *, const void *))
{
  bst_node_t *y = NULL;
  bst_node_t *x = tree->root;

  while (x != NULL)
  {
    y = x;

    if (compare(z->key, x->key))
    {
      x = x->left;
    }
    else
    {
      x = x->right;
    }
  }

  z->parent = y;

  if (y == NULL)
  {
    tree->root = z;
  }
  else if (compare(z->key, y->key))
  {
    y->left = z;
  }
  else
  {
    y->right = z;
  }
}

bst_tree_t *bst_tree_new(bst_node_t *n)
{
  bst_tree_t *t = malloc(sizeof(bst_tree_t));
  t->root = n;
  return t;
}

bst_node_t *bst_node_new(void *p)
{
  bst_node_t *n = malloc(sizeof(bst_node_t));
  n->key = p;
  n->parent = n->left = n->right = NULL;
  return n;
}
