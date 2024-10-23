convert: convert.c
	gcc -o convert convert.c
ctest: convert.c
	gcc -o ctest --coverage convert.c