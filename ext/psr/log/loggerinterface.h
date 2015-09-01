#ifndef PSR_LOG_LOGGERINTERFACE_H
#define PSR_LOG_LOGGERINTERFACE_H

#include "php_psr3logger.h"

ZEND_DLEXPORT extern zend_class_entry* psr_log_loggerinterface_ce;

PSR3LOGGER_VISIBILITY_HIDDEN int init_Psr_Log_LoggerInterface(TSRMLS_D);

ZEND_BEGIN_ARG_INFO_EX(arginfo_psr_log_loggerinterface_log, 0, 0, 2)
	ZEND_ARG_INFO(0, level)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_psr_log_loggerinterface_logspecialized, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 0)
ZEND_END_ARG_INFO()

#endif /* PSR_LOG_LOGGERINTERFACE_H */
