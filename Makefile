# Makefile

all: lib/libdynarray.so

da_install: lib/libdynarray.so inc/dynarray.h
	cp inc/dynarray.h /usr/include/adt/
	cp lib/libdynarray.so /usr/lib/adt/
	ln /usr/lib/adt/libdynarray.so /usr/lib/libdynarray.so

da_uninstall:
	rm /usr/include/dynarray.h
	rm /usr/lib/adt/libdynarray.so

lib/libdynarray.so: adt/dynarray.c inc/dynarray.h lib/
	gcc -I. -shared -o lib/libdynarray.so -fPIC adt/dynarray.c

lib/:
	mkdir -p lib/

clean:
	rm -rf a.out *.o *.so

#test_naive: tests/other/naive_test.c inc/dynarray.h
#	gcc tests/other/naive_test.c adt/dynarray.c -I.

#test_cmocka: tests/other/dynarray_cmocka.c adt/dynarray.h
#	gcc tests/other/dynarray_cmocka.c -I. -l cmocka 

#test_unity: tests/other/dynarray_unity.c adt/dynarray.h Unity/src/unity.h libunity.so
#	gcc tests/other/dynarray_unity.c -I. -L $(PWD) -l unity -Wl,-rpath,. -Wl,--wrap=da_create 

#test_softunity: tests/other/dynarray_softunity.c adt/dynarray.h Unity/src/unity.h libunity.so
#	gcc tests/other/dynarray_softunity.c -I. -L $(PWD) -l unity -Wl,-rpath,. -Wl,--wrap=da_create 

#libunity.so: Unity/src/unity.h Unity/src/unity_internals.h Unity/src/unity.c
#	gcc -shared -o libunity.so -fPIC Unity/src/unity.c -I.