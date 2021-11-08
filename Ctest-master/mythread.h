//
// Created by mikasa on 2021/11/8.
//

typedef struct mythread{
    void * arg;
    int argnum;
    mythread * next;
}thread;
void init_thread_arg(thread * t,int argnum,...);