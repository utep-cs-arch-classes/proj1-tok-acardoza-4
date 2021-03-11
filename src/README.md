Project 1: Tokenizer
====================

# About Tokenizer

Tokenizer is formed by 3 c files: tokenizer.c, history.c and user_interface.c,
some header files, and a makefile. Tokenizer's goal is to continuously receive
input from the user and tokenize it while storing it in a history list so the
user can access it later on.

##How To Run

Compile Tokenizer by running ***make*** in the terminal. Run the program with
***./tokenizer*** in the terminal.

Tokenizer will ask the user to provide an input with a **$** symbol. Up to 100
characters of input are accepted each time. The input is then displayed again
and separated into tokens based on whitespaces. Then, the input is stored in
the history list with an id so it can be retrieved.

To retrieve a previous input from history, enter ***!n***, where n is the
index of the nth item (e.g. "$!4" retrieves the 4th input).

An error message will be displayed to the user if an index number that is
outside of the range in the history list is given.

To exit Tokenizer enter ***q*** at any given time. Tokenizer will display the
entire history and free the allocated memory history used before ending.
