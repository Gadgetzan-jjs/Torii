//
// Created by mikasa on 2021/10/20.
//

#include "stdlib.h"
#include "stdio.h"
#include "stdarg.h"
#include "string.h"
#include "InitConfig.h"
#include "strings.h"
#include "MyController.h"
#include "math.h"
ServletMapping * servletHeading;
ServletMapping * servletIndex;
void do_result(thread * t){
    char * final_conffilepath=get_conffilepath();
    int target_size=strlen(final_conffilepath)+strlen(t->returnvalue)+5;
    char * target=(char *)malloc(target_size);
    memset(target,0,target_size);
    strcat(target,final_conffilepath);
    strcat(target,t->returnvalue);
    strcat(target,".html");

    printf("attribute is %s\n",t->attribute->value);

}

void RequestMapping(char * value,void *(*function)(void * ),thread * t){
    if (servletHeading==NULL){
        servletHeading=(ServletMapping *)malloc(sizeof(ServletMapping));
        servletIndex=servletHeading;
        servletHeading->value=NULL;
        servletHeading->function=NULL;
        servletHeading->next=NULL;
        servletHeading->left=NULL;
        servletHeading->right=NULL;
        servletHeading->listsize=0;
    }
    ServletMapping * servlet=(ServletMapping *)malloc(sizeof(ServletMapping));
    servlet->value=value;
    servlet->function=function;
    servlet->args=t;
    if (servletHeading->listsize<=64){
        servletIndex->next=servlet;
        servletIndex=servlet;
        servletHeading->listsize++;
    } else {
        //这里可扩展为b+树
    }
}
void doRequestMapping(char * value){
    if (servletHeading->listsize<=64){
        ServletMapping * index=servletHeading->next;
        while (index!=NULL){
            if (!strcmp(index->value,value)){
                index->args=(thread *)index->function(index->args);
                do_result(index->args);
                break;
            } else{
                index=index->next;
            }
        }
    } else {

    }
}

