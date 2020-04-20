#ifndef _SCENARIO_HPP
#define _SCENARIO_HPP

#include <string>
#include "Spell.hpp"

using namespace std;

struct Scenario{
    Scenario(string text, Spell* spell, bool success, signed char rating);
    string _text;
    Spell* _spell;
    bool _success;
    signed char _rating; //Don't need need more than a byte to store values -2 to 2
};

#endif