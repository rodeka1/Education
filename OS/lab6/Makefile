malloc:
	gcc malloc_test.c -o malloc_test
calloc:
	gcc calloc_test.c -o calloc_test
mi_malloc:
	gcc mi_malloc_test.c -o mi_malloc_test -lmimalloc
tc_malloc:
	gcc tc_malloc_test.c -o tc_malloc_test -ltcmalloc
all: malloc calloc mi_malloc tc_malloc
test: all
	./malloc_test
	./calloc_test
	./mi_malloc_test
	./tc_malloc_test
clean: 
	rm malloc_test calloc_test mi_malloc_test tc_malloc_test

