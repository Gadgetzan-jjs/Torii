//
// Created by mikasa on 2021/11/4.
//

#include "InitConfig.h"
#include "stdio.h"
#include "stdlib.h"
#include "strings.h"
#include "string.h"
//#include "cstring"
//using namespace std;
#include <bits/types/FILE.h>
char * final_ipaddress=(char * )malloc(15);
char * final_port=(char *)malloc(6);
//static char * final_conffilepath=(char *)malloc(101);

static char final_conffilepath[101];
char * get_conffilepath(){
    return final_conffilepath;
}
void confconfig(Config * config,char * filepath) {
    FILE *fp;
    if ((fp = fopen(filepath, "r"))==NULL){
        perror("[ERROR]: open file fail\n");
        exit(1);
    }
    char context[101];
    int sonpart=0;
    while (fgets(context, sizeof(context),fp)){
        if (context[0]==' ')sonpart=1;
        else sonpart=0;
        if (sonpart||!strcmp(context,"server:\n")){
            if (sonpart||fgets(context,sizeof(context),fp)){
                char * key=strtok(context,":");
                if (!strcmp(key,"    port")){
                    char *value=strtok(NULL,key);
                    value=strtok(value,"\n");
                    strcpy(config->port,value);
                    printf("port %s\n",config->port);
                } else if (!strcmp(key,"    ipaddress")){
                    char *value=strtok(NULL,key);
                    value=strtok(value,"\n");
                    strcpy(config->ipaddress,value);
                    printf("ipaddress %s\n",config->ipaddress);
                }
            }
        } else if (sonpart||!strcmp(context,"webinfo:\n")){
            if (sonpart||fgets(context, sizeof(context),fp)){
                char * key=strtok(context,":");
                if (!strcmp(key,"    location")){
                    char * afterpart=strtok(NULL,":");
                    char value[101];
                    int valueindex=0;
                    int len=strlen(afterpart);
                    bzero(value,101);
                    for (int i = 0; i < len; ++i) {
                        if (valueindex<101){
                            if (afterpart[i]=='\n')break;
                            value[valueindex++]=afterpart[i];
                        }
                    }
                    value[valueindex]='\0';
//                    printf("value is isi %s\n",value);
//                    value=strtok(value,"\n");
                    config->conffilepath=value;
                    printf("location %s\n",value);
                }
            }
        }
    }
    int conffp_len=strlen(config->conffilepath);
    int i;
    for (i = 0; i < conffp_len; ++i) {
        final_conffilepath[i]=config->conffilepath[i];
    }
    final_conffilepath[i]='\0';
}
