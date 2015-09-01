#include "psr/log/nulllogger.h"
#include "psr/log/abstractlogger.h"
#include "psr/log/loggerinterface.h"

zend_class_entry *psr_log_nulllogger_ce;

static PHP_METHOD(Psr_Log_NullLogger, log)
{
	zval *level, *message, *context = NULL;

	if (FAILURE == zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|z!", &level, &message, &context)) {
		RETURN_NULL();
	}
}

static const zend_function_entry fe_psr_log_nulllogger[] = {
	PHP_ME(Psr_Log_NullLogger, log, arginfo_psr_log_loggerinterface_log, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

int init_Psr_Log_NullLogger(TSRMLS_D)
{
	zend_class_entry ce;
	INIT_CLASS_ENTRY(ce, "Psr\\Log\\NullLogger", fe_psr_log_nulllogger);

	psr_log_nulllogger_ce = zend_register_internal_class_ex(
		&ce,
		psr_log_abstractlogger_ce
#if PHP_MAJOR_VERSION < 7
		, NULL
#endif
		TSRMLS_CC
	);

	return (EXPECTED(psr_log_nulllogger_ce != NULL)) ? SUCCESS : FAILURE;
}
