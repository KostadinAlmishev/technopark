//
// Created by k on 26.10.19 г..
//

#include "matrix.h"

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "err.h"

typedef struct {
    int32_t **mtr;
    size_t n;
    size_t m;
} mtr_t;

void init_mtr(mtr_t *mtr) {
    mtr->mtr = NULL;
    mtr->n = 0;
    mtr->m = 0;
}

err_t alloc_mtr(mtr_t *mtr, size_t n, size_t m) {   // Улучшение ветвления (сначало выполнять то, что выполняется чаще всего в условии)
    if (mtr && n && m && !mtr->mtr) {

        mtr->mtr = malloc(n * sizeof(*mtr->mtr));
        if (mtr->mtr) {
            mtr->n = n;
            mtr->m = m;
        } else {
            init_mtr(mtr);
            return ERR_MEM;
        }

    } else {
        return ERR_INTERNAL;
    }

    return OK;
}

err_t alloc_mtr_1(mtr_t *mtr, size_t n, size_t m) {   // Улучшение ветвления (сначало выполнять то, что выполняется чаще всего в условии) + 1 return
    err_t rc = OK;
    if (mtr && n && m && !mtr->mtr) {

        mtr->mtr = malloc(n * sizeof(*mtr->mtr));
        if (mtr->mtr) {
            mtr->n = n;
            mtr->m = m;
        } else {
            init_mtr(mtr);
            rc = ERR_MEM;
        }

    } else {
        rc = ERR_INTERNAL;
    }

    return rc;
}

err_t alloc_mtr_2(mtr_t *mtr, size_t n, size_t m) { // уменшение уровня вложености
    if (!(mtr && n && m && !mtr->mtr)) {
        return ERR_INTERNAL;
    }

    mtr->mtr = malloc(n * sizeof(*mtr->mtr));
    if (!mtr->mtr) {
        init_mtr(mtr);
        return ERR_MEM;
    }

    mtr->n = n;
    mtr->m = m;

    return OK;
}


