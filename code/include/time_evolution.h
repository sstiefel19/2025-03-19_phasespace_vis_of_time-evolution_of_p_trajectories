#pragma once

#include "TParticle.h"

#include<string>
#include<vector>


class Time_evolution {
    
    public:
        class State {

        public:
            State();
            ~State();  

            // member functions

            // member variables
        private:
            double fTime;
            int fStep;
            std::vector<TParticle> fParticles;
            std::string fID;    
        };
    


    // constructor
    Time_evolution(std::string _ID, size_t _nSteps);
    // destructor
    ~Time_evolution();  

    // member functions
    int Init();
    int Run();

    // member variables
    State fStartState;
    State fEndState;

    private:
    std::string fID;
    size_t fNSteps;
    std::vector<State> fStates;
};