#include <gtest/gtest.h>

#include "s21_matrix_oop.h"

TEST(S21Matrix, True_1) {
  S21Matrix matrix_a;
  ASSERT_TRUE(matrix_a.getRows() == 3);
  ASSERT_TRUE(matrix_a.getCols() == 3);
}

TEST(S21Matrix, True_1_1) { ASSERT_ANY_THROW(S21Matrix matrix_a(-3, -3)); }
TEST(eqMatrix, True_2) {
  S21Matrix matrix_a(3, 3);
  S21Matrix matrix_b(3, 3);
  ASSERT_TRUE(matrix_a == matrix_b);
}
TEST(eqMatrix, False_3) {
  S21Matrix matrix_a(3, 3);
  S21Matrix matrix_b(2, 2);
  ASSERT_FALSE(matrix_a == matrix_b);
}
TEST(eqMatrix, Throw_4) {
  S21Matrix matrix_a(2, 2);
  S21Matrix matrix_b(2, 2);

  matrix_a(0, 0) = 3.14;
  matrix_a(0, 1) = 0.56;
  matrix_a(1, 0) = -69.3;
  matrix_a(1, 1) = 0;

  matrix_b(0, 0) = -78.14;
  matrix_b(0, 1) = 0;
  matrix_b(1, 0) = -0.3;
  matrix_b(1, 1) = 2;

  ASSERT_FALSE(matrix_a == matrix_b);
}
TEST(sumMatrix, True_5) {
  S21Matrix matrix_a(2, 2);
  S21Matrix matrix_b(2, 2);
  S21Matrix result(2, 2);

  matrix_a(0, 0) = 3.14;
  matrix_a(0, 1) = 0.56;
  matrix_a(1, 0) = -69.3;
  matrix_a(1, 1) = 0;

  matrix_b(0, 0) = -78.14;
  matrix_b(0, 1) = 0;
  matrix_b(1, 0) = -0.3;
  matrix_b(1, 1) = 2;

  result(0, 0) = -75;
  result(0, 1) = 0.56;
  result(1, 0) = -69.6;
  result(1, 1) = 2;
  matrix_a.sumMatrix(matrix_b);
  ASSERT_TRUE(matrix_a == result);
}
TEST(sumMatrix, False_6) {
  S21Matrix matrix_a(1, 2);
  S21Matrix matrix_b(2, 2);

  matrix_a(0, 0) = 3.14;
  matrix_a(0, 1) = 0.56;

  matrix_b(0, 0) = -78.14;
  matrix_b(0, 1) = 0;
  matrix_b(1, 0) = -0.3;
  matrix_b(1, 1) = 2;

  ASSERT_ANY_THROW(matrix_a.sumMatrix(matrix_b));
}
TEST(subMatrix, True_7) {
  S21Matrix matrix_a(2, 2);
  S21Matrix matrix_b(2, 2);
  S21Matrix result(2, 2);

  matrix_a(0, 0) = 3;
  matrix_a(0, 1) = 2;
  matrix_a(1, 0) = -6;
  matrix_a(1, 1) = 0;

  matrix_b(0, 0) = -7;
  matrix_b(0, 1) = 0;
  matrix_b(1, 0) = -3;
  matrix_b(1, 1) = 2;

  result(0, 0) = 10;
  result(0, 1) = 2;
  result(1, 0) = -3;
  result(1, 1) = -2;

  matrix_a.subMatrix(matrix_b);

  ASSERT_TRUE(matrix_a == result);
}
TEST(subMatrix, False_8) {
  S21Matrix matrix_a(1, 2);
  S21Matrix matrix_b(2, 2);

  matrix_a(0, 0) = 3;
  matrix_a(0, 1) = 2;

  matrix_b(0, 0) = -7;
  matrix_b(0, 1) = 0;
  matrix_b(1, 0) = -3;
  matrix_b(1, 1) = 2;

  ASSERT_ANY_THROW(matrix_a.sumMatrix(matrix_b));
}
TEST(mulNumber, True_9) {
  S21Matrix matrix_a(2, 2);
  S21Matrix result(2, 2);

  matrix_a(0, 0) = -78.14;
  matrix_a(0, 1) = 0;
  matrix_a(1, 0) = -0.3;
  matrix_a(1, 1) = 2;

  result(0, 0) = -781.4;
  result(0, 1) = 0;
  result(1, 0) = -3;
  result(1, 1) = 20;

  matrix_a.mulNumber(10);

  ASSERT_TRUE(matrix_a == result);
}
TEST(mulNumber, True_10) {
  S21Matrix matrix_a(2, 2);

  matrix_a(0, 0) = -78.14;
  matrix_a(0, 1) = 0;
  matrix_a(1, 0) = -0.3;
  matrix_a(1, 1) = 2;

  S21Matrix b = matrix_a * 2;

  ASSERT_TRUE(matrix_a == matrix_a);
}
TEST(mulMatrix, True_11) {
  S21Matrix matrix_a(2, 2);
  S21Matrix matrix_b(2, 2);
  S21Matrix result(2, 2);

  matrix_a(0, 0) = 3;
  matrix_a(0, 1) = 2;
  matrix_a(1, 0) = -6.6;
  matrix_a(1, 1) = 0;

  matrix_b(0, 0) = -7;
  matrix_b(0, 1) = 0;
  matrix_b(1, 0) = -3.5;
  matrix_b(1, 1) = 2;

  result(0, 0) = -28;
  result(0, 1) = 4;
  result(1, 0) = 46.2;
  result(1, 1) = 0;

  matrix_a.mulMatrix(matrix_b);

  ASSERT_TRUE(matrix_a == result);
}
TEST(mulMatrix, False_12) {
  S21Matrix matrix_a(2, 1);
  S21Matrix matrix_b(2, 2);
  ASSERT_ANY_THROW(matrix_a.mulMatrix(matrix_b));
}
TEST(OperatorParentheses, True_13) {
  S21Matrix matrix_a(2, 2);

  matrix_a(0, 0) = 3;
  matrix_a(0, 1) = 2;
  matrix_a(1, 0) = -6.6;
  matrix_a(1, 1) = 0;
  ASSERT_DOUBLE_EQ(matrix_a(0, 1), 2);
}
TEST(OperatorParentheses, False_14) {
  S21Matrix matrix_a(2, 2);

  matrix_a(0, 0) = 3;
  matrix_a(0, 1) = 2;
  matrix_a(1, 0) = -6.6;
  matrix_a(1, 1) = 0;
  ASSERT_NE(matrix_a(0, 1), 10);
}
TEST(OperatorPlus, True_15) {
  S21Matrix matrix_a(2, 2);
  S21Matrix matrix_b(2, 2);
  S21Matrix result(2, 2);

  matrix_a(0, 0) = 3.14;
  matrix_a(0, 1) = 0.56;
  matrix_a(1, 0) = -69.3;
  matrix_a(1, 1) = 0;

  matrix_b(0, 0) = -78.14;
  matrix_b(0, 1) = 0;
  matrix_b(1, 0) = -0.3;
  matrix_b(1, 1) = 2;

  result(0, 0) = -75;
  result(0, 1) = 0.56;
  result(1, 0) = -69.6;
  result(1, 1) = 2;

  ASSERT_TRUE((matrix_a + matrix_b) == result);
}
TEST(OperatorPlus, False_16) {
  S21Matrix matrix_a(2, 2);
  S21Matrix matrix_b(3, 2);
  ASSERT_ANY_THROW(matrix_a + matrix_b);
}
TEST(OperatorMinus, True_17) {
  S21Matrix matrix_a(2, 2);
  S21Matrix matrix_b(2, 2);
  S21Matrix result(2, 2);

  matrix_a(0, 0) = 3;
  matrix_a(0, 1) = 2;
  matrix_a(1, 0) = -6;
  matrix_a(1, 1) = 0;

  matrix_b(0, 0) = -7;
  matrix_b(0, 1) = 0;
  matrix_b(1, 0) = -3;
  matrix_b(1, 1) = 2;

  result(0, 0) = 10;
  result(0, 1) = 2;
  result(1, 0) = -3;
  result(1, 1) = -2;

  ASSERT_TRUE((matrix_a - matrix_b) == result);
}
TEST(OperatorMinus, False_18) {
  S21Matrix matrix_a(2, 2);
  S21Matrix matrix_b(3, 2);
  ASSERT_ANY_THROW(matrix_a - matrix_b);
}
TEST(OperatorMultiplyMatrix, True_19) {
  S21Matrix matrix_a(2, 2);
  S21Matrix matrix_b(2, 2);
  S21Matrix result(2, 2);

  matrix_a(0, 0) = 3;
  matrix_a(0, 1) = 2;
  matrix_a(1, 0) = -6.6;
  matrix_a(1, 1) = 0;

  matrix_b(0, 0) = -7;
  matrix_b(0, 1) = 0;
  matrix_b(1, 0) = -3.5;
  matrix_b(1, 1) = 2;

  result(0, 0) = -28;
  result(0, 1) = 4;
  result(1, 0) = 46.2;
  result(1, 1) = 0;

  ASSERT_TRUE((matrix_a * matrix_b) == result);
}
TEST(OperatorMulNum, True_20) {
  S21Matrix matrix_a(2, 2);
  S21Matrix result(2, 2);
  double num = 2.0;

  matrix_a(0, 0) = 3;
  matrix_a(0, 1) = 2;
  matrix_a(1, 0) = -6;
  matrix_a(1, 1) = 0;

  result(0, 0) = 6;
  result(0, 1) = 4;
  result(1, 0) = -12;
  result(1, 1) = 0;

  ASSERT_TRUE((num * matrix_a) == result);
}
TEST(OperatorMulNum, True_21) {
  S21Matrix matrix_a(2, 2);
  S21Matrix result(2, 2);
  double num = 2.0;

  matrix_a(0, 0) = 3;
  matrix_a(0, 1) = 2;
  matrix_a(1, 0) = -6;
  matrix_a(1, 1) = 0;

  result(0, 0) = 6;
  result(0, 1) = 4;
  result(1, 0) = -12;
  result(1, 1) = 0;

  ASSERT_TRUE((matrix_a * num) == result);
}
TEST(OperatorMultiplyNumber, True_22) {
  S21Matrix matrix_a(2, 2);
  S21Matrix result(2, 2);

  matrix_a(0, 0) = -78.14;
  matrix_a(0, 1) = 0;
  matrix_a(1, 0) = -0.3;
  matrix_a(1, 1) = 2;

  result(0, 0) = -781.4;
  result(0, 1) = 0;
  result(1, 0) = -3;
  result(1, 1) = 20;

  ASSERT_TRUE((matrix_a * 10) == result);
}
TEST(OperatorMultiplyNum, True_23) {
  S21Matrix matrix_a(2, 2);
  S21Matrix result(2, 2);

  matrix_a(0, 0) = -78.14;
  matrix_a(0, 1) = 0;
  matrix_a(1, 0) = -0.3;
  matrix_a(1, 1) = 2;

  result(0, 0) = -781.4;
  result(0, 1) = 0;
  result(1, 0) = -3;
  result(1, 1) = 20;

  ASSERT_TRUE((matrix_a * 10) == result);
}
TEST(OperatoreqMatrix, True_24) {
  S21Matrix matrix_a(3, 3);
  S21Matrix matrix_b(1, 3);
  matrix_a = matrix_b;
  ASSERT_TRUE(matrix_a == matrix_b);
}

TEST(OperatorsumMatrix, True_25) {
  S21Matrix matrix_a(2, 2);
  S21Matrix matrix_b(2, 2);
  S21Matrix result(2, 2);

  matrix_a(0, 0) = 3.14;
  matrix_a(0, 1) = 0.56;
  matrix_a(1, 0) = -69.3;
  matrix_a(1, 1) = 0;

  matrix_b(0, 0) = -78.14;
  matrix_b(0, 1) = 0;
  matrix_b(1, 0) = -0.3;
  matrix_b(1, 1) = 2;

  result(0, 0) = -75;
  result(0, 1) = 0.56;
  result(1, 0) = -69.6;
  result(1, 1) = 2;

  ASSERT_TRUE((matrix_a += matrix_b) == result);
}
TEST(OperatorsumMatrix, False_26) {
  S21Matrix matrix_a(1, 2);
  S21Matrix matrix_b(2, 2);

  matrix_a(0, 0) = 3.14;
  matrix_a(0, 1) = 0.56;

  matrix_b(0, 0) = -78.14;
  matrix_b(0, 1) = 0;
  matrix_b(1, 0) = -0.3;
  matrix_b(1, 1) = 2;

  ASSERT_ANY_THROW((matrix_a += matrix_b));
}

TEST(OperatorsubMatrix, True_27) {
  S21Matrix matrix_a(2, 2);
  S21Matrix matrix_b(2, 2);
  S21Matrix result(2, 2);

  matrix_a(0, 0) = 3;
  matrix_a(0, 1) = 2;
  matrix_a(1, 0) = -6;
  matrix_a(1, 1) = 0;

  matrix_b(0, 0) = -7;
  matrix_b(0, 1) = 0;
  matrix_b(1, 0) = -3;
  matrix_b(1, 1) = 2;

  result(0, 0) = 10;
  result(0, 1) = 2;
  result(1, 0) = -3;
  result(1, 1) = -2;

  ASSERT_TRUE((matrix_a -= matrix_b) == result);
}
TEST(OperatorsubMatrix, False_28) {
  S21Matrix matrix_a(1, 2);
  S21Matrix matrix_b(2, 2);
  ASSERT_ANY_THROW(matrix_a -= matrix_b);
}
TEST(OperatormulNumber, True_29) {
  S21Matrix matrix_a(2, 2);
  S21Matrix result(2, 2);

  matrix_a(0, 0) = -78.14;
  matrix_a(0, 1) = 0;
  matrix_a(1, 0) = -0.3;
  matrix_a(1, 1) = 2;

  result(0, 0) = -781.4;
  result(0, 1) = 0;
  result(1, 0) = -3;
  result(1, 1) = 20;

  ASSERT_TRUE((matrix_a *= 10) == result);
}
TEST(OperatormulMatrix, True_30) {
  S21Matrix matrix_a(2, 2);
  S21Matrix matrix_b(2, 2);
  S21Matrix result(2, 2);

  matrix_a(0, 0) = 3;
  matrix_a(0, 1) = 2;
  matrix_a(1, 0) = -6.6;
  matrix_a(1, 1) = 0;

  matrix_b(0, 0) = -7;
  matrix_b(0, 1) = 0;
  matrix_b(1, 0) = -3.5;
  matrix_b(1, 1) = 2;

  result(0, 0) = -28;
  result(0, 1) = 4;
  result(1, 0) = 46.2;
  result(1, 1) = 0;

  ASSERT_TRUE((matrix_a *= matrix_b) == result);
}
TEST(OperatormulMatrix, Throw_31) {
  S21Matrix matrix_a(2, 2);
  S21Matrix matrix_b(3, 2);
  ASSERT_ANY_THROW(matrix_a * matrix_b);
}
TEST(OperatormulMatrix, False_32) {
  S21Matrix matrix_a(2, 1);
  S21Matrix matrix_b(2, 2);
  ASSERT_ANY_THROW(matrix_a *= matrix_b);
}
TEST(OperatorIndex, False_33) {
  S21Matrix matrix_a(2, 1);
  ASSERT_ANY_THROW(matrix_a(3, 1));
}
TEST(OperatorIndex, True_34) {
  S21Matrix matrix_a(2, 1);

  matrix_a(0, 0) = 5.1;
  ASSERT_DOUBLE_EQ(matrix_a(0, 0), 5.1);
}
TEST(transpose, True_35) {
  S21Matrix matrix_a(4, 3);
  S21Matrix result(3, 4);

  matrix_a(0, 0) = 7;
  matrix_a(0, 1) = -98;
  matrix_a(0, 2) = 0.5;
  matrix_a(1, 0) = 0;
  matrix_a(1, 1) = 5.4;
  matrix_a(1, 2) = 32;
  matrix_a(2, 0) = 3.12;
  matrix_a(2, 1) = 2323;
  matrix_a(2, 2) = 23;
  matrix_a(3, 0) = -78;
  matrix_a(3, 1) = 476.4;
  matrix_a(3, 2) = 21;

  result(0, 0) = 7;
  result(0, 1) = 0;
  result(0, 2) = 3.12;
  result(0, 3) = -78;
  result(1, 0) = -98;
  result(1, 1) = 5.4;
  result(1, 2) = 2323;
  result(1, 3) = 476.4;
  result(2, 0) = 0.5;
  result(2, 1) = 32;
  result(2, 2) = 23;
  result(2, 3) = 21;
  S21Matrix res = matrix_a.transpose();
  ASSERT_TRUE(res == result);
}

TEST(transpose, True_36) {
  S21Matrix matrix_a(4, 3);
  S21Matrix matrix_b = matrix_a.transpose();

  ASSERT_TRUE(matrix_b == matrix_b);
}

TEST(Inverse, False_37) {
  S21Matrix matrix_a(4, 3);
  S21Matrix result(3, 4);

  matrix_a(0, 0) = 7;
  matrix_a(0, 1) = -98;
  matrix_a(0, 2) = 0.5;
  matrix_a(1, 0) = 0;
  matrix_a(1, 1) = 5.4;
  matrix_a(1, 2) = 32;
  matrix_a(2, 0) = 3.12;
  matrix_a(2, 1) = 2323;
  matrix_a(2, 2) = 23;
  matrix_a(3, 0) = -78;
  matrix_a(3, 1) = 476.4;
  matrix_a(3, 2) = 21;

  ASSERT_ANY_THROW(matrix_a.inverseMatrix());
}
TEST(Inverse, True_38) {
  S21Matrix matrix_a(3, 3);
  S21Matrix result(3, 3);

  matrix_a(0, 0) = 2;
  matrix_a(0, 1) = 5;
  matrix_a(0, 2) = 7;
  matrix_a(1, 0) = 6;
  matrix_a(1, 1) = 3;
  matrix_a(1, 2) = 4;
  matrix_a(2, 0) = 5;
  matrix_a(2, 1) = -2;
  matrix_a(2, 2) = -3;

  result(0, 0) = 1;
  result(0, 1) = -1;
  result(0, 2) = 1;
  result(1, 0) = -38;
  result(1, 1) = 41;
  result(1, 2) = -34;
  result(2, 0) = 27;
  result(2, 1) = -29;
  result(2, 2) = 24;

  ASSERT_TRUE(matrix_a.inverseMatrix().eqMatrix(result));

  S21Matrix matrix_b(3, 3);
  matrix_b(0, 0) = 1;
  matrix_b(0, 1) = 2;
  matrix_b(0, 2) = 3;
  matrix_b(1, 0) = 4;
  matrix_b(1, 1) = 5;
  matrix_b(1, 2) = 6;
  matrix_b(2, 0) = 7;
  matrix_b(2, 1) = 8;
  matrix_b(2, 2) = 9;

  ASSERT_ANY_THROW(matrix_b.inverseMatrix());
}
TEST(Inverse, True_39) {
  S21Matrix matrix_a(1, 1);
  matrix_a(0, 0) = 2;
  ASSERT_DOUBLE_EQ(matrix_a.inverseMatrix()(0, 0), 0.5);
}
TEST(Get, True_40) {
  S21Matrix matrix_a(3, 3);

  matrix_a(0, 0) = 2;
  matrix_a(0, 1) = 5;
  matrix_a(0, 2) = 7;
  matrix_a(1, 0) = 6;
  matrix_a(1, 1) = 3;
  matrix_a(1, 2) = 4;
  matrix_a(2, 0) = 5;
  matrix_a(2, 1) = -2;
  matrix_a(2, 2) = -3;

  ASSERT_EQ(matrix_a.getRows(), 3);
  ASSERT_EQ(matrix_a.getCols(), 3);
}
TEST(Set, True_41) {
  S21Matrix matrix_a(3, 3);
  S21Matrix result(3, 2);

  matrix_a(0, 0) = 2;
  matrix_a(0, 1) = 5;
  matrix_a(0, 2) = 7;
  matrix_a(1, 0) = 6;
  matrix_a(1, 1) = 3;
  matrix_a(1, 2) = 4;
  matrix_a(2, 0) = 5;
  matrix_a(2, 1) = -2;
  matrix_a(2, 2) = -3;

  result(0, 0) = 2;
  result(0, 1) = 5;

  result(1, 0) = 6;
  result(1, 1) = 3;

  result(2, 0) = 5;
  result(2, 1) = -2;
  matrix_a.setCols(2);

  ASSERT_TRUE(matrix_a == result);

  S21Matrix matrix_b(3, 3);
  S21Matrix result_b(2, 3);

  matrix_b(0, 0) = 2;
  matrix_b(0, 1) = 5;
  matrix_b(0, 2) = 7;
  matrix_b(1, 0) = 6;
  matrix_b(1, 1) = 3;
  matrix_b(1, 2) = 4;
  matrix_b(2, 0) = 5;
  matrix_b(2, 1) = -2;
  matrix_b(2, 2) = -3;

  result_b(0, 0) = 2;
  result_b(0, 1) = 5;
  result_b(0, 2) = 7;
  result_b(1, 0) = 6;
  result_b(1, 1) = 3;
  result_b(1, 2) = 4;

  matrix_b.setRows(2);
  ASSERT_TRUE(matrix_b == result_b);
}
TEST(setCols, False_42) {
  S21Matrix matrix_a(3, 3);
  ASSERT_ANY_THROW(matrix_a.setCols(-1));
}
TEST(setRows, False_43) {
  S21Matrix matrix_a(3, 3);
  ASSERT_ANY_THROW(matrix_a.setRows(-1));
}

TEST(calcComplements, False_44) {
  S21Matrix matrix_a(2, 3);
  ASSERT_ANY_THROW(matrix_a.calcComplements());
}
TEST(inverseMatrix, False_45) {
  S21Matrix matrix_a(2, 2);
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      matrix_a(i, j) = 1;
    }
  }
  ASSERT_ANY_THROW(matrix_a.inverseMatrix());
}
TEST(calcComplements, True_46) {
  S21Matrix matrix_a(1, 1);
  ASSERT_DOUBLE_EQ(matrix_a.calcComplements()(0, 0), 1.0);
}
TEST(determinant, True_47) {
  S21Matrix matrix_a(1, 1);
  matrix_a(0, 0) = 7.5;
  double det = matrix_a.determinant();
  ASSERT_DOUBLE_EQ(det, 7.5);
}
TEST(determinant, False_48) {
  S21Matrix matrix_a(3, 2);
  ASSERT_ANY_THROW(matrix_a.determinant());
}
TEST(getMinor, False_49) {
  S21Matrix matrix_a(1, 1);
  ASSERT_ANY_THROW(matrix_a.getMinor(0, 0));
}
TEST(getMinor, Throw_50) {
  S21Matrix matrix_a(2, 3);
  ASSERT_ANY_THROW(matrix_a.getMinor(1, 1));
}
TEST(getMatrixMinor, Throw_51) {
  S21Matrix matrix_a(2, 3);
  ASSERT_ANY_THROW(matrix_a.getMinor(1, 1));
}
TEST(getMatrixMinor, Throw_52) {
  S21Matrix matrix_a(1, 1);
  ASSERT_ANY_THROW(matrix_a.getMinor(0, 0));
}

TEST(resizeMatrix, 53) {
  S21Matrix matrix_a(1, 1);
  matrix_a(0, 0) = 1;
  matrix_a.resizeMatrix(2, 1);
  S21Matrix matrix_b(2, 1);
  matrix_b(0, 0) = 1;
  matrix_b(1, 0) = 0;

  ASSERT_TRUE(matrix_a == matrix_b);
}

TEST(resizeMatrix, 54) {
  S21Matrix matrix_a(2, 1);
  matrix_a(0, 0) = 1;
  matrix_a(1, 0) = 1;
  matrix_a.resizeMatrix(2, 2);
  S21Matrix matrix_b(2, 2);
  matrix_b(0, 0) = 1;
  matrix_b(1, 0) = 0;
  matrix_b(1, 0) = 1;
  matrix_b(1, 1) = 0;

  ASSERT_TRUE(matrix_a == matrix_b);
}

TEST(resizeMatrix, 55) {
  S21Matrix matrix_b(2, 2);
  matrix_b(0, 0) = 1;
  matrix_b(1, 0) = 0;
  matrix_b(1, 0) = 1;
  matrix_b(1, 1) = 0;

  matrix_b.resizeMatrix(2, 1);
  S21Matrix matrix_a(2, 1);
  matrix_a(0, 0) = 1;
  matrix_a(1, 0) = 1;

  ASSERT_TRUE(matrix_a == matrix_b);
}

TEST(constructor_move, True_56) {
  S21Matrix matrix_a(2, 1);
  matrix_a(0, 0) = 1;
  matrix_a(1, 0) = 1;

  S21Matrix matrix_c(2, 1);
  matrix_c(0, 0) = 1;
  matrix_c(1, 0) = 1;

  S21Matrix matrix_b(matrix_a);

  ASSERT_TRUE(matrix_c == matrix_b);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}