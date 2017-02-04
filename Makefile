CXX=g++
CXXFLAGS=-g -Wall -std=c++11

TARGET=hotspot

SRC=src/hotspot.cpp \
	src/hs_dbscan.cpp \
	src/hs_export.cpp \
	src/hs_model.cpp \
	src/hs_reformat.cpp \
	src/hs_client.cpp \
	src/hs_client_map.cpp \
	src/main.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

.PHONY: clean

clean:
	rm -rf *.o $(TARGET)
	rm -r $(TARGET).dSYM
