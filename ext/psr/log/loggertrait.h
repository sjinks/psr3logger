#ifndef PSR_LOG_LOGGERTRAIT_H
#define PSR_LOG_LOGGERTRAIT_H

#include "php_psr3logger.h"

ZEND_DLEXPORT extern zend_class_entry *psr_log_loggertrait_ce;

PSR3LOGGER_VISIBILITY_HIDDEN int init_Psr_Log_LoggerTrait(TSRMLS_D);

#endif /* PSR_LOG_LOGGERTRAIT_H */
