#include "psr/log/abstractlogger.h"
#include "psr/log/loggerinterface.h"
#include "psr/log/loglevel.h"

zend_class_entry* psr_log_abstractlogger_ce;

static void psr_log_abstractlogger_log_helper(INTERNAL_FUNCTION_PARAMETERS, const char *lvl)
{
#if PHP_MAJOR_VERSION >= 7
	zval z_context;
	zval z_level;
#endif
	zval* level;
	zval* message;
	zval* context = NULL;
#if PHP_MAJOR_VERSION >= 7
	zval params[3];
	zval retval;
#else
	zval** params[3] = { &level, &message, &context };
	zval* retval = NULL;
	zval function_name = zval_used_for_init;
#endif
	zend_fcall_info fci;
	zend_fcall_info_cache fcic;
	zend_class_entry* ce;

	if (FAILURE == zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &message, &context)) {
		RETURN_NULL();
	}

	ce = Z_OBJCE_P(getThis());

	if (!context) {
#if PHP_MAJOR_VERSION >= 7
		context = &z_context;
#else
		MAKE_STD_ZVAL(context);
#endif
		array_init(context);
		Z_SET_REFCOUNT_P(context, 0);
	}

#if PHP_MAJOR_VERSION >= 7
	level = &z_level;
	ZVAL_STRING(level, lvl);
#else
	MAKE_STD_ZVAL(level);
	ZVAL_STRING(level, lvl, 1);
#endif
	Z_SET_REFCOUNT_P(level, 0);



#if PHP_MAJOR_VERSION >= 7
	{
		zval func;
		ZVAL_STRING(&func, "log");
		call_user_function(&ce->function_table, getThis(), &func, NULL, 3, params TSRMLS_CC);
		zval_ptr_dtor(&func);
	}
#else
	{
		zval* params[3] = {level,message,context};
		zval* func;
		MAKE_STD_ZVAL(func);
		ZVAL_STRING(func, "log", 1);
		call_user_function(&ce->function_table, &(getThis()), func, NULL, 3, params TSRMLS_CC);
		zval_ptr_dtor(&func);
	}
#endif

	return;




#if PHP_MAJOR_VERSION >= 7
	params[0] = z_level;
	params[1] = *message;
	params[2] = z_context;
#endif

	fci.size           = sizeof(fci);
	fci.function_table = &ce->function_table;
#if PHP_MAJOR_VERSION >= 7
	ZVAL_UNDEF(&fci.function_name);
	fci.object         = Z_OBJ_P(getThis());
	fci.retval         = &retval;
#else
	fci.function_name  = &function_name;
	fci.object_ptr     = getThis();
	fci.retval_ptr_ptr = &retval;
#endif
	fci.param_count    = 3;
	fci.params         = params;
	fci.no_separation  = 1;
	fci.symbol_table   = NULL;

	fcic.initialized   = 1;
#if PHP_MAJOR_VERSION >= 7
	fcic.object        = Z_OBJ_P(getThis());
#else
	fcic.object_ptr    = getThis();
#endif
	fcic.calling_scope = ce;
	fcic.called_scope  = ce;

#if PHP_MAJOR_VERSION >= 7
	fcic.function_handler = zend_hash_str_find_ptr(fci.function_table, "log", sizeof("log")-1);
	if (!fcic.function_handler) {
		fcic.initialized = 0;
		ZVAL_STRINGL(&fci.function_name, "log", sizeof("log")-1);
	}
#else
	if (zend_hash_quick_find(fci.function_table, ZEND_STRS("log"), zend_inline_hash_func(ZEND_STRS("log")), (void**)&fcic.function_handler) == FAILURE) {
		fcic.initialized = 0;
		ZVAL_STRING(&function_name, "log", 0);
	}
#endif

	zend_call_function(&fci, &fcic TSRMLS_CC);

#if PHP_MAJOR_VERSION >= 7
	zval_ptr_dtor(&retval);
	zval_ptr_dtor(&fci.function_name);
#else
	if (retval) {
		zval_ptr_dtor(&retval);
	}
#endif
}

PHP_FUNCTION(Psr_Log_Emergency)
{
	psr_log_abstractlogger_log_helper(INTERNAL_FUNCTION_PARAM_PASSTHRU, PSR_LOG_LOGLEVEL_EMERGENCY);
}

PHP_FUNCTION(Psr_Log_Alert)
{
	psr_log_abstractlogger_log_helper(INTERNAL_FUNCTION_PARAM_PASSTHRU, PSR_LOG_LOGLEVEL_ALERT);
}

PHP_FUNCTION(Psr_Log_Critical)
{
	psr_log_abstractlogger_log_helper(INTERNAL_FUNCTION_PARAM_PASSTHRU, PSR_LOG_LOGLEVEL_CRITICAL);
}

PHP_FUNCTION(Psr_Log_Error)
{
	psr_log_abstractlogger_log_helper(INTERNAL_FUNCTION_PARAM_PASSTHRU, PSR_LOG_LOGLEVEL_ERROR);
}

PHP_FUNCTION(Psr_Log_Warning)
{
	psr_log_abstractlogger_log_helper(INTERNAL_FUNCTION_PARAM_PASSTHRU, PSR_LOG_LOGLEVEL_WARNING);
}

PHP_FUNCTION(Psr_Log_Notice)
{
	psr_log_abstractlogger_log_helper(INTERNAL_FUNCTION_PARAM_PASSTHRU, PSR_LOG_LOGLEVEL_NOTICE);
}

PHP_FUNCTION(Psr_Log_Info)
{
	psr_log_abstractlogger_log_helper(INTERNAL_FUNCTION_PARAM_PASSTHRU, PSR_LOG_LOGLEVEL_INFO);
}

PHP_FUNCTION(Psr_Log_Debug)
{
	psr_log_abstractlogger_log_helper(INTERNAL_FUNCTION_PARAM_PASSTHRU, PSR_LOG_LOGLEVEL_DEBUG);
}

static const zend_function_entry fe_psr_log_abstractlogger[] = {
	PHP_ME_MAPPING(emergency, Psr_Log_Emergency, arginfo_psr_log_loggerinterface_logspecialized, ZEND_ACC_PUBLIC)
	PHP_ME_MAPPING(alert, Psr_Log_Alert, arginfo_psr_log_loggerinterface_logspecialized, ZEND_ACC_PUBLIC)
	PHP_ME_MAPPING(critical, Psr_Log_Critical, arginfo_psr_log_loggerinterface_logspecialized, ZEND_ACC_PUBLIC)
	PHP_ME_MAPPING(error, Psr_Log_Error, arginfo_psr_log_loggerinterface_logspecialized, ZEND_ACC_PUBLIC)
	PHP_ME_MAPPING(warning, Psr_Log_Warning, arginfo_psr_log_loggerinterface_logspecialized, ZEND_ACC_PUBLIC)
	PHP_ME_MAPPING(notice, Psr_Log_Notice, arginfo_psr_log_loggerinterface_logspecialized, ZEND_ACC_PUBLIC)
	PHP_ME_MAPPING(info, Psr_Log_Info, arginfo_psr_log_loggerinterface_logspecialized, ZEND_ACC_PUBLIC)
	PHP_ME_MAPPING(debug, Psr_Log_Debug, arginfo_psr_log_loggerinterface_logspecialized, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

int init_Psr_Log_AbstractLogger(TSRMLS_D)
{
	zend_class_entry ce;
	INIT_CLASS_ENTRY(ce, "Psr\\Log\\AbstractLogger", fe_psr_log_abstractlogger);

	psr_log_abstractlogger_ce = zend_register_internal_class(&ce TSRMLS_CC);
	if (EXPECTED(psr_log_abstractlogger_ce != NULL)) {
		zend_class_implements(psr_log_abstractlogger_ce TSRMLS_CC, 1, psr_log_loggerinterface_ce);
		return SUCCESS;
	}

	return FAILURE;
}
