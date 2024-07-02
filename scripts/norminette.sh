#!/bin/bash

install_norminette() {
	echo "Failed to find norminette. Attempting to install..."
	if command -v pip >/dev/null 2>&1; then
		pip install norminette
		if [[ $? -ne 0 ]]; then
			echo "Failed to install Norminette."
			exit 1
		else
			echo "Norminette installed successfully."
		fi
	else
		echo "Failed to find pip."
		exit 1
	fi
}

if ! command -v norminette >/dev/null 2>&1; then
	install_norminette
fi

INCLUDE_DIR="../include"
SRC_DIR="../src"

if [[ ! -d $INCLUDE_DIR || ! -d $SRC_DIR ]]; then
	echo "The specified directories do not exist."
	exit 1
fi

output=$(norminette "$INCLUDE_DIR" "$SRC_DIR" 2>&1)
if [[ $? -ne 0 ]]; then
	echo "Failed to run norminette."
	exit 1
fi

all_ok=true

echo "$output" | while IFS= read -r line; do
	if [[ $line == *"OK!"* ]]; then
		continue
	else
		modified_line=$(echo "$line" | sed 's/: KO!//')
		echo "KO! $modified_line"
		all_ok=false
	fi
done

if $all_ok; then
	echo "OK!"
fi
