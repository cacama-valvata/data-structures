da_naive: tests/naive_test.c adt/dynarray.h
	gcc tests/naive_test.c -I.

da_cmocka: tests/dynarray_cmocka.c adt/dynarray.h
	gcc tests/dynarray_cmocka.c -I. -l cmocka 

da_unity: tests/dynarray_unity.c adt/dynarray.h Unity/src/unity.h libunity.so
	gcc tests/dynarray_unity.c -I. -L $(PWD) -l unity -Wl,-rpath,. -Wl,--wrap=da_create 

da_softunity: tests/dynarray_softunity.c adt/dynarray.h Unity/src/unity.h libunity.so
	gcc tests/dynarray_softunity.c -I. -L $(PWD) -l unity -Wl,-rpath,. -Wl,--wrap=da_create 

libunity.so: Unity/src/unity.h Unity/src/unity_internals.h Unity/src/unity.c
	gcc -shared -o libunity.so -fPIC Unity/src/unity.c -I.

clean:
	rm a.out *.o *.so