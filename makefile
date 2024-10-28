convert: convert.c check.c check.h usage.c usage.h help.c help.h ProcessingNum.c ProcessingNum.h ConvertNumToBase.c ConvertNumToBase.h
	gcc -o convert convert.c check.c usage.c help.c ProcessingNum.c ConvertNumToBase.c
ctest: convert.c check.c check.h usage.c usage.h help.c help.h ProcessingNum.c ProcessingNum.h ConvertNumToBase.c ConvertNumToBase.h
	gcc -o ctest --coverage convert.c check.c usage.c help.c ProcessingNum.c ConvertNumToBase.c