// Copyright 2018 Your Name <your_email>

#include <gtest/gtest.h>
#include "stack_for_uncopyable_types.hpp"
#include "stack.hpp"
using namespace std;
TEST(stack, push1)
{
    stack <int> mystack;

    const int a = 2;
    const int b = 5;

    mystack.push(a);
    mystack.push(b);

    EXPECT_EQ(mystack.head(), 5);
}

TEST(stack, pop)
{
    stack <int> mystack;

    mystack.push(2);
    mystack.push(5);

    mystack.pop();

    EXPECT_EQ(mystack.head(), 2);
}

TEST(stack, except)
{
    stack <int> mystack;

    EXPECT_THROW(mystack.pop(), Exceptions);
}

TEST(stack, excepthead)
{
    stack <double> mystack;

    EXPECT_THROW(mystack.head(), Exceptions);
}

TEST(stack, push2)
{
    stack <int> mystack;

    mystack.push(std::move(4));
    mystack.push(std::move(8));

    EXPECT_EQ(mystack.head(), 8);

    mystack.pop();

    EXPECT_EQ(mystack.head(), 4);
}


TEST(stack_for_uncopyable_types, push_emplace)
{
    stack_for_uncopyable_types < pair <int, double>> mystack{};

    mystack.push_emplace(23, 8.9);
    mystack.push_emplace(34, 4.2);

auto pair = make_pair(34, 4.2);
    EXPECT_EQ(mystack.head(), pair);
}


TEST(stack_for_uncopyable_types, pop)
{
    stack_for_uncopyable_types < pair <int, double>> mystack{};

    mystack.push_emplace(23, 8.9);
    mystack.push_emplace(34, 4.2);

    auto pair = make_pair(34, 4.2);
    EXPECT_EQ(mystack.head(), pair);


    auto pair2 = make_pair(34, 4.2);
   EXPECT_EQ(mystack.pop(), pair2);
}

TEST(stack_for_uncopyable_types, push)
{
    stack_for_uncopyable_types <double> mystack;

    mystack.push(23.1);
    mystack.push(4.6);

    EXPECT_EQ(mystack.head(), 4.6);
}

TEST(stack_for_uncopyable_types, except)
{
    stack_for_uncopyable_types <int> mystack;

    EXPECT_THROW(mystack.pop(), Exceptions);
}

TEST(stack_for_uncopyable_types, excepthead)
{
    stack_for_uncopyable_types <int> mystack;

    EXPECT_THROW(mystack.head(), Exceptions);
}