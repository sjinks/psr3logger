#! /bin/bash

DIR=$(readlink -enq "$(dirname $0)/../ext/")

shopt -s nullglob
export NO_INTERACTION=1
export REPORT_EXIT_STATUS=1
export TEST_PHP_ARGS=-m
sed -i 's!--vex-iropt-register-updates=allregs-at-mem-access!!g' "$DIR/run-test.php"
make -C "$DIR" test
for i in $DIR/tests/*.log; do
	echo "====== $i ======";
	cat "$i";
done
[ -n "$(echo $DIR/tests/*.log)" ] && exit 1
exit 0
