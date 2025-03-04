#include <catch2/catch_test_macros.hpp>

#include "my_list.h"


TEST_CASE("PopBack and PopFront throw on empty list", "[List]") {
    List list;
    REQUIRE_THROWS(list.PopBack());
    REQUIRE_THROWS(list.PopFront());
}


TEST_CASE("Function `PushBack` works correctly", "[List]") {
    List list;
    list.PushBack(10);
    REQUIRE(list.Size() == 1);

    list.PushBack(20);
    REQUIRE(list.Size() == 2);

    REQUIRE(list.PopFront() == 10);
    REQUIRE(list.PopFront() == 20);
}


TEST_CASE("Function `PushFront` works correctly", "[List]") {
    List list;
    list.PushFront(30);
    REQUIRE(list.Size() == 1);

    list.PushFront(40);
    REQUIRE(list.Size() == 2);

    REQUIRE(list.PopBack() == 30);
    REQUIRE(list.PopBack() == 40);
}


TEST_CASE("Function `PopBack` works correctly", "[List]") {
    List list;
    REQUIRE_THROWS_AS(list.PopBack(), std::runtime_error);

    list.PushBack(50);
    list.PushBack(60);
    REQUIRE(list.PopBack() == 60);
    REQUIRE(list.PopBack() == 50);
    REQUIRE(list.Empty());
}


TEST_CASE("Function `PopFront` works correctly", "[List]") {
    List list;
    REQUIRE_THROWS_AS(list.PopFront(), std::runtime_error);

    list.PushFront(70);
    list.PushFront(80);
    REQUIRE(list.PopFront() == 80);
    REQUIRE(list.PopFront() == 70);
    REQUIRE(list.Empty());
}


TEST_CASE("Complex usage", "[List]") {
    List list;

    list.PushFront(10);
    list.PushBack(20);
    list.PushFront(5);
    list.PushBack(25);

    REQUIRE(list.Size() == 4);

    REQUIRE(list.PopFront() == 5);
    REQUIRE(list.PopBack() == 25);
    REQUIRE(list.PopFront() == 10);
    REQUIRE(list.PopBack() == 20);

    REQUIRE(list.Empty());
}