/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2019-07-23     tyustli      first version
 */

#include <rtthread.h>
#include <gd32vf103_longan_nano.h>

#define THREAD_PRIORITY         25
#define THREAD_STACK_SIZE       512
#define THREAD_TIMESLICE        10

#if RT_USING_HEAP
    rt_sem_t thread1_sem = NULL;
    rt_sem_t thread2_sem = NULL;
#else
    struct rt_semaphore thread1_sem_static;
    struct rt_semaphore thread2_sem_static;
    rt_sem_t thread1_sem = &thread1_sem_static;
    rt_sem_t thread2_sem = &thread2_sem_static;
#endif

#if RT_USING_HEAP
static rt_thread_t tid1 = RT_NULL;
static rt_thread_t tid2 = RT_NULL;
static rt_thread_t tid3 = RT_NULL;
#else
ALIGN(RT_ALIGN_SIZE)
static char thread1_stack[1024];
static struct rt_thread thread1;

ALIGN(RT_ALIGN_SIZE)
static char thread2_stack[512];
static struct rt_thread thread2;
#endif

/* Entry Function for Thread 1 */
static void thread1_entry(void *parameter)
{
    int i = 0;
    rt_sem_t thread_sem = parameter;

    gd_longan_nano_led_off(LED1);
    gd_longan_nano_led_off(LED2);
    gd_longan_nano_led_off(LED3);

    rt_kputs("> thread1_entry()\n");
    while (1)
    {
        gd_longan_nano_led_toggle(LED1);
        gd_longan_nano_led_toggle(LED2);
        gd_longan_nano_led_toggle(LED3);
        rt_thread_delay(30);

        gd_longan_nano_led_toggle(LED1);
        gd_longan_nano_led_toggle(LED2);
        gd_longan_nano_led_toggle(LED3);
        rt_thread_delay(70);
    }

    rt_kputs("< thread1_entry()\n");

    rt_sem_release(thread_sem);
}


struct rt_timer timer2_static;
static rt_timer_t timer2 = &timer2_static;

/* Timer 2 Timeout Function */
static void timeout2(void *parameter)
{
    rt_kprintf("one shot timer is timeout\n");
    rt_sem_release(thread2_sem);
    rt_thread_resume(&thread2);
}

/* Entry Function for Thread 2 */
static void thread2_entry(void *parameter)
{
    int i = 0;
    rt_sem_t thread_sem = parameter;

    /* Create Timer 2 One Shot Timer */
     rt_timer_init(timer2, "timer2", timeout2, RT_NULL, 30, RT_TIMER_FLAG_PERIODIC);

    /* Start Timer 2 */
    if (timer2 != RT_NULL) rt_timer_start(timer2);

    rt_kputs("> thread2_entry()\n");
    while (1)
    {
        gd_longan_nano_led_on(LED6);

        rt_sem_take(thread_sem, RT_WAITING_FOREVER);

        gd_longan_nano_led_off(LED6);

        rt_sem_take(thread_sem, RT_WAITING_FOREVER);

    }

    rt_kputs("< thread2_entry()\n");
    rt_sem_release(thread_sem);
}

int x_main(int argc, char *argv[]) {
    rt_err_t result;

    rt_kputs("> main()\n");

#if RT_USING_HEAP
    thread1_sem = rt_sem_create("thread1_sem", 0, RT_IPC_FLAG_FIFO);
    thread2_sem = rt_sem_create("thread2_sem", 0, RT_IPC_FLAG_FIFO);
#else
    rt_sem_init(thread1_sem, "thread1_sem", 0, RT_IPC_FLAG_FIFO);
    rt_sem_init(thread2_sem, "thread2_sem", 0, RT_IPC_FLAG_FIFO);
#endif

    rt_kputs("| main() - starting thread1\n");

#if RT_USING_HEAP
    /* Create thread 1, Name is thread1，Entry is thread1_entry */
    tid1 = rt_thread_create("thread1",
                            thread1_entry, thread1_sem,
                            THREAD_STACK_SIZE,
                            THREAD_PRIORITY, THREAD_TIMESLICE);

    /* Start this thread if you get the thread control block */
    if (tid1 != RT_NULL)
        rt_thread_startup(tid1);
#else
    rt_thread_init(&thread1,
                   "thread1",
                   thread1_entry,
                   thread1_sem,
                   &thread1_stack[0],
                   sizeof(thread1_stack),
                   THREAD_PRIORITY - 1, THREAD_TIMESLICE);
    rt_thread_startup(&thread1);
#endif

    rt_kputs("| main() - starting thread2\n");

#if RT_USING_HEAP
    /* Create thread 2, Name is thread1，Entry is thread2_entry */
    tid2 = rt_thread_create("thread2",
                            thread2_entry, thread2_sem,
                            THREAD_STACK_SIZE,
                            THREAD_PRIORITY, THREAD_TIMESLICE);

    /* Start this thread if you get the thread control block */
    if (tid2 != RT_NULL)
        rt_thread_startup(tid2);
#else
    rt_thread_init(&thread2,
                   "thread2",
                   thread2_entry,
                   thread2_sem,
                   &thread2_stack[0],
                   sizeof(thread2_stack),
                   THREAD_PRIORITY - 1, THREAD_TIMESLICE);
    rt_thread_startup(&thread2);
#endif

    rt_kputs("| main() - waiting for joining thread1_sem semaphore\n");

    /* permanently wait for the semaphore; once obtain the semaphore, perform the number self-add operation */
    result = rt_sem_take(thread1_sem, RT_WAITING_FOREVER);
    if (result != RT_EOK)
    {
        rt_kprintf("take thread1_sem semaphore, failed.\n");
#if RT_USING_HEAP
        rt_sem_delete(thread1_sem);
#endif
    }

    rt_kputs("| main() - waiting for joining thread2_sem semaphore\n");

    result = rt_sem_take(thread2_sem, RT_WAITING_FOREVER);
    if (result != RT_EOK)
    {
        rt_kprintf("take thread2_sem semaphore, failed.\n");
#if RT_USING_HEAP
        rt_sem_delete(thread2_sem);
#endif
    }

    rt_kputs("< main()\n");

    return RT_EOK;
}

int main(void)
{
    rt_thread_init(&thread1,
                   "thread1",
                   thread1_entry,
                   thread1_sem,
                   &thread1_stack[0],
                   sizeof(thread1_stack),
                   THREAD_PRIORITY - 1, THREAD_TIMESLICE);
    rt_thread_startup(&thread1);

    while (1)
    {
        rt_thread_delay(50);
        gd_longan_nano_led_on(LED6);
        rt_thread_delay(50);
        gd_longan_nano_led_off(LED6);
    }
}

/******************** end of file *******************/
