#include "../include/time_evolution.h"

#include <cstdio>
#include <iostream>


// ================ Time_evolution::State ================


Time_evolution::State::State() {
    std::cout << "// Initialize member variables if necessary\n";
}

Time_evolution::State::~State() {
    // Clean up resources if necessary
}

// ================ Time_evolution ================
Time_evolution::Time_evolution(std::string _ID, size_t _nSteps) :
    fID(_ID),
    fNSteps(_nSteps),
    fStates(_nSteps) 
{
    printf("Time_evolution::Time_evolution(): INFO: id: %s created with %zu steps.\n", fID.data(), _nSteps);    

}

// ================ Time_evolution::Init ================
int Time_evolution::Init() {
    printf("Time_evolution::Init(): INFO: ID %s initializing\n", fID.data());
    return 0;
}

// ================ Time_evolution::Run ================
int Time_evolution::Run() {
    printf("Time_evolution::Run(): INFO: ID %s running\n", fID.data());
    return 0;
}

// ================ ~Time_evolution ================
Time_evolution::~Time_evolution() {
    printf("INFO: ID %s destroying.\n", fID.data());
}