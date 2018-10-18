#include "lib/command_parse.h"
#include "stdlib.h"

CommandArgs command_parse_args(char *string,char *error){
    CommandArgs cmd = {0};
    char *buf = strtok(string," ");     
    char *p = NULL;
    int i=0;
    strcpy(cmd.command_id,buf);
    
     while(buf!=NULL){
         strcpy(cmd.args[i++],buf);
         buf=strtok(NULL," ");
     }
     return cmd;
}
