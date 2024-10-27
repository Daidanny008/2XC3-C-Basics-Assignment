convert: convert.c check.c check.h
	gcc -o convert convert.c check.c
ctest: convert.c check.c check.h
	gcc -o ctest --coverage convert.c check.c