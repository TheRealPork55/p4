#pragma once
#include <string>

struct WordInfo {
    std::string word;
    std::string definition;
    int difficulty;
    int lookupCount;

    WordInfo() : difficulty(1), lookupCount(0) {}
};