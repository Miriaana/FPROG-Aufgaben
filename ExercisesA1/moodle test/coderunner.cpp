//#define DOCTEST_CONFIG_IMPLEMENT

#include <iostream>
#include <list>
#include <map>
#include <string>
#include <functional>
#include <numeric>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;
using namespace std::placeholders;

auto printSomething = [](const std::string text)
{
    std::cout << text;
};

// A3 Curried Root --------------------------------------------------------
auto curriedroot = [](int base)
{
    return [base](double argument) -> double
    {
        if (argument < 0)
        {
            return -1; // Invalid input
        }
        if (argument == 0)
        {
            return 0;
        }

        const int max_iterations = 1000;
        const double epsilon = 1e-10;

        double low_guess = 0, high_guess = argument;
        double mid_guess;

        for (int i = 0; i < max_iterations; ++i)
        {
            mid_guess = (low_guess + high_guess) / 2.0;

            double mid_square = mid_guess;
            for(int i = 1; i < base; i++){
                mid_square *= mid_guess;
            }

            if (mid_square > argument)
            {
                high_guess = mid_guess;
            }
            else if (mid_square < argument)
            {
                low_guess = mid_guess;
            }

            if (high_guess - low_guess < epsilon)
            {
                break;
            }
        }

        return mid_guess;
    };
};

TEST_CASE("sqrt and curried sqrt one") //personal test
{
    //sqrt(16)
    CHECK_EQ(4, doctest::Approx(curriedroot(2)(16)));

    auto root_index2 = curriedroot(2);
    CHECK_EQ(4, doctest::Approx(root_index2(16)));
}
TEST_CASE("sqrt and curried sqrt two")
{
    CHECK_EQ(1.41421, doctest::Approx(curriedroot(2)(2)));

    auto root_index2 = curriedroot(2);
    CHECK_EQ(1.41421, doctest::Approx(root_index2(2)));
}
TEST_CASE("root and curried root")
{
    CHECK_EQ(1.24573, doctest::Approx(curriedroot(5)(3)));

    auto root_index5 = curriedroot(5);
    CHECK_EQ(1.24573, doctest::Approx(root_index5(3)));
}
TEST_CASE("root and curried root"){
    CHECK_EQ(1.17542, doctest::Approx(curriedroot(7)(3.1)));

    auto root_index7 = curriedroot(7);
    CHECK_EQ(1.17542, doctest::Approx(root_index7(3.1)));
}
TEST_CASE("root and curried root"){
    CHECK_EQ(1.16993, doctest::Approx(curriedroot(7)(3)));

    auto root_index7 = curriedroot(7);
    CHECK_EQ(1.16993, doctest::Approx(root_index7(3)));
}

// A3 double_it lambda --------------------------------------------------------
auto double_it = [](const double var){
    return var + var;
};
TEST_CASE("Double it"){
    CHECK_EQ(4, double_it(2));
}
TEST_CASE("Double it"){
    CHECK_EQ(4.0, double_it(2.0));
}
TEST_CASE("Double it"){
    CHECK_EQ(5.0, double_it(2.5));
}








/*
int main(int argc, char **argv)
{
    // doctest setup
    
    doctest::Context ctx;
    ctx.setOption("abort-after", 5);  // default - stop after 5 failed asserts
    ctx.applyCommandLine(argc, argv); // apply command line - argc / argv
    ctx.setOption("no-breaks", true); // override - don't break in the debugger
    int res = ctx.run();              // run test cases unless with --no-run
    if (ctx.shouldExit())             // query flags (and --exit) rely on this
        return res;                   // propagate the result of the tests

    // your actual program execution goes here - only if we haven't exited

    std::stringstream output;
    output << "Hello World" << std::endl;

    printSomething(output.str());

    return 0;// res; // + your_program_res
}*/