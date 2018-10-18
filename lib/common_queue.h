#ifndef _LIB_COMMON_QUEUE_H
#define _LIB_COMMON_QUEUE_H
#include <string.h>
#include <stdlib.h>

#define COMMAND_QUEUE_SIZE 100

typedef enum{
    QUEUE_OK,
    QUEUE_ERROR
}Queuestatus;

typedef struct _command_args{
    char command_id[32];   //消息id
    char args[16][32];     //id对应函数的参数
}CommandArgs;

typedef struct _Commandqueue{
    CommandArgs cmd[COMMAND_QUEUE_SIZE];
    int front;
    int rear;
}CommandQueue;

Queuestatus common_queue_init_queue(CommandQueue *Q);

Queuestatus common_queue_en_queue(CommandQueue *Q ,CommandArgs c);

Queuestatus common_queue_del_queue(CommandQueue *Q,CommandArgs *c);

int common_queue_get_length(CommandQueue Q);

int common_queue_command_args_length(CommandArgs c);

Queuestatus common_queue_print(CommandQueue Q);

#endif /*_LIB_COMMON_QUEUE_H*/

