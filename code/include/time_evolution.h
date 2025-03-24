#pragma once

// #include <TROOT.h>

#include "/Users/stephanstiefelmaier/work/alice/sw/osx_arm64/ROOT/latest/include/Rtypes.h"
#include "/Users/stephanstiefelmaier/work/alice/sw/osx_arm64/ROOT/latest/include/RConfigure.h"

#include "/Users/stephanstiefelmaier/work/alice/sw/osx_arm64/ROOT/latest/include/TParticle.h"

// #include <TParticle.h>
#include <iostream>
#include <string>
#include <vector>

/*
IDEA:
    - visualize the time evolution of a system of particles in phase space(s)
    - each particle is represented by a TParticle object with a timestamp

IMPLEMENTATION:
    Time_evolution::State
        - represents a snapshot of the system at a given decay iteration
        - contains a vector of TParticle objects
        - has a timestamp and a step number
*/

class Time_evolution {

public:
  class State {
  public:
    State();
    // State(std::string _ID, double _time);
    ~State();

    // member functions
    // member variables
  private:
    std::string fID;
    double fTime;
    std::vector<TParticle> fParticles;
  };

  Time_evolution(std::string _ID, size_t _nSteps);
  ~Time_evolution();

  // member functions
  int Init();
  int Run();

  // member variables
private:
    std::string fID;
    size_t fNSteps; // the current size of the fStates vector
    std::vector<State> fStates;

    // transient
    State &fStartState;
    State *fEndState;

    // status
    bool fEndStateDefined;
    bool fIsInitialized;
};