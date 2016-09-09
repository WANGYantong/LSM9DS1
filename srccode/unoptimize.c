
#include "global.h"

void DEV_DelayMs(U32 uiMs)
{
	U32 i;
	U32 j;

	j = 5540 * uiMs;

	for (i = 0;; i++) {
		if (i == j) {
			break;
		}
	}
}
