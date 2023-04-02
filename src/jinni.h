#ifndef jinni_h
#define jinni_h

#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <wchar.h>


// see https://learn.microsoft.com/en-us/openspecs/windows_protocols/ms-oaut/3fe7db9f-5803-4dc4-9d14-5425d3f5461f

enum VARENUM {
    VT_EMPTY        = 0x0000,
    VT_I2           = 0x0002,
    VT_I4           = 0x0003,
    VT_R8           = 0x0005,
    VT_DATE         = 0x0007,   // Date and time value
    VT_BSTR         = 0x0008,   // Null-terminated Unicode string
    VT_DISPATCH     = 0x0009,   // Pointer to an IDispatch interface on an object
    VT_ERROR        = 0x000A,   // HRESULT error code
    VT_BOOL         = 0x000B,
    VT_VARIANT      = 0x000C,
    VT_UNKNOWN      = 0x000D,
    VT_I1           = 0x0010,
    VT_UI1          = 0x0011,   // 1-byte unsigned integer (byte)
    VT_UI2          = 0x0012,
    VT_UI4          = 0x0013,
    VT_I8           = 0x0014,
    VT_UI8          = 0x0015,
    VT_HRESULT      = 0x0019,
    VT_ARRAY        = 0x2000,   // Pointer to a SAFEARRAY structure
    VT_BYREF        = 0x4000,   // Pointer to a value of the corresponding base type
};


#define xlErrNull           2000;       // #NULL!
#define xlErrDiv0           2007;       // #DIV/0!
#define xlErrValue          2015;       // #VALUE!
#define xlErrRef            2023;       // #REF!
#define xlErrName           2029;       // #NAME?
#define xlErrNum            2036;       // #NUM!
#define xlErrNA             2042;       // #N/A
#define xlErrGettingData    2043;       // #GETTING_DATA
#define xlErrSpill          2045;       // #SPILL!
#define xlErrConnect        2046;       // #CONNECT!
#define xlErrBlocked        2047;       // #BLOCKED!
#define xlErrUnknown        2048;       // #UNKNOWN!
#define xlErrField          2049;       // #FIELD!
#define xlErrCalc           2050;       // #CALC!


// windows typedefs
typedef uint16_t    VARTYPE;        // 16-bit unsigned integer
typedef uint16_t    WORD;           // 16-bit unsigned integer
typedef uint16_t    USHORT;         // 16-bit unsigned integer
typedef int16_t     INT;            // 16-bit signed integer
typedef int16_t     SHORT;          // 16-bit signed integer
typedef int32_t     LONG;           // 32-bit signed integer
typedef uint32_t    ULONG;
typedef double      DOUBLE;         // 64- bit IEEE float
typedef int16_t     VARIANT_BOOL;   // 16-bit signed
typedef double      DATE;           // 64- bit IEEE float as datetime
typedef wchar_t     OLECHAR;
typedef OLECHAR *   BSTR;
typedef void *      PVOID;
typedef LONG        SCODE;
typedef long        HRESULT;

VARIANT_BOOL VARIANT_TRUE = -1;
VARIANT_BOOL VARIANT_FALSE = 0;



typedef struct {
    ULONG cElements;
    LONG  lLbound;
} SAFEARRAYBOUND;

typedef struct {
    USHORT         cDims;
    USHORT         fFeatures;
    ULONG          cbElements;
    ULONG          cLocks;
    PVOID          pvData;
    SAFEARRAYBOUND rgsabound[1];
} SAFEARRAY;

typedef struct {
    uint8_t     reserved[12];
    ULONG       vt;
    SAFEARRAY   sa;
} FULLSAFEARRAY;


// https://learn.microsoft.com/en-us/windows/win32/api/oaidl/ns-oaidl-safearray

#define FADF_AUTO        0x0001; // An array that is allocated on the stack.
#define FADF_STATIC      0x0002; // An array that is statically allocated.
#define FADF_EMBEDDED    0x0004; // An array that is embedded in a structure.
#define FADF_FIXEDSIZE   0x0010; // An array that may not be resized or reallocated.
#define FADF_RECORD      0x0020; // An array that contains records. When set, there will be a pointer to the IRecordInfo interface at negative offset 4 in the array descriptor.
#define FADF_HAVEIID     0x0040; // An array that has an IID identifying interface. When set, there will be a GUID at negative offset 16 in the safe array descriptor. Flag is set only when FADF_DISPATCH or FADF_UNKNOWN is also set.
#define FADF_HAVEVARTYPE 0x0080; // An array that has a variant type. The variant type can be retrieved with SafeArrayGetVartype.
#define FADF_BSTR        0x0100; // An array of BSTRs.
#define FADF_UNKNOWN     0x0200; // An array of IUnknown*.
#define FADF_DISPATCH    0x0400; // An array of IDispatch*.
#define FADF_VARIANT     0x0800; // An array of VARIANTs.
#define FADF_RESERVED    0xF008; // Bits reserved for future use.


typedef struct {
    VARTYPE vt;
    WORD    wReserved[3];
    union {
        LONG         lVal;
        DOUBLE       dblVal;
        VARIANT_BOOL boolVal;
        SCODE        scode;
        DATE         date;
        BSTR         *pbstrVal;
        SAFEARRAY    *parray;
    } data;
    WORD padding[4];                // due to __VARIANT_NAME_4 in the tagVARIANT struct
} VARIANT;



//        LONGLONG     llVal;
//        BYTE         bVal;
//        SHORT        iVal;
//        CHAR         cVal;
//        USHORT       uiVal;
//        ULONG        ulVal;
//        ULONGLONG    ullVal;
//        INT          intVal;
//        UINT         uintVal;
//        CHAR         *pcVal;
//        USHORT       *puiVal;
//        ULONG        *pulVal;
//        ULONGLONG    *pullVal;
//        INT          *pintVal;
//        UINT         *puintVal;


extern VARIANT doubleInVariant(double x, int size);

//extern int add(int32_t a, int32_t b);
//extern void add_arrays(double *a, double *b, double *c, int32_t n);
//extern double *square_array(double *a, int32_t n);
//extern double *square_array(double *a, int32_t n);
//extern VARIANT *returnALong(int x);
//extern VARIANT *returnErr(int x);
//VARTYPE vartype(VARIANT *x);
//double extractLong(VARIANT x);
//double extractLong2(VARIANT *x);


#endif
