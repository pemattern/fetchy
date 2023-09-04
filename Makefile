CC			 = g++

CPPFILES = $(wildcard *.cpp)
OBJFILES = $(CPPFILES:.cpp=.o)
OUT      = fetchy

CPPFLAGS = -std=c++17
LDLIBS = -lstdc++ -lm

$(OUT): $(OBJFILES)

.PHONY: clean
clean:
	rm -f $(OBJFILES) $(OUT)