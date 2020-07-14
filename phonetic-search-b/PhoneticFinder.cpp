//
// Created by miros on 20/03/2020.
//
/**
 * Phonetic search method definition:
 * this method will get both a sentence and a word (represented by string)
 * @param sentence - a misspelled sentence .
 * @param word - the word we are looking for in the sentence.
 * the letters that may have been replaced mistakenly:
 * v,w
 * b,f,p
 * g,j
 * c,k,q
 * s,z
 * d,t
 * o,u
 * i,y
 */
#include <string>
#include <stdexcept>
#include <iostream>
#include <bits/stdc++.h>

#include"PhoneticFinder.hpp"
using namespace std;

std::string phonetic::find(std::string sentence, std::string word){
    if(word == "")throw out_of_range{"cannot do any calculation on an empty word"};
    string tmpWord = word;
    string tmp1;
    string tmp2;
    int count = 0;
    //lower casing the word
    transform(word.begin(), word.end(), word.begin() , ::tolower);
   //adding a word from the sentence to tmp1
    for (int i = 0; i <sentence.length() ; ++i) {
        if(sentence[i] != ' '){
            tmp1.append(1u, sentence[i]);
        }
        if(sentence[i]== ' ' || i == sentence.length()-1){
            if(tmp1.length() == word.length()){
                tmp2 = tmp1;
                transform(tmp1.begin(), tmp1.end(), tmp1.begin(), ::tolower);
                for (int i = 0; i <word.length() ; ++i) {
                    count += similarCharsCounter(tmp1[i],word[i]);
                }
                //if the value is true then we found the word in the text and we can return tmp2
                //tmp2 contains the word as given from the text
                if(count == word.length()){
                    //return the word as found in the sentence(tmp2)
                    return tmp2;
                }
            }
            //else the words found until this far is not the one we are searching for.
            tmp1.clear();
            count = 0;
        }
    }
    throw out_of_range{tmpWord + "is not found in the sentence.!"};
}
int similarCharsCounter(char a, char b){
    if(a==b) return 1;
    if((a=='w' || a=='v') && (b=='w' || b=='v'))return 1;
    if((a=='g' || a=='j') && (b=='g' || b=='j'))return 1;
    if((a=='s' || a=='z') && (b=='s' || b=='z'))return 1;
    if((a=='d' || a=='t') && (b=='d' || b=='t'))return 1;
    if((a=='o' || a=='u') && (b=='o' || b=='u'))return 1;
    if((a=='i' || a=='y') && (b=='i' || b=='y'))return 1;
    if((a=='b' || a=='f' || a=='p') && (b=='b' || b=='f' || b=='p'))return 1;
    if((a=='c' || a=='k' || a=='q') && (b=='c' || b=='k' || b=='q'))return 1;
    return 0;
}
