#include "../common/types.h"
// Iterate 12-byte entries of the table at D_01c6cb98 (built without interblock scheduling).
struct E2495 { u8 d[12]; };
struct H2495 { u16 a; u16 n; E2495 e[1]; };
extern "C" {
extern H2495* D_01c6cb98;
E2495* func_001a82b0(E2495* p) {
    E2495* q;
    if (!p) { q = D_01c6cb98->e; }
    else { q = p + 1; if (q >= &D_01c6cb98->e[D_01c6cb98->n]) q = 0; }
    return q;
}
}
