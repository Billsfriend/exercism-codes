#include "robot_simulator.h"
#include <string.h>

robot_status_t robot_create(robot_direction_t direction, int x, int y) {
    robot_position_t position = {.x = x, .y = y};
    robot_status_t robot = {
        .direction = direction,
        .position = position
    };
    return robot;
}

void robot_move(robot_status_t *robot, const char *commands) {
    size_t len = strlen(commands);
    for (size_t i = 0; i < len; i++) {
        if (commands[i] == 'R') {
            robot->direction++;
            if (robot->direction == DIRECTION_MAX) {
                robot->direction = DIRECTION_NORTH;
            }
        } else if (commands[i] == 'L') {
            if (robot->direction == DIRECTION_NORTH) {
                robot->direction = DIRECTION_WEST;
            } else {
                robot->direction--;
            }
        } else if (commands[i] == 'A') {
            switch (robot->direction) {
                case DIRECTION_NORTH:
                    robot->position.y++;
                    break;    
                case DIRECTION_EAST:
                    robot->position.x++;
                    break;
                case DIRECTION_SOUTH:
                    robot->position.y--;
                    break;
                case DIRECTION_WEST:
                    robot->position.x--;
                    break;
                default:
                    break;
            }
        }
    }
}