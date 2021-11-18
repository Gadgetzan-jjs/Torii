//
// Created by mikasa on 2021/11/8.
//
#include "MyAnalysisNew.h"
#ifndef __TOOLS_H__
#define __TOOLS_H__
typedef struct to_attribute{
    char * key;
    void * value;
    to_attribute * next;
    int type;
};


typedef struct mythread{
    void * arg;
    int argnum;
    char * returnvalue;
    mythread * next;
    to_attribute * attribute;
}thread;
void init_thread_arg(thread * t,int argnum,...);
#endif