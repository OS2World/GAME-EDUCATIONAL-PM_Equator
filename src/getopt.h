#ifndef __EQUATOR_GETOPT_H__
#define __EQUATOR_GETOPT_H__

extern char *optarg;
extern int optind;
extern int opterr;
extern int optopt;

int getopt(int argc, char * const argv[], const char *optstring);

#endif