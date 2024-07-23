COMPILER = g++
CFLAGS = -lgtest -std=c++17 -g -fno-elide-constructors -Wextra -Werror -Wall

all rebuild: clean s21_matrix_oop.a

clean:
	rm -rf *.o *.a *.gcno *.gcda *.info *.gch *.out *.gcov *.txt coverage_report report main

s21_matrix_oop.o: clean s21_matrix_oop.cpp
	$(COMPILER) $(CFLAGS) -c s21_matrix_oop.cpp

s21_matrix_oop.a: s21_matrix_oop.o
	ar rc libs21_matrix_oop.a s21_matrix_oop.o
	ranlib libs21_matrix_oop.a
	cp libs21_matrix_oop.a s21_matrix_oop.a

test:
	$(COMPILER)  main.cpp s21_matrix_oop.cpp $(CFLAGS) -o main
	./main

clang:
	clang-format -n *.cpp *.h

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem --std=c++17 --language=c++ *.cpp *.h

leaks_linux: clean test
	valgrind --trace-children=yes --track-fds=yes --leak-check=yes --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind_log.txt ./main 9>&1 
	tail -n 8 valgrind_log.txt

leaks_mac: clean test
	CK_FORK=no leaks --atExit -- ./main

gcov_report: clean
	$(COMPILER)  --coverage -fno-elide-constructors s21_matrix_oop.cpp main.cpp $(CFLAGS) -o main
	./main
	lcov -c --directory . --output-file s21_matrix_oop_coverage.info
	genhtml s21_matrix_oop_coverage.info --output-directory coverage_report

