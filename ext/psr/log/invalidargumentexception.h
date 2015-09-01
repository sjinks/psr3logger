#ifndef PSR_LOG_INVALIDARGUMENTEXCEPTION_H
#define PSR_LOG_INVALIDARGUMENTEXCEPTION_H

#include "php_psr3logger.h"

ZEND_DLEXPORT extern zend_class_entry* psr_log_invalidargumentexception_ce;

PSR3LOGGER_VISIBILITY_HIDDEN int init_Psr_Log_InvalidArgumentException(TSRMLS_D);

#endif /* PSR_LOG_INVALIDARGUMENTEXCEPTION_H */
