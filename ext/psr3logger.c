#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <main/php.h>
#include <Zend/zend.h>
#include "php_psr3logger.h"

#include "psr/log/abstractlogger.h"
#include "psr/log/invalidargumentexception.h"
#include "psr/log/loggerawareinterface.h"
#include "psr/log/loggerawaretrait.h"
#include "psr/log/loggerinterface.h"
#include "psr/log/loggertrait.h"
#include "psr/log/loglevel.h"
#include "psr/log/nulllogger.h"


static PHP_MINIT_FUNCTION(psr3logger)
{
	return
		(
			   SUCCESS == init_Psr_Log_LoggerAwareInterface(TSRMLS_C)
			&& SUCCESS == init_Psr_Log_LoggerInterface(TSRMLS_C)
			&& SUCCESS == init_Psr_Log_InvalidArgumentException(TSRMLS_C)
			&& SUCCESS == init_Psr_Log_LogLevel(TSRMLS_C)
			&& SUCCESS == init_Psr_Log_AbstractLogger(TSRMLS_C)
			&& SUCCESS == init_Psr_Log_NullLogger(TSRMLS_C)
			&& SUCCESS == init_Psr_Log_LoggerAwareTrait(TSRMLS_C)
			&& SUCCESS == init_Psr_Log_LoggerTrait(TSRMLS_C)
		)
		? SUCCESS : FAILURE
	;
}

static
#if ZEND_MODULE_API_NO > 20060613
const
#endif
zend_module_dep psr3logger_deps[] = {
	ZEND_MOD_REQUIRED("spl")
	ZEND_MOD_END
};

zend_module_entry psr3logger_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	psr3logger_deps,
	PHP_PSR3LOGGER_EXTNAME,
	NULL,
	PHP_MINIT(psr3logger),
	NULL,
	NULL,
	NULL,
	NULL,
	PHP_PSR3LOGGER_EXTVER,
	NO_MODULE_GLOBALS,
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_PSR3LOGGER
ZEND_GET_MODULE(psr3logger)
#endif
