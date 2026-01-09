#include "run_length_encoding.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *encode(const char *text) {
    if (!text) return NULL;

    size_t len = strlen(text);
    char *code = malloc(len + 1);
    if (!code) return NULL;

    size_t code_len = 0;
    for (size_t i = 0; i < len; ) {
        char temp = text[i];
        int seq_count = 0;
        
        while (i < len && text[i] == temp) {
            seq_count++;
            i++;
        }

        if (seq_count > 1) {
            code_len += sprintf(code + code_len, "%d", seq_count);
        }
        code[code_len++] = temp;
    }
    code[code_len] = '\0';
    
    char *resized_code = realloc(code, code_len + 1);
    return resized_code ? resized_code : code; // 如果realloc失败，返回原指针
}

char *decode(const char *data) {
    if (!data) return NULL;

    size_t len = strlen(data);
    
    size_t text_len = 0;
    size_t i = 0;
    while (i < len) {
        int num = 0;
        while (i < len && isdigit((unsigned char)data[i])) {
            num = num * 10 + (data[i] - '0');
            i++;
        }

        if (num == 0) num = 1;
        
        if (i < len) {
            text_len += num;
            i++;
        }
    }

    char *text = malloc(text_len + 1);
    if (!text) return NULL;

    i = 0;
    size_t pos = 0;
    while (i < len) {
        int num = 0;
        while (i < len && isdigit((unsigned char)data[i])) {
            num = num * 10 + (data[i] - '0');
            i++;
        }
        if (num == 0) num = 1;

        if (i < len) {
            char c = data[i++];
            for (int j = 0; j < num; j++) {
                text[pos++] = c;
            }
        }
    }
    text[pos] = '\0';
    return text;
}

