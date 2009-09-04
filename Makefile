CC = CL
LD = LINK

SDLDIR = "E:/Source/SDK/SDL"
CRTDIR = "C:/Program Files/Microsoft Visual Studio 9.0/VC"
WINSDK = "C:/Program Files/Microsoft SDKs/Windows/v6.0A"
FIDIR = "E:/Source/SDK/FreeImage"

S = "./src"
O = "./obj"

CLFLAGS = /DFGF_DLL /I$(SDLDIR)\include /I$(CRTDIR)/Include /I$(WINSDK)/include /I$(FIDIR) /c /EHsc /MD /Ox
LINKFLAGS = /LIBPATH:$(CRTDIR)/Lib /LIBPATH:$(WINSDK)/Lib /LIBPATH:$(SDLDIR)/lib /LIBPATH:$(FIDIR) /DLL
LIB = OpenGL32.lib Kernel32.lib SDL.lib SDL_mixer.lib FreeImage.lib
OBJ = $O/*.obj
SRC = $S/*.cpp

prepare:
	mkdir obj
	mkdir lib

compile: prepare
	$(CC) $(CLFLAGS) $(SRC) /Fo./obj/

link: compile
	$(LD) $(LINKFLAGS) $(OBJ) $(LIB) /OUT:./lib/Fulcrum.dll /IMPLIB:./lib/Fulcrum.lib

clean:
	del obj /Q
	rmdir obj
	del lib /Q
	rmdir lib
	del docs /Q
	rmdir docs

all: prepare compile link
