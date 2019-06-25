#include "callbacks.h"
extern uint8_t flag_elapsed;
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
    flag_elapsed=1;
}
