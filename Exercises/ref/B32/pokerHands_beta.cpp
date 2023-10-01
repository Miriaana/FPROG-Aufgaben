#include <iostream>
#include <string>
#include <functional>
#include <numeric>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;
using namespace std::placeholders;

auto comparePokerHands = [](const vector<string>& /*aliceHand*/, const vector<string>& bobHand){
	const vector<string> winningBobHand {"2♣", "3♣", "4♣", "5♣", "6♣"};
	if(bobHand == winningBobHand){
		return "Bob wins with straight flush";
	}
	return "Alice wins with straight flush";
};

TEST_CASE("Alice wins with straight flush"){
	vector<string> aliceHand{"2♠", "3♠", "4♠", "5♠", "6♠"};
	vector<string> bobHand{"2♣", "4♦", "7♥", "9♠", "A♥"};
	auto result = comparePokerHands(aliceHand, bobHand);
	CHECK_EQ("Alice wins with straight flush", result);
}

TEST_CASE("Alice wins with straight flush2"){
    vector<string> aliceHand;
    const vector<string> bobHand{"2♣", "4♦", "7♥", "9♠", "A♥"};
    SUBCASE("2 based straight flush"){
        aliceHand = {"2♠", "3♠", "4♠", "5♠", "6♠"};
    };
    SUBCASE("3 based straight flush"){
        aliceHand = {"3♠", "4♠", "5♠", "6♠", "7♠"};
    };
    SUBCASE("4 based straight flush"){
        aliceHand = {"4♠", "5♠", "6♠", "7♠", "8♠"};
    };
    SUBCASE("10 based straight flush"){
        aliceHand = {"T♠", "J♠", "Q♠", "K♠", "A♠"};
    };
    CAPTURE(aliceHand);
    auto result = comparePokerHands(aliceHand, bobHand);
    CHECK_EQ("Alice wins with straight flush", result);
}


TEST_CASE("Bob wins with straight flush"){
    vector<string> aliceHand{"2♠", "3♠", "4♠", "5♠", "9♠"};
    vector<string> bobHand;
    SUBCASE("2 based straight flush"){
			bobHand = {"2♣", "3♣", "4♣", "5♣", "6♣"};
    };
    CAPTURE(bobHand);
    auto result = comparePokerHands(aliceHand, bobHand);
    CHECK_EQ("Bob wins with straight flush", result);
}
