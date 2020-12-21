/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2019-07-23     tyustli      first version
 *
 */

#ifndef __BOARD__
#define __BOARD__

#include "gd32vf103_longan_nano.h"


#ifdef BSP_USING_USART
#if defined(BSP_USING_UART0)
#define LONGAN_NANO_UART LONGAN_NANO_COM0
#elif defined(BSP_USING_UART1)
#define LONGAN_NANO_UART LONGAN_NANO_COM1
#elif defined(BSP_USING_UART2)
#define LONGAN_NANO_UART LONGAN_NANO_COM2
#else
#error No BSP_USING_UARTx defined
#endif
#endif

void rt_hw_board_init(void);

#endif /* __BOARD__ */

/******************** end of file *******************/
