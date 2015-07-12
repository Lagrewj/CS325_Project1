CXX = g++
CXXFLAGS = -std=c++0x 
CXXFLAGS += -Wall #Turns on all warnings
CXXFLAGS += -pedantic-errors #strictly enforce standard
CXXFLAGS += -g #debugging informoration
#CXXFLAGS += -O3 #optimization
LDFLAGS = -lboost_date_time

#OBJS = f.o g.o

SRCS = main.cpp algorithms.cpp file_action.cpp file_check.cpp validation.cpp

HEADERS = algorithms.h file_action.h file_check.h validation.h

maxSubArray: ${SRCS} ${HEADERS}
	${CXX} ${LDFLAGS} ${SRCS} -o maxSubArray
