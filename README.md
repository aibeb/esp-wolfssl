# esp-wolfssl

Wolfssl 3.15.7 to ESP-IDF & ESP-RTOS-SDK 3.x

## setup

* Add submodule

```bash
git submodule add https://github.com/aibeb/esp-wolfssl.git <path>
```

* Define macro in main/component.mk

```makefile
CFLAGS +=-DWOLFSSL_ESPIDF
CFLAGS +=-DWOLFSSL_USER_SETTINGS
```

* ignore the original ssl component

edit Makefile in project root directory

```makefile
EXCLUDE_COMPONENTS := ssl
```

* override wolfssl configuration if needed

edit main/component.mk or main/Makefile.projbuild

```makefile
CFLAGS +=-DNO_INLINE
```
