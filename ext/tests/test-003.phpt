--TEST--
Test LoggerTrait
--SKIPIF--
<?php include 'skipif.inc'; ?>
<?php if (PHP_VERSION_ID < 50400) die('skip PHP 5.4+ required'); ?>
--FILE--
<?php

class MyLogger implements \Psr\Log\LoggerInterface
{
	use \Psr\Log\LoggerTrait;

	public function log($level, $message, array $context = array())
	{
		echo $level, ' ', $message, PHP_EOL;
	}
}

$l = new \MyLogger();
$l->log(\Psr\Log\LogLevel::WARNING, "WARNING");
$l->log(\Psr\Log\LogLevel::ERROR, "ERROR");
?>
--EXPECT--
warning WARNING
error ERROR
