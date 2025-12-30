#include "matching_brackets.h"

#include <stddef.h>
#include <string.h>

static const char left_brackets[] = "([{";

static const char right_brackets[] = ")]}";

static const char *parse(const char *s, char expected_close)
{
    while (*s != '\0') {
        const char *open = strchr(left_brackets, *s);
        if (open != NULL) {
            char close = right_brackets[open - left_brackets];

            const char *next = parse(s + 1, close);
            if (next == NULL) {
                return NULL;
            }
            s = next;      // close this pair & begin a new round
            continue;
        }

        const char *close = strchr(right_brackets, *s);
        if (close != NULL) {
            // top level
            if (expected_close == '\0') {
                return NULL;
            }

            // mismatched close
            if (*s != expected_close) {
                return NULL;
            }

            // matched close
            return s + 1;
        }

        // skip non-bracket char
        s++;
    }

    // end of string
    if (expected_close != '\0') {
        return NULL;
    }

    return s;
}

bool is_paired(const char *input)
{
    if (input == NULL) {
        return true;
    }

    const char *end = parse(input, '\0');
    return (end != NULL && *end == '\0');
}