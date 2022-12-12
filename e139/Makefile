CXX := g++
CXXFLAGS := -static -DONLINE_JUDGE -s -x c++ -O2 -std=c++17 -D__USE_MINGW_ANSI_STDIO=0
LDFLAGS := -lm

SOURCES=$(wildcard *.cc)
EXECS=$(SOURCES:%.cc=%)

.PHONY: all
all: $(EXECS)

.cc:
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f $(EXECS)
