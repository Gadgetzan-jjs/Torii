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
int myfun(va_list vaList){
//    void *agenum=va_arg(vaList, void *);
//    int  argnum= (int)(agenum);
//    printf("argnum is %d\n",argnum);
//    for (int i = 0; i < argnum; ++i) {
////        printf("xixi\n");
//    }

    void * a=va_arg(vaList,void *);
    void * b=va_arg(vaList,void *);
    printf("fun a is %d and %d\n",a,b);

    sleep(3);
}
int other(va_list vaList){
    void * a=va_arg(vaList,void *);
    void * b=va_arg(vaList,void *);
    printf("fun a is %d and %d\n",a,b);
    sleep(1);

}
//void funcc(void *(*function)(void *),...) {
//
//    Thread_Pool_task_t *task = (Thread_Pool_task_t *) malloc(sizeof(Thread_Pool_task_t));
//    task->function = reinterpret_cast<void *(*)(void *, ...)>(myfun);
//    va_list args;
//    va_start(args, function);
//    task->function(args);
//}

int main() {
    std::cout << "Hello, World!" << std::endl;

    RequestMapping("/hello", reinterpret_cast<void *(*)(void *)>(myfun), "hello", "world");
    serverepoll("/home/mikasa/CLionProjects/Torii_1.0_1103/Ctest-master/Toriiconf");

//    serverepoll()
    return 0;
}
