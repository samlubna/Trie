#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dict.h"
Node * createNode () {
    Node * node = malloc(sizeof(Node));
    for (int i = 0; i < MAX_SIZE; i++)
        node->children[i] = NULL;
    node->isWord = false;
    node->size = 0;
    return node;
}
bool insertWord (Node ** root, char * word) {
    if (word == NULL || !*word ) return false;
    if (*root == NULL) *root = createNode();
    char c = *word; Node * current = *root;
    while (c) {
        if (current->children[c] == NULL) {
            current->size++;
            current->children[c] = createNode();
        } current = current->children[c];
        word++; c = *word;
    }
    if (!current->isWord) {
        current->isWord = true;
        return true;
    } return false;
}
Node * deleteHelper (Node ** root, char * word) {
    Node * current = *root; char c = *word;
    if (c) {
        if (!current->children[c]) return current;
        current->children[c] = 
        deleteHelper(&current->children[c],word+1);
        current->size -= (!current->children[c]);
    } 
    else if (current->isWord) current->isWord = false;
    if (!current->size && !current->isWord) {
        free(current); current = NULL;
    }
    return current;
}
void deleteWord (Node ** root, char * word) {
    // Do nothing
    if (word != NULL && *word && *root != NULL) 
        *root = deleteHelper (&(*root), word);
    
}
bool searchWord (Node * root, char * word) {
    if (word == NULL || !*word || root == NULL) 
        return false;
    char c = *word;
    while (c) {
        if (!root->children[c])
            return false;
        root = root->children[c];
        word++; c = *word;
    }
    return root->isWord;
}
void printHelper (Node * root, char * c, size_t len) {
    if (root->isWord) printf("Word --> %s\n", c);
    char arr[len]; 
    if (c) memcpy(arr,c,len);
    arr[len-1] = '\0';
    for (int i = 0; i < MAX_SIZE; i++) {
        if (root->children[i]) {
            arr[len-2] = i;
            printHelper(root->children[i], arr, len + 1);
        }
    }
}
void printTree (Node * root) {
    if (root == NULL)
        printf("Empty Trie\n");
    else printHelper(root, NULL, 2);
}


