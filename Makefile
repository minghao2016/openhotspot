# BSD 3-Clause License
# Canalysis v0.0.1 Beta
# Copyright (c) 2016, Matt Perez, all rights reserved.
#
# This source is licensed under the BSD 3-Clause License.
# The license can be found in the main directory for more
# information about using this program.

PROJECT=canalysis
CXX=g++
CXXFLAGS=-g -Wall -std=c++11
FILES=src/canalysis.cpp src/parser.cpp src/layer.cpp src/predict.cpp src/utils.cpp

$(PROJECT):
	$(CXX) $(CXXFLAGS) -o $(PROJECT) $(FILES) src/main.cpp

clean:
	find . -name '*.DS_Store' -type f -delete
	rm -r $(PROJECT).dSYM

total-lines:
	# Just to see check... Remove later
	find . -name '*.cpp' | xargs wc -l
