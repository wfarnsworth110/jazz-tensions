CXX = g++
CXXFLAGS = -std=c++23 -Wall -Wextra -pedantic
TARGET = test
SOURCE = main.cpp

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CXX) -g $(CXXFLAGS) $(SOURCE) -o $(TARGET)

clean:
	rm -f $(TARGET)