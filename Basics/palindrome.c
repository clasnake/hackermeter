#include <stdio.h>
#include <string.h>

int is_palindrome(char* s, unsigned n) {
	unsigned i;
	for (i = 0; i < n / 2; i++) {
		if (s[i] != s[n - i - 1]) {
			return 0;
		}
	}
	return 1;
}
int main() {
	int cases;
	scanf("%d", &cases);
	while (cases--) {
		char* s;
		scanf("%s", s);
		unsigned n = strlen(s);
		if (is_palindrome(s, n)) {
			printf("Y\n");
		}
		else {
			printf("N\n");
		}
	}
	return 0;
}
