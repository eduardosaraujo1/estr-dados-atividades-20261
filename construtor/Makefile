CXXFLAGS = -Wall -Wpedantic -Wextra

.PHONY: run clean

%: %/main.cpp
	mkdir -p build
	g++ $(CXXFLAGS) $(shell find . -path "*/$*/*.cpp") -o build/$*

clean:
	rm -rf ./build