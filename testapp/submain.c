#include "testapp/submain.h"
#include "lib/common_queue.h"
#include "string.h"
CommandQueue global_command_queue = {0};



void spf_main(){
    CommandArgs cmd = {0};
    while(1){
        common_queue_del_queue(&global_command_queue,&cmd);
        // strcmp((cmd.command_id),"recv")
        switch(1){
            case 1:
                break;
            default:
                break;
        }
    }
}