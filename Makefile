PROJECT=hotspot

CXX=g++
CXXFLAGS=-g -Wall -std=c++11
INCLUDE=-I

FILES=src/hotspot.cpp src/hs_client.cpp src/hs_export.cpp src/hs_layer.cpp src/hs_reformat.cpp src/hs_utils.cpp

.PHONY: clean

$(PROJECT):
	$(CXX) $(CXXFLAGS) -o $(PROJECT) $(FILES) src/main.cpp

clean:
	find . -name '*.DS_Store' -type f -delete
	rm -r $(PROJECT).dSYM
	rm -r $(PROJECT)

# Remove later
total-lines:
	find . -name '*.cpp' | xargs wc -l
