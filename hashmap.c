#define HASHMAP_IMPLEMENTATION
#define HASHMAP_SIZE 69 
#define HASH_PRIME_NUMBER 2
#include "hashmap.h"

int main(void);

int main(void){
    Map *map = malloc(sizeof(Map));
    init_map(map);
    put_in_map(map, "key", "first");
    put_in_map(map, "key2", "second");
    put_in_map(map, "key3", "third");
    put_in_map(map, "key4", "fourth");
    put_in_map(map, "key5", "fifth");
    put_in_map(map, "key6", "sixth");
    put_in_map(map, "key7", "sixth");
    put_in_map(map, "key8", "sixth");
    put_in_map(map, "key9", "sixth");
    put_in_map(map, "key10", "sixth");
    put_in_map(map, "key11", "sixth");
    put_in_map(map, "key16", "sixth");
    put_in_map(map, "key56", "sixth");
    put_in_map(map, "key26", "sixth");
    put_in_map(map, "key36", "sixth");
    put_in_map(map, "key46", "sixth");
    put_in_map(map, "key556", "sixth");

    if(remove_from_map(map, "key2") != 0){
        fprintf(stderr, "error: could not remove from map\n");
        exit(1);
    }

    char *value = get_from_map(map, "key3");
    if(value == NULL){
        fprintf(stderr, "error: could not get item from map\n");
        exit(1);
    }

    printf("%s\n", value);



    PRINT_MAP(map, "%s", (char*)); // 2 collisions with default hashmap size of 69 and of hashmap prime number of 2

    delete_and_free_map(map);
}
