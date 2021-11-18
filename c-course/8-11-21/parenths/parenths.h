/*
 *  Igor Krzywda
 *  lista 3, zadanie 2
 *
 *  Argument 'c' pozwala na ewaluowanie kodu C pod względem
 *  zamknięcia nawiasów (pomijanie komentarzy i definicji 
 *  znaków oraz stringów
 */

#ifndef PARENTHS_H
#define PARENTHS_H

#include <stdio.h>

#define TEXT_DATA_SIZE 5

typedef unsigned int TextData[TEXT_DATA_SIZE];

void throw_error(char paren, TextData pos);
int get_next_paren(TextData t);
void skip_multiline_comment(TextData t);
void skip_comment(TextData t);
void skip_char_def();
void skip_str_def();
int get_next_paren_c(TextData t);
int compare_parens(char p1, char p2);
char opposite_paren(char paren);
int index_for_paren(char c);
int nesting(char c, TextData t);
void change_nesting(int i, char c, TextData t);
void find_pair(char p, TextData t);
void find_pair_c(char p, TextData t);
void process_parens();
void process_parens_in_c_source();

#endif
