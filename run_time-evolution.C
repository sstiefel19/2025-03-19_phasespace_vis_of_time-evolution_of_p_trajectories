
#include "code/include/time_evolution.h"

int run_time_evolution(){

    size_t nSteps = 5;
    Time_evolution lTimeEvolution("t1", nSteps);

    lTimeEvolution.Init();
    lTimeEvolution.Run();
    return 0;
}

