#include "../common/types.h"
// 00108080: wrapper that tail-calls func_00112568 (layout row split from the GS init at 00108098).
extern "C" {
void func_00112568(void);
void func_00108080(void) { func_00112568(); }
}
