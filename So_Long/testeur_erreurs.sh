#!/bin/bash
PATH_TO_MAP="map/error_maps"
make
for i in `ls ${PATH_TO_MAP}` ; 
    do echo $i && valgrind ./so_long ${PATH_TO_MAP}/$i ;
done
