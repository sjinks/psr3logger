--TEST--
Test AbstractLogger and LoggerAwareInterface
--SKIPIF--
<?php include 'skipif.inc'; ?>
--FILE--
<?php

class MyLogger extends \Psr\Log\AbstractLogger
{
	public function log($level, $message, array $context = array())
	{
		echo $level, ' ', $message, PHP_EOL;
	}
}

class LoggerAware implements \Psr\Log\LoggerAwareInterface
{
	private $_logger;

	public function setLogger(\Psr\Log\LoggerInterface $logger)
	{
		$this->_logger = $logger;
	}

	public function test()
	{
		$this->_logger->warning('WARNING');
		$this->_logger->error('ERROR');
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
