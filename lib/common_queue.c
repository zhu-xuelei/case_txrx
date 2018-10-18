#include "lib/common_queue.h"
#include <stdio.h>
#include <string.h>

Queuestatus common_queue_init_queue(CommandQueue *Q){
    Q = (CommandQueue*)malloc(COMMAND_QUEUE_SIZE*sizeof(CommandQueue));
    if(!Q->cmd){
        return QUEUE_ERROR;
    }
    Q->front=Q->rear = 0;
    return QUEUE_OK;
}
Queuestatus common_queue_en_queue(CommandQueue *Q ,CommandArgs c){
    if(Q->rear+1%COMMAND_QUEUE_SIZE == Q->front){   //判断满队列
        return QUEUE_ERROR;
    }
    Q->cmd[Q->rear] = c;
    Q->rear = (Q->rear+1)%COMMAND_QUEUE_SIZE; //赋值后后移一位

    return QUEUE_OK;
}
Queuestatus common_queue_del_queue(CommandQueue *Q,CommandArgs *c){
    if(Q->front == Q->rear){           //判断为空
        return QUEUE_ERROR;
    }
    *c = Q->cmd[Q->front];
    Q->front = (Q->front+1)%COMMAND_QUEUE_SIZE;
    return QUEUE_OK;
}

int common_queue_get_length(CommandQueue Q){
    return (Q.rear-Q.front+COMMAND_QUEUE_SIZE)%COMMAND_QUEUE_SIZE;
}
int common_queue_command_args_length(CommandArgs c){
    int num = 0;
    while(1){
        if(!strcmp(c.args[num++],"\0" )){
            break;
        }
    }
    return num;
}

Queuestatus common_queue_print(CommandQueue Q){
    int i =0,j=0;
    unsigned char length = 0;
    unsigned char num = 0;
    
    
    for(i=0;i<length;i++){
        num = common_queue_get_length(Q);
        printf("command id =0x%s, ",Q.cmd[i].command_id);
        common_queue_command_args_length(Q.cmd[i]);
        for(j=0;j<num;j++){
            printf("arg[%d]:%s ",j,Q.cmd[i].args[j]);
        }
        printf("\n");
        Q.front=(Q.front+1)%COMMAND_QUEUE_SIZE;
    }
}