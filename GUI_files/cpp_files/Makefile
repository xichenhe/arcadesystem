#CC specifies which compiler we're using
CXX = g++

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -w -g

#INCLUDE_PATHS specifies the additional include paths we'll need
INCLUDE_PATHS = -I. -I..\..\SDL_files\include\SDL2 -I..\headers -I..\..\source

#LIBRARY_PATHS specifies the additional library paths we'll need
LIBRARY_PATHS = -L..\..\SDL_files\lib

SRCS := $(wildcard *.cpp) 
OBJS := $(patsubst %.cpp,%.o,$(SRCS)) 

$(OBJS): $(SRCS)
	$(CXX) $^ $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) -c $< 

clean:
	del *.o $(OBJ_NAME)