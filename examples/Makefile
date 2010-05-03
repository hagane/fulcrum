FGFDIR = "E:/Source/FGF"
SDLDIR = "E:/Source/SDK/SDL"
CRTDIR = "C:/Program Files/Microsoft Visual Studio 9.0/VC"
WINSDK = "C:/Program Files/Microsoft SDKs/Windows/v6.0A"
FIDIR = "E:/Source/SDK/FreeImage"

CLFLAGS = /I$(FGFDIR)\include /I$(SDLDIR)\include /I$(CRTDIR)/Include /I$(WINSDK)/include /I$(FIDIR) /c /EHsc /MD
LINKFLAGS = /ENTRY:SDL_main /LIBPATH:$(FGFDIR)/lib /LIBPATH:$(CRTDIR)/Lib /LIBPATH:$(WINSDK)/Lib /subsystem:console
LIB = Fulcrum.lib OpenGL32.lib GLU32.lib  Kernel32.lib

all: compile link

compile:
	CL example1.cpp $(CLFLAGS)
	CL example2.cpp $(CLFLAGS)
	CL example3.cpp $(CLFLAGS)

link: $(OBJ)
	LINK example1.obj $(LIB) $(LINKFLAGS) /OUT:example1.exe
	LINK example2.obj $(LIB) $(LINKFLAGS) /OUT:example2.exe
	LINK example3.obj $(LIB) $(LINKFLAGS) /OUT:example3.exe

clean:
	echo cleaning...
	rm *.obj
	rm *.manifest
	rm *.exe
	rm *.log
