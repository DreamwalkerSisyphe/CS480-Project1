#include "Scenario.hpp"

Scenario::Scenario(string text, Spell* spell, bool success, signed char rating) : _text{text}, _spell{spell}, _success{_success}, _rating{rating} {}
