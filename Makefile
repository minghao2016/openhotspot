CXX=g++
CXXFLAGS=-g -Wall -std=c++11
INCLUDE=-I

PROJECT=canalysis
FILES=src/canalysis.cpp src/parser.cpp src/layer.cpp src/predict.cpp src/utils.cpp

.PHONY: clean

$(PROJECT):
	$(CXX) $(CXXFLAGS) -o $(PROJECT) $(FILES) src/main.cpp

clean:
	find . -name '*.DS_Store' -type f -delete
	rm -r $(PROJECT).dSYM
	rm -r $(PROJECT)
