#include "queen_attack.h"
#include <stdint.h>

attack_status_t can_attack(position_t queen1, position_t queen2) {
    if (queen1.row > 7 || queen1.column > 7 || 
        queen2.row > 7 || queen2.column > 7 ||
        (queen1.row == queen2.row && queen1.column == queen2.column)) {
        return INVALID_POSITION;
    }

    if (queen1.row == queen2.row) {
        return CAN_ATTACK;
    }

    if (queen1.column == queen2.column) {
        return CAN_ATTACK;
    }

    uint8_t row_diff = queen1.row > queen2.row ? 
                      queen1.row - queen2.row : 
                      queen2.row - queen1.row;
                      
    uint8_t col_diff = queen1.column > queen2.column ? 
                      queen1.column - queen2.column : 
                      queen2.column - queen1.column;

    if (row_diff == col_diff) {
        return CAN_ATTACK;
    }

    return CAN_NOT_ATTACK;
}
