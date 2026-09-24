#include "getopt.h"
#include <stdio.h>
#include <string.h>

char *optarg;
int optind = 1;
int opterr = 1;
int optopt = '?';

int getopt(int argc, char * const argv[], const char *optstring)
{
	static int sp = 1;
	static const char *token = NULL;
	const char *p;
	char c;

	if (sp == 1) {
		if (optind >= argc) return -1;
		if (argv[optind][0] != '-' || argv[optind][1] == '\0') return -1;
		if (strcmp(argv[optind], "--") == 0) { optind++; return -1; }
		token = argv[optind];
		optind++;
	}
	c = token[sp];
	if (c == ':' || (p = strchr(optstring, c)) == NULL) {
		if (opterr) fprintf(stderr, "%s: illegal option -- %c\n", argv[0], c);
		optopt = c;
		sp = 1;
		return '?';
	}
	if (p[1] == ':') {
		if (token[sp+1] != '\0') {
			optarg = (char *)&token[sp+1];
			sp = 1;
		} else if (optind < argc) {
			optarg = argv[optind];
			optind++;
			sp = 1;
		} else if (optstring[0] == ':') {
			optopt = c;
			return ':';
		} else {
			if (opterr) fprintf(stderr, "%s: option requires an argument -- %c\n", argv[0], c);
			optopt = c;
			return '?';
		}
	} else {
		optarg = NULL;
		sp++;
		if (token[sp] == '\0') sp = 1;
	}
	optopt = c;
	return c;
}