#include "Lsystem.h"

Lsystem::Lsystem(std::string axiom)
{
    if(isWordValid(axiom))
        word = axiom;
    else{
        std::cout << "Error: invalid axiom.\n";
        exit(0);
    }
}

Lsystem::~Lsystem()
{
    //dtor
}

std::ostream& operator<<(std::ostream& os, const Lsystem& lsystem){
    return os << lsystem.word;
}

std::string Lsystem::getWord(void){
    return word;
}



bool Lsystem::isWordValid(std::string _word)
{
    for(auto i = _word.begin(); i != _word.end(); i++){

        if(!isInGrammer(*i))
           return false;
    }

    return true;
}

void Lsystem::iterate(void){

    std::string newWord = "";



    for (unsigned int i = 0; i < word.length(); i++){
    //for(auto i = word.begin(); i != word.end(); i++){



        if(isInPredecessor(word[i])){
            newWord += successor[getPredecessorIndex(word[i])];
        }

        else{
            newWord += word[i];
        }
    }

    word = newWord;



}


bool Lsystem::isInGrammer(char x){

    for(auto i = grammer.begin(); i != grammer.end(); i++){

        if(x == *i){
            return true;
        }
    }

    return false;
}

bool Lsystem::isInPredecessor(char x){

    for(auto i = predecessor.begin(); i != predecessor.end(); i++){

        if(x == *i){
            return true;
        }
    }

    return false;
}


int Lsystem::getPredecessorIndex(char x){

    int index = 0;

    for(auto i = predecessor.begin(); i != predecessor.end(); i++){

        if(x == *i){
            return index;
        }

        index++;
    }

    // should never reach here!
    return -1;
}
