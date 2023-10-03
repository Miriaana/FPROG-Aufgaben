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

/** my new functions **/

// swaps two elements in a vector
auto swap_pure = [](Values Vector, int indexOne, int indexTwo){
    int temp = Vector[indexOne];
    Vector[indexOne] = Vector[indexTwo];
    Vector[indexTwo] = temp;
    return Vector;
};

// shuffles a vector
auto shuffleVector = [](Values VectorToShuffle){
    std::shuffle(VectorToShuffle.begin(), VectorToShuffle.end(), std::default_random_engine(41));
    return VectorToShuffle;
};

// performs a lambda on a vector
auto for_each_collection = [](auto Vector, auto fn){
    return for_each(Vector.begin(), Vector.end(), fn);
};

// sorts two elements of a vector so that they are in ascending order
auto sort_pure_asc = [](Values Vector, int indexOne, int indexTwo){
    if(Vector[indexOne] > Vector[indexTwo]){
        Vector = swap_pure(Vector, indexOne, indexTwo);
    }
    return Vector;
};

// creates a smaller vector out of a bigger one
auto createSubVector = [](auto Vector, int startIndex = 0, int endIndex = 0){
    if(startIndex < (int)Vector.size() && endIndex < (int)Vector.size()){
        Values subVector(Vector.begin() + startIndex, Vector.end() - endIndex);
        return subVector;
    }
    return Vector;
};

// creates a bigger vector out of two smaller ones
auto mergeVector = [](auto& VectorOne, const auto& VectorTwo) {
    VectorOne.insert(VectorOne.end(), VectorTwo.begin(), VectorTwo.end());
    return VectorOne;
};

/** My new Sorts*/

auto selection_sort = [](Values Vector){
    if(Vector.size() <= 1){
        return Vector;
    }

    int LookingAt = 0;
    for_each_collection(Vector, [&](auto iter) mutable {
        // Swap the Element and the smallest Element in the vector 
        // Vector.begin() + i since we already know that all Values we LookedAt are already sorted
        Vector = sort_pure_asc(Vector, LookingAt, distance(Vector.begin(), min_element(Vector.begin() + LookingAt, Vector.end())));
        LookingAt++;
    });
    return Vector;
};

auto bubble_sort = [](Values Vector){
    if(Vector.size() <= 1){
        return Vector;
    }

    int SortedElements = 0;
    // Vector.end() -1 since if there is only 1 unsorted element left in the Vector we know 
    // that its already sorted
    for_each(Vector.begin(), Vector.end() - 1, [&](int& iter1) mutable {
        int LookingAt = 0;
        // swap the number and the next one, so they are correctly sorted
        for_each(Vector.begin(), Vector.end() - SortedElements, [&](int& iter2) mutable {
            if(iter2 != *prev(Vector.end())){
                Vector = sort_pure_asc(Vector, LookingAt, LookingAt + 1);
            }
            LookingAt++;
        });
        SortedElements++;
    });
    return Vector;
};

auto bucket_sort = [](Values Vector){
    if(Vector.size() <= 1){
        return Vector;
    }
    
    int max = *max_element(Vector.begin(), Vector.end());
    int min = *min_element(Vector.begin(), Vector.end());

    int range = max - min + 1;

    // reserve a space for every number between the biggest and smallest
    Values buckets(range, 0);

    // write each number in the vector into its bucket,
    // the index of the smallestValue should be 0, so we put each at Index[number - smallestValue]
    for_each_collection(Vector, [&](auto iter){
        buckets[iter - min]++;
    });

    Values result;

    int LookingAt = 0;
    for_each_collection(buckets, [&](auto iter){
        // insert each number into the result as often as the corresponding number appears in the Bucket
        result.insert(result.end(), iter, LookingAt + min);
        ++LookingAt;
    });

    return result;
};

auto insertion_sort = [](Values Vector){
    if(Vector.size() <= 1){
        return Vector;
    }

    int Pivot = 0;
    // Pick a pivot
    for_each(Vector.begin(), Vector.end(), [&](int& iter1) mutable {
        int LookingAt = 0;
        // Look through every element, if one of them is bigger than our pivot swap them
        // and use the higher value as the new pivot
        for_each(Vector.begin(), Vector.begin() + Pivot, [&](int& iter2) mutable {
            Vector = sort_pure_asc(Vector, LookingAt, Pivot);
            ++LookingAt;
        });
        ++Pivot;
    });

    return Vector;
};

auto quick_sort_recursively = [](Values Vector, auto&& quick_sort_recursively){
    if(Vector.size() <= 1){
        return Vector;
    }

    int pivot = Vector[0];
    Values PivotVector = { pivot };

    Values lesser, greater;

    // split the vector into two Buckets, one smaller and one bigger than our pivot
    for_each(Vector.begin() + 1, Vector.end(), [&](int& iter) mutable{
        if(iter <= pivot){
            lesser.push_back(iter);
        } else {
            greater.push_back(iter);
        }
    });

    // sort each bucket recursively
    Values LesserVector = quick_sort_recursively(lesser, quick_sort_recursively);
    Values GreaterVector = quick_sort_recursively(greater, quick_sort_recursively);

    // merge them back to one vector
    return mergeVector(LesserVector, mergeVector(PivotVector, GreaterVector));
};

auto quick_sort = [](Values Vector) -> vector<int> {
    return quick_sort_recursively(Vector, quick_sort_recursively);
};
