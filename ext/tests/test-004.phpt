--TEST--
Test LoggerAwareTrait
--SKIPIF--
<?php include 'skipif.inc'; ?>
<?php if (PHP_VERSION_ID < 50400) die('skip PHP 5.4+ required'); ?>
--FILE--
<?php

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
?>
--EXPECT--
