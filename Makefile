CPP=g++
CPPFLAGS= -Wall -g
CLEAN= rm -f

SOURCEDIR=src
BUILDDIR=build

EXECUTABLE=target/cmatch3
SOURCES=$(wildcard $(SOURCEDIR)/*.cpp)
OBJECTS=$(patsubst $(SOURCEDIR)/%.cpp,$(BUILDDIR)/%.o,$(SOURCES))

build: create_dirs $(EXECUTABLE)

create_dirs:
	mkdir build target

$(EXECUTABLE): $(OBJECTS)
	$(CPP) $(CPPFLAGS) -o $@ $^

$(OBJECTS): $(BUILDDIR)/%.o: $(SOURCEDIR)/%.cpp
	$(CPP) $(CPPFLAGS) -c -o $@ $<

clean:
	$(CLEAN) $(BUILDDIR)/*.o $(EXECUTABLE)