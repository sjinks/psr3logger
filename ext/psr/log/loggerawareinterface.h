#ifndef PSR_LOG_LOGGERAWAREINTERFACE_H
#define PSR_LOG_LOGGERAWAREINTERFACE_H

#include "php_psr3logger.h"

ZEND_DLEXPORT extern zend_class_entry* psr_log_loggerawareinterface_ce;

PSR3LOGGER_VISIBILITY_HIDDEN int init_Psr_Log_LoggerAwareInterface(TSRMLS_D);

ZEND_BEGIN_ARG_INFO_EX(arginfo_psr_log_loggerawareinterface_setlogger, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, logger, Psr\\Log\\LoggerInterface, 0)
ZEND_END_ARG_INFO()

#endif /* PSR_LOG_LOGGERAWAREINTERFACE_H */
