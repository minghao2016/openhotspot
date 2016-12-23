CXX=g++
CXXFLAGS=-g -Wall -std=c++11
INCLUDE=-I

PROJECT=canalysis
FILES=src/canalysis.cpp src/layer.cpp src/writer.cpp src/utils.cpp src/client.cpp

.PHONY: clean

$(PROJECT):
	$(CXX) $(CXXFLAGS) -o $(PROJECT) $(FILES) src/main.cpp

clean:
	find . -name '*.DS_Store' -type f -delete
	rm -r $(PROJECT).dSYM
	rm -r $(PROJECT)
