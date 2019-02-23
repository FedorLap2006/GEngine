
LPATH=-Lsrc/libs/GLFW -Lsrc/libs
IPATH=-Isrc/include
StLIBS=-lopengl32
DyLIBS=-lgdi32


CASH?=off

ifeq ($(CASH),off)
	RCASH=rm -rf $(CASHDIR) && mkdir $(CASHDIR) 
else
	RCASH=
endif


LIBDIR=src/libs

TESTDIR=tests
OBJDIR=src/obj
CASHDIR=src/cash
SRCDIR=src

LLABEL=libGEngine.a
BIN=$(TESTDIR)/gen_example.exe
EP=$(TESTDIR)/main.cpp

DLIBS=$(IPATH) $(LPATH) $(StLIBS) $(DyLIBS)
PLIBS=$(IPATH) $(LPATH) $(StLIBS) $(DyLIBS)

ifeq ($(shell uname -o),Cygwin)
	CC=x86_64-w64-mingw32-g++ -std=c++14 -W
	AR=x86_64-w64-mingw32-ar
else
	CC=g++ -std=c++14 -W
endif

all: build
build: setup_src gengine test

setup_src: 
	$(CC) -c $(SRCDIR)/*.cpp $(DLIBS)
	mv *.o $(OBJDIR)/

gengine:
	cp $(OBJDIR)/*.o $(CASHDIR)
	cp $(LIBDIR)/GLFW/libglfw3.a $(CASHDIR)
	cp $(LIBDIR)/OGL/libopengl32.a $(CASHDIR)
	cp $(SRCDIR)/gengine.hpp include/
	cd $(CASHDIR) && \
		$(AR) x libglfw3.a && \
		$(AR) x libopengl32.a && \
		$(AR) rc $(LLABEL) *.o *.obj && \
		cp $(LLABEL) ../libs/
	$(RCASH)

gengine_dll:
	echo 'hello'
	
test:
	cp $(LLABEL) $(TESTDIR)
	$(CC) -L. $(EP) $(TESTDIR)/libGEngine.a $(PLIBS) -o $(BIN)
	

	

	
