def pattern_match(string input_str, string pattern):
	words = input_str.split()
	used_chars = {}
	word_to_char = {}
	length = len(words)
	if len(word) != len(pattern):
		return 0
	for i in range(length):
		if words[i] in word_to_char:
			if word_to_char[words[i]] != pattern[i]:
				return 0
			else:
				continue
		else:
			if pattern[i] in used_chars:
				return 0
			else:
				used_chars[pattern[i]] = 1
				word_to_char[words[i]] = pattern[i]
	return 1



used_chars = {}
word_to_char = {}

def slow_pattern_match(string input_str, string pattern):
	if (len(input_str) == 0 and len(pattern) == 0) return 1
	elif (len(input_str) != 0 and len(pattern) == 0) return 0
	elif (len(input_str) == 0 and len(pattern) != 0) return 0
	length = len(pattern)

	for j in range(len(input_str)):
		tmpword = input_str[0:j]
		if tmpword in word_to_char:
			if word_to_char[tmpword] != pattern[0]:
				continue
			else:
				if slow_pattern_match(input_str[j:len(input_str)], pattern[1:length]):
					return 1
		else:
			if pattern[0] in used_chars:
				continue
			else:
				used_chars[pattern[0]] = 1
				word_to_char[tmpword] = pattern[0]
				if slow_pattern_match(input_str[j:len(input_str)], pattern[1:length]):
					return 1
				del used_chars[pattern]
				del word_to_char[tmpword]
	return 0