#line 1 "numpy/core/src/common/npy_sort.h.src"

/*
 *****************************************************************************
 **       This file was autogenerated from a template  DO NOT EDIT!!!!      **
 **       Changes should be made to the original source (.src) file         **
 *****************************************************************************
 */

#line 1
#ifndef __NPY_SORT_H__
#define __NPY_SORT_H__

/* Python include is for future object sorts */
#include <Python.h>
#include <numpy/npy_common.h>
#include <numpy/ndarraytypes.h>

#define NPY_ENOMEM 1
#define NPY_ECOMP 2

static NPY_INLINE int npy_get_msb(npy_uintp unum)
{
    int depth_limit = 0;
    while (unum >>= 1)  {
        depth_limit++;
    }
    return depth_limit;
}

#ifdef __cplusplus
extern "C" {
#endif



/*
 *****************************************************************************
 **                            NUMERIC SORTS                                **
 *****************************************************************************
 */


#line 40

NPY_NO_EXPORT int quicksort_bool(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int heapsort_bool(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int mergesort_bool(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int timsort_bool(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int aquicksort_bool(void *vec, npy_intp *ind, npy_intp cnt, void *null);
NPY_NO_EXPORT int aheapsort_bool(void *vec, npy_intp *ind, npy_intp cnt, void *null);
NPY_NO_EXPORT int amergesort_bool(void *vec, npy_intp *ind, npy_intp cnt, void *null);
NPY_NO_EXPORT int atimsort_bool(void *vec, npy_intp *ind, npy_intp cnt, void *null);


#line 40

NPY_NO_EXPORT int quicksort_byte(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int heapsort_byte(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int mergesort_byte(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int timsort_byte(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int aquicksort_byte(void *vec, npy_intp *ind, npy_intp cnt, void *null);
NPY_NO_EXPORT int aheapsort_byte(void *vec, npy_intp *ind, npy_intp cnt, void *null);
NPY_NO_EXPORT int amergesort_byte(void *vec, npy_intp *ind, npy_intp cnt, void *null);
NPY_NO_EXPORT int atimsort_byte(void *vec, npy_intp *ind, npy_intp cnt, void *null);


#line 40

NPY_NO_EXPORT int quicksort_ubyte(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int heapsort_ubyte(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int mergesort_ubyte(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int timsort_ubyte(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int aquicksort_ubyte(void *vec, npy_intp *ind, npy_intp cnt, void *null);
NPY_NO_EXPORT int aheapsort_ubyte(void *vec, npy_intp *ind, npy_intp cnt, void *null);
NPY_NO_EXPORT int amergesort_ubyte(void *vec, npy_intp *ind, npy_intp cnt, void *null);
NPY_NO_EXPORT int atimsort_ubyte(void *vec, npy_intp *ind, npy_intp cnt, void *null);


#line 40

NPY_NO_EXPORT int quicksort_short(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int heapsort_short(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int mergesort_short(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int timsort_short(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int aquicksort_short(void *vec, npy_intp *ind, npy_intp cnt, void *null);
NPY_NO_EXPORT int aheapsort_short(void *vec, npy_intp *ind, npy_intp cnt, void *null);
NPY_NO_EXPORT int amergesort_short(void *vec, npy_intp *ind, npy_intp cnt, void *null);
NPY_NO_EXPORT int atimsort_short(void *vec, npy_intp *ind, npy_intp cnt, void *null);


#line 40

NPY_NO_EXPORT int quicksort_ushort(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int heapsort_ushort(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int mergesort_ushort(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int timsort_ushort(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int aquicksort_ushort(void *vec, npy_intp *ind, npy_intp cnt, void *null);
NPY_NO_EXPORT int aheapsort_ushort(void *vec, npy_intp *ind, npy_intp cnt, void *null);
NPY_NO_EXPORT int amergesort_ushort(void *vec, npy_intp *ind, npy_intp cnt, void *null);
NPY_NO_EXPORT int atimsort_ushort(void *vec, npy_intp *ind, npy_intp cnt, void *null);


#line 40

NPY_NO_EXPORT int quicksort_int(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int heapsort_int(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int mergesort_int(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int timsort_int(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int aquicksort_int(void *vec, npy_intp *ind, npy_intp cnt, void *null);
NPY_NO_EXPORT int aheapsort_int(void *vec, npy_intp *ind, npy_intp cnt, void *null);
NPY_NO_EXPORT int amergesort_int(void *vec, npy_intp *ind, npy_intp cnt, void *null);
NPY_NO_EXPORT int atimsort_int(void *vec, npy_intp *ind, npy_intp cnt, void *null);


#line 40

NPY_NO_EXPORT int quicksort_uint(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int heapsort_uint(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int mergesort_uint(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int timsort_uint(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int aquicksort_uint(void *vec, npy_intp *ind, npy_intp cnt, void *null);
NPY_NO_EXPORT int aheapsort_uint(void *vec, npy_intp *ind, npy_intp cnt, void *null);
NPY_NO_EXPORT int amergesort_uint(void *vec, npy_intp *ind, npy_intp cnt, void *null);
NPY_NO_EXPORT int atimsort_uint(void *vec, npy_intp *ind, npy_intp cnt, void *null);


#line 40

NPY_NO_EXPORT int quicksort_long(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int heapsort_long(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int mergesort_long(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int timsort_long(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int aquicksort_long(void *vec, npy_intp *ind, npy_intp cnt, void *null);
NPY_NO_EXPORT int aheapsort_long(void *vec, npy_intp *ind, npy_intp cnt, void *null);
NPY_NO_EXPORT int amergesort_long(void *vec, npy_intp *ind, npy_intp cnt, void *null);
NPY_NO_EXPORT int atimsort_long(void *vec, npy_intp *ind, npy_intp cnt, void *null);


#line 40

NPY_NO_EXPORT int quicksort_ulong(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int heapsort_ulong(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int mergesort_ulong(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int timsort_ulong(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int aquicksort_ulong(void *vec, npy_intp *ind, npy_intp cnt, void *null);
NPY_NO_EXPORT int aheapsort_ulong(void *vec, npy_intp *ind, npy_intp cnt, void *null);
NPY_NO_EXPORT int amergesort_ulong(void *vec, npy_intp *ind, npy_intp cnt, void *null);
NPY_NO_EXPORT int atimsort_ulong(void *vec, npy_intp *ind, npy_intp cnt, void *null);


#line 40

NPY_NO_EXPORT int quicksort_longlong(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int heapsort_longlong(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int mergesort_longlong(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int timsort_longlong(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int aquicksort_longlong(void *vec, npy_intp *ind, npy_intp cnt, void *null);
NPY_NO_EXPORT int aheapsort_longlong(void *vec, npy_intp *ind, npy_intp cnt, void *null);
NPY_NO_EXPORT int amergesort_longlong(void *vec, npy_intp *ind, npy_intp cnt, void *null);
NPY_NO_EXPORT int atimsort_longlong(void *vec, npy_intp *ind, npy_intp cnt, void *null);


#line 40

NPY_NO_EXPORT int quicksort_ulonglong(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int heapsort_ulonglong(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int mergesort_ulonglong(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int timsort_ulonglong(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int aquicksort_ulonglong(void *vec, npy_intp *ind, npy_intp cnt, void *null);
NPY_NO_EXPORT int aheapsort_ulonglong(void *vec, npy_intp *ind, npy_intp cnt, void *null);
NPY_NO_EXPORT int amergesort_ulonglong(void *vec, npy_intp *ind, npy_intp cnt, void *null);
NPY_NO_EXPORT int atimsort_ulonglong(void *vec, npy_intp *ind, npy_intp cnt, void *null);


#line 40

NPY_NO_EXPORT int quicksort_half(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int heapsort_half(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int mergesort_half(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int timsort_half(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int aquicksort_half(void *vec, npy_intp *ind, npy_intp cnt, void *null);
NPY_NO_EXPORT int aheapsort_half(void *vec, npy_intp *ind, npy_intp cnt, void *null);
NPY_NO_EXPORT int amergesort_half(void *vec, npy_intp *ind, npy_intp cnt, void *null);
NPY_NO_EXPORT int atimsort_half(void *vec, npy_intp *ind, npy_intp cnt, void *null);


#line 40

NPY_NO_EXPORT int quicksort_float(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int heapsort_float(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int mergesort_float(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int timsort_float(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int aquicksort_float(void *vec, npy_intp *ind, npy_intp cnt, void *null);
NPY_NO_EXPORT int aheapsort_float(void *vec, npy_intp *ind, npy_intp cnt, void *null);
NPY_NO_EXPORT int amergesort_float(void *vec, npy_intp *ind, npy_intp cnt, void *null);
NPY_NO_EXPORT int atimsort_float(void *vec, npy_intp *ind, npy_intp cnt, void *null);


#line 40

NPY_NO_EXPORT int quicksort_double(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int heapsort_double(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int mergesort_double(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int timsort_double(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int aquicksort_double(void *vec, npy_intp *ind, npy_intp cnt, void *null);
NPY_NO_EXPORT int aheapsort_double(void *vec, npy_intp *ind, npy_intp cnt, void *null);
NPY_NO_EXPORT int amergesort_double(void *vec, npy_intp *ind, npy_intp cnt, void *null);
NPY_NO_EXPORT int atimsort_double(void *vec, npy_intp *ind, npy_intp cnt, void *null);


#line 40

NPY_NO_EXPORT int quicksort_longdouble(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int heapsort_longdouble(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int mergesort_longdouble(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int timsort_longdouble(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int aquicksort_longdouble(void *vec, npy_intp *ind, npy_intp cnt, void *null);
NPY_NO_EXPORT int aheapsort_longdouble(void *vec, npy_intp *ind, npy_intp cnt, void *null);
NPY_NO_EXPORT int amergesort_longdouble(void *vec, npy_intp *ind, npy_intp cnt, void *null);
NPY_NO_EXPORT int atimsort_longdouble(void *vec, npy_intp *ind, npy_intp cnt, void *null);


#line 40

NPY_NO_EXPORT int quicksort_cfloat(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int heapsort_cfloat(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int mergesort_cfloat(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int timsort_cfloat(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int aquicksort_cfloat(void *vec, npy_intp *ind, npy_intp cnt, void *null);
NPY_NO_EXPORT int aheapsort_cfloat(void *vec, npy_intp *ind, npy_intp cnt, void *null);
NPY_NO_EXPORT int amergesort_cfloat(void *vec, npy_intp *ind, npy_intp cnt, void *null);
NPY_NO_EXPORT int atimsort_cfloat(void *vec, npy_intp *ind, npy_intp cnt, void *null);


#line 40

NPY_NO_EXPORT int quicksort_cdouble(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int heapsort_cdouble(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int mergesort_cdouble(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int timsort_cdouble(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int aquicksort_cdouble(void *vec, npy_intp *ind, npy_intp cnt, void *null);
NPY_NO_EXPORT int aheapsort_cdouble(void *vec, npy_intp *ind, npy_intp cnt, void *null);
NPY_NO_EXPORT int amergesort_cdouble(void *vec, npy_intp *ind, npy_intp cnt, void *null);
NPY_NO_EXPORT int atimsort_cdouble(void *vec, npy_intp *ind, npy_intp cnt, void *null);


#line 40

NPY_NO_EXPORT int quicksort_clongdouble(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int heapsort_clongdouble(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int mergesort_clongdouble(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int timsort_clongdouble(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int aquicksort_clongdouble(void *vec, npy_intp *ind, npy_intp cnt, void *null);
NPY_NO_EXPORT int aheapsort_clongdouble(void *vec, npy_intp *ind, npy_intp cnt, void *null);
NPY_NO_EXPORT int amergesort_clongdouble(void *vec, npy_intp *ind, npy_intp cnt, void *null);
NPY_NO_EXPORT int atimsort_clongdouble(void *vec, npy_intp *ind, npy_intp cnt, void *null);


#line 40

NPY_NO_EXPORT int quicksort_datetime(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int heapsort_datetime(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int mergesort_datetime(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int timsort_datetime(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int aquicksort_datetime(void *vec, npy_intp *ind, npy_intp cnt, void *null);
NPY_NO_EXPORT int aheapsort_datetime(void *vec, npy_intp *ind, npy_intp cnt, void *null);
NPY_NO_EXPORT int amergesort_datetime(void *vec, npy_intp *ind, npy_intp cnt, void *null);
NPY_NO_EXPORT int atimsort_datetime(void *vec, npy_intp *ind, npy_intp cnt, void *null);


#line 40

NPY_NO_EXPORT int quicksort_timedelta(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int heapsort_timedelta(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int mergesort_timedelta(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int timsort_timedelta(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int aquicksort_timedelta(void *vec, npy_intp *ind, npy_intp cnt, void *null);
NPY_NO_EXPORT int aheapsort_timedelta(void *vec, npy_intp *ind, npy_intp cnt, void *null);
NPY_NO_EXPORT int amergesort_timedelta(void *vec, npy_intp *ind, npy_intp cnt, void *null);
NPY_NO_EXPORT int atimsort_timedelta(void *vec, npy_intp *ind, npy_intp cnt, void *null);



#line 57
#ifdef __cplusplus
extern "C" {
#endif
NPY_NO_EXPORT int radixsort_bool(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int aradixsort_bool(void *vec, npy_intp *ind, npy_intp cnt, void *null);
#ifdef __cplusplus
}
#endif


#line 57
#ifdef __cplusplus
extern "C" {
#endif
NPY_NO_EXPORT int radixsort_byte(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int aradixsort_byte(void *vec, npy_intp *ind, npy_intp cnt, void *null);
#ifdef __cplusplus
}
#endif


#line 57
#ifdef __cplusplus
extern "C" {
#endif
NPY_NO_EXPORT int radixsort_ubyte(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int aradixsort_ubyte(void *vec, npy_intp *ind, npy_intp cnt, void *null);
#ifdef __cplusplus
}
#endif


#line 57
#ifdef __cplusplus
extern "C" {
#endif
NPY_NO_EXPORT int radixsort_short(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int aradixsort_short(void *vec, npy_intp *ind, npy_intp cnt, void *null);
#ifdef __cplusplus
}
#endif


#line 57
#ifdef __cplusplus
extern "C" {
#endif
NPY_NO_EXPORT int radixsort_ushort(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int aradixsort_ushort(void *vec, npy_intp *ind, npy_intp cnt, void *null);
#ifdef __cplusplus
}
#endif


#line 57
#ifdef __cplusplus
extern "C" {
#endif
NPY_NO_EXPORT int radixsort_int(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int aradixsort_int(void *vec, npy_intp *ind, npy_intp cnt, void *null);
#ifdef __cplusplus
}
#endif


#line 57
#ifdef __cplusplus
extern "C" {
#endif
NPY_NO_EXPORT int radixsort_uint(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int aradixsort_uint(void *vec, npy_intp *ind, npy_intp cnt, void *null);
#ifdef __cplusplus
}
#endif


#line 57
#ifdef __cplusplus
extern "C" {
#endif
NPY_NO_EXPORT int radixsort_long(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int aradixsort_long(void *vec, npy_intp *ind, npy_intp cnt, void *null);
#ifdef __cplusplus
}
#endif


#line 57
#ifdef __cplusplus
extern "C" {
#endif
NPY_NO_EXPORT int radixsort_ulong(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int aradixsort_ulong(void *vec, npy_intp *ind, npy_intp cnt, void *null);
#ifdef __cplusplus
}
#endif


#line 57
#ifdef __cplusplus
extern "C" {
#endif
NPY_NO_EXPORT int radixsort_longlong(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int aradixsort_longlong(void *vec, npy_intp *ind, npy_intp cnt, void *null);
#ifdef __cplusplus
}
#endif


#line 57
#ifdef __cplusplus
extern "C" {
#endif
NPY_NO_EXPORT int radixsort_ulonglong(void *vec, npy_intp cnt, void *null);
NPY_NO_EXPORT int aradixsort_ulonglong(void *vec, npy_intp *ind, npy_intp cnt, void *null);
#ifdef __cplusplus
}
#endif





/*
 *****************************************************************************
 **                             STRING SORTS                                **
 *****************************************************************************
 */


#line 81

NPY_NO_EXPORT int quicksort_string(void *vec, npy_intp cnt, void *arr);
NPY_NO_EXPORT int heapsort_string(void *vec, npy_intp cnt, void *arr);
NPY_NO_EXPORT int mergesort_string(void *vec, npy_intp cnt, void *arr);
NPY_NO_EXPORT int timsort_string(void *vec, npy_intp cnt, void *arr);
NPY_NO_EXPORT int aquicksort_string(void *vec, npy_intp *ind, npy_intp cnt, void *arr);
NPY_NO_EXPORT int aheapsort_string(void *vec, npy_intp *ind, npy_intp cnt, void *arr);
NPY_NO_EXPORT int amergesort_string(void *vec, npy_intp *ind, npy_intp cnt, void *arr);
NPY_NO_EXPORT int atimsort_string(void *vec, npy_intp *ind, npy_intp cnt, void *arr);


#line 81

NPY_NO_EXPORT int quicksort_unicode(void *vec, npy_intp cnt, void *arr);
NPY_NO_EXPORT int heapsort_unicode(void *vec, npy_intp cnt, void *arr);
NPY_NO_EXPORT int mergesort_unicode(void *vec, npy_intp cnt, void *arr);
NPY_NO_EXPORT int timsort_unicode(void *vec, npy_intp cnt, void *arr);
NPY_NO_EXPORT int aquicksort_unicode(void *vec, npy_intp *ind, npy_intp cnt, void *arr);
NPY_NO_EXPORT int aheapsort_unicode(void *vec, npy_intp *ind, npy_intp cnt, void *arr);
NPY_NO_EXPORT int amergesort_unicode(void *vec, npy_intp *ind, npy_intp cnt, void *arr);
NPY_NO_EXPORT int atimsort_unicode(void *vec, npy_intp *ind, npy_intp cnt, void *arr);




/*
 *****************************************************************************
 **                             GENERIC SORT                                **
 *****************************************************************************
 */


NPY_NO_EXPORT int npy_quicksort(void *vec, npy_intp cnt, void *arr);
NPY_NO_EXPORT int npy_heapsort(void *vec, npy_intp cnt, void *arr);
NPY_NO_EXPORT int npy_mergesort(void *vec, npy_intp cnt, void *arr);
NPY_NO_EXPORT int npy_timsort(void *vec, npy_intp cnt, void *arr);
NPY_NO_EXPORT int npy_aquicksort(void *vec, npy_intp *ind, npy_intp cnt, void *arr);
NPY_NO_EXPORT int npy_aheapsort(void *vec, npy_intp *ind, npy_intp cnt, void *arr);
NPY_NO_EXPORT int npy_amergesort(void *vec, npy_intp *ind, npy_intp cnt, void *arr);
NPY_NO_EXPORT int npy_atimsort(void *vec, npy_intp *ind, npy_intp cnt, void *arr);

#ifdef __cplusplus
}
#endif

#endif

