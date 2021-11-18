//
// Created by mikasa on 2021/11/4.
//
#include "stdlib.h"
typedef struct ConfigStruct{
    char * ipaddress;
    char * port;
    char * conffilepath;
}Config;
void confconfig(Config * config,char * filepath);
Config * get_config(Config * config);
void set_config(Config * config);
char * get_conffilepath();