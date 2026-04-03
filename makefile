__COMP = g++
__CXXFLAGS = -std=c++17
__FLAGS = -lvulkan

__DST = build/app
__SRC = build/app.cpp $(wildcard include/_*/*.cpp)
__OBJ = $(__SRC:.cpp=.o)

ifdef WAYLAND_DISPLAY
	__CXXFLAGS += -D__TECMA_WAYLAND
endif

ifdef DISPLAY
	__CXXFLAGS += -D__TECMA_XLIB
	__FLAGS += -lX11
endif

all: clean $(__DST)

$(__DST): $(__OBJ)
	$(__COMP) -g -fsanitize=address -fno-omit-frame-pointer $(__OBJ) -Iinclude -o $@ $(__FLAGS)

%.o: %.cpp
	$(__COMP) -g -fsanitize=address -fno-omit-frame-pointer -c $< -Iinclude -o $@ $(__CXXFLAGS)

clean: 
	@find . -path "./include/_*/*.o" -type f -delete
	@rm -f $(__DST)