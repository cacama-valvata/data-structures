da_cmocka: tests/dynarray_cmocka.c adt/dynarray.h
	gcc tests/dynarray_cmocka.c -I. -l cmocka 
