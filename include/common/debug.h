#ifndef __DEBUG_MACROS_H__
#define __DEBUG_MACROS_H__

#include <stdio.h>

#ifdef DEBUG
#define DEBUG_TEST 1
#else
#define DEBUG_TEST 0
#endif

#define dbg_trace(fmt, ...) \
  do { if(DEBUG_TEST) \
          fprintf(stderr, \
            "DEBUG:%d: %s(): " fmt, \
            __LINE__, __func__, __VA_ARGS__); \
     } while(0)

#define dbg_info(fmt, ...) \
 do { if(DEBUG_TEST) \
         fprintf(stderr, \
           "INFO:%d: %s(): " fmt, \
           __LINE__, __func__ ); \
    } while(0)


#define print_output(fmt, ...) \
  do { fprintf(stdout, fmt, __VA_ARGS__); \
     } while(0)

#endif /* __DEBUG_MACROS_H__ */
