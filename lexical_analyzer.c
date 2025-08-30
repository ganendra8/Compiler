#include <stdio.h>
#include <string.h>

int isKeyword(char* s) {
    return strcmp(s, "int") == 0 || strcmp(s, "float") == 0 || 
           strcmp(s, "if") == 0 || strcmp(s, "else") == 0 || 
           strcmp(s, "while") == 0 || strcmp(s, "for") == 0 || 
           strcmp(s, "return") == 0 || strcmp(s, "void") == 0;
}

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '=' ||
           c == '<' || c == '>' || c == '!' || c == '&' || c == '|';
}

int isDelimiter(char c) {
    return c == '(' || c == ')' || c == '{' || c == '}' || 
           c == '[' || c == ']' || c == ';' || c == ',';
}

int isDigit(char c) {
    return c >= '0' && c <= '9';
}

int isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
}

int main() {
    char input[1000];
    printf("Enter C code: ");
    fgets(input, sizeof(input), stdin);
    
    int len = strlen(input);
    
    for(int i = 0; i < len; i++) {
        if(input[i] == ' ' || input[i] == '\n') continue;
        
        // Number
        if(isDigit(input[i])) {
            char num[100];
            int j = 0;
            while(i < len && isDigit(input[i])) {
                num[j++] = input[i++];
            }
            num[j] = '\0';
            i--;
            printf("NUMBER: %s\n", num);
        }
        // Identifier/Keyword
        else if(isLetter(input[i])) {
            char word[100];
            int j = 0;
            while(i < len && (isLetter(input[i]) || isDigit(input[i]))) {
                word[j++] = input[i++];
            }
            word[j] = '\0';
            i--;
            if(isKeyword(word))
                printf("KEYWORD: %s\n", word);
            else
                printf("IDENTIFIER: %s\n", word);
        }
        // Operator
        else if(isOperator(input[i])) {
            printf("OPERATOR: %c\n", input[i]);
        }
        // Delimiter
        else if(isDelimiter(input[i])) {
            printf("DELIMITER: %c\n", input[i]);
        }
    }
    
    return 0;
}