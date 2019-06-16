#ifndef _RBTREE
#define _RBTREE

#define RED 0
#define BLACK 1

typedef struct _rbnode{
    char color;
    int key;
    struct _rbnode *parent, *left, *right; 
}rbnode;

typedef struct {
  rbnode *root , *nil;
} rbtree;

int rbtree_init(rbtree *t);

void rbtree_print(rbtree *t);

rbnode *rbtree_search(rbtree *t, int key);

rbnode *rbtree_begin(rbtree *t);

rbnode *rbtree_end(rbtree *t);

rbnode *rbtree_next(rbtree *t, rbnode *x);

rbnode *rbtree_prev(rbtree *t, rbnode *x);

int *rbtree_insert(rbtree *t, int key);

void *rbtree_erase(rbtree *t, int key);

void *rbtree_free(rbtree *t);

#endif