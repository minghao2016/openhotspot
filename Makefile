CXX=g++
CXXFLAGS=-g -Wall -std=c++11

SRC_FILES=src/hs_dbscan.cpp src/hs_export.cpp src/hs_logger.cpp src/hs_reformat.cpp src/main.cpp src/http/hs_client.cpp
OBJ=src/hs_dbscan.o src/hs_export.o src/hs_logger.o src/hs_reformat.o src/main.o src/http/hs_client.o

hotspot: $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(PROJECT) $(SRC_FILES) src/main.cpp

clean:
	rm -rf *.o hotspot
	rm -r hotspot.dSYM
