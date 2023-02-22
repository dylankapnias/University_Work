<?php
//To run, use the command 'php s18108467.php "string_of_choice"' and replace string_of_choice with the string to be tested, ensuring it is encapsulated by the quotation marks.

function convertInput($s) {
    $res = "";
    $sp = str_split($s);
    foreach($sp as $c) {
        if (ctype_alpha($c)) {
            $res = $res . strtolower($c);
        }
    }

    $out = <<<EOD
    <!DOCTYPE html>
    <html lang="en">
    <meta charset="UTF-8">
    <title>COS333 Prac 6 PHP</title>
    <body>
    <p>$res</p>

    EOD;
    echo $out;
    if (isPalindrome($res)) {
        $out = "<p>Palindrome</p>\n";
    } else {
        $out = "<p>Not a palindrome</p>\n";
    }
    $out = $out . "</body>\n</html>\n";
    echo $out;
}

function isPalindrome($s) {
    $out = "";
    if ($s == strrev($s)) {
        return true;
    } else {
        return false;
    }
}

// echo "Please input string: ";
// $cmd = fopen("php://stdin","rb");
// $line = fgets($cmd);
// $line = trim($line);
// convertInput($line);
convertInput($argv[1]);