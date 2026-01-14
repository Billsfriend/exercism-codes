#include "rail_fence_cipher.h"
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

char *encode(char *text, size_t rails) {
    size_t len = strlen(text);
    char *code = malloc(len+1);
    if (code == NULL) return NULL;
    char **fence = malloc(rails * sizeof(char *));
    if (fence == NULL) { free(code); return NULL; }
    for (size_t i = 0; i < rails; i++) {
        fence[i] = calloc(len + 1, sizeof(char));
        if (fence[i] == NULL) {
            for (size_t j = 0; j < i; j++) free(fence[j]);
            free(fence);
            free(code);
            return NULL;
        }
        memset(fence[i], ' ', len);
    }
    size_t row = 0;
    int fence_down = 1;
    for (size_t col = 0; col < len; col++) {
        char temp = text[col];
        fence[row][col] = temp;
        if (row == rails - 1 && fence_down == 1) {
            fence_down = -1;
        }
        if (row == 0 && fence_down == -1) {
            fence_down = 1;
        }
        row += fence_down;
    }
    char *code_write = code;
    for (size_t i = 0; i < rails; i++) {
        for (size_t j = 0; j < len; j++) {
            if (fence[i][j] != ' ') {
                *code_write = fence[i][j];
                code_write++;
            }
        }
        free(fence[i]);
    }
    free(fence); 
    *code_write = '\0';
    return code;
}

char *decode(char *code, size_t rails) {
    size_t len = strlen(code);
    char *text = malloc(len + 1);
    if (text == NULL) return NULL;

    // a position mark array
    int *pos = calloc(len, sizeof(int));
    if (pos == NULL) { free(text); return NULL; }

    size_t row = 0;
    int fence_down = 1;
    for (size_t i = 0; i < len; i++) {
        pos[i] = row;
        if (row == rails - 1 && fence_down == 1) {
            fence_down = -1;
        }
        if (row == 0 && fence_down == -1) {
            fence_down = 1;
        }
        row += fence_down;
    }

    // group by row
    char **groups = malloc(rails * sizeof(char *));
    if (groups == NULL) { free(pos); free(text); return NULL; }
    int *group_len = calloc(rails, sizeof(int));
    if (group_len == NULL) { free(groups); free(pos); free(text); return NULL; }

    // calculate length of groups
    for (size_t i = 0; i < len; i++) {
        group_len[pos[i]]++;
    }

    // alloc memory
    char *code_ptr = code;
    for (size_t i = 0; i < rails; i++) {
        groups[i] = malloc(group_len[i] + 1);
        if (groups[i] == NULL) {
            for (size_t j = 0; j < i; j++) free(groups[j]);
            free(groups);
            free(group_len);
            free(pos);
            free(text);
            return NULL;
        }
        memcpy(groups[i], code_ptr, group_len[i]);
        groups[i][group_len[i]] = '\0';
        code_ptr += group_len[i];
    }

    // decoding
    int *group_ptr = calloc(rails, sizeof(int));
    if (group_ptr == NULL) {
        for (size_t i = 0; i < rails; i++) free(groups[i]);
        free(groups);
        free(group_len);
        free(pos);
        free(text);
        return NULL;
    }

    for (size_t i = 0; i < len; i++) {
        int r = pos[i];
        text[i] = groups[r][group_ptr[r]++];
    }
    text[len] = '\0';

    // free temp heap
    for (size_t i = 0; i < rails; i++) free(groups[i]);
    free(groups);
    free(group_len);
    free(group_ptr);
    free(pos);

    return text;
}

