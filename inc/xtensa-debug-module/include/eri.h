#ifndef ERI_H
#define ERI_H

#include <stdint.h>

/*
 The ERI is a bus internal to each Xtensa core. It connects, amongst others, to the debug interface, where it
 allows reading/writing the same registers as available over JTAG.
*/


/**
 * @brief  Perform an ERI read
 * @param  addr : ERI register to read from
 *
 * @return Value read
 */
uint32_t esp_eri_read(int addr);


/**
 * @brief  Perform an ERI write
 * @param  addr : ERI register to write to
 * @param  data : Value to write
 *
 * @return Value read
 */
void esp_eri_write(int addr, uint32_t data);


#endif