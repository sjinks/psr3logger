#ifndef PSR_LOG_LOGGERAWARETRAIT_H
#define PSR_LOG_LOGGERAWARETRAIT_H

#include "php_psr3logger.h"

ZEND_DLEXPORT extern zend_class_entry* psr_log_loggerawaretrait_ce;

PSR3LOGGER_VISIBILITY_HIDDEN int init_Psr_Log_LoggerAwareTrait(TSRMLS_D);

#endif /* PSR_LOG_LOGGERAWARETRAIT_H */
