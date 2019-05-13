(echo "a9c55180c67a4bc62753d836843f46fa47af28874600cdc637de921d711937ed") > A
(echo "pickle rick" | ./ft_ssl sha256) > B
if diff A B
then echo "equal"
else echo "not equal"
fi

echo "----------------------------------------------------------------------"
(echo "Do not pity the dead, Harry." | ./ft_ssl sha256 -p) > A
(echo "Do not pity the dead, Harry.
7197000d32ca5a13cf923ba196286a72daa06e9f168c4dd5753f917568ea373f") > B
if diff A B
then echo "equal"
else echo "not equal"
fi

echo "----------------------------------------------------------------------"
(echo "Pity the living." | ./ft_ssl sha256 -q -r) > A
(echo "40133cfe543247c1cae0ffb0003c1179ce9fb0046bee19f9fca167380643ba45") > B
if diff A B
then echo "equal"
else echo "not equal"
fi

echo "----------------------------------------------------------------------"
(echo "And above all," > file)
(./ft_ssl sha256 file) > A
(echo "SHA256 (file) = f9eb9a5a063eb386a18525c074e1065c316ec434f911e0d7d59ba2d9fd134705") > B
if diff A B
then echo "equal"
else echo "not equal"
fi

echo "----------------------------------------------------------------------"
(./ft_ssl sha256 -r file) > A
(echo "f9eb9a5a063eb386a18525c074e1065c316ec434f911e0d7d59ba2d9fd134705 file") > B
if diff A B
then echo "equal"
else echo "not equal"
fi

echo "----------------------------------------------------------------------"
(./ft_ssl sha256 -s "pity those that aren't following baerista on spotify.") > A
(echo "SHA256 (\"pity those that aren't following baerista on spotify.\") = 7838c25c9debff86c584245d67b429186d3850c89da31c0b49b8d0380a3e14bf") > B
if diff A B
then echo "equal"
else echo "not equal"
fi

echo "----------------------------------------------------------------------"
(echo "be sure to handle edge cases carefully" | ./ft_ssl sha256 -p file) > A
(echo "be sure to handle edge cases carefully
ef9241f878a1da676104a81239792a2817bc0390a427ca20bad1a59030fd20c2
SHA256 (file) = f9eb9a5a063eb386a18525c074e1065c316ec434f911e0d7d59ba2d9fd134705") > B
if diff A B
then echo "equal"
else echo "not equal"
fi

echo "----------------------------------------------------------------------"
(echo "some of this will not make sense at first" | ./ft_ssl sha256 file) > A
(echo "SHA256 (file) = f9eb9a5a063eb386a18525c074e1065c316ec434f911e0d7d59ba2d9fd134705") > B
if diff A B
then echo "equal"
else echo "not equal"
fi

echo "----------------------------------------------------------------------"
(echo "but eventually you will understand" | ./ft_ssl sha256 -p -r file) > A
(echo "but eventually you will understand
43da940057fd3b7453ee91b3a056a41343e6f0bce315570ed27e06c993a539da
f9eb9a5a063eb386a18525c074e1065c316ec434f911e0d7d59ba2d9fd134705 file") > B
if diff A B
then echo "equal"
else echo "not equal"
fi

echo "----------------------------------------------------------------------"
(echo "GL HF let's go" | ./ft_ssl sha256 -p -s "foo" file) > A
(echo "GL HF let's go
f33201f3d70c9dccccec022e2ff0df2006e016f153f600407917d14955fbec22
SHA256 (\"foo\") = 2c26b46b68ffc68ff99b453c1d30413413422d706483bfa0f98a5e886266e7ae
SHA256 (file) = f9eb9a5a063eb386a18525c074e1065c316ec434f911e0d7d59ba2d9fd134705") > B
if diff A B
then echo "equal"
else echo "not equal"
fi

echo "----------------------------------------------------------------------"
(echo "one more thing" | ./ft_ssl sha256 -r -p -s "foo" file -s "bar") > A
(echo "one more thing
720bbf63077e0bea3b70c87954123daa6fcf32f973f4d646622bd016b140ec75
2c26b46b68ffc68ff99b453c1d30413413422d706483bfa0f98a5e886266e7ae \"foo\"
f9eb9a5a063eb386a18525c074e1065c316ec434f911e0d7d59ba2d9fd134705 file
ft_ssl: sha256: -s: No such file or directory
ft_ssl: sha256: bar: No such file or directory") > B
if diff A B
then echo "equal"
else echo "not equal"
fi

echo "----------------------------------------------------------------------"
(echo "just to be extra clear" | ./ft_ssl sha256 -r -q -p -s "foo" file) > A
(echo "just to be extra clear
41c3da28172faf72bb777d6a428b6d801427d02513c56cd9e3672f44383f8eee
2c26b46b68ffc68ff99b453c1d30413413422d706483bfa0f98a5e886266e7ae
f9eb9a5a063eb386a18525c074e1065c316ec434f911e0d7d59ba2d9fd134705") > B
if diff A B
then echo "equal"
else echo "not equal"
fi


