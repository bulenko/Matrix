#ifndef S21_MATRIX_OOP_H
#define S21_MATRIX_OOP_H
#include <cmath>
#include <cstring>
#include <iostream>
#define EPS 1e-7

class S21Matrix {
 private:
  // attributes
  int rows_, cols_;  // rows_ and columns attributes
  double *matrix_;   // pointer to the memory where the matrix will be allocated

 public:
  S21Matrix();                    // default constructor
  S21Matrix(int rows, int cols);  // parameterized constructor
  S21Matrix(const S21Matrix &o);  // copy cnstructor
  S21Matrix(S21Matrix &&o);       // move cnstructor
  ~S21Matrix();                   // destructor

  // some operators overloads
  S21Matrix &operator=(const S21Matrix &o);  // assignment operator overload
  bool operator==(const S21Matrix &o);
  double &operator()(int row, int col);  // index operator overload
  S21Matrix &operator+=(const S21Matrix &o);
  S21Matrix operator+(const S21Matrix &o);
  S21Matrix &operator-=(const S21Matrix &o);
  S21Matrix operator-(const S21Matrix &o);
  S21Matrix &operator*=(const S21Matrix &o);
  S21Matrix operator*(const S21Matrix &o);
  S21Matrix operator*(const double num);
  S21Matrix &operator*=(const double num);
  friend S21Matrix operator*(const double num, const S21Matrix &o);

  // some public methods
  bool eqMatrix(
      const S21Matrix &other);  //  Проверяет матрицы на равенство между собой
  void sumMatrix(
      const S21Matrix &other);  // Прибавляет вторую матрицы к текущей
                                // (исключение - различная размерность матриц)
  void subMatrix(
      const S21Matrix &other);  // Вычитает из текущей матрицы другую
                                // (исключение - различная размерность матриц)
  void mulNumber(const double num);  // Умножает текущую матрицу на число
  void mulMatrix(
      const S21Matrix &other);  // Умножает текущую матрицу на вторую
                                // (исключение -  число столбцов первой матрицы
                                // не равно числу строк второй матрицы)
  S21Matrix transpose();  //Создает новую транспонированную матрицу из текущей и
                          //возвращает ее
  S21Matrix calcComplements();  // Вычисляет матрицу алгебраических дополнений
                                // текущей матрицы и возвращает ее (исключение -
                                // матрица не является квадратной)
  double determinant();  // Вычисляет и возвращает определитель текущей матрицы
                         // (исключение - матрица не является квадратной)
  S21Matrix inverseMatrix();  // Вычисляет и возвращает обратную матрицу
                              // (исключение - определитель матрицы равен 0)
  // accessor and mutator
  void setRows(int nRows);
  void setCols(int nCols);
  int getRows();
  int getCols();
  void resizeMatrix(int nRows, int nCols);
  S21Matrix getMinor(int row, int col);
  S21Matrix getMatrixMinors();
  double minor(int row, int col);
};
#endif  // S21_MATRIX_OOP_H
