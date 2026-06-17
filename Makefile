CC = gcc
CFLAGS = -I include
LDFLAGS = -L lib -lraylib -lgdi32 -lwinmm
TARGET = Perlin.exe
SRC = src/Perlin.c

$(TARGET): $(SRC)
	$(CC) -o $(TARGET) $(SRC) $(CFLAGS) $(LDFLAGS)

clean:
	rm -f $(TARGET)
