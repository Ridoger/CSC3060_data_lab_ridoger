#include <gtest/gtest.h>

#include <cstdint>

#include "data_lab.hpp"

// Add function tests (12 tests)
TEST(AddTest, PositiveNumbers) { EXPECT_EQ(data_lab::add(5, 3), 8); }

TEST(AddTest, NegativeNumbers) { EXPECT_EQ(data_lab::add(-5, -3), -8); }

TEST(AddTest, MixedSigns) { EXPECT_EQ(data_lab::add(10, -3), 7); }

TEST(AddTest, WithZero) { EXPECT_EQ(data_lab::add(0, 5), 5); }

TEST(AddTest, BothZero) { EXPECT_EQ(data_lab::add(0, 0), 0); }

TEST(AddTest, LargePositive) {
  EXPECT_EQ(data_lab::add(1000000, 2000000), 3000000);
}

TEST(AddTest, PowersOfTwo) {
  EXPECT_EQ(data_lab::add(1 << 20, 1 << 20), 1 << 21);
}

TEST(AddTest, NearIntMax) {
  EXPECT_EQ(data_lab::add(INT32_MAX - 1, 1), INT32_MAX);
}

TEST(AddTest, NearIntMin) {
  EXPECT_EQ(data_lab::add(INT32_MIN + 1, -1), INT32_MIN);
}

TEST(AddTest, OverflowWrap) {
  EXPECT_EQ(data_lab::add(INT32_MAX, 1), INT32_MIN);
}

TEST(AddTest, CommutativeProperty) {
  EXPECT_EQ(data_lab::add(7, 13), data_lab::add(13, 7));
}

TEST(AddTest, AssociativeProperty) {
  EXPECT_EQ(data_lab::add(data_lab::add(1, 2), 3),
            data_lab::add(1, data_lab::add(2, 3)));
}

// Subtract function tests (12 tests)
TEST(SubtractTest, PositiveNumbers) { EXPECT_EQ(data_lab::subtract(10, 3), 7); }

TEST(SubtractTest, NegativeNumbers) {
  EXPECT_EQ(data_lab::subtract(-10, -3), -7);
}

TEST(SubtractTest, MixedSigns) { EXPECT_EQ(data_lab::subtract(10, -3), 13); }

TEST(SubtractTest, WithZero) { EXPECT_EQ(data_lab::subtract(5, 0), 5); }

TEST(SubtractTest, FromZero) { EXPECT_EQ(data_lab::subtract(0, 5), -5); }

TEST(SubtractTest, BothZero) { EXPECT_EQ(data_lab::subtract(0, 0), 0); }

TEST(SubtractTest, PowersOfTwo) {
  EXPECT_EQ(data_lab::subtract(1 << 22, 1 << 21), 1 << 21);
}

TEST(SubtractTest, NearIntMax) {
  EXPECT_EQ(data_lab::subtract(INT32_MAX, 1), INT32_MAX - 1);
}

TEST(SubtractTest, NearIntMin) {
  EXPECT_EQ(data_lab::subtract(INT32_MIN, -1), INT32_MIN + 1);
}

TEST(SubtractTest, UnderflowWrap) {
  EXPECT_EQ(data_lab::subtract(INT32_MIN, 1), INT32_MAX);
}

TEST(SubtractTest, SameNumbers) { EXPECT_EQ(data_lab::subtract(42, 42), 0); }

TEST(SubtractTest, Identity) { EXPECT_EQ(data_lab::subtract(100, 0), 100); }

// Multiply function tests (12 tests)
TEST(MultiplyTest, PositiveNumbers) { EXPECT_EQ(data_lab::multiply(5, 3), 15); }

TEST(MultiplyTest, NegativeNumbers) {
  EXPECT_EQ(data_lab::multiply(-5, -3), 15);
}

TEST(MultiplyTest, MixedSigns) { EXPECT_EQ(data_lab::multiply(5, -3), -15); }

TEST(MultiplyTest, WithZero) { EXPECT_EQ(data_lab::multiply(5, 0), 0); }

TEST(MultiplyTest, ZeroWithNegative) {
  EXPECT_EQ(data_lab::multiply(0, -5), 0);
}

TEST(MultiplyTest, WithOne) { EXPECT_EQ(data_lab::multiply(7, 1), 7); }

TEST(MultiplyTest, WithNegativeOne) {
  EXPECT_EQ(data_lab::multiply(7, -1), -7);
}

TEST(MultiplyTest, PowersOfTwo) {
  EXPECT_EQ(data_lab::multiply(1 << 10, 1 << 5), 1 << 15);
}

TEST(MultiplyTest, LargeNumbers) {
  EXPECT_EQ(data_lab::multiply(1000, 1000), 1000000);
}

TEST(MultiplyTest, NearIntMax) {
  EXPECT_EQ(data_lab::multiply(INT32_MAX / 2, 2), INT32_MAX - 1);
}

TEST(MultiplyTest, CommutativeProperty) {
  EXPECT_EQ(data_lab::multiply(7, 13), data_lab::multiply(13, 7));
}

TEST(MultiplyTest, DistributiveProperty) {
  EXPECT_EQ(data_lab::multiply(2, data_lab::add(3, 4)),
            data_lab::add(data_lab::multiply(2, 3), data_lab::multiply(2, 4)));
}

// Divide function tests (12 tests)
TEST(DivideTest, PositiveNumbers) { EXPECT_EQ(data_lab::divide(15, 3), 5); }

TEST(DivideTest, NegativeNumbers) { EXPECT_EQ(data_lab::divide(-15, -3), 5); }

TEST(DivideTest, NegativeByPositive) {
  EXPECT_EQ(data_lab::divide(-15, 3), -5);
}

TEST(DivideTest, PositiveByNegative) {
  EXPECT_EQ(data_lab::divide(15, -3), -5);
}

TEST(DivideTest, ZeroDividend) { EXPECT_EQ(data_lab::divide(0, 5), 0); }

TEST(DivideTest, DivideByOne) { EXPECT_EQ(data_lab::divide(42, 1), 42); }

TEST(DivideTest, DivideByNegativeOne) {
  EXPECT_EQ(data_lab::divide(42, -1), -42);
}

TEST(DivideTest, SameNumbers) { EXPECT_EQ(data_lab::divide(42, 42), 1); }

TEST(DivideTest, LargeNumbers) {
  EXPECT_EQ(data_lab::divide(1000000, 1000), 1000);
}

TEST(DivideTest, PowersOfTwo) {
  EXPECT_EQ(data_lab::divide(1 << 20, 1 << 10), 1 << 10);
}

TEST(DivideTest, IntegerDivision) { EXPECT_EQ(data_lab::divide(17, 5), 3); }

TEST(DivideTest, NegativeIntegerDivision) {
  EXPECT_EQ(data_lab::divide(-17, 5), -3);
}

// Modulo function tests (12 tests)
TEST(ModuloTest, PositiveNumbers) { EXPECT_EQ(data_lab::modulo(17, 5), 2); }

TEST(ModuloTest, NegativeByPositive) {
  EXPECT_EQ(data_lab::modulo(-17, 5), -2);
}

TEST(ModuloTest, PositiveByNegative) { EXPECT_EQ(data_lab::modulo(17, -5), 2); }

TEST(ModuloTest, NegativeNumbers) { EXPECT_EQ(data_lab::modulo(-17, -5), -2); }

TEST(ModuloTest, ZeroDividend) { EXPECT_EQ(data_lab::modulo(0, 5), 0); }

TEST(ModuloTest, NoRemainder) { EXPECT_EQ(data_lab::modulo(15, 5), 0); }

TEST(ModuloTest, DividendSmallerThanDivisor) {
  EXPECT_EQ(data_lab::modulo(3, 5), 3);
}

TEST(ModuloTest, SameNumbers) { EXPECT_EQ(data_lab::modulo(42, 42), 0); }

TEST(ModuloTest, ModuloByOne) { EXPECT_EQ(data_lab::modulo(42, 1), 0); }

TEST(ModuloTest, LargeNumbers) {
  EXPECT_EQ(data_lab::modulo(1000007, 1000), 7);
}

TEST(ModuloTest, PowersOfTwo) { EXPECT_EQ(data_lab::modulo(1023, 512), 511); }

TEST(ModuloTest, NegativeLargeNumber) {
  EXPECT_EQ(data_lab::modulo(-1000007, 1000), -7);
}
