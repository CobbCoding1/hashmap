# Hashmap
Simple hashmap implementation in C

Key has to be a string, but the value can be any pointer.

## Init map
```C
Map map;
init_map(&map); // initializes with NULL values
```


## Place in map
```C
if(put_in_map(map, "key", "value") != 0) {
    // error: could not place in map
}

int value = 12;
if(put_in_map(map, "key", &value) != 0) {
    // error: could not place in map
}
```

## Get from map
```C
int *value = get_from_map(&map, "key");
if(value == NULL) {
    // error: could not find in map
}
printf("%d\n", *value);
```

## Remove from map
```C
if(remove_from_map(&map, "key") != 0){
    // error: could not remove from map
}
```

## Print map
```C
PRINT_MAP(&map //name of map, "%s" //printf symbol for value, (char*) //value data type);
```

## Delete and free map
```C
delete_and_free_map(&map);
```

