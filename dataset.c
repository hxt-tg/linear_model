#include "dataset.h"
#include "errors.h"
#include <stdlib.h>
#include <stdio.h>

void *Malloc(size_t size){
    void *p = malloc(size);
    if (!p) err(1, "Cannot alloc new space");
    return p;
}

void *Realloc(void *raw, size_t size){
    void *p = realloc(raw, size);
    if (!p) err(1, "Cannot alloc new space");
    return p;
}

/* DataColumn */
DataColumn createDataColumn(const char *tag){
    DataColumn dc = (DataColumn)Malloc(sizeof(struct SDataColumn));
    dc->count = 0;
    strncpy(dc->name, tag, SLEN);
    dc->data = NULL;
    return dc;
}

Status addDataColumn(DataColumn dc, DSElem val){
    dc->data = (DSElem *)Realloc(dc->data, sizeof(DSElem)*(dc->count+1));
    dc->data[dc->count++] = val;
    return OK;
}

Status deleteDataColumn(DataColumn dc){
    free(dc->data);
    free(dc);
    return OK;
}


/* DataSet */
DataSet createDataSet(const char *tag){
    DataSet ds = (DataSet)Malloc(sizeof(struct SDataSet));
    strncpy(ds->name, tag, SLEN);
    ds->count_input = 0;
    ds->input = NULL;
    ds->output = NULL;
    return ds;
}

Status addInputColumns(DataSet ds, Count n_columns, ...){
    unsigned int i;
    if (ds->input){
        for (i = 0; i < ds->count_input; i++)
            deleteDataColumn(ds->input[i]);
        free(ds->input);
    }
    ds->count_input = n_columns;
    ds->input = (DataColumn *)Malloc(sizeof(DataColumn)*n_columns);
    va_list ap;
    va_start(ap, n_columns);
    for (i = 0; i < n_columns; i++)
        ds->input[i] = createDataColumn(va_arg(ap, char *));
    va_end(ap);
    return OK;
}

Status addOutputColumn(DataSet ds, const char *tag){
    if (ds->output) {
        deleteDataColumn(ds->output[0]);
        free(ds->output);
    }
    ds->output = (DataColumn *)Malloc(sizeof(DataColumn));
    ds->output[0] = createDataColumn(tag);
    return OK;
}

Status addRow(DataSet ds, ...){
    if (!ds->input || !ds->output ) return FAILED;
    unsigned int i;
    va_list ap;
    va_start(ap, ds);
    for (i = 0; i < ds->count_input; i++)
        addDataColumn(ds->input[i], va_arg(ap, DSElem));
    addDataColumn(ds->output[0], va_arg(ap, DSElem));
    va_end(ap);
    return OK;
}

Status deleteDataSet(DataSet ds){
    unsigned int i;
    for (i = 0; i < ds->count_input; i++)
        deleteDataColumn(ds->input[i]);
    if(ds->output) deleteDataColumn(ds->output[0]);
    free(ds);
    return OK;
}

