convert: convert.c check.c check.h usage.c usage.h
	gcc -o convert convert.c check.c usage.c
ctest: convert.c check.c check.h usage.c usage.h
	gcc -o ctest --coverage convert.c check.c usage.c