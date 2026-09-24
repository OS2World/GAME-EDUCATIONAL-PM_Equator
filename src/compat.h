#ifndef __EQUATOR_COMPAT_H__
#define __EQUATOR_COMPAT_H__

#include <stdlib.h>

#ifndef __GNUC__
#define random rand
#define srandom srand
#endif

#endif