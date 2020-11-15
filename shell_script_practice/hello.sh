echo "hello world"
printf "hello world"
echo
printf "%s %s" hello world

string_test() {
	local string="local variable"
	echo "string ${string}"
}

function string_test2() {
	echo "string test 2"
	echo "인자값: ${@}"
}

echo
string_test
string_test2 "HELLO" "WORLD"

string="hello variable"
echo ${string}