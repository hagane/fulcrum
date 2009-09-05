#CC = CL
#LD = LINK

#SDLDIR = "E:/Source/SDK/SDL"
#CRTDIR = "C:/Program Files/Microsoft Visual Studio 9.0/VC"
#WINSDK = "C:/Program Files/Microsoft SDKs/Windows/v6.0A"
#FIDIR = "E:/Source/SDK/FreeImage"

SOURCES=$(shell find src -iname *.cpp)
OBJECTS=$(SOURCES:.cpp=.o)

LDFLAGS=$(shell sdl-config --libs) $(shell pkg-config --libs gl) -lfreeimage -lSDL_mixer -shared
CXXFLAGS=$(shell sdl-config --cflags) $(shell pkg-config --cflags gl) -I include -fno-rtti -shared-libgcc -fms-extensions -fPIC

fulcrum.so:	${OBJECTS}
	${CXX} ${LDFLAGS} ${OBJECTS} -o fulcrum.so

all:	fulcrum.so

clean:
	rm -f src/*.o fulcrum.so

