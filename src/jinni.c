#include "jinni.h"


void free_buffer(void *buffer) {
    free(buffer);
}

void * parray(VARIANT *v) {
    if (v->vt & VT_ARRAY) return v->data.parray;
    return NULL;
}

int makeEmpty(VARIANT * answer) {
    answer->vt = VT_EMPTY;
    answer->data.parray = NULL;
    return 0;
}

VARTYPE vartype(VARIANT *x) {
    return x->vt;
}

VARIANT doubleInVar(double x) {
    VARIANT answer;
    answer.vt = VT_R8;
    answer.data.dblVal = x;
    return answer;
}

VARIANT doubleArrayInVar(double x, int count) {
    int ndims = 1;

    void *p = malloc(sizeof(FULLSAFEARRAY) + (ndims - 1) * sizeof(SAFEARRAYBOUND));
    FULLSAFEARRAY *fsa = (FULLSAFEARRAY *) p;
    fsa->vt = VT_R8;
    fsa->sa.cDims = 1;
    fsa->sa.fFeatures = FADF_HAVEVARTYPE;
    fsa->sa.cbElements = sizeof(double);
    fsa->sa.cLocks = 0;
    fsa->sa.pvData = malloc(count * sizeof(double));
    fsa->sa.rgsabound[0].cElements = count;
    fsa->sa.rgsabound[0].lLbound = 1;

    double* elements = (double*) fsa->sa.pvData;
    for (size_t i = 0; i < count; i++) {
        elements[i] = x;
    }

    VARIANT answer;
    answer.vt = VT_ARRAY | VT_R8;
    answer.data.parray = p + 16;
    return answer;
}


VARIANT errorInVar(int32_t x) {
    VARIANT answer;
    answer.vt = VT_ERROR;
    answer.data.scode = x;
    return answer;
}


void callFunction(int (*func)(int)) {
    int result = func(42);
    printf("Result: %d\n", result);
}


double extractDoubleByRef(VARIANT *x) {
    if (x->vt == VT_R8) return x->data.dblVal;
    return -1;
}
