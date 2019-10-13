#CC specifies which compiler we're using
CXX = g++

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -w -g

#INCLUDE_PATHS specifies the additional include paths we'll need
INCLUDE_PATHS = -I. -I..\SDL_files\include\SDL2 -I..\GUI_files\headers

#LIBRARY_PATHS specifies the additional library paths we'll need
LIBRARY_PATHS = -L..\SDL_files\lib

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = arcadeSystem.exe

SRCS := $(wildcard *.cpp) 
OBJS := $(patsubst %.cpp,%.o,$(SRCS)) 
# 1 make all depends on ArcadeSystem 
all: $(OBJ_NAME)

# 2 ArcadeSystem depends on the .o files, g++ -o ArcadeSystem *.o
# the .o files come from the wilcard statements
$(OBJ_NAME): $(OBJS) ../GUI_files/cpp_files/*.o
	$(CXX) $^ $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $@ 

# 3 all the .o files rely on the .cpp files
%.o: %.cpp
	$(CXX) $(INCLUDE_PATHS) $(COMPILER_FLAGS) -c $< 
clean:
	del *.o $(OBJ_NAME)