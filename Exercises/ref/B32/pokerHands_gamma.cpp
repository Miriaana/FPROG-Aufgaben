#include <iostream>
#include <string>
#include <functional>
#include <numeric>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;
using namespace std::placeholders;

using Hand = vector<string>;
auto comparePokerHands = [](const Hand& /*aliceHand*/, const Hand& bobHand){
	Hand winningBobHand {"2♣", "3♣", "4♣", "5♣", "6♣"};
	if(bobHand == winningBobHand){
		return "Bob wins with straight flush";
	}
	return "Alice wins with straight flush";
};

TEST_CASE("Bob wins with straight flush"){
	Hand aliceHand{"2♠", "3♠", "4♠", "5♠", "9♠"};
	Hand bobHand;
	SUBCASE("2 based straight flush"){
		bobHand = {"2♣", "3♣", "4♣", "5♣", "6♣"};
	};
	CAPTURE(bobHand);
	auto result = comparePokerHands(aliceHand, bobHand);
	CHECK_EQ("Bob wins with straight flush", result);
}
