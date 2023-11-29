#define HASHMAP_IMPLEMENTATION
#define HASHMAP_SIZE 69 
#define HASH_PRIME_NUMBER 2
#include "hashmap.h"
#include "time.h"

#include "Cuazar/lib/Cuazar.h"

int main(void){
    Init_Cuazar(TRUE);

    __CUAZAR_RETURN__(bumpT(), 7, (int)hashmap_hash("test1"));
    __CUAZAR_RETURN__(bumpT(), 8, (int)hashmap_hash("test2"));
    __CUAZAR_RETURN__(bumpT(), 9, (int)hashmap_hash("test3"));
    __CUAZAR_RETURN__(bumpT(), 49, (int)hashmap_hash("asdjkhakjzhcjkahsdbanmxdjkahekjquosuasoidu"));

    Map *map = malloc(sizeof(Map));
    init_map(map);

    __CUAZAR_RETURN__(bumpT(), 0, put_in_map(map, "test1", "test1"));
    __CUAZAR_RETURN__(bumpT(), 0, put_in_map(map, "test2", "test2"));
    __CUAZAR_RETURN__(bumpT(), 0, put_in_map(map, "test3", "test3"));
    __CUAZAR_RETURN__(bumpT(), 0, put_in_map(map, "test4", "test4"));
    __CUAZAR_RETURN__(bumpT(), 0, put_in_map(map, "test5", "test5"));
    __CUAZAR_RETURN__(bumpT(), 0, put_in_map(map, "test6", "test6"));
    __CUAZAR_RETURN__(bumpT(), 0, put_in_map(map, "test7", "test6"));
    __CUAZAR_RETURN__(bumpT(), 0, put_in_map(map, "test8", "test6"));
    __CUAZAR_RETURN__(bumpT(), 0, put_in_map(map, "test9", "test6"));
    __CUAZAR_RETURN__(bumpT(), 0, put_in_map(map, "test10", "test6"));
    __CUAZAR_RETURN__(bumpT(), 0, put_in_map(map, "test11", "test6"));
    __CUAZAR_RETURN__(bumpT(), 0, put_in_map(map, "test12", "test6"));
    __CUAZAR_RETURN__(bumpT(), 0, put_in_map(map, "test19", "test6"));
    __CUAZAR_RETURN__(bumpT(), 0, put_in_map(map, "test20", "test6"));
    __CUAZAR_RETURN__(bumpT(), 0, put_in_map(map, "test106", "test6"));


    __CUAZAR_RETURN__(bumpT(), 0, remove_from_map(map, "test2"));
    __CUAZAR_RETURN__(bumpT(), 1, remove_from_map(map, "test2"));
    __CUAZAR_RETURN__(bumpT(), 0, remove_from_map(map, "test4"));
    __CUAZAR_RETURN__(bumpT(), 0, remove_from_map(map, "test6"));

    // expect NULL from function trying to remove empty slot
    __CUAZAR_EQUALS_PTR__(bumpT(), NULL, get_from_map(map, "test4"));
    __CUAZAR_EQUALS_PTR__(bumpT(), NULL, get_from_map(map, "test2"));
    __CUAZAR_EQUALS_STR__(bumpT(), "test1", (char*)get_from_map(map, "test1"));
    __CUAZAR_EQUALS_STR__(bumpT(), "test3", (char*)get_from_map(map, "test3"));
    __CUAZAR_EQUALS_STR__(bumpT(), "test5", (char*)get_from_map(map, "test5"));
    __CUAZAR_RETURN__(bumpT(), 0, put_in_map(map, "test6", "test6"));
    __CUAZAR_EQUALS_STR__(bumpT(), "test6", (char*)get_from_map(map, "test6"));

    PRINT_MAP(map, "%s", (char*));

    delete_and_free_map(map);

    map = malloc(sizeof(Map));
    init_map(map);

    // declare variables to insert into hashmap
    int value1 = 1;
    int value2 = 2;
    int value3 = 3;

    __CUAZAR_RETURN__(bumpT(), 0, put_in_map(map, "test1", &value1));
    __CUAZAR_RETURN__(bumpT(), 0, put_in_map(map, "test2", &value2));
    __CUAZAR_RETURN__(bumpT(), 0, put_in_map(map, "test3", &value3));
    __CUAZAR_RETURN__(bumpT(), 0, put_in_map(map, "null", NULL));

    __CUAZAR_RETURN__(bumpT(), 0, remove_from_map(map, "test3"));

    __CUAZAR_EQUALS_PTR__(bumpT(), NULL, get_from_map(map, "test3"));
    __CUAZAR_EQUALS_PTR__(bumpT(), NULL, get_from_map(map, "test40"));
    __CUAZAR_EQUALS_PTR__(bumpT(), NULL, get_from_map(map, "null"));

    __CUAZAR_RETURN__(bumpT(), value1, *(int*)get_from_map(map, "test1"));
    __CUAZAR_RETURN__(bumpT(), value1, *(int*)get_from_map(map, "test1"));
    __CUAZAR_RETURN__(bumpT(), value1, *(int*)get_from_map(map, "test1"));
    __CUAZAR_RETURN__(bumpT(), value2, *(int*)get_from_map(map, "test2"));

    PRINT_MAP(map, "%p", (void*));

    delete_and_free_map(map);
}
