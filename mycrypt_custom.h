/* This header is meant to be included before mycrypt.h in projects where
 * you don't want to throw all the defines in a makefile. 
 */

#ifndef MYCRYPT_CUSTOM_H_
#define MYCRYPT_CUSTOM_H_

/* this will sort out which stuff based on the user-config in options.h */
#include "../options.h"

/* macros for various libc functions you can change for embedded targets */
#define XMALLOC  malloc
#define XREALLOC realloc
#define XCALLOC  calloc
#define XFREE    free

#define XMEMSET  memset
#define XMEMCPY  memcpy

#define XCLOCK   clock
#define XCLOCKS_PER_SEC CLOCKS_PER_SEC

#ifdef DROPBEAR_SMALL_CODE
#define SMALL_CODE
#endif

/* Enable self-test test vector checking */
/* Not for dropbear */
//#define LTC_TEST

/* clean the stack of functions which put private information on stack */
// #define CLEAN_STACK

/* disable all file related functions */
// #define NO_FILE

#define CLEAN_STACK

#ifdef DROPBEAR_BLOWFISH_CBC
#define BLOWFISH
#endif

#ifdef DROPBEAR_AES128_CBC
#define RIJNDAEL
#endif

#ifdef DROPBEAR_TWOFISH128_CBC
#define TWOFISH

/* enabling just TWOFISH_SMALL will make the binary ~1kB smaller, turning on
 * TWOFISH_TABLES will make it a few kB bigger, but perhaps reduces runtime
 * memory usage? */
#define TWOFISH_SMALL
/*#define TWOFISH_TABLES*/
#endif

#ifdef DROPBEAR_3DES_CBC
#define DES
#endif
#define CBC

#if defined(DROPBEAR_DSS) && defined(DSS_PROTOK)
#define SHA512
#endif

#define SHA1

#ifdef DROPBEAR_MD5_HMAC
#define MD5
#endif

#define HMAC

/* Various tidbits of modern neatoness */
#define BASE64

#define FORTUNA_POOLS 0

#endif

