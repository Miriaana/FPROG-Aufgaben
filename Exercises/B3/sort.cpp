// #include <iostream>
#include <functional>
#include <numeric>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;
using namespace std::placeholders;

auto bucket_sort = [](int toSort[]){
    return toSort;
};

TEST_CASE("Bucket Sort")
{
    int arrayToSort[] =   { 4, 3, 8, 14, 2, 9, 76, 30, 1, 2, 5 };
    int expectedArray[] = { 1, 2, 2, 3, 4, 5, 8, 9, 14, 30, 76 };
    CHECK_EQ(expectedArray, bucket_sort(arrayToSort));
}


/*
TEST_CASE("Insertion Sort")
{
    int expected = true;
    CHECK_EQ(expected, true);
}

TEST_CASE("Bubble Sort")
{
    int expected = true;
    CHECK_EQ(expected, true);
}

TEST_CASE("Selection Sort")
{
    int expected = true;
    CHECK_EQ(expected, true);
}

TEST_CASE("Quick Sort")
{
    int expected = true;
    CHECK_EQ(expected, true);
}
*/

/*
TEST_CASE("Greater than")
{
    struct Data
    {
        int first;
        int second;
        bool expected;
    } data;
    SUBCASE("2 is greater than 1")
    {
        data.first = 2;
        data.second = 1;
        data.expected = true;
    }
    SUBCASE("2 is not greater than 2")
    {
        data.first = 2;
        data.second = 2;
        data.expected = false;
    }
    SUBCASE("2 is not greater than 3")
    {
        data.first = 2;
        data.second = 3;
        data.expected = false;
    }
    CAPTURE(data);
    CHECK_EQ(true, data.expected);
}*/
