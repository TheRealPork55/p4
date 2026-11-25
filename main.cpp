#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "Dictionary.h"
#include "HashDictionary.h"
#include "MaxHeap.h"
#include "WordInfo.h"

void loadFile(const std::string& filename, HashDictionary<std::string, WordInfo>& dict) {
    std::ifstream fin(filename);
    if (!fin) {
        std::cout << "Failed to open words.txt\n";
        return;
    }

    std::string line;
    while (std::getline(fin, line)) {
        std::stringstream ss(line);
        std::string word, difficultyStr, definition;

        if (!std::getline(ss, word, '|')) continue;
        if (!std::getline(ss, difficultyStr, '|')) continue;
        if (!std::getline(ss, definition)) continue;

        WordInfo w;
        w.word = word;
        w.difficulty = std::stoi(difficultyStr);
        w.definition = definition;
        w.lookupCount = 0;

        dict.insert(word, w);
    }
}

void commandLoop(HashDictionary<std::string, WordInfo>& dict) {
    std::string input;

    while (true) {
        std::cout << "> ";
        if (!std::getline(std::cin, input)) break;

        std::stringstream ss(input);
        std::string cmd;
        ss >> cmd;

        if (cmd == "QUIT") break;

        else if (cmd == "FIND") {
            std::string word;
            ss >> word;

            WordInfo result;
            if (dict.find(word, result)) {
                result.lookupCount++;
                dict.update(word, result);

                std::cout << result.word << " (difficulty=" 
                          << result.difficulty << ")\n";
                std::cout << "definition: " << result.definition << "\n";
                std::cout << "lookup count: " << result.lookupCount << "\n";
            } else {
                std::cout << "Word not found.\n";
            }
        }

        else if (cmd == "INSERT") {
            std::string word;
            int difficulty;
            ss >> word >> difficulty;

            std::string definition;
            std::getline(ss, definition);
            if (!definition.empty() && definition[0] == ' ') {
                definition.erase(0, 1);
            }

            WordInfo w;
            w.word = word;
            w.difficulty = difficulty;
            w.definition = definition;
            w.lookupCount = 0;

            dict.insert(word, w);
            std::cout << "Word inserted/updated successfully.\n";
        }

        else if (cmd == "ERASE") {
            std::string word;
            ss >> word;

            if (dict.erase(word))
                std::cout << "Word removed successfully.\n";
            else
                std::cout << "Word not found.\n";
        }

        else if (cmd == "TOP") {
            int N;
            ss >> N;

            std::vector<WordInfo*> entries = dict.getAllEntries();
            MaxHeap heap(entries);

            for (int i = 1; i <= N && !heap.empty(); ++i) {
                WordInfo* w = heap.top();
                heap.pop();
                std::cout << i << ". " << w->word 
                          << " (lookupCount=" << w->lookupCount << ")\n";
            }
        }

        else {
            std::cout << "Unknown command.\n";
        }
    }
}

int main() {
    HashDictionary<std::string, WordInfo> dict;

    loadFile("words.txt", dict);
    commandLoop(dict);

    return 0;
}