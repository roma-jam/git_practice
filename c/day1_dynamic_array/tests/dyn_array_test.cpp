#include <gtest/gtest.h>

extern "C" {
#include "dyn_array.h"
}

TEST(DynArrayTest, InitAndFree) {
    dyn_array_t arr;
    EXPECT_EQ(dyn_array_init(&arr, 4), 0);
    EXPECT_EQ(arr.size, 0);
    EXPECT_EQ(arr.capacity, 4);
    EXPECT_NE(arr.data, nullptr);

    dyn_array_free(&arr);
    EXPECT_EQ(arr.data, nullptr);
    EXPECT_EQ(arr.size, 0);
    EXPECT_EQ(arr.capacity, 0);
}

TEST(DynArrayTest, PushBackAndGet) {
    dyn_array_t arr;
    dyn_array_init(&arr, 2);

    dyn_array_push_back(&arr, 10);
    dyn_array_push_back(&arr, 20);

    int value;
    EXPECT_EQ(dyn_array_get(&arr, 0, &value), 0);
    EXPECT_EQ(value, 10);

    EXPECT_EQ(dyn_array_get(&arr, 1, &value), 0);
    EXPECT_EQ(value, 20);

    dyn_array_free(&arr);
}

TEST(DynArrayTest, PushTriggersResize) {
    dyn_array_t arr;
    dyn_array_init(&arr, 1);

    dyn_array_push_back(&arr, 1);
    dyn_array_push_back(&arr, 2);

    EXPECT_GE(arr.capacity, 2);
    EXPECT_EQ(arr.size, 2);

    dyn_array_free(&arr);
}

TEST(DynArrayTest, PopBack) {
    dyn_array_t arr;
    dyn_array_init(&arr, 2);

    EXPECT_EQ(dyn_array_pop_back(&arr), -1);

    dyn_array_push_back(&arr, 5);
    EXPECT_EQ(dyn_array_pop_back(&arr), 0);
    EXPECT_EQ(arr.size, 0);

    dyn_array_free(&arr);
}

TEST(DynArrayTest, ResizeLargerInitializesZero) {
    dyn_array_t arr;
    dyn_array_init(&arr, 2);

    dyn_array_resize(&arr, 5);
    EXPECT_EQ(arr.size, 5);

    int value;
    for (size_t i = 0; i < 5; ++i) {
        dyn_array_get(&arr, i, &value);
        EXPECT_EQ(value, 0);
    }

    dyn_array_free(&arr);
}
