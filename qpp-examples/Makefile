PROJ = minimal

CC = g++

CFLAGS = -std=c++11

$(PROJ): $(PROJ).cpp
	$(CC) $(CFLAGS) -o $@ $^ -I/usr/local/eigen -I/usr/local/qpp/include

.PHONY: clean
clean:
	rm $(PROJ)
