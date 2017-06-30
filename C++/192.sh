# Read from the file words.txt and output the word frequency list to stdout.
sed 's/ \+/\n/g' words.txt | sed '/^[[:space:]]*$/d' | sort | uniq -c | sort -n -r | awk '{print $2, $1}'
