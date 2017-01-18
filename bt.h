#ifndef BST
#define BST

typedef struct bst_node bst_node_t;

struct bst_node {
  void *key;

  bst_node_t *left;
  bst_node_t *right;
  bst_node_t *parent;
};


typedef struct {
  bst_node_t *root;
} bst_tree_t;

/**
 * Insert
 *
 * Inserts node into tree according to the output of compare. Non-zero will
 * assign as left child, zero right.
 */
void bst_insert(bst_tree_t *tree, bst_node_t *x, int (*compare)(const void *, const void *));

/**
 * Return a pointer to a new tree with root set to n.
 *
 * Pointer to be freed after use.
 */
bst_tree_t *bst_tree_new(bst_node_t *n);

/**
 * Return a pointer to a new node with key set to p and parent, left and right
 * set to NULL.
 *
 * Pointer to be freed after use.
 */
bst_node_t *bst_node_new(void *p);

#endif
