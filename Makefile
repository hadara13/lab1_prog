CXX = g++
CXXFLAGS = -g -Wall
SRC_DIR = src
BUILD_DIR = build
TARGET = $(BUILD_DIR)/debug.out


$(BUILD_DIR)/lab1.o: $(SRC_DIR)/lab1.cpp
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(BUILD_DIR)/rect.o: $(SRC_DIR)/rect.cpp $(SRC_DIR)/rect.h
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(BUILD_DIR)/barrel.o: $(SRC_DIR)/barrel.cpp $(SRC_DIR)/barrel.h
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(BUILD_DIR)/matrix.o: $(SRC_DIR)/matrix.cpp $(SRC_DIR)/matrix.h
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(BUILD_DIR)/mystring.o: $(SRC_DIR)/mystring.cpp $(SRC_DIR)/mystring.h
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<


$(TARGET): $(BUILD_DIR)/rect.o $(BUILD_DIR)/mystring.o $(BUILD_DIR)/barrel.o $(BUILD_DIR)/matrix.o $(BUILD_DIR)/lab1.o
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^


debug: $(TARGET)
	gdb $(TARGET)

build/leaks.out: $(BUILD_DIR)/rect.o $(BUILD_DIR)/mystring.o $(BUILD_DIR)/barrel.o $(BUILD_DIR)/matrix.o $(BUILD_DIR)/lab1.o
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

leaks: build/leaks.out
	./build/leaks.out < input.txt


build/test_rect_methods.out: tests/test_rect_methods.cpp $(BUILD_DIR)/rect.o
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

test-rect: build/test_rect_methods.out
	./build/test_rect_methods.out


build/test_rect_properties.out: tests/test_rect_properties.cpp $(BUILD_DIR)/rect.o
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^


build/test_rect_operations.out: tests/test_rect_operations.cpp $(BUILD_DIR)/rect.o
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^


build/test_bounding_rect.out: tests/test_bounding_rect.cpp $(BUILD_DIR)/rect.o
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^


test-properties: build/test_rect_properties.out
	./build/test_rect_properties.out

test-operations: build/test_rect_operations.out
	./build/test_rect_operations.out

test-bounding: build/test_bounding_rect.out
	./build/test_bounding_rect.out

test-rect-all: test-rect test-properties test-operations test-bounding
	@echo " All Rect tests passed!"

test: test-rect-all
	@echo " All tests completed successfully!"

clean:
	rm -rf $(BUILD_DIR)

