# This make file compiles all the .cpp files
# in this directory into acording .o files

#CC specifies which compiler we're using
CXX = g++

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings, -g adds debug information
COMPILER_FLAGS = -w -g

#INCLUDE_PATHS specifies thepaths to header files
INCLUDE_PATHS = -I. -I..\..\SDL_files\include\SDL2 -I..\headers -I..\..\source

#LIBRARY_PATHS specifies paths to libs we need
LIBRARY_PATHS = -L..\..\SDL_files\lib 

#SRCS is all the .cpp files in the current directory
SRCS := $(wildcard *.cpp) 

#OBJS is all the .o files that will be created from SRCS
OBJS := $(patsubst %.cpp,%.o,$(SRCS)) 

# The name of the target we want relies on the object files
all: $(OBJS) 

# make a list of dependency files from the .o files
DEPS := $(OBJS:.o=.d)

-include $(DEPS)

# This specifies a static pattern rule because we have multiple targets that 
# should each be compiled separately and rely only on the according .o file
# -MMD is a compiler flag that generates rules for make for dependent include files
$(OBJS): %.o: %.cpp
	$(CXX) -MMD -c $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $< -o $@
clean:
	del *.o $(OBJ_NAME)
