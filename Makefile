CXX=g++
CXXFLAGS=-g -Wall -std=c++11

PROJECT=hotspot
MAIN_FILES=src/hotspot.cpp src/hs_model.cpp
SRC_FILES=src/hs_dbscan.cpp src/hs_export.cpp src/hs_reformat.cpp src/main.cpp
HTTP_FILES=src/http/hs_client.cpp

$(PROJECT):
	$(CXX) $(CXXFLAGS) -o $(PROJECT) $(MAIN_FILES) \
	$(SRC_FILES) $(HTTP_FILES) src/main.cpp

clean:
	rm -f hotspot *.o
	rm -r $(PROJECT).dSYM
