CC = g++

CXXFLAGS = -std=c++11 -Wall -g -fPIC 

INCLUDES = -I./eigen-git-mirror/

LIBDIR = 

LIBS = 

SRCS = $(wildcard *.cpp)

OBJS = $(SRCS:.cpp=.o)

OUT = samples

.PHONY: depend clean

all: $(OUT)

$(OUT): $(OBJS)
	$(CC) $(LIBS) -o $(OUT) $(OBJS)

.cpp.o:
	$(CC) $(INCLUDES) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) *.o $(OUT)

depend: $(SRCS)
	makedepend $(INCLUDES) $^
