CCFLAGS := -static -DONLINE_JUDGE -lm -s -x c++ -O2 -std=c++11 -D__USE_MINGW_ANSI_STDIO=0 -g

all: A B C D E F



A: a.cpp
	$(CXX) $(CCFLAGS) a.cpp -o $@


B: b.cpp
	$(CXX) $(CCFLAGS) b.cpp -o $@


C: c.cpp
	$(CXX) $(CCFLAGS) c.cpp -o $@


D: d.cpp
	$(CXX) $(CCFLAGS) d.cpp -o $@


E: e.cpp
	$(CXX) $(CCFLAGS) e.cpp -o $@

F: f.cpp
	$(CXX) $(CCFLAGS) f.cpp -o $@


clean:
	rm -f A B C D E F
