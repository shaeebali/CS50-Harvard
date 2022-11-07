// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;
//Prototypes
unsigned int hash(const char *word);

// TODO: Choose number of buckets in hash table
const unsigned int N = 187751;

// Hash table
node *table[N]; //may need to use calloc

//word count
int word_count = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    for (node *tmp = table[hash(word)]; tmp != NULL; tmp = tmp->next) //iterate through bucket
    {
        if (strcasecmp(tmp->word, word) == 0) //compare strings
        {
            return true;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int hash = 0;

    for (int i = 0; i <= strlen(word); i++)
    {
        hash = (31 * hash + toupper(word[i])) % N;
    }
    return hash;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        return false;
    }
    //create temp string for word
    char *word = malloc(LENGTH + 1);
    if (word == NULL)
    {
        return false;
    }
    //read words from dictionary and write to hash table
    while (fscanf(dict, "%s", word) != EOF)
    {
        //node *tmp_word = NULL;
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        int pos = hash(word);
        strcpy(n->word, word);
        if (table[pos] == NULL)
        {
            n->next = NULL;
        }
        else
        {
            n->next = table[pos];
        }
        table[pos] = n;
        word_count++;
    }
    fclose(dict);
    free(word);

    return true;
}

unsigned int size(void)
{
    return word_count;
}


bool unload(void)
{
    // TODO
    for (int i = 0; i <= N; i++)
    {
        while (table[i] != NULL)
        {
            node *tmp = table[i]->next;
            free(table[i]);
            table[i] = tmp;
        }
    }
    return true;
}
