CXX = g++
CXXFLAGS = -std=c++11 -Wall
TARGETS = blackjack generateHand

all: $(TARGETS)

blackjack: blackjack.cpp
	$(CXX) $(CXXFLAGS) -o blackjack blackjack.cpp

generateHand: generateHand.cpp
	$(CXX) $(CXXFLAGS) -o generateHand generateHand.cpp

clean:
	rm -f $(TARGETS)