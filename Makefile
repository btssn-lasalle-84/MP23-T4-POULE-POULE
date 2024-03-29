TARGET = poule-poule.out
MAIN = main
JOUEUR = Joueur
CARTE = Carte
MAITREPOULEPOULE = MaitrePoulePoule
IHM = IHM

SOURCES := $(wildcard *.cpp)
HEADERS := $(wildcard *.h)

CFLAGS = -std=c++11 -Wall -I.
CXX = g++ $(CFLAGS) -c
LD = g++ -o
RM = rm -f

all: $(TARGET)

$(TARGET): $(MAIN).o $(JOUEUR).o $(CARTE).o $(MAITREPOULEPOULE).o $(IHM).o
	$(LD) $@ $(LDFLAGS) $^

$(MAIN).o: $(MAIN).cpp
	$(CXX) $(CFLAGS) $^

$(JOUEUR).o: $(JOUEUR).cpp
	$(CXX) $(CFLAGS) $^

$(CARTE).o: $(CARTE).cpp
	$(CXX) $(CFLAGS) $^

$(MAITREPOULEPOULE).o: $(MAITREPOULEPOULE).cpp
	$(CXX) $(CFLAGS) $^

$(IHM).o: $(IHM).cpp
	$(CXX) $(CFLAGS) $^

.PHONY: check cppcheck format clean cleanall

check:
	clang-tidy $(SOURCES) --quiet -header-filter='.*' -checks=-*,boost-*,bugprone-*,performance-*,readability-*,portability-*,modernize-use-nullptr,clang-analyzer-*,cppcoreguidelines-* --format-style=none -- -std=c++11

cppcheck:
	cppcheck --enable=all --std=c++11 --platform=unix64 --suppress=missingIncludeSystem --quiet $(SOURCES)

format:
	find . -regex '.*\.\(cpp\|h\)' -exec clang-format -i --style=file {} \;

clean:
	$(RM) *.o

cleanall:
	$(RM) *.o* *.*~ $(TARGET)
