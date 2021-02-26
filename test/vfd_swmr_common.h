/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Copyright by The HDF Group.                                               *
 * Copyright by the Board of Trustees of the University of Illinois.         *
 * All rights reserved.                                                      *
 *                                                                           *
 * This file is part of HDF5.  The full HDF5 copyright notice, including     *
 * terms governing use, modification, and redistribution, is contained in    *
 * the COPYING file, which can be found at the root of the source code       *
 * distribution tree, or in https://support.hdfgroup.org/ftp/HDF5/releases.  *
 * If you do not have access to either file, you may request a copy from     *
 * help@hdfgroup.org.                                                        *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef _VFD_SWMR_COMMON_H
#define _VFD_SWMR_COMMON_H

/***********/
/* Headers */
/***********/

#include <stdarg.h>
#include <unistd.h> /* For demo */
#include "h5test.h"

/**********/
/* Macros */
/**********/

/* The maximum # of records to add/remove from the dataset in one step,
 * used by vfd_swmr_addrem_writer and vfd_swmr_remove_reader.
 */
#define MAX_SIZE_CHANGE     10

#define VFD_SWMR_FILENAME        "vfd_swmr_data.h5"  /* SWMR test file name */

/* The message sent by writer that the file open is done--releasing the file lock */
#define VFD_SWMR_WRITER_MESSAGE "VFD_SWMR_WRITER_MESSAGE"

/* For demo */
#ifndef __arraycount
#define __arraycount(__a) (sizeof(__a) / sizeof((__a)[0]))
#endif

/************/
/* Typedefs */
/************/

typedef struct _estack_state {
    H5E_auto_t efunc;
    void *edata;
} estack_state_t;

typedef enum _testsel {
  TEST_NONE = 0
, TEST_NULL
, TEST_OOB
} testsel_t;

/********************/
/* Global Variables */
/********************/

/**************/
/* Prototypes */
/**************/
#ifdef __cplusplus
extern "C" {
#endif

H5TEST_DLL bool below_speed_limit(struct timespec *, const struct timespec *);

H5TEST_DLL estack_state_t estack_get_state(void);
H5TEST_DLL estack_state_t disable_estack(void);
H5TEST_DLL void restore_estack(estack_state_t);


H5TEST_DLL void block_signals(sigset_t *);
H5TEST_DLL void restore_signals(sigset_t *);
H5TEST_DLL void await_signal(hid_t);

H5TEST_DLL hid_t 
vfd_swmr_create_fapl(bool use_latest_format, bool use_vfd_swmr, bool only_meta_pages, 
    H5F_vfd_swmr_config_t *config);

H5TEST_DLL void
init_vfd_swmr_config(H5F_vfd_swmr_config_t *config, uint32_t tick_len, uint32_t max_lag, hbool_t writer,
    hbool_t flush_raw_data, uint32_t md_pages_reserved, const char *md_file_fmtstr, ...)
    H5_ATTR_FORMAT(printf, 7, 8);

H5TEST_DLL void dbgf(int, const char *, ...) H5_ATTR_FORMAT(printf, 2, 3);
H5TEST_DLL void evsnprintf(char *, size_t, const char *, va_list);
H5TEST_DLL void esnprintf(char *, size_t, const char *, ...)
    H5_ATTR_FORMAT(printf, 3, 4);

H5TEST_DLL int fetch_env_ulong(const char *, unsigned long, unsigned long *);

/* For demo */
H5TEST_DLL size_t strlcpy(char *, const char *, size_t);

#ifdef __cplusplus
}
#endif

extern int verbosity;

#endif /* _SWMR_COMMON_H */
