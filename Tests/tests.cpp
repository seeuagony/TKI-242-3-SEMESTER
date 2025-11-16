#include <gtest/gtest.h>
#include "../Library/Matrix.h"
#include "../Library/RandomGenerator.h"
#include "../Library/ConstantGenerator.h"
#include "../Library/ZeroGenerator.h"
#include "../Library/IStreamGenerator.h"
#include "../Library/Task1.h"
#include "../Library/Task2.h"
#include "../Library/Task3.h"
#include <sstream>

using namespace miit::algebra;

class MatrixTest : public ::testing::Test {
protected:
    void SetUp() override {
    }

    void TearDown() override {
    }
};

TEST_F(MatrixTest, Creation) {
    Matrix<int> arr(5);
    EXPECT_EQ(arr.getSize(), 5);
    EXPECT_FALSE(arr.isEmpty());
}

TEST_F(MatrixTest, EmptyArray) {
    Matrix<int> emptyArr;
    EXPECT_EQ(emptyArr.getSize(), 0);
    EXPECT_TRUE(emptyArr.isEmpty());
}

TEST_F(MatrixTest, ZeroSizeThrowsException) {
    EXPECT_THROW({
        Matrix<int> arr(0);
    }, std::invalid_argument);
}

TEST_F(MatrixTest, FillWithConstant) {
    Matrix<int> arr(5);
    ConstantGenerator gen(42);
    arr.fill(gen);
    
    for (size_t i = 0; i < arr.getSize(); i++) {
        EXPECT_EQ(arr[i], 42);
    }
}

TEST_F(MatrixTest, FillWithZeros) {
    Matrix<int> arr(5);
    ZeroGenerator gen;
    arr.fill(gen);
    
    for (size_t i = 0; i < arr.getSize(); i++) {
        EXPECT_EQ(arr[i], 0);
    }
}

TEST_F(MatrixTest, Indexing) {
    Matrix<int> arr(5);
    
    for (size_t i = 0; i < arr.getSize(); i++) {
        arr[i] = i * 10;
    }
    
    EXPECT_EQ(arr[0], 0);
    EXPECT_EQ(arr[2], 20);
    EXPECT_EQ(arr[4], 40);
}

TEST_F(MatrixTest, OutOfBoundsThrowsException) {
    Matrix<int> arr(5);
    
    EXPECT_THROW({
        int value = arr[10];
    }, std::out_of_range);
}

TEST_F(MatrixTest, CopyConstructor) {
    Matrix<int> arr1(3);
    arr1[0] = 1;
    arr1[1] = 2;
    arr1[2] = 3;
    
    Matrix<int> arr2 = arr1;
    
    EXPECT_EQ(arr2.getSize(), 3);
    EXPECT_EQ(arr2[0], 1);
    EXPECT_EQ(arr2[1], 2);
    EXPECT_EQ(arr2[2], 3);
    
    arr2[0] = 999;
    EXPECT_EQ(arr1[0], 1);
    EXPECT_EQ(arr2[0], 999);
}

TEST_F(MatrixTest, CopyAssignment) {
    Matrix<int> arr1(3);
    arr1[0] = 1;
    arr1[1] = 2;
    arr1[2] = 3;
    
    Matrix<int> arr2(5);
    arr2 = arr1;
    
    EXPECT_EQ(arr2.getSize(), 3);
    EXPECT_EQ(arr2[0], 1);
    EXPECT_EQ(arr2[1], 2);
    EXPECT_EQ(arr2[2], 3);
}

TEST_F(MatrixTest, MoveConstructor) {
    Matrix<int> arr1(3);
    arr1[0] = 1;
    arr1[1] = 2;
    arr1[2] = 3;
    
    Matrix<int> arr2 = std::move(arr1);
    
    EXPECT_EQ(arr2.getSize(), 3);
    EXPECT_EQ(arr2[0], 1);
    EXPECT_EQ(arr2[1], 2);
    EXPECT_EQ(arr2[2], 3);
    
    EXPECT_TRUE(arr1.isEmpty());
}

TEST_F(MatrixTest, MoveAssignment) {
    Matrix<int> arr1(3);
    arr1[0] = 1;
    arr1[1] = 2;
    arr1[2] = 3;
    
    Matrix<int> arr2(5);
    arr2 = std::move(arr1);
    
    EXPECT_EQ(arr2.getSize(), 3);
    EXPECT_EQ(arr2[0], 1);
    EXPECT_TRUE(arr1.isEmpty());
}

TEST_F(MatrixTest, ToString) {
    Matrix<int> arr(3);
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    
    EXPECT_EQ(arr.toString(), "[1, 2, 3]");
    
    Matrix<int> empty;
    EXPECT_EQ(empty.toString(), "[]");
}

TEST(GeneratorTest, RandomGenerator) {
    RandomGenerator gen(1, 10);
    
    for (int i = 0; i < 100; i++) {
        int value = gen.generate();
        EXPECT_GE(value, 1);
        EXPECT_LE(value, 10);
    }
}

TEST(GeneratorTest, ConstantGenerator) {
    ConstantGenerator gen(42);
    
    for (int i = 0; i < 10; i++) {
        EXPECT_EQ(gen.generate(), 42);
    }
}

TEST(GeneratorTest, ZeroGenerator) {
    ZeroGenerator gen;
    
    for (int i = 0; i < 10; i++) {
        EXPECT_EQ(gen.generate(), 0);
    }
}

TEST(GeneratorTest, IStreamGenerator) {
    std::istringstream input("5 10 15 20");
    IStreamGenerator gen(input);
    
    EXPECT_EQ(gen.generate(), 5);
    EXPECT_EQ(gen.generate(), 10);
    EXPECT_EQ(gen.generate(), 15);
    EXPECT_EQ(gen.generate(), 20);
}

TEST(Task1Test, ReplaceLastMultipleOfThree) {
    Matrix<int> arr(5);
    arr[0] = 5;
    arr[1] = 9;
    arr[2] = 7;
    arr[3] = 12;
    arr[4] = 8;
    
    int lastIndex = -1;
    for (int i = arr.getSize() - 1; i >= 0; i--) {
        if (arr[i] != 0 && arr[i] % 3 == 0) {
            lastIndex = i;
            break;
        }
    }
    
    EXPECT_EQ(lastIndex, 3);
    
    arr[lastIndex] = 0;
    EXPECT_EQ(arr[3], 0);
    EXPECT_EQ(arr[1], 9);
}

TEST(Task1Test, NoMultipleOfThree) {
    Matrix<int> arr(3);
    arr[0] = 5;
    arr[1] = 7;
    arr[2] = 11;
    
    int lastIndex = -1;
    for (int i = arr.getSize() - 1; i >= 0; i--) {
        if (arr[i] != 0 && arr[i] % 3 == 0) {
            lastIndex = i;
            break;
        }
    }
    
    EXPECT_EQ(lastIndex, -1);
}

TEST(Task2Test, CountEvenElements) {
    Matrix<int> arr(5);
    arr[0] = 2;
    arr[1] = 3;
    arr[2] = 4;
    arr[3] = 5;
    arr[4] = 6;
    
    size_t evenCount = 0;
    for (size_t i = 0; i < arr.getSize(); i++) {
        if (arr[i] % 2 == 0) evenCount++;
    }
    
    EXPECT_EQ(evenCount, 3);
}

TEST(Task2Test, InsertKAfterEven) {
    Matrix<int> arr(4);
    arr[0] = 2;
    arr[1] = 3;
    arr[2] = 4;
    arr[3] = 5;
    
    int k = 99;
    
    size_t evenCount = 0;
    for (size_t i = 0; i < arr.getSize(); i++) {
        if (arr[i] % 2 == 0) evenCount++;
    }
    
    size_t newSize = arr.getSize() + evenCount;
    Matrix<int> result(newSize);
    
    size_t j = 0;
    for (size_t i = 0; i < arr.getSize(); i++) {
        result[j++] = arr[i];
        if (arr[i] % 2 == 0) {
            result[j++] = k;
        }
    }
    
    EXPECT_EQ(result.getSize(), 6);
    EXPECT_EQ(result.toString(), "[2, 99, 3, 4, 99, 5]");
}

TEST(Task3Test, CreateArrayM) {
    Matrix<int> P(5);
    P[0] = 10;
    P[1] = -5;
    P[2] = 8;
    P[3] = 3;
    P[4] = -7;
    
    Matrix<int> M(5);
    
    M[0] = 0;
    M[4] = 0;
    
    for (size_t i = 1; i < 4; i++) {
        if ((i + 1) % 4 == 0) {
            M[i] = 4 * std::abs(P[i]);
        } else {
            M[i] = -P[i] * static_cast<int>(i + 1);
        }
    }
    
    EXPECT_EQ(M[0], 0);
    EXPECT_EQ(M[1], 10);
    EXPECT_EQ(M[2], -24);
    EXPECT_EQ(M[3], 12);
    EXPECT_EQ(M[4], 0);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
