#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "sort.cpp"
#include <iostream>
#include <functional>
#include <numeric>
#include <optional>
#include <random>
#include <iterator>
#include <algorithm>
#include <vector>
//#include <ranges>

using namespace std;
using namespace std::placeholders;

using Values = vector<int>;

/** My new Tests **/
TEST_CASE("Shuffle"){
    Values PreShuffled = {1, 2, 14, 37, 49, 123};

    Values Shuffled = shuffleVector(PreShuffled);

    CHECK_NE(Shuffled, PreShuffled);

    Values ShuffledAgain = shuffleVector(PreShuffled);

    CHECK_EQ(Shuffled, ShuffledAgain);
}

TEST_CASE("SubVector"){
    Values Vector = {1, 2, 14, 37, 49, 123};

    Values SubVector = createSubVector(Vector, 2, 2);

    Values expectedSubVector = { 14, 37};

    CHECK_EQ(SubVector, expectedSubVector);
}

TEST_CASE("Merge SubVectors"){
    Values Vector = {1, 2, 14, 37, 49, 123};

    Values SubVectorOne = createSubVector(Vector, 0, 3);
    Values SubVectorTwo = createSubVector(Vector, 3, 0);

    Values MergedVector = mergeVector(SubVectorOne, SubVectorTwo);

    CHECK_EQ(Vector, MergedVector);
}

TEST_CASE("Bucket Sort"){
    Values PreShuffled = {1, 2, 14, 37, 49, 123};

    Values Shuffled = shuffleVector(PreShuffled);
    
    Values Sorted = bucket_sort(Shuffled);
    
    CHECK_EQ(PreShuffled, Sorted);
}

TEST_CASE("Insertion Sort"){
    Values PreShuffled = {1, 2, 14, 37, 49, 123};

    Values Shuffled = shuffleVector(PreShuffled);
    
    Values Sorted = insertion_sort(Shuffled);
    
    CHECK_EQ(PreShuffled, Sorted);
}

TEST_CASE("Bubble Sort"){
    Values PreShuffled = {1, 2, 14, 37, 49, 123};

    Values Shuffled = shuffleVector(PreShuffled);
    
    Values Sorted = bubble_sort(Shuffled);
    
    CHECK_EQ(PreShuffled, Sorted);
}


TEST_CASE("Selection Sort"){
    Values PreShuffled = {1, 2, 14, 37, 49, 123};

    Values Shuffled = shuffleVector(PreShuffled);
    
    Values Sorted = selection_sort(Shuffled);
    
    CHECK_EQ(PreShuffled, Sorted);
}

TEST_CASE("Quick Sort"){
    Values PreShuffled = {1, 2, 14, 37, 49, 123};

    Values Shuffled = shuffleVector(PreShuffled);
    
    Values Sorted = quick_sort(Shuffled);
    
    CHECK_EQ(PreShuffled, Sorted);
}

