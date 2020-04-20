CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

aitran: main.o Transcript.o Scenario.o Spell.o GameTree.o Trie.o helpers.o
	$(CXX) $(CXXFLAGS) -o aitran main.o Transcript.o Scenario.o Spell.o GameTree.o Trie.o helpers.o
	
main.o: main.cpp Transcript.hpp helpers.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

Transcript.o: Transcript.hpp Scenario.hpp helpers.hpp

Scenario.o: Scenario.hpp Spell.hpp

Spell.o: Spell.hpp

GameTree.o: GameTree.hpp Trie.hpp helpers.hpp

Trie.o: Trie.hpp

helpers.o: helpers.hpp

clean:
	rm aitran *.o