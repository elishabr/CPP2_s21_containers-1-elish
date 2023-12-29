GCC := gcc -Werror -Wextra -Wall --std=c++17 -lstdc++ -lm
SANITIZER := -fsanitize=address
SOURSE := tests_for_tree/*.cc
FLAGS_LCOV := -g -fprofile-arcs -ftest-coverage
FLAGS_GTEST := -lgtest -lgcov -pthread
OS = $(shell uname)

all:

test: clean
	$(GCC) $(SANITIZER) $(FLAGS_LCOV) $(SOURSE) $(FLAGS_GTEST) -o s21_test
	./s21_test
gcov_report: test
	lcov  -t test -o rep.info -c -d .
	genhtml -o report rep.info
	rm -rf gcovreport gcovreport.info *.gcda *.gcno math_test.gcda math_test.gcno
	open ./report/index.html
clean:
	rm -rf s21_test
	rm -rf *.o test *.a a.out *.gcno *.gcda s21_test.dSYM *.info report *.gch
check: test
	clang-format -style="{BasedOnStyle: Google}" -n tests_for_tree/*.* AVLTree.cc AVLTree.h
	clang-format -style="{BasedOnStyle: Google}" -i tests_for_tree/*.* AVLTree.cc AVLTree.h
#cppcheck --enable=all --suppress=missingIncludeSystem --inconclusive --check-config AVLTree.cc AVLTree.h
ifeq ($(OS), Darwin)
	leaks --atExit -- ./s21_test
else
	CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=RESULT_VALGRIND.txt ./s21_test
endif