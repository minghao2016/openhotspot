AUTOMAKE_OPTIONS=foreign
SUBDIR=src

CXX=g++
CXXFLAGS=-g -Wall -std=c++11

PROJECT=hotspot
FILES=src/hotspot.cpp src/hs_model.cpp src/http/hs_client.cpp src/hs_dbscan.cpp src/hs_export.cpp src/hs_reformat.cpp src/main.cpp

$(PROJECT):
	$(CXX) $(CXXFLAGS) -o $(PROJECT) $(FILES) src/main.cpp

clean:
	rm -f hotspot *.o
	rm -r $(PROJECT).dSYM
