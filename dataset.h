#ifndef DATASET_H
#define DATASET_H

#include "misc.h"
#include <stdarg.h>

/* DataColumn */
DataColumn createDataColumn(const char *tag);
Status addDataColumn(DataColumn dc, DSElem val);
Status deleteDataColumn(DataColumn dc);

/* DataSet */
DataSet createDataSet(const char *tag);
Status addInputColumns(DataSet ds, Count n_columns, ...);
Status addOutputColumn(DataSet ds, const char *tag);
Status addRow(DataSet ds, ...);
Status deleteDataSet(DataSet ds);

#endif /* ifndef DATASET_H */
