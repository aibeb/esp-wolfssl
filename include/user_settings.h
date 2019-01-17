/* user_settings.h
 *
 * Copyright (C) 2006-2018 wolfSSL Inc.
 *
 * This file is part of wolfSSL.
 *
 * wolfSSL is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * wolfSSL is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1335, USA
 */

#define BENCH_EMBEDDED
#define USE_CERT_BUFFERS_2048

/* TLS 1.3                                 */
#define WOLFSSL_TLS13
#define HAVE_TLS_EXTENSIONS
#define WC_RSA_PSS
#define HAVE_HKDF
#define HAVE_FFDHE_2048
#define HAVE_AEAD
#define HAVE_SUPPORTED_CURVES

/* when you want to use SINGLE THREAD */
/* #define SINGLE_THREADED */
#define NO_FILESYSTEM

#define HAVE_AESGCM
/* when you want to use SHA384 */
/* #define WOLFSSL_SHA384 */
#define WOLFSSL_SHA512
#define HAVE_ECC
#define HAVE_CURVE25519
#define CURVE25519_SMALL
#define HAVE_ED25519

/* debug options */
/* #define DEBUG_WOLFSSL */
/* #define WOLFSSL_ESP32WROOM32_CRYPT_DEBUG */

/* date/time                               */
/* if it cannot adjust time in the device, */
/* enable macro below                      */
/* #define NO_ASN_TIME */
/* #define XTIME time */

/* when you want not to use HW acceleration */
/* #define NO_ESP32WROOM32_CRYPT */
/* #define NO_WOLFSSL_ESP32WROOM32_CRYPT_HASH*/
/* #define NO_WOLFSSL_ESP32WROOM32_CRYPT_AES */

// ESP-RTOS-SDK
#ifndef __USER_SETTINGS_H__
#define __USER_SETTINGS_H__

#define WOLFSSL_LWIP
#define NO_WRITEV
#define NO_WOLFSSL_DIR
#define NO_INLINE
// #define NO_WOLFSSL_MEMORY
#define HAVE_PK_CALLBACKS
#define WOLFSSL_KEY_GEN
#define WOLFSSL_RIPEMD
#define USE_WOLFSSL_IO
#define WOLFSSL_STATIC_RSA
#define NO_DH
#define NO_MD4
#define NO_DES3
#define NO_DSA
#define NO_RC4
#define NO_RABBIT
#define HAVE_ECC
#define HAVE_AES_ECB
#define WOLFSSL_AES_DIRECT
#define WC_NO_HARDEN
#define FREERTOS
#define WOLFSSL_TYPES
#define NO_FILESYSTEM
#define WOLFSSL_ALT_CERT_CHAINS
#define WOLFSSL_ALLOW_TLSV10
#define WOLFSSL_SMALL_STACK
#define SMALL_SESSION_CACHE
// #define OPENSSL_EXTRA

#define SSL_CTX_use_certificate_ASN1(ctx, len, buf) wolfSSL_CTX_use_certificate_buffer(ctx, buf, len, WOLFSSL_FILETYPE_PEM)
#define SSL_CTX_use_PrivateKey_ASN1(type, ctx, buf, len) wolfSSL_CTX_use_PrivateKey_buffer(ctx, buf, len, WOLFSSL_FILETYPE_PEM)
#define SSL_CTX_load_verify_buffer(ctx, buf, len) wolfSSL_CTX_load_verify_buffer(ctx, buf, len, WOLFSSL_FILETYPE_PEM)

#ifdef WOLFSSL_TYPES
#ifndef byte
typedef unsigned char byte;
#endif
typedef unsigned short word16;
typedef unsigned int word32;
typedef byte word24[3];
#endif

#ifndef CUSTOM_RAND_GENERATE_BLOCK
#include "esp_libc.h"
/* To use define the following:*/
#define CUSTOM_RAND_GENERATE_BLOCK os_get_random
#endif

#endif
