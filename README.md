#### Course: Data Structures and Objects
#### Name: William Parker
#### Project: Smart Dictionary Application

# Purpose
This application uses multiple data structures to manipulate a dictionary of terms. Each term has an associated difficulty, definition, and lookup count, which is used to sort the most searched terms in the
dictionary. 

# Description of Commands
All commands are in entirely uppercase letters, though the terms and descriptions do not have to be.
## INSERT
Insert allows for the insertion of data into the dictionary. Entries must fit the following syntax inside words.txt: word|difficulty|definition and words will be input within the program like this:
word difficulty definition
Words cannot have whitespace, and words with whitespace will have the first word be returned when searching for it. Definitions do not have this limit, and can contain whitespace. Difficulty is an integer
from 1 to 5 and cannot be outside that range or contain anything but an integer.
Words already in the dictionary will be updated when insert is called on them and updated, resetting their lookup count to zero if applicable.
## FIND
Find allows for the searching of data already in the dictionary and displays the entry and the lookup count, which is incremented each time the word is looked up.
## ERASE
Erase removes a word from the dictionary.
## TOP N (where N is any integer)
Top displays n words, sorted from most searched to least searched. If n is greater than the amount of words in the dictionary, the entire dictionary will be shown without throwing an error.
## QUIT
Exits the program.

# Compilation
The entire program can be compiled with the following bash command:
g++ -std=c++17 *.cpp -o dict

# Purpose of Each File


# Assumptions and Known Issues
The program functions perfectly assuming you insert words knowing whitespace is not allowed and what the interaction the program has with whitespace. The program currently does not modify words.txt, so any
newly inserted words will not be there following quit.
