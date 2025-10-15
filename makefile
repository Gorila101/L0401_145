# Компилятор и флаги
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# Имена исходников и бинарников
MAIN_SRC = main.cpp
TESTS_SRC = tests.cpp
HEADERS = my_qsort.h

MAIN_EXE = main
TESTS_EXE = tests

# === Цели сборки ===

# Цель по умолчанию
all: $(MAIN_EXE) $(TESTS_EXE)

# Сборка основной программы
$(MAIN_EXE): $(MAIN_SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(MAIN_SRC) -o $(MAIN_EXE)

# Сборка тестов
$(TESTS_EXE): $(TESTS_SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(TESTS_SRC) -o $(TESTS_EXE)

# Очистка
clean:
	rm -f $(MAIN_EXE) $(TESTS_EXE)

# Запуск программы
run: $(MAIN_EXE)
	./$(MAIN_EXE)

# Запуск тестов
test: $(TESTS_EXE)
	./$(TESTS_EXE)

.PHONY: all clean run test

