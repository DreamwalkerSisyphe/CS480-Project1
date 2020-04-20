#ifndef _TRANSCRIPT_HPP
#define _TRANSCRIPT_HPP

#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include "Scenario.hpp"
#include "helpers.hpp"

using namespace std;

class Transcript {
public:
    Transcript(pair<string, string> _startSpell);
    void getScenario();
    void setEnding(string _ending);
    string transcribe();

private:
    vector<Scenario*> allScenarios;
    pair<string, string> startSpell;
    string ending;
};

#endif