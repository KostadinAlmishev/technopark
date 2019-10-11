#include "roman_numerals.h"

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define _PROCESS_BUFF_INITIAL_SIZE 5
#define _PROCESS_BUFF_INCREASE_COEF 2


static inline char* create_buff(size_t *size) {
    assert(size);

    char* buff =  malloc(_PROCESS_BUFF_INITIAL_SIZE * sizeof(char));

    if (buff) 
        *size = _PROCESS_BUFF_INITIAL_SIZE;
    else
        return NULL;
    

    return buff;
}

static inline char* realloc_buff(char** buff, size_t* size) {
    assert(buff);
    assert(*buff);
    assert(size);
    assert(*size);

    const size_t _new_size = *size * _PROCESS_BUFF_INCREASE_COEF;

    char* res = realloc(*buff, _new_size * sizeof(char));
    if (!res) {
        free(*buff);

        *buff = NULL;
        *size = 0;

        return NULL;
    }

    *buff = res;
    *size = _new_size;

    return res;
}

static inline char* truncate_buff(char** buff, size_t size) {
    assert(buff);
    assert(*buff);

    char* res = realloc(*buff, size * sizeof(char));
    if (!res) {
        free(*buff);

        *buff = NULL;

        return NULL;
    }

    *buff = res;

    return res;
}

char* to_rom_num(size_t *size, unsigned num) {
    assert(size);

    *size = 0;
    if (num == 0)
        return NULL;

    char *buff = NULL;
    size_t buff_size = 0;

    if ((buff = create_buff(&buff_size)) == NULL) {
        return NULL;
    }

    size_t i;
    
    for (i = 0; num != 0; i++) {
        if (i + 2 < buff_size && \
            realloc_buff(&buff, &buff_size) == NULL)
            return NULL;

        if (num >= 1000) {
            buff[i] = 'M';

            num -= 1000;
        } else if (num >= 900) {
            buff[i++] = 'C';
            buff[i] = 'M';

            num -= 900;
        } else if (num >= 500) {           
            buff[i] = 'D';

            num -= 500;
        } else if (num >= 400) {
            buff[i++] = 'C';
            buff[i] = 'D';

            num -= 400;
        } else if (num >= 100) {
            buff[i] = 'C';
            num -= 100;                       
        } else if (num >= 90) {
            buff[i++] = 'X';
            buff[i] = 'C';

            num -= 90;                                              
        } else if (num >= 50) {
            buff[i] = 'L';
            num -= 50;                                                                     
        } else if (num >= 40) {
            buff[i++] = 'X';
            buff[i] = 'L';

            num -= 40;
        } else if (num >= 10) {
            buff[i] = 'X';
            num -= 10;           
        } else if (num >= 9) {
            buff[i++] = 'I';
            buff[i] = 'X';

            num -= 9;                         
        } else if (num >= 5) {
            buff[i] = 'V';
            num -= 5;                                     
        } else if (num >= 4) {
            buff[i++] = 'I';
            buff[i] = 'V';

            num -= 4;                                                            
        } else if (num >= 1) {
            buff[i] = 'I';
            num -= 1;                                                                                   
        } 
    }

    // is enough space for \0
    if (i == buff_size) {
        buff_size++;
        char *ptmp = realloc(buff, buff_size * sizeof(char));
        if (!ptmp) {
            free(buff);

            buff = NULL;

            return NULL;
        }
    }

    buff[i] = 0;    // 0 terminated
    buff_size = i + 1;
    truncate_buff(&buff, buff_size);

    *size = buff_size;

    return buff;
}