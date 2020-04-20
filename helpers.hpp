#ifndef _HELPERS_HPP
#define _HELPERS_HPP

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

void cinclr();
void clean(string& s);
vector<string> getWords(string filename);
pair<string, string> makeSpell();
bool inDict(string verb, string noun);

#endif
