#define HASHMAP_IMPLEMENTATION
#define HASHMAP_SIZE 69 
#define HASH_PRIME_NUMBER 2
#include "hashmap.h"
#include "time.h"

#include "Cuazar/lib/Cuazar.c"
#include "Cuazar/lib/Cuazar.h"

int testModeIsOn;

int testCount = 0;

int iota(void) {
    return testCount++;
}

int main(void){
    Init_Cuazar();
    Map *map = malloc(sizeof(Map));
    init_map(map);

    __CUAZAR_RETURN__(iota(), 0, put_in_map(map, "test1", "test1"));
    __CUAZAR_RETURN__(iota(), 0, put_in_map(map, "test2", "test2"));
    __CUAZAR_RETURN__(iota(), 0, put_in_map(map, "test3", "test3"));
    __CUAZAR_RETURN__(iota(), 0, put_in_map(map, "test4", "test4"));
    __CUAZAR_RETURN__(iota(), 0, put_in_map(map, "test5", "test5"));
    __CUAZAR_RETURN__(iota(), 0, put_in_map(map, "test6", "test6"));


    __CUAZAR_RETURN__(iota(), 0, remove_from_map(map, "test2"));
    __CUAZAR_RETURN__(iota(), 1, remove_from_map(map, "test2"));
    __CUAZAR_RETURN__(iota(), 0, remove_from_map(map, "test4"));
    __CUAZAR_RETURN__(iota(), 0, remove_from_map(map, "test6"));

    // expect NULL from function trying to remove empty slot
    __CUAZAR_RETURN_PTR__(iota(), NULL, get_from_map(map, "test4"));
    __CUAZAR_RETURN_PTR__(iota(), NULL, get_from_map(map, "test2"));
    __CUAZAR_EQUALS_STR__(iota(), "test1", (char*)get_from_map(map, "test1"));
    __CUAZAR_EQUALS_STR__(iota(), "test3", (char*)get_from_map(map, "test3"));
    __CUAZAR_EQUALS_STR__(iota(), "test5", (char*)get_from_map(map, "test5"));
    __CUAZAR_RETURN__(iota(), 0, put_in_map(map, "test6", "test6"));
    __CUAZAR_EQUALS_STR__(iota(), "test6", (char*)get_from_map(map, "test6"));

    PRINT_MAP(map, "%s", (char*));

    delete_and_free_map(map);

    testCount = 100;

    map = malloc(sizeof(Map));
    init_map(map);

    // declare variables to insert into hashmap
    int value1 = 1;
    int value2 = 2;
    int value3 = 3;

    __CUAZAR_RETURN__(iota(), 0, put_in_map(map, "test1", &value1));
    __CUAZAR_RETURN__(iota(), 0, put_in_map(map, "test2", &value2));
    __CUAZAR_RETURN__(iota(), 0, put_in_map(map, "test3", &value3));
    __CUAZAR_RETURN__(iota(), 0, put_in_map(map, "null", NULL));

    __CUAZAR_RETURN__(iota(), 0, remove_from_map(map, "test3"));

    __CUAZAR_RETURN_PTR__(iota(), NULL, get_from_map(map, "test3"));
    __CUAZAR_RETURN_PTR__(iota(), NULL, get_from_map(map, "test40"));
    __CUAZAR_RETURN_PTR__(iota(), NULL, get_from_map(map, "null"));

    __CUAZAR_RETURN__(iota(), value1, *(int*)get_from_map(map, "test1"));
    __CUAZAR_RETURN__(iota(), value1, *(int*)get_from_map(map, "test1"));
    __CUAZAR_RETURN__(iota(), value1, *(int*)get_from_map(map, "test1"));
    __CUAZAR_RETURN__(iota(), value2, *(int*)get_from_map(map, "test2"));

    PRINT_MAP(map, "%p", (void*));

    delete_and_free_map(map);
}
