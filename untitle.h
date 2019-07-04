#ifndef _RBTREE
#define _RBTREE

#define RED 0
#define BLACK 1

typedef struct _rbnode{
    char color;
    char *word, *mean;
    struct _rbnode *parent, *left, *right; 
}rbnode;

typedef struct {
  rbnode *root , *nil;
}rbtree;

int rbtree_init(rbtree *t);

void rbtree_print(rbtree *t);

rbnode *rbtree_search(rbtree *t, rbnode *x, char* word);

rbnode *rbtree_begin(rbtree *t);

rbnode *rbtree_end(rbtree *t);

rbnode *rbtree_next(rbtree *t, rbnode *x);

rbnode *rbtree_prev(rbtree *t, rbnode *x);

void *rbtree_insert(rbtree *t, rbnode *x, char* word, char* mean);

void *rbtree_erase(rbtree *t, rbnode *x, char* word);

void *rbtree_free(rbtree *t);

#endif