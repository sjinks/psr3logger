#ifndef PSR_LOG_LOGLEVEL_H
#define PSR_LOG_LOGLEVEL_H

#include "php_psr3logger.h"

#define PSR_LOG_LOGLEVEL_EMERGENCY    "emergency"
#define PSR_LOG_LOGLEVEL_ALERT        "alert"
#define PSR_LOG_LOGLEVEL_CRITICAL     "critical"
#define PSR_LOG_LOGLEVEL_ERROR        "error"
#define PSR_LOG_LOGLEVEL_WARNING      "warning"
#define PSR_LOG_LOGLEVEL_NOTICE       "notice"
#define PSR_LOG_LOGLEVEL_INFO         "info"
#define PSR_LOG_LOGLEVEL_DEBUG        "debug"

ZEND_DLEXPORT extern zend_class_entry* psr_log_loglevel_ce;

PSR3LOGGER_VISIBILITY_HIDDEN int init_Psr_Log_LogLevel(TSRMLS_D);

#endif /* PSR_LOG_LOGLEVEL_H */
