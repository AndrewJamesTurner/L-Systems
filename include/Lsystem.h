#ifndef LSYSTEM_H
#define LSYSTEM_H

#include <vector>
#include <string>
#include <iostream>


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

        std::vector<char> grammer = {'X','F','+','-','[',']'};
        std::vector<char> predecessor = {'X', 'F'};
        std::vector<std::string> successor = { "F−[[X]+X]+F[+FX]−X", "FF" };

        std::string word;

        bool isWordValid(std::string _word);
        bool isInGrammer(char x);
        bool isInPredecessor(char x);
        int getPredecessorIndex(char x);



};

#endif // LSYSTEM_H
