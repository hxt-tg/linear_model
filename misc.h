#ifndef MISC_H
#define MISC_H

#include <string.h>

#define SLEN 256
#define MLEN 1024
#define LLEN 4096
#define BUFSIZE 4096

typedef int Status;
#define OK 0
#define FAILED 1

#define TRUE 1
#define FALSE 0

#define PC
#ifdef PC
typedef double DSElem;
#else
typedef float DSElem;
#endif

typedef unsigned int Count;

/* DataColumn */
typedef struct SDataColumn {
    char name[SLEN];
    DSElem *data;
    Count count;
} *DataColumn;

/* DataSet */
typedef struct SDataSet {
    char name[SLEN];
    DataColumn *input;
    DataColumn *output;
    Count count_input;
} *DataSet;

/* File structures */
typedef enum EFileType {
    FT_UNKNOWN, FT_CSV, FT_TXT
} FileType;

typedef enum EDFType {
    DF_UNKNOWN, DF_INT, DF_BOOL, DF_FLOAT, DF_DOUBLE, DF_STRING
} DFType;

typedef struct SDFElem {
    DFType type;
    void *data;
} DFElem;

typedef struct SDataFile {
    char path[MLEN];
    FileType type;
    Count nrow;
    Count ncol;
    DFElem **data;
} *DataFile;

#endif /* ifndef MISC_H */
