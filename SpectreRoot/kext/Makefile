KEXT_NAME = rootkit.kext
KEXT_ID = com.spectreroot.kext.rootkit

SRC = rootkit.cpp
OBJ = $(SRC:.cpp=.o)
CXX = clang++
CXXFLAGS = -Wall -Wextra -fno-exceptions -fno-rtti -mkernel -std=c++17 -arch x86_64 -mmacosx-version-min=10.9
LD = ld
LDFLAGS = -macosx_version_min 10.9 -arch x86_64 -lSystem -lkmodc++

KEXT_BIN = $(KEXT_NAME)/Contents/MacOS/rootkit

all: $(KEXT_BIN)

$(KEXT_BIN): $(OBJ)
	mkdir -p $(KEXT_NAME)/Contents/MacOS
	$(LD) $(LDFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ) $(KEXT_NAME)