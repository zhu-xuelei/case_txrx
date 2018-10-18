#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <testapp/submain.h>
#include "lib/common_queue.h"
#include "lib/command_parse.h"

#define INPUTDATASIZE 1024

void (*sub_thread)()=spf_main;

int start_pthread(){
    pthread_t pid;
    int ret=pthread_create(&pid,NULL,(void *)spf_main,NULL);
    if(ret){
        return -1;
    }
    return 0;
}

void rx_command_line_args(){
    char input_args[INPUTDATASIZE]={0};
    CommandArgs command = {0}; 
    char error = 0;
    while(1){
        fgets(input_args,sizeof(input_args),stdin);//标准输入接收字符串
        if(!strcmp(&input_args[strlen(input_args)-1],"\n")){
            input_args[strlen(input_args)-1]='\0';// 
        }

        if(strlen(input_args) == 0){
            continue;
        }
        if(!strcmp(&input_args[0],"#")){
            continue;
        }
        command_parse_args(input_args,&error);
        common_queue_en_queue(&global_command_queue,command);
        
    }
}
/*主线程接收数据存入队列,子线程消费数据*/
int main(){
    common_queue_init_queue(&global_command_queue);
    start_pthread();
    rx_command_line_args();

    return 0;
}