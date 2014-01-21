#ifndef PHP_PSR3LOGGER_H
#define PHP_PSR3LOGGER_H

#include <main/php.h>

#define PHP_PSR3LOGGER_EXTNAME  "psr3logger"
#define PHP_PSR3LOGGER_EXTVER   "1.0"

#ifndef ZEND_MOD_END
#	define ZEND_MOD_END { NULL, NULL, NULL, 0 }
#endif

#if defined(__GNUC__) && __GNUC__ >= 4
#	define PSR3LOGGER_VISIBILITY_HIDDEN __attribute__((visibility("hidden")))
#else
#	define PSR3LOGGER_VISIBILITY_HIDDEN
#endif


#ifdef COMPILE_DL_PSR3LOGGER
PSR3LOGGER_VISIBILITY_HIDDEN
#endif
extern zend_module_entry psr3logger_module_entry;

#define phpext_psr3logger_ptr &psr3logger_module_entry

#endif /* PHP_PSR3LOGGER_H */
