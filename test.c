#include <stdio.h>
#include "misc.h"
#include "dataset.h"
#include "errors.h"
#include "read.h"

int main(void) {
    DataSet ds = createDataSet("Test Dataset");
    addInputColumns(ds, 2, "Test input 1", "Test input 2");
    addOutputColumn(ds, "Test Output");
    addRow(ds, 1.0, 2.0, 3.0);
    addRow(ds, 4.0, 5.0, 6.0);
    printf("%d\n", ds->output[0]->count);
    printf("%lf, %lf, %lf\n", ds->input[0]->data[0],
                              ds->input[1]->data[0],
                              ds->output[0]->data[0]);
    printf("%lf, %lf, %lf\n", ds->input[0]->data[1],
                              ds->input[1]->data[1],
                              ds->output[0]->data[1]);
    deleteDataSet(ds);
    return 0;
}
