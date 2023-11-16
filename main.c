#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHMAP_SIZE 1

typedef struct Node{
    char *key;
    int value;
    struct Node *next;
} Node;

typedef struct {
    Node *hashmap[HASHMAP_SIZE];
    char *key;
} Map;

size_t hash(char *key){
    size_t hash = 0; 

    for(size_t i = 0; i < strlen(key); i++){
        hash += ((int)key[i] * 10) / 3;
    }

    return hash % HASHMAP_SIZE;
}

void init_map(Map *map){
    for(size_t i = 0; i < HASHMAP_SIZE; i++){
        map->hashmap[i] = NULL;
    }
}

int put_in_map(Map *map, char *key, int value){
    size_t index = hash(key); 
    Node *tmp = map->hashmap[index];
    Node *current = malloc(sizeof(Node));
    current->value = value;
    current->key = malloc(sizeof(char) * strlen(key));
    current->key = key;
    current->next = NULL;
    if(tmp != NULL) {
        Node *tmp = map->hashmap[index];
        while(tmp->next != NULL) {
           tmp = tmp->next; 
        }
        tmp->next = current;
    } else {
        map->hashmap[index] = current;
    }
    return 0;
}

int get_from_map(Map *map, char *key, int *value) {
    size_t index = hash(key);
    if(map->hashmap[index] == NULL) {
        return 1;
    }
    if(strcmp(map->hashmap[index]->key, key) == 0){
        *value = map->hashmap[index]->value;
        return 0;
    } else {
        Node *current = map->hashmap[index];
        while(strcmp(current->key, key) != 0){
            if(current->next == NULL) {
                return 1;
            }
            current = current->next;
        }
        *value = current->value;
        return 0;
    }
}

int remove_from_map(Map *map, char *key) {
    size_t index = hash(key);
    Node *current = map->hashmap[index];
    if(current == NULL) {
        return 1; 
    }
    if(strcmp(current->key, key) == 0){
        Node *tmp = current;
        if(current->next != NULL){
            tmp = current->next;
            map->hashmap[index] = tmp;
            return 0;
        }
        free(current);
        map->hashmap[index] = NULL;
    } else {
        Node *tmp = map->hashmap[index];
        while(strcmp(tmp->next->key, key) != 0){
            if(tmp->next == NULL) {
                return 1;
            }
            tmp = tmp->next;
        }
        Node *tmp2 = tmp;
        if(tmp2->next->next != NULL){
            tmp2 = tmp2->next->next;
            tmp->next = tmp2;
        } else {
            free(tmp->next);
            tmp->next = NULL;
        }
    }
    return 0;
}

void handle_error(int error) {
    if(error != 0){
        fprintf(stderr, "error\n");
        exit(1);
    }
}

int main(){
    Map *map = malloc(sizeof(Map));
    init_map(map);
    int error = put_in_map(map, "hello", 15);
    handle_error(error);
    error = put_in_map(map, "what", 11);
    handle_error(error);
    error = put_in_map(map, "up", 20);
    handle_error(error);
    int value;
    error = get_from_map(map, "wht", &value);
    handle_error(error);
    printf("%d\n", value);
}
