#!/bin/bash
# There is a site which has implemted many methods of repeating a string.
# URL:https://www.rosettacode.org/wiki/Repeat_a_string#UNIX_Shell

repeat_string_printf()
{
    eval "printf '$1'%0.s {1..$2}"
}

repeat_string_printf_ge()
{
        typeset e="$(sed -e 's,%,%%,g' -e 's,\\,\\\\,g' <<< "$1")"
        eval 'printf "$e"%.0s '"{1..$2}"
}


repeat_string_head()
{
        head -c $2 < /dev/zero | tr '\0' "$1"
}

repeat_string_printf "a" 20
echo

repeat_string_printf_ge "=" 20 # bug '-'
echo

repeat_string_head "-" 30
echo
