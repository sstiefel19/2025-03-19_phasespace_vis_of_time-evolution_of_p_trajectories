#include "TROOT.h"

void compile()
{
    bool t1 = gROOT->ProcessLine(".L code/src/time_evolution.cpp+");

    // bool u1 = gROOT->ProcessLine(".L /analysisSoftware/utils_sstiefel_2024/src/utils_utils.cpp+");
    // bool u2 = gROOT->ProcessLine(".L /analysisSoftware/utils_sstiefel_2024/src/utils_computational.cpp+");
 

}