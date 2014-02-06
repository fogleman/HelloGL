SRC = src
BUILD = build
FLAGS = -std=c99 -O3
LIBS = -lglew -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo
OBJ = $(patsubst $(SRC)/%.c,$(BUILD)/%.o,$(wildcard $(SRC)/*.c))
INC = $(wildcard src/*.h)

all: $(BUILD) main

run: all
	./main

clean:
	rm -Rf $(BUILD)
	rm main

$(BUILD):
	mkdir -p $@

$(BUILD)/%.o: $(SRC)/%.c ${INC}
	gcc -c -o $@ $(FLAGS) $<

main: $(OBJ)
	gcc -o $@ $^ $(CFLAGS) $(LIBS)
