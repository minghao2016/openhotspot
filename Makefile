CXX=g++
CXXFLAGS=-g -Wall -std=c++11

TARGET=hotspot

SOURCES=$(shell find src -name *.cpp)
SRC=$(SOURCES:%.cpp=%.o)

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

.PHONY: clean

clean:
	rm -rf *.o $(TARGET)
