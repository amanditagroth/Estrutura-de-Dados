#include "untitle.h"
#include <stdio.h>
#include <stdlib.h>


int  rbtree_init(rbtree *t){
    t->nil = malloc(sizeof(rbnode));
    if(!t->nil) return 0;
    t->nil->color = BLACK;
    t->root = t->nil; 
    return 1;
}

void _rbtree_print(rbtree *t, rbnode *x){
    if(x == t->nil) return;
    _rbtree_print(t, x->left);
    printf("%d\n", x->key);
    _rbtree_print(t, x->right);
}

void rbtree_print(rbtree *t){
    _rbtree_print(t, t->root);
}

rbnode *rbtree_search(rbtree *t, int key){
    rbnode *x = t->root;
    while(x != t->nil && x->key != key){
        if(key < x->key) x = x->left;
        else x = x->right;
    }
    return x;
}

rbnode *_rbtree_begin(rbtree *t, rbnode *x){
    rbnode *y = t->nil;
    while(x != t->nil){
        y = x;
        x = x->left;
    }
    return y;
}

rbnode *rbtree_begin(rbtree *t){
    return _rbtree_begin(t, t->root);
}

rbnode *_rbtree_end(rbtree *t, rbnode *x){
    rbnode *y = t->nil;
    while(x != t->nil){
        y = x;
        x = x->right;
    }
    return y;
}

rbnode *rbtree_end(rbtree *t){
    return _rbtree_end(t, t->root);   
}

rbnode *rbtree_next(rbtree *t, rbnode *x){
    //Achando o carinha a direita
    if(x->right != t->nil){ 
        return _rbtree_begin(t,x->right);
    while(x->parent != t->nil && x->parent->right == x){
        x = x->parent;
     }
    }
    
    //Achando o carinha a esquerda
    if(x->left != t->nil){ 
        return _rbtree_begin(t,x->left);
    while(x->parent != t->nil && x->parent->left == x){
        x = x->parent;
     }
    }
        return x->parent;
}

rbnode *rbtree_prev(rbtree *t, rbnode *x){
    // ponteiro para seguir X(?????)
    rbnode *y = t->nil;
    //X vai seguir até Nil, mas Y vai parar um parente antes.
    while(x->parent != t->nil ){
        y = x;
        x = x->parent;
    }
        // retorna Y na posição antes de Nil, ou seja, na Raíz.
        return y;
}

void left_rotate(rbtree *t,rbnode *x){
    rbnode *y = x->right;
    x->right = y->left;
    if(x->right != t->nil){
        x->right->parent = x;
    }
    y->parent = x->parent;
    if(x->parent == t->nil) t->root = y;
    else if(x== x->parent->left) x->parent->left = y;
    else x->parent->right = y;
    y->left = x;
    x->parent = y;
}

void right_rotate(rbtree *t, rbnode *x){
    // Fazer Depois
}

void _rb_insert_fixup(rbtree *t, rbnode *z){
    rbnode *y;
    while(z->parent->color == RED){
        if(z->parent == z->parent->parent->left){
            y = z->parent->parent->right;

            // CASO UM
            if(y->color == RED){
                z->parent->color = y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }

            // CASO DOIS
            else{
                if(z = z->parent->parent->right){
                    z = z->parent;
                    left_rotate(t, z);
                }
                // CASO TRÊS
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                right_rotate(t, z->parent->parent); 
            }

            }else {
                y = z->parent->parent->left;
                //fazer depois
            }
        }// fim while 
        t->root->color = BLACK;
    }
int rbtree_insert(rbtree *t, int key){
    rbnode *z = malloc(sizeof(rbnode)), *x, *y;
    if(!z) return 0;
    z->key = key;
    x = t->root; y = t->nil;
    while(x != t->nil){
        y = x;
        if (key < X->key) x = x->left;
        else x = x->right;
    }
    z->parent = y;
    if(y == t->nil) t->root = z;
    else if(y->key < key) y->right = z;
    else y->left = z;
    z->left = z->right = t->nil;
    z->color = RED;
    _rb_insert_fixup(t, z);
    return 1;
}

void rbtree_erase(rbtree *t, int key) {
    //Fazer depois
}

void _rbtree_free(rbtree *t, rbnode *x) {
    if (x == t->nil) return;
    _rbtree_free(t, x->left);
    _rbtree_free(t, x->right);
    free(x);
}

void rbtree_free(rbtree *t) {
    _rbtree_free(t, t->root);
    free(t->nil);
}
