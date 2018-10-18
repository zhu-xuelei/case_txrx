#############################################################
# Makefile for static SPF
#############################################################
SRC_ROOT = ./
BUILD_PATH = dist
NAME = TEST

#############################################################
# TOOLS
#############################################################

#set your own environment option
CC = gcc
# CC = arm-none-eabi-gcc
#static library use 'ar' command 
AR = ar
# AR = arm-none-eabi-ar

#############################################################
# FLAGS
#############################################################

CC_FLAG = \
-g \



#set your inc and lib
INC = \
-I. \
-I${SRC_ROOT}/lib \
-I${SRC_ROOT}/testapp \


LIB = \
 -lpthread \
 -lm
 
#############################################################
# SRC
#############################################################
SRCS = \
	lib/command_parse.c \
	lib/command.c \
	lib/common_queue.c \
	testapp/submain.c




SRCS += \




SRCS += \
main.c


#############################################################
# Targets
#############################################################
#把SRC下的所有.c文件全部替换为.o
FULL_PATH_OBJS = $(patsubst %.c,${BUILD_PATH}/objs/%.o,$(SRCS) )

$(BUILD_PATH)/objs/%.o : $(SRC_ROOT)/%.c
	@mkdir -p $(@D)
	$(CC) $(CC_FLAG) $(INC) -c $<  -o $@

.PHONY: lib

# lib: $(FULL_PATH_OBJS)
# 	$(AR) -r lib$(NAME).a $^
	
.PHONY: $(NAME)
$(NAME): ${FULL_PATH_OBJS} 
	$(CC) -o $(NAME) $^ $(CC_FLAG) $(LIB)

.PHONY: all

all: $(NAME)

.PHONY: clean

clean:
	rm -f ${FULL_PATH_OBJS}
