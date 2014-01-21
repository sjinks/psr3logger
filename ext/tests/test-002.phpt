--TEST--
Test LoggerTrait and LoggerAwareTrait
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

class LoggerAware implements \Psr\Log\LoggerAwareInterface
{
	use \Psr\Log\LoggerAwareTrait;

	public function setLogger(\Psr\Log\LoggerInterface $logger)
	{
		$this->logger = $logger;
	}

	public function test()
	{
		$this->logger->warning('WARNING');
		$this->logger->error('ERROR');
	}
}

$x = new \LoggerAware();
$l = new \MyLogger();
$x->setLogger($l);
$x->test();
?>
--EXPECT--
warning WARNING
error ERROR
