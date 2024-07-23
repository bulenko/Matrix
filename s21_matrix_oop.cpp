#include "s21_matrix_oop.h"

// construcrors and destructor
S21Matrix::S21Matrix() : S21Matrix(3, 3) {}

S21Matrix::S21Matrix(int rows, int cols) {
  if (rows < 1 || cols < 1) {
    throw std::out_of_range("Incorrect input, rows and cols should be > 0");
  }
  rows_ = rows;
  cols_ = cols;
  matrix_ = new double[rows_ * cols_]();
}

S21Matrix::S21Matrix(const S21Matrix &o) : rows_(o.rows_), cols_(o.cols_) {
  matrix_ = new double[o.rows_ * o.cols_]();
  memcpy(matrix_, o.matrix_, o.rows_ * o.cols_ * sizeof(double));
}

S21Matrix::S21Matrix(S21Matrix &&o)
    : rows_(o.rows_), cols_(o.cols_), matrix_(o.matrix_) {
  o.matrix_ = NULL;
  o.rows_ = 0;
  o.cols_ = 0;
}

S21Matrix::~S21Matrix() {
  if (matrix_) {
    delete[] matrix_;
  }
}

// setters and getters
void S21Matrix::setRows(int nRows) {
  if (nRows < 1) {
    throw std::out_of_range("Incorrect input, rows_ should be > 0");
  }
  resizeMatrix(nRows, cols_);
}

void S21Matrix::setCols(int nCols) {
  if (nCols < 1) {
    throw std::out_of_range("Incorrect input, cols should be > 0");
  }
  resizeMatrix(rows_, nCols);
}

int S21Matrix::getRows() { return rows_; };
int S21Matrix::getCols() { return cols_; };

// additional functions
void S21Matrix::resizeMatrix(int nRows, int nCols) {
  if (nRows < 1 || nCols < 1) {
    throw std::out_of_range("Incorrect input, rows and cols should be > 0");
  }
  double *res = new double[nRows * nCols]();

  for (int k = 0; k < rows_ * cols_; ++k) {
    int temp_i = k / cols_;
    int temp_j = k % cols_;
    if (temp_i >= nRows || temp_j >= nCols) continue;
    res[temp_i * nCols + temp_j] = matrix_[k];
  }

  delete[] matrix_;
  rows_ = nRows;
  cols_ = nCols;
  matrix_ = res;
}

// operator overload
S21Matrix &S21Matrix::operator=(const S21Matrix &o) {
  if (&o == this) {
  } else {
    delete[] matrix_;
    matrix_ = new double[o.rows_ * o.cols_]();
    memcpy(matrix_, o.matrix_, o.cols_ * o.rows_ * sizeof(double));
    rows_ = o.rows_;
    cols_ = o.cols_;
  }
  return *this;
}

bool S21Matrix::operator==(const S21Matrix &o) { return this->eqMatrix(o); }

S21Matrix S21Matrix::operator+(const S21Matrix &o) {
  S21Matrix res = S21Matrix(*this);
  res.sumMatrix(o);
  return res;
}

S21Matrix &S21Matrix::operator+=(const S21Matrix &o) {
  sumMatrix(o);
  return *this;
}

S21Matrix S21Matrix::operator-(const S21Matrix &o) {
  S21Matrix res = S21Matrix(*this);
  res.subMatrix(o);
  return res;
}

S21Matrix &S21Matrix::operator-=(const S21Matrix &o) {
  subMatrix(o);
  return *this;
}

S21Matrix S21Matrix::operator*(const S21Matrix &o) {
  S21Matrix res = S21Matrix(*this);
  res.mulMatrix(o);
  return res;
}

S21Matrix &S21Matrix::operator*=(const S21Matrix &o) {
  mulMatrix(o);
  return *this;
}

S21Matrix S21Matrix::operator*(const double num) {
  S21Matrix res = S21Matrix(*this);
  res.mulNumber(num);
  return res;
}

S21Matrix operator*(const double num, const S21Matrix &o) {
  S21Matrix res = S21Matrix(o);
  res.mulNumber(num);
  return res;
}

S21Matrix &S21Matrix::operator*=(const double num) {
  mulNumber(num);
  return *this;
}

double &S21Matrix::operator()(int row, int col) {
  if (row >= rows_ || col >= cols_ || col < 0 || row < 0) {
    throw std::out_of_range("Incorrect input, index is out of range");
  }
  return matrix_[row * cols_ + col];
}

// funstions
/* true = 1;
false = 0 */
bool S21Matrix::eqMatrix(const S21Matrix &o) {
  if (o.rows_ != rows_ || o.cols_ != cols_) return false;

  for (int i = 0; i < rows_ * cols_; ++i) {
    if (fabs(matrix_[i] - o.matrix_[i]) > EPS) return false;
  }
  return true;
}

void S21Matrix::sumMatrix(const S21Matrix &o) {
  if (rows_ != o.rows_ || cols_ != o.cols_) {
    throw std::out_of_range(
        "Incorrect input, matrices should have the same size");
  }
  for (int i = 0; i < rows_ * cols_; i++) {
    matrix_[i] = matrix_[i] + o.matrix_[i];
  }
}

void S21Matrix::subMatrix(const S21Matrix &o) {
  if (rows_ != o.rows_ || cols_ != o.cols_) {
    throw std::out_of_range(
        "Incorrect input, matrices should have the same size");
  }
  for (int i = 0; i < rows_ * cols_; i++) {
    matrix_[i] = matrix_[i] - o.matrix_[i];
  }
}

void S21Matrix::mulNumber(const double num) {
  for (int i = 0; i < rows_ * cols_; i++) {
    matrix_[i] = matrix_[i] * num;
  }
}

void S21Matrix::mulMatrix(const S21Matrix &o) {
  if (cols_ != o.rows_) {
    throw std::out_of_range(
        "Incorrect input, cols_1 should be the same size as rows_2");
  }
  double *res = new double[rows_ * o.cols_]();
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < o.cols_; ++j) {
      for (int k = 0; k < cols_; ++k) {
        res[i * o.cols_ + j] +=
            matrix_[i * cols_ + k] * o.matrix_[k * o.cols_ + j];
      }
    }
  }
  delete[] matrix_;
  cols_ = o.cols_;
  matrix_ = res;
}

S21Matrix S21Matrix::transpose() {
  S21Matrix res = S21Matrix(cols_, rows_);
  for (int k = 0; k < res.rows_ * res.cols_; ++k) {
    res.matrix_[k / res.cols_ * res.cols_ + k % res.cols_] =
        matrix_[k % res.cols_ * cols_ + k / res.cols_];
  }
  return res;
}

S21Matrix S21Matrix::calcComplements() {
  if (rows_ != cols_) {
    throw std::out_of_range(
        "Incorrect input, rows_ should be the same as cols_.");
  }
  S21Matrix res = S21Matrix(rows_, cols_);
  if (rows_ == 1 && cols_ == 1) {
    res.matrix_[0] = 1;
  } else {
    S21Matrix matrix_a = getMatrixMinors();
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        if ((i + j) % 2 == 0) {
          res.matrix_[i * cols_ + j] = matrix_a.matrix_[i * cols_ + j];
        } else {
          res.matrix_[i * cols_ + j] = matrix_a.matrix_[i * cols_ + j] * (-1);
        }
      }
    }
  }
  return res;
}

double S21Matrix::determinant() {
  double res = 0;
  if (rows_ != cols_) {
    throw std::out_of_range(
        "Incorrect input, rows_ should be the same as cols_.");
  } else if (rows_ == 1) {
    res = matrix_[0];
  } else if (rows_ == 2) {
    res = matrix_[0] * matrix_[3] - matrix_[2] * matrix_[1];
  } else {
    S21Matrix cc = calcComplements();
    for (int i = 0; i < cols_; ++i) {
      res = matrix_[i] * cc.matrix_[i] + res;
    }
  }
  return res;
}

S21Matrix S21Matrix::inverseMatrix() {
  if (rows_ != cols_) {
    throw std::out_of_range(
        "Incorrect input, rows_ should be the same as cols_.");
  } else if (fabs(determinant()) <= EPS) {
    throw std::out_of_range(
        "Incorrect input, fabs(determinant) should be > 0.");
  }
  S21Matrix res = S21Matrix(rows_, cols_);
  if (rows_ == 1) {
    res.rows_ = 1;
    res.cols_ = 1;
    res.matrix_[0] = 1 / matrix_[0];
  } else {
    res = calcComplements();
    res = res.transpose();
    res.mulNumber(1 / determinant());
  }
  return res;
}

S21Matrix S21Matrix::getMinor(int row, int col) {
  if (rows_ != cols_) {
    throw std::out_of_range(
        "Incorrect input, rows_ should be the same as cols_.");
  }
  if (rows_ == 1) {
    throw std::out_of_range("Incorrect input, rows_ should be > 0.");
  }
  int n = 0;
  S21Matrix res = S21Matrix(rows_ - 1, cols_ - 1);
  for (int i = 0; i < rows_; ++i) {
    if (i == row) continue;
    int m = 0;
    for (int j = 0; j < cols_; ++j) {
      if (j == col) continue;
      res.matrix_[n * (cols_ - 1) + m] = matrix_[i * cols_ + j];
      m++;
    }
    n++;
  }
  return res;
}

double S21Matrix::minor(int row, int col) {
  double res = 0;
  S21Matrix gm = getMinor(row, col);
  res = gm.determinant();
  return res;
}

S21Matrix S21Matrix::getMatrixMinors() {
  double min;
  S21Matrix res(rows_, cols_);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      min = minor(i, j);
      res.matrix_[i * cols_ + j] = min;
    }
  }
  return res;
}
