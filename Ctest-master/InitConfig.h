//
// Created by mikasa on 2021/11/4.
//
typedef struct ConfigStruct{
    char * ipaddress;
    char * port;
    char * conffilepath;
}Config;
void confconfig(Config * config,char * filepath);
