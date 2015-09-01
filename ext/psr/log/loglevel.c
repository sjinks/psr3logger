#include "psr/log/loglevel.h"

zend_class_entry *psr_log_loglevel_ce;

int init_Psr_Log_LogLevel(TSRMLS_D)
{
	zend_class_entry ce;
	INIT_CLASS_ENTRY(ce, "Psr\\Log\\LogLevel", NULL);

	psr_log_loglevel_ce = zend_register_internal_class(&ce TSRMLS_CC);
	if (EXPECTED(psr_log_loglevel_ce != NULL)) {
		zend_declare_class_constant_stringl(psr_log_loglevel_ce, ZEND_STRL("EMERGENCY"), ZEND_STRL(PSR_LOG_LOGLEVEL_EMERGENCY) TSRMLS_CC);
		zend_declare_class_constant_stringl(psr_log_loglevel_ce, ZEND_STRL("ALERT"),     ZEND_STRL(PSR_LOG_LOGLEVEL_ALERT)     TSRMLS_CC);
		zend_declare_class_constant_stringl(psr_log_loglevel_ce, ZEND_STRL("CRITICAL"),  ZEND_STRL(PSR_LOG_LOGLEVEL_CRITICAL)  TSRMLS_CC);
		zend_declare_class_constant_stringl(psr_log_loglevel_ce, ZEND_STRL("ERROR"),     ZEND_STRL(PSR_LOG_LOGLEVEL_ERROR)     TSRMLS_CC);
		zend_declare_class_constant_stringl(psr_log_loglevel_ce, ZEND_STRL("WARNING"),   ZEND_STRL(PSR_LOG_LOGLEVEL_WARNING)   TSRMLS_CC);
		zend_declare_class_constant_stringl(psr_log_loglevel_ce, ZEND_STRL("NOTICE"),    ZEND_STRL(PSR_LOG_LOGLEVEL_NOTICE)    TSRMLS_CC);
		zend_declare_class_constant_stringl(psr_log_loglevel_ce, ZEND_STRL("INFO"),      ZEND_STRL(PSR_LOG_LOGLEVEL_INFO)      TSRMLS_CC);
		zend_declare_class_constant_stringl(psr_log_loglevel_ce, ZEND_STRL("DEBUG"),     ZEND_STRL(PSR_LOG_LOGLEVEL_DEBUG)     TSRMLS_CC);

		return SUCCESS;
	}

	return FAILURE;
}
