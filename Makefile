CC      = gcc
CFLAGS  = -Wall -Wno-unused-function

all: parser

parser: y.tab.c lex.yy.c
	$(CC) $(CFLAGS) y.tab.c lex.yy.c -o parser

y.tab.c y.tab.h: parser.y
	yacc -d parser.y

lex.yy.c: lexicalAnalyzer.l y.tab.h
	flex lexicalAnalyzer.l

clean:
	rm -f y.tab.c y.tab.h lex.yy.c parser parser.exe *.json

test: parser
	@echo "=== Valid: softmax kernel ==="
	./parser example.triton parser_output.json && echo "PASS" || echo "FAIL"
	@echo "=== Error: missing colon ==="
	./parser tests/error_missing_colon.triton /dev/null; true
	@echo "=== Error: unbalanced parens ==="
	./parser tests/error_unbalanced_parens.triton /dev/null; true
	@echo "=== Edge: function with pass ==="
	./parser tests/valid_pass_func.triton /dev/null && echo "PASS" || echo "FAIL"

.PHONY: all clean test
