#include "pch.h"
#include "vector.h"

TEST(VectorTest, ConstructorTest)
{
    Vector<int> nd = { 95 };
    EXPECT_EQ(nd.size(), 1);
    EXPECT_EQ(nd.capacity(), 1);
    EXPECT_EQ(nd[0], 95);
}

TEST(VectorTest, CopyConstructor)
{
    Vector<int> nd = { 90 };
    Vector<int> copy = nd;
    EXPECT_EQ(copy.size(), nd.size());
    EXPECT_EQ(copy.capacity(), nd.capacity());
    EXPECT_EQ(copy[0], nd[0]);
}

TEST(VectorTest, MoveConstructor)
{
    Vector<int> nd = { 89 };
    Vector<int> moved = std::move(nd);
    EXPECT_EQ(moved.size(), 1);
    EXPECT_EQ(moved.capacity(), 1);
    EXPECT_EQ(moved[0], 89);
}

TEST(VectorTest, CopyAssignment)
{
    Vector<int> nd = { 85 };
    Vector<int> copy;
    copy = nd;
    EXPECT_EQ(copy.size(), nd.size());
    EXPECT_EQ(copy.capacity(), nd.capacity());
    EXPECT_EQ(copy[0], nd[0]);
}


TEST(VectorTest, AssignFunkcija) {
    Vector<int> v;
    v.assign(5, 10);
    EXPECT_EQ(v.size(), 5);
    EXPECT_EQ(v.capacity(), 5);
    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(v[i], 10);
    }
}

TEST(VectorTest, AtFunkcija) {
    Vector<int> v(5, 10);
    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(v.at(i), 10);
    }
    EXPECT_THROW(v.at(10), std::out_of_range);
}

TEST(VectorTest, FrontFunkcija) {
    Vector<int> v = { 1, 2, 3, 4, 5 };
    EXPECT_EQ(v.front(), 1);
}

TEST(VectorTest, BackFunkcija) {
    Vector<int> v = { 1, 2, 3, 4, 5 };
    EXPECT_EQ(v.back(), 5);
}

TEST(VectorTest, Size) {
    Vector<int> v;
    EXPECT_EQ(v.size(), 0);
    v.push_back(10);
    EXPECT_EQ(v.size(), 1);
}

TEST(VectorTest, Resize) {
    Vector<int> v;
    v.resize(5);
    EXPECT_EQ(v.size(), 5);
    v.resize(3);
    EXPECT_EQ(v.size(), 3);
}

TEST(VectorTest, Capacity) {
    Vector<int> v;
    v.resize(10);
    EXPECT_GE(v.capacity(), v.size());
}

TEST(VectorTest, Empty) {
    Vector<int> v;
    EXPECT_TRUE(v.empty());
    v.push_back(5);
    EXPECT_FALSE(v.empty());
}

TEST(VectorTest, Reserve) {
    Vector<int> v;
    v.reserve(100);
    EXPECT_GE(v.capacity(), 100);
}

TEST(VectorTest, Clear) {
    Vector<int> v;
    v.push_back(5);
    v.clear();
    EXPECT_TRUE(v.empty());
}

TEST(VectorTest, LygusVektoriai) {
    Vector<int> v1{ 1, 2, 3 };
    Vector<int> v2{ 1, 2, 3 };
    EXPECT_TRUE(v1 == v2);
}

TEST(VectorTest, NelygusVektoriai) {
    Vector<int> v1{ 1, 2, 3 };
    Vector<int> v2{ 1, 2, 4 };
    EXPECT_TRUE(v1 != v2);
}