//
// Created by mikasa on 2021/11/8.
//

#include "mythread.h"
#include "stdlib.h"
#include "stdarg.h"
void init_thread_arg(thread * t,int argnum,...){
    va_list args;
    thread *ptr=t;
    ptr->argnum=argnum;
    va_start(args,argnum);
    ptr->arg=va_arg(args,void *);
    for (int i = 0; i < argnum; ++i) {
            ptr->next=(thread *)malloc(sizeof(thread));
            ptr=ptr->next;
            ptr->arg=va_arg(args,void *);
        }
}