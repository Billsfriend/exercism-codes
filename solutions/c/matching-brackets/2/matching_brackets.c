#include "matching_brackets.h"

#include <stddef.h>
#include <string.h>

static const char left_brackets[] = "([{";

static const char right_brackets[] = ")]}";

bool is_paired(const char *input)
{
    size_t len = strlen(input);
    char stack[len];
    size_t stack_count = 0;
    while (*input != '\0') {
        // found open bracket
        if (strchr(left_brackets, *input)) {
            // add to stack
            stack[stack_count++] = *input;
        }
        // found close bracket
        if (strchr(right_brackets, *input)) {
            // on top level
            if (stack_count == 0) {
                return false;
            }
            int bracket_index = strchr(right_brackets, *input) - right_brackets;
            // mismatched close
            if (left_brackets[bracket_index] != stack[stack_count-1]) {
                return false;
            }
            // matched close
            stack_count--;
        }
        input++;
    }
    return stack_count == 0;
}