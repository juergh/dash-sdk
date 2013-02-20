/* safenetssl.h

   Kernel module for SSL acceleration.
   Header file, constant definitions, typedefs and ioctls.

   Copyright (C) 2004 SafeNet B.V. Vught The Netherlands.
   All rights reserved.

   Date: 2004-06-07

*/


#ifndef SA_CRYPTO_DES
/* SafeNet specific codes for crypto and hash algorithms */
#define SA_CRYPTO_DES							0x00000000
#define SA_CRYPTO_TDES							0x00000001
#define SA_CRYPTO_ARC4							0x00000002
#define SA_CRYPTO_AES							0x00000003
#define SA_CRYPTO_NULL							0x0000000f
#define SA_HASH_MD5								0x00000000
#define SA_HASH_SHA1							0x00000001
#define SA_HASH_NULL							0x0000000f
#define SA_CRYPTO_MODE_ECB						0x00000000
#define SA_CRYPTO_MODE_CBC						0x00000001
#define SA_CRYPTO_MODE_OFB						0x00000002
#define SA_CRYPTO_MODE_CFB						0x00000003
#endif

/* The following data structures describe the parameters as 
   passed to the various ioctl functions in the driver.
*/

/* expmod command parameters */
typedef struct {
  unsigned long *res;
  unsigned long ressize;
  unsigned long *a;
  unsigned long asize;
  unsigned long *p;
  unsigned long psize;
  unsigned long *m;
  unsigned long msize;
} expmod_param_blk;

/* expcrtmod command parameters */
typedef struct {
  unsigned long *res;
  unsigned long ressize;
  unsigned long *a;
  unsigned long asize;
  unsigned long *p;
  unsigned long psize;
  unsigned long *q;
  unsigned long qsize;
  unsigned long *dp;
  unsigned long dpsize;
  unsigned long *dq;
  unsigned long dqsize;
  unsigned long *u;
  unsigned long usize;  
} expcrtmod_param_blk;

/* Parameter block for the crypto command (all parameters used), also
   for update/final digest and random commands, a subset of the parameters
   is used */
typedef struct {
  int ctx; /* index of cipher/hash context */
  const unsigned char *input;
  unsigned char *output;
  unsigned int size;
} crypto_param_blk;

/* initkey command parameters */
typedef struct {
  int algo;
  int keylen;
  int fmode; /* feedback mode, ECB or CBC */
  const unsigned char *key;
  const unsigned char *iv;
  int dir; /* direction, 1 for encrypt, 0 for decrypt */
} initkey_param_blk;

#define SAFENET_IOC_MAGIC 'u'

#define SAFENET_IOCEXPMOD _IOW(SAFENET_IOC_MAGIC, 0, expmod_param_blk)
#define SAFENET_IOCEXPCRTMOD _IOW(SAFENET_IOC_MAGIC, 1, expcrtmod_param_blk)
#define SAFENET_IOCRANDOM   _IOW(SAFENET_IOC_MAGIC, 2 , crypto_param_blk)
#define SAFENET_IOCINITKEY _IOW(SAFENET_IOC_MAGIC, 3, initkey_param_blk)
#define SAFENET_IOCCIPHER _IOW(SAFENET_IOC_MAGIC, 4, crypto_param_blk)
#define SAFENET_IOCCLEANKEY _IO(SAFENET_IOC_MAGIC, 5)
#define SAFENET_IOCINITDIGEST _IO(SAFENET_IOC_MAGIC, 6)
#define SAFENET_IOCUPDATEDIGEST _IOW(SAFENET_IOC_MAGIC, 7, crypto_param_blk)
#define SAFENET_IOCFINALDIGEST _IOW(SAFENET_IOC_MAGIC, 8, crypto_param_blk)
#define SAFENET_IOCCLEANDIGEST _IO(SAFENET_IOC_MAGIC, 9)
#define SAFENET_IOCCOPYDIGEST _IO(SAFENET_IOC_MAGIC, 10)
