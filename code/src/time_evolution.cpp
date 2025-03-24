#include "../include/time_evolution.h"

#include <cstdio>
#include <iostream>
#include <string>

// ================ Time_evolution::State ================
Time_evolution::State::State() :
    fID(""),
    fTime(0.0)//,
    //fParticles() 
{
  std::cout << "// Initialize member variables if necessary\n";
}

// Time_evolution::State::State(std::string _ID, double _time, int _step)
//     : fID(_ID), fTime(_time), fStep(_step), fParticles(fStep) {
//   std::cout << "// Initialize member variables if necessary\n";
// }

Time_evolution::State::~State() {
  // Clean up resources if necessary
}

// ================ Time_evolution ================
Time_evolution::Time_evolution(std::string _ID, size_t _nSteps)
    : fID(_ID), 
      fNSteps(_nSteps), 
      fStates(_nSteps), 
      fStartState(fStates[0]),
      fEndState(nullptr),
      fEndStateDefined(false), 
      fIsInitialized(false)
{
  printf("Time_evolution::Time_evolution(): INFO: id: %s created with %zu "
         "steps.\n",
         fID.data(), _nSteps);
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