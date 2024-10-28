convert: convert.c check.c check.h usage.c usage.h help.c help.h
	gcc -o convert convert.c check.c usage.c help.c
ctest: convert.c check.c check.h usage.c usage.h help.c help.h
	gcc -o ctest --coverage convert.c check.c usage.c help.c