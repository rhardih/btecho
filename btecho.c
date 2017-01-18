/**
 * btecho 1.0
 *
 * Write integer arguments as a binary tree to the standard output.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bt.h"

#define INDWIDTH 3
#define MAXNLEN 21

int icompare(const void *a, const void *b)
{
  long n = *(long *)a;
  long m = *(long *)b;

  return n < m;
}

int only_child(bst_node_t *x)
{
  if (x->parent == NULL) return 1;

  return (x->parent->left == x && x->parent->right == NULL) ||
    (x->parent->right == x && x->parent->left == NULL);
}

int (left_child(bst_node_t *x))
{
  if (x->parent == NULL) return 1;

  return x->parent->left == x;
}

char *sideways(bst_node_t *x)
{
  // send zero byte back up to free
  if (x == NULL) return calloc(1, sizeof(char));

  char *tree, *lead;
  char *rtree = sideways(x->right);
  char *ltree = sideways(x->left);
  char *tok, *sep = "\n", *line;

  int rtl = strlen(rtree);
  int ltl = strlen(ltree);
  int lines = 0, offset = 0, i;

  for (i = 0; i < rtl; ++i)
    if (rtree[i] == '\n') lines++;

  for (i = 0; i < ltl; ++i)
    if (ltree[i] == '\n') lines++;

  lines += INDWIDTH * lines + MAXNLEN; // enough for lead and max long 2^64 + \0

  tree = malloc(rtl + ltl + lines);
  lead = only_child(x) || left_child(x) ? "   " : "|  ";

  offset = sprintf(tree, "|- %lu\n", *(long *)x->key);

  for (line = strtok(rtree, sep); line != NULL; line = strtok(NULL, sep))
    offset += sprintf(tree + offset, "%s%s\n", lead, line);

  for (line = strtok(ltree, sep); line != NULL; line = strtok(NULL, sep))
    offset += sprintf(tree + offset, "%s%s\n", lead, line);

  free(rtree);
  free(ltree);

  return tree;
}

int main(int argc, char const *argv[])
{
  long l, *lp;

  bst_tree_t *tree = bst_tree_new(NULL);
  bst_node_t *n;

  while (scanf("%lu\n", &l) != EOF)
  {
    lp = malloc(sizeof(long));
    *lp = l;
    n = bst_node_new(lp);
    bst_insert(tree, n, icompare);
  }

  printf("%s", sideways(tree->root));

  return 0;
}
