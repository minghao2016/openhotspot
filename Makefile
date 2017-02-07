CXX=g++
CXXFLAGS=-g -Wall -std=c++11

TARGET=hotspot

INCLUDES=-I /usr/local/include
LDFLAGS=-L /usr/local/lib

SOURCES=$(shell find src -name *.cpp)
SRC=$(SOURCES:%.cpp=%.o)

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC) \
	$(INCLUDES) $(LDFLAGS)

.PHONY: clean

clean:
	rm -rf *.o $(TARGET)
