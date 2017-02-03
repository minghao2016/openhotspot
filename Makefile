CXX=g++
CXXFLAGS=-g -Wall -std=c++11

PROJECT_NAME=hotspot

SRC=src/hotspot.cpp 	\
	 src/hs_dbscan.cpp \
	 src/hs_export.cpp \
	 src/hs_logger.cpp \
	 src/hs_model.cpp \
	 src/hs_reformat.cpp \
	 src/http/hs_client.cpp \
	 src/main.cpp

hotspot: $(SRC)
	$(CXX) $(CXXFLAGS) -o $(PROJECT_NAME) $(SRC)

.PHONY: clean

clean:
	rm -rf *.o hotspot
	rm -r hotspot.dSYM
