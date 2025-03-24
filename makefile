ROOTLIBDIR      = $(shell root-config --libdir)
ROOTLIBS        = $(shell root-config --libs)
ROOTINCL        = $(shell root-config --cflags)
ROOTLDFLAGS     = $(shell root-config --ldflags)
PLATFORM        = $(shell root-config --platform)
ARCH            = $(shell root-config --arch)

# use macosx64 for Intel mac
ifeq ($(ARCH),macosxarm64)
    # mac
    CXX = clang++
    CXXOPT = -Wall -pthread -g -Wno-unused-const-variable
    # SOFLAGS = -dynamiclib -single_module -undefined dynamic_lookup
    SOSUFFIX = dylib
else
    # linux
    CXX = g++
    CXXOPT = -Wall -g -Wno-unknown-pragmas
    SOSUFFIX = so
endif

# Source files
SRCS = run_time-evolution.C code/src/time_evolution.cpp# code/src/timed_particle.cpp 
OBJS = $(SRCS:.cpp=.o)

# Executable target
my_executable: $(OBJS)
	$(CXX) $(CXXOPT) $(OBJS) `root-config --cflags --glibs` -I ${ROOTSYS} ${PYTHIA8}/include ${PYTHIA8}/lib/libpythia8.$(SOSUFFIX) $(ROOTLIBDIR)/libEGPythia8.so -o my_executable

# Pattern rule for compiling .cpp files to .o files
%.o: %.cpp
	$(CXX) $(CXXOPT) -c $< -o $@

# Pattern rule for compiling .cpp files in subdirectories to .o files
code/src/%.o: code/src/%.cpp
	$(CXX) $(CXXOPT) -c $< -o $@

# Clean rule to remove object files and executable
clean:
	rm -f $(OBJS) my_executable