PHP_ARG_ENABLE(psr3logger, whether to enable PSR-3 Logger Extension, [  --enable-psr3logger     Enable PSR-3 Logger Extension])

if test "$PHP_PSR3LOGGER" = "yes"; then
	AC_DEFINE([HAVE_PSR3LOGGER], [1], [Whether PSR-3 Logger Extension is enabled])

	psr3logger_sources="psr3logger.c \
psr/log/abstractlogger.c \
psr/log/invalidargumentexception.c \
psr/log/loggerawareinterface.c \
psr/log/loggerawaretrait.c \
psr/log/loggerinterface.c \
psr/log/loggertrait.c \
psr/log/loglevel.c \
psr/log/nulllogger.c"


	PHP_NEW_EXTENSION([psr3logger], $psr3logger_sources, $ext_shared)

	PHP_ADD_EXTENSION_DEP([psr3logger], [spl])
fi
