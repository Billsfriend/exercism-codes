#include "grade_school.h"
#include <string.h>

void init_roster(roster_t *roster) {
    roster->count = 0;
}

bool add_student(roster_t *roster, const char *name, uint8_t grade) {
    // check if student already exists
    for (size_t i = 0; i < roster->count; i++) {
        if (strcmp(roster->students[i].name, name) == 0) {
            return false;
        }
    }

    // create new student
    student_t new_student;
    new_student.grade = grade;
    strncpy(new_student.name, name, MAX_NAME_LENGTH - 1);
    new_student.name[MAX_NAME_LENGTH - 1] = '\0';

    // check where to insert (ascending)
    size_t insert_pos = roster->count;
    for (size_t i = 0; i < roster->count; i++) {
        if (grade < roster->students[i].grade ||
            (grade == roster->students[i].grade && strcmp(name, roster->students[i].name) < 0)) {
            insert_pos = i;
            break;
        }
    }

    // shift position of existed students
    if (insert_pos < roster->count) {
        memmove(&roster->students[insert_pos + 1], 
                &roster->students[insert_pos],
                (roster->count - insert_pos) * sizeof(student_t));
    }

    // insert new student
    roster->students[insert_pos] = new_student;
    roster->count++;
    return true;
}

roster_t get_grade(roster_t *roster, uint8_t grade) {
    roster_t result;
    init_roster(&result);

    for (size_t i = 0; i < roster->count; i++) {
        if (roster->students[i].grade == grade) {
            if (result.count < MAX_STUDENTS) {
                result.students[result.count++] = roster->students[i];
            }
        }
    }
    return result;
}
