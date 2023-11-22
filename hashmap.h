#ifndef HASHMAP_IMPLEMENTATION
#define HASHMAP_IMPLEMENTATION
_Static_assert(0, "Error, missing HASHMAP_IMPLEMENTATION definition\n");
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef HASHMAP_SIZE
#define HASHMAP_SIZE 69 
#endif
#ifndef HASH_PRIME_NUMBER
#define HASH_PRIME_NUMBER 2
#endif

typedef struct Hashmap_Node{
    char *key;
    void *value;
    struct Hashmap_Node *next;
} Hashmap_Node;

typedef struct {
    Hashmap_Node *hashmap[HASHMAP_SIZE];
    char *key;
} Map;

double hashmap_my_fmod(float num1, float num2);
static size_t hashmap_hash(char *key);
void init_map(Map *map);
int put_in_map(Map *map, char *key, void *value);
void *get_from_map(Map *map, char *key);
int remove_from_map(Map *map, char *key);
void delete_and_free_map(Map *map);

#define PRINT_MAP(map, printing_type, type) \
            do { \
                for(size_t i = 0; i < HASHMAP_SIZE; i++){ \
                    Hashmap_Node *node = map->hashmap[i]; \
                    if(node == NULL) { \
                        continue; \
                    } \
                    while(node != NULL){ \
                        printf("%s: "printing_type" -> ", node->key, type node->value); \
                        node = node->next;\
                    } \
                    printf("NULL\n"); \
                } \
            } while(0)

double hashmap_my_fmod(float num1, float num2){
    return num1 - (int)(num1 / num2) * num2;
}

size_t hashmap_mul_hash(char *key){
    size_t hash = 0; 
    float C = 1.618033988;

    for(size_t i = 0; i < strlen(key); i++){
        hash += (int)key[i];
    }

    return (int)(HASHMAP_SIZE * hashmap_my_fmod(hash * C, 1.0));
}

size_t hashmap_mod_hash(char *key){
    size_t hash = 0;
    for(size_t i = 0; i < strlen(key); i++){
        hash += (int)key[i];
    }
    return hash % HASHMAP_SIZE;
}

size_t hashmap_knuth_hash(char *key) {
    size_t hash = 0;
    for(size_t i = 0; i < strlen(key); i++){
        hash += (int)key[i];
    }
    return hash * (hash + 3) % HASHMAP_SIZE;
}

static size_t hashmap_hash(char *key) {
    size_t hash = HASH_PRIME_NUMBER;
    for(size_t i = 0; i < strlen(key); i++){
        hash = hash * 31 + (int)key[i];
    }
    return hash % HASHMAP_SIZE;
}

void init_map(Map *map){
    for(size_t i = 0; i < HASHMAP_SIZE; i++){
        map->hashmap[i] = NULL;
    }
}


int put_in_map(Map *map, char *key, void *value){
    size_t index = hashmap_hash(key); 
    Hashmap_Node *tmp = map->hashmap[index];
    Hashmap_Node *current = malloc(sizeof(Hashmap_Node));
    current->value = value;
    current->key = malloc(sizeof(char) * (strlen(key) + 1));
    strcpy(current->key, key);
    current->next = NULL;
    if(tmp != NULL) {
        Hashmap_Node *tmp = map->hashmap[index];
        while(tmp->next != NULL) {
           tmp = tmp->next; 
        }
        tmp->next = current;
    } else {
        map->hashmap[index] = current;
    }
    return 0;
}

void *get_from_map(Map *map, char *key) {
    size_t index = hashmap_hash(key);
    if(map->hashmap[index] == NULL) {
        return NULL;
    }
    if(strcmp(map->hashmap[index]->key, key) == 0){
        return map->hashmap[index]->value;
    } else {
        Hashmap_Node *current = map->hashmap[index];
        while(strcmp(current->key, key) != 0){
            if(current->next == NULL) {
                return NULL;
            }
            current = current->next;
        }
        return current->value;
    }
}

int remove_from_map(Map *map, char *key) {
    size_t index = hashmap_hash(key);
    Hashmap_Node *current = map->hashmap[index];
    if(current == NULL) {
        return 1; 
    }
    if(strcmp(current->key, key) == 0){
        Hashmap_Node *tmp = current;
        if(current->next != NULL){
            tmp = current->next;
            map->hashmap[index] = tmp;
            return 0;
        }
        free(current->key);
        free(current);
        map->hashmap[index] = NULL;
    } else {
        Hashmap_Node *tmp = map->hashmap[index];
        while(strcmp(tmp->next->key, key) != 0){
            if(tmp->next == NULL) {
                return 1;
            }
            tmp = tmp->next;
        }
        Hashmap_Node *tmp2 = tmp;
        if(tmp2->next->next != NULL){
            tmp2 = tmp2->next->next;
            free(tmp->next->key);
            free(tmp->next);
            tmp->next = tmp2;
        } else {
            free(tmp->next->key);
            free(tmp->next);
            tmp->next = NULL;
        }
    }
    return 0;
}

void delete_and_free_map(Map *map){
    for(size_t i = 0; i < HASHMAP_SIZE; i++){
        Hashmap_Node *node = map->hashmap[i];
        while(node != NULL){
            Hashmap_Node *tmp = node->next;
            free(node->key);
            free(node);
            node = NULL;
            node = tmp;
        }
    }
    free(map);
}
