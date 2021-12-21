#ifndef DICT_H
#define DICT_H
#include "stdbool.h"
#include <stddef.h>
#define MAX_SIZE 128
typedef struct Node {
    struct Node * children [MAX_SIZE];
    bool isWord;
    int size;
} Node ;
Node * createNode();
bool insertWord (Node ** root, char * word);
bool searchWord (Node * root, char * word);
void deleteWord (Node ** root, char * word);
void printTree (Node * root);
#endif // DICT_H


