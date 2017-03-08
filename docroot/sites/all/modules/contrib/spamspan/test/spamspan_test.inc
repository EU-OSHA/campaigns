<?php
//  A simple test framework for testing the spamspan regexp
//  This should be run from the command line as php spamspan_test.inc

require_once('simpletest/unit_tester.php');
require_once('simpletest/reporter.php');
require_once('../spamspan.module');

class Main extends UnitTestCase 
{

	function checkEmail($prefix='', $suffix='', $original="", $shouldbe='') {
		// Simple utility function to check that email within text is converted
		$this->assertEqual($prefix.$shouldbe.$suffix, spamspan($prefix.$original.$suffix, "") );
	}
	
	function testNoEmail() {
		// test that strings without emails a passed unchanged
		$noemails = array(
			'no email here',
			'oneword',
			'',
			'notan@email',
			'notan@email either',
			'some text and notan.email@something here',

			);
		while ($text = each($noemails)) {
			$this->assertEqual(spamspan($text, ""), $text);
		}
	}

	function testEmail() {
		// check that emails in odd places are properly converted

		// a list of address, together with what they should look like
		$emails = array('user@example.com' => 
			'<span class="spamspan"><span class="u">user</span> [at] <span class="d">example [dot] com</span></span>',
			'user@example.co.uk' => 
			'<span class="spamspan"><span class="u">user</span> [at] <span class="d">example [dot] co [dot] uk</span></span>', 
			'user@example.museum' => 
			'<span class="spamspan"><span class="u">user</span> [at] <span class="d">example [dot] museum</span></span>',
			'user.user@example.com' => 
			'<span class="spamspan"><span class="u">user.user</span> [at] <span class="d">example [dot] com</span></span>',
			'user\'user@example.com' => 
			'<span class="spamspan"><span class="u">user\'user</span> [at] <span class="d">example [dot] com</span></span>',
			'user-user@example.com' => 
			'<span class="spamspan"><span class="u">user-user</span> [at] <span class="d">example [dot] com</span></span>',
			'user_user@example.com' => 
			'<span class="spamspan"><span class="u">user_user</span> [at] <span class="d">example [dot] com</span></span>',
			'user+user@example.com' => 
			'<span class="spamspan"><span class="u">user+user</span> [at] <span class="d">example [dot] com</span></span>',


			);

		print "Test for bare email\n";
		foreach ($emails as $original => $shouldbe) {
			$this->checkEmail("","",$original,$shouldbe);
		}

		print "Test for email with text at the start\n";
		foreach ($emails as $original => $shouldbe) {
			$this->checkEmail("some text here ","",$original,$shouldbe);
		}
		print "Test for email with text at the end\n";
		foreach ($emails as $original => $shouldbe) {
			$this->checkEmail(""," some text here",$original,$shouldbe);
		}
		print "Test for email with text at the start and end\n";
		foreach ($emails as $original => $shouldbe) {
			$this->checkEmail("some text here "," some text here",$original,$shouldbe);
		}
		print "Test for email with tags at the start and end\n";
		foreach ($emails as $original => $shouldbe) {
			$this->checkEmail("<p>","</p>",$original,$shouldbe);
		}	
		print "Test for email with trailing commas\n";
		foreach ($emails as $original => $shouldbe) {
			$this->checkEmail("some text here. ",", Next sentence",$original,$shouldbe);
		}
		print "Test for email with trailing full stop\n";
		foreach ($emails as $original => $shouldbe) {
			$this->checkEmail("some text here. ",". Next sentence",$original,$shouldbe);
		}
		print "Test for email with preceding tag\n";
		foreach ($emails as $original => $shouldbe) {
			$this->checkEmail("<p>","</p>",$original,$shouldbe);
		}
		print "Test for email with preceding tag, and no closing tag\n";
		foreach ($emails as $original => $shouldbe) {
			$this->checkEmail("<dt>",". no tag here",$original,$shouldbe);
		}
		print"Test for brackets\n";
		foreach ($emails as $original => $shouldbe) {
			$this->checkEmail("(",")",$original,$shouldbe);
		}
		print"Test for angle brackets\n";
		foreach ($emails as $original => $shouldbe) {
			$this->checkEmail("<",">",$original,$shouldbe);
		}
		print"Test for newlines\n";
		foreach ($emails as $original => $shouldbe) {
			$this->checkEmail("\n","\n",$original,$shouldbe);
		}
		print"Test for spaces\n";
		foreach ($emails as $original => $shouldbe) {
			$this->checkEmail(" "," ",$original,$shouldbe);
		}

	}
	
	function testMailto() {
		$this->assertEqual(spamspan_convertmailto("<a href='mailto:email@example.com'></a>"), "email@example.com");
		$this->assertEqual(spamspan_convertmailto("<a href='email@example.com'></a>"), "<a href='email@example.com'></a>");
		$this->assertEqual(spamspan_convertmailto("<a href='mailto:email@example.com'>some text</a>text"), "email@example.comtext");
		$this->assertEqual(spamspan_convertmailto("<a href='mailto:email@example.com'></a>"), "email@example.com");
		$this->assertEqual(spamspan_convertmailto("<a attribute='something' href='mailto:email@example.com' attribute='something'></a>"), "email@example.com");
		$this->assertEqual(spamspan_convertmailto('<a href="mailto:email@example.com">some text</a>'), "email@example.com");
// ignore parameters
		$this->assertEqual(spamspan_convertmailto('<a href="mailto:email@example.com">some text</a>'), "email@example.com");
		}
		}


// set up a dummy function, because variable_get is not available outside drupal
function variable_get($one, $two)
{
	return $two;
}


$test = &new Main();
$test->run(new TextReporter());

?>
