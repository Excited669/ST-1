// Copyright 2025 UNN-CS
#include <gtest/gtest.h>
#include <cstdint>
#include "alg.h"

// -------- checkPrime --------

TEST(PrimeTest, CheckPrimeRequiredSmallSet) {
  EXPECT_FALSE(checkPrime(0));
  EXPECT_FALSE(checkPrime(1));
  EXPECT_TRUE(checkPrime(2));
  EXPECT_TRUE(checkPrime(3));
  EXPECT_FALSE(checkPrime(4));
  EXPECT_TRUE(checkPrime(5));
  EXPECT_FALSE(checkPrime(9));
  EXPECT_FALSE(checkPrime(25));
  EXPECT_FALSE(checkPrime(49));
}

TEST(PrimeTest, CheckPrimeEvenAndOdd) {
  EXPECT_FALSE(checkPrime(10));
  EXPECT_FALSE(checkPrime(12));
  EXPECT_TRUE(checkPrime(97));
  EXPECT_FALSE(checkPrime(99));
}

TEST(PrimeTest, CheckPrimeLargerNumbers) {
  EXPECT_TRUE(checkPrime(104729));       
  EXPECT_FALSE(checkPrime(104730));      
  EXPECT_TRUE(checkPrime(2147483647ULL)); 
}

// -------- nPrime --------

TEST(NPrimeTest, FirstPrimes) {
  EXPECT_EQ(nPrime(1), 2ULL);
  EXPECT_EQ(nPrime(2), 3ULL);
  EXPECT_EQ(nPrime(3), 5ULL);
  EXPECT_EQ(nPrime(4), 7ULL);
  EXPECT_EQ(nPrime(5), 11ULL);
  EXPECT_EQ(nPrime(6), 13ULL);
  EXPECT_EQ(nPrime(7), 17ULL);
  EXPECT_EQ(nPrime(8), 19ULL);
  EXPECT_EQ(nPrime(9), 23ULL);
  EXPECT_EQ(nPrime(10), 29ULL);
}

TEST(NPrimeTest, LargerN) {
  EXPECT_EQ(nPrime(20), 71ULL);
  EXPECT_EQ(nPrime(50), 229ULL);
  EXPECT_EQ(nPrime(100), 541ULL);
}

// -------- nextPrime --------

TEST(NextPrimeTest, ExamplesFromStatement) {
  EXPECT_EQ(nextPrime(4), 5ULL);
  EXPECT_EQ(nextPrime(11), 13ULL);
}

TEST(NextPrimeTest, SmallValues) {
  EXPECT_EQ(nextPrime(0), 2ULL);
  EXPECT_EQ(nextPrime(1), 2ULL);
  EXPECT_EQ(nextPrime(2), 3ULL);
  EXPECT_EQ(nextPrime(3), 5ULL);
}

TEST(NextPrimeTest, MoreCases) {
  EXPECT_EQ(nextPrime(14), 17ULL);
  EXPECT_EQ(nextPrime(17), 19ULL);
  EXPECT_EQ(nextPrime(100), 101ULL);
}

// -------- sumPrime --------

TEST(SumPrimeTest, RequiredBounds) {
  EXPECT_EQ(sumPrime(0), 0ULL);
  EXPECT_EQ(sumPrime(1), 0ULL);
  EXPECT_EQ(sumPrime(2), 0ULL);
  EXPECT_EQ(sumPrime(3), 2ULL);
  EXPECT_EQ(sumPrime(10), 17ULL);
  EXPECT_EQ(sumPrime(20), 77ULL);
  EXPECT_EQ(sumPrime(100), 1060ULL);
}

TEST(SumPrimeTest, ExtraBounds) {
  EXPECT_EQ(sumPrime(30), 129ULL);
}

TEST(st1, sumPrime1) {
  uint64_t res = sumPrime(2000000);
  uint64_t expected = 142913828922ULL;
  EXPECT_EQ(expected, res);
}

TEST(st1, sumPrime2) {
  uint64_t res = sumPrime(10);
  uint64_t expected = 17ULL;
  EXPECT_EQ(expected, res);
}
