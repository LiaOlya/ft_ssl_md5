(echo "c5e433c1dbd7ba01e3763a9483e74b04") > A
(echo "pickle rick" | ./ft_ssl md5) > B
if diff A B
then echo "equal"
else echo "not equal"
fi

echo "----------------------------------------------------------------------"
(echo "Do not pity the dead, Harry." | ./ft_ssl md5 -p) > A
(echo "Do not pity the dead, Harry.
2d95365bc44bf0a298e09a3ab7b34d2f") > B
if diff A B
then echo "equal"
else echo "not equal"
fi

echo "----------------------------------------------------------------------"
(echo "Pity the living." | ./ft_ssl md5 -q -r) > A
(echo "e20c3b973f63482a778f3fd1869b7f25") > B
if diff A B
then echo "equal"
else echo "not equal"
fi

echo "----------------------------------------------------------------------"
(echo "And above all," > file)
(./ft_ssl md5 file) > A
(echo "MD5 (file) = 53d53ea94217b259c11a5a2d104ec58a") > B
if diff A B
then echo "equal"
else echo "not equal"
fi

echo "----------------------------------------------------------------------"
(./ft_ssl md5 -r file) > A
(echo "53d53ea94217b259c11a5a2d104ec58a file") > B
if diff A B
then echo "equal"
else echo "not equal"
fi

echo "----------------------------------------------------------------------"
(./ft_ssl md5 -s "pity those that aren't following baerista on spotify.") > A
(echo "MD5 (\"pity those that aren't following baerista on spotify.\") = a3c990a1964705d9bf0e602f44572f5f") > B
if diff A B
then echo "equal"
else echo "not equal"
fi

echo "----------------------------------------------------------------------"
(echo "be sure to handle edge cases carefully" | ./ft_ssl md5 -p file) > A
(echo "be sure to handle edge cases carefully
3553dc7dc5963b583c056d1b9fa3349c
MD5 (file) = 53d53ea94217b259c11a5a2d104ec58a") > B
if diff A B
then echo "equal"
else echo "not equal"
fi

echo "----------------------------------------------------------------------"
(echo "some of this will not make sense at first" | ./ft_ssl md5 file) > A
(echo "MD5 (file) = 53d53ea94217b259c11a5a2d104ec58a") > B
if diff A B
then echo "equal"
else echo "not equal"
fi

echo "----------------------------------------------------------------------"
(echo "but eventually you will understand" | ./ft_ssl md5 -p -r file) > A
(echo "but eventually you will understand
dcdd84e0f635694d2a943fa8d3905281
53d53ea94217b259c11a5a2d104ec58a file") > B
if diff A B
then echo "equal"
else echo "not equal"
fi

echo "----------------------------------------------------------------------"
(echo "GL HF let's go" | ./ft_ssl md5 -p -s "foo" file) > A
(echo "GL HF let's go
d1e3cc342b6da09480b27ec57ff243e2
MD5 (\"foo\") = acbd18db4cc2f85cedef654fccc4a4d8
MD5 (file) = 53d53ea94217b259c11a5a2d104ec58a") > B
if diff A B
then echo "equal"
else echo "not equal"
fi

echo "----------------------------------------------------------------------"
(echo "one more thing" | ./ft_ssl md5 -r -p -s "foo" file -s "bar") > A
(echo "one more thing
a0bd1876c6f011dd50fae52827f445f5
acbd18db4cc2f85cedef654fccc4a4d8 \"foo\"
53d53ea94217b259c11a5a2d104ec58a file
ft_ssl: md5: -s: No such file or directory
ft_ssl: md5: bar: No such file or directory") > B
if diff A B
then echo "equal"
else echo "not equal"
fi

echo "----------------------------------------------------------------------"
(echo "just to be extra clear" | ./ft_ssl md5 -r -q -p -s "foo" file) > A
(echo "just to be extra clear
3ba35f1ea0d170cb3b9a752e3360286c
acbd18db4cc2f85cedef654fccc4a4d8
53d53ea94217b259c11a5a2d104ec58a") > B
if diff A B
then echo "equal"
else echo "not equal"
fi


