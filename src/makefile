all: tokenizer

tokenizer: tokenizer.c history.c user_interface.c
	gcc $^ -o $@

clean:
	rm -f *.o *.c~ tokenizer
