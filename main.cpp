#include <iostream>
#include "Socket.h"
#include "InitConfig.h"
#include <stdarg.h>
#include "unistd.h"
#include "stdlib.h"
#include "strings.h"
#include "string.h"
#include "simple_thread_pool.h"
#include "iostream"
#include "MyController.h"
using namespace std;
thread *  myfun(thread * t){
    void * arg;
    for (int i = 0; i < 2; ++i) {
            arg=t->arg;
            printf("%s\n",arg);
            t=t->next;
    }
    t->returnvalue=(char *)malloc(5);
    t->returnvalue="hello";
    t->attribute=(to_attribute *)malloc(sizeof(to_attribute));
    t->attribute->key="username";
    t->attribute->value=(void *)"haibara";
    sleep(3);
    return t;
}
//int other(va_list vaList){
//    void * a=va_arg(vaList,void *);
//    void * b=va_arg(vaList,void *);
//    printf("fun a is %d and %d\n",a,b);
//    sleep(1);
//
//}
//void funcc(void *(*function)(void *),...) {
//
//    Thread_Pool_task_t *task = (Thread_Pool_task_t *) malloc(sizeof(Thread_Pool_task_t));
//    task->function = reinterpret_cast<void *(*)(void *, ...)>(myfun);
//    va_list args;
//    va_start(args, function);
//    task->function(args);
//}
int main() {

    thread * t=(thread *)malloc(sizeof(thread));
    init_thread_arg(t,2,"hello", "world");
    RequestMapping("/hello", reinterpret_cast<void *(*)(void *)>(myfun), t);
    serverepoll("/home/mikasa/CLionProjects/Torii_1.0_1103/Ctest-master/Toriiconf");





    ////jinja2解释器测试代码


//    char * path="/home/mikasa/Gadgetzan-jjs/CLionProjects/Torii/resources/";
//    open("/home/mikasa/Gadgetzan-jjs/CLionProjects/Torii/resources/Test.html", nullptr, path);
//    Mattribute * attribute=(Mattribute *)malloc(sizeof(Mattribute));
//    char * afaf="1111";
//    attribute->context=afaf;
//    attribute->type=String;
//    printf("%s\n",(char *)attribute->context);
//    setAttribute(":name",attribute);
//    close();
//    sleep(10);

    return 0;
}
