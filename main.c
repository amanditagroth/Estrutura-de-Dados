#include"untitle.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    rbtree t;
    rbnode x;
    int n = 0;
    char c, d;
    char letra;
    char* mean = malloc(0);
    char* word = malloc(0);
    scanf("%c", &letra);
    switch (letra)
    {
    case 'i':
        while ((c = getchar()) != '\n') {
        word = (char *)realloc(word, (++n) * sizeof(char));
        word[n - 1] = c;
        }
        n = 0;
        while ((d = getchar()) != '\n') {
        mean = (char *)realloc(mean, (++n) * sizeof(char));
        mean[n - 1] = d;
        }
        rbtree_insert(&t, &x, word, mean);

    break;

    case 'q':
        
    break;

    case 'e':
        
    break;

    case 'p':
        
    break;
    
    default:
        break;
    }

    return 0;
}