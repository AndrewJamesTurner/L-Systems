#ifndef LSYSTEM_H
#define LSYSTEM_H

#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>


class Lsystem
{
    public:
        Lsystem(std::string axiom);
        virtual ~Lsystem();

        friend std::ostream& operator<<(std::ostream& os, const Lsystem& lsystem);

        void iterate(void);
        std::string getWord(void);

    protected:

    private:

        int numSuccessor = 3;

        std::vector<char> grammer = {'X','F','+','-','[',']'};
        std::vector<char> predecessor = {'X', 'F'};
        //std::vector<std::string> successor = { "F-[[X]+X]+F[+FX]-X", "FF" };

        std::vector<std::string> successor = { "X", "F[+F]F[-F]F" };
        std::vector<std::string> successor2 = { "X", "F[+F]F" };
        std::vector<std::string> successor3 = { "X", "F[-F]F" };

        //std::vector<std::string> successor = { "F[+X][-X]FX", "FF" };
        //std::vector<std::string> successor = { "X", "FF-[-F+F+F]+[+F-F-F]" };


        //std::vector<char> grammer = {'F','+','-'};
        //std::vector<char> predecessor = {'F'};
        //std::vector<std::string> successor = { "F+F-F-F+F" };

        std::string word;

        bool isWordValid(std::string _word);
        bool isInGrammer(char x);
        bool isInPredecessor(char x);
        int getPredecessorIndex(char x);



};

#endif // LSYSTEM_H
