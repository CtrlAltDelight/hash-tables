BASE_NAME=hash
SRC_C=$(BASE_NAME).c
SRC_H=$(BASE_NAME).h
TEST_C=test_$(SRC_C)
EXECUTABLE=test_hash
CFLAGS=-g -std=c11 -Wall -Wshadow -Wvla -Werror -pedantic

$(EXECUTABLE): $(SRC_C) $(SRC_H) $(TEST_C)
	gcc $(SRC_C) $(TEST_C) $(CFLAGS) -o $(EXECUTABLE)

test: $(EXECUTABLE)
	./$(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE)
