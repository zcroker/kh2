// worldmap::CameraManager (0x2c6120-0x2c6420). Linked unit.
#include "cameramanager.hpp"

extern u32 D_0032b96c asm("D_0032b96c");
void func_002ef8d0(void*, u32) asm("func_002ef8d0");
void func_002c65f8(worldmap::ManagedCamera*) asm("func_002c65f8");
void func_001024a8(TASK*) asm("func_001024a8");

namespace worldmap {

static void exec(TASK* t);
static CameraManager s_instance;

CameraManager::CameraManager() {
    m_flag = 1;
    m_priority = 26000;
    m_exec = exec;
    m_task = 0;
    clear();
}

void CameraManager::clear() {
    ManagedCamera** p = m_cam;
    s32 i = 2;

    do {
        *p = 0;
        i -= 1;
        p += 1;
    } while (i >= 0);
}

void CameraManager::removeAll() {
    for (s32 i = 0; i < 3; i++) {
        remove(i);
    }
}

ManagedCamera* CameraManager::getCamera(s32 i) {
    return m_cam[i];
}

void* CameraManager::get() {
    return &s_instance;
}

void CameraManager::set(s32 i, ManagedCamera* cam) {
    u8* o = (u8*)this;
    remove(i);
    ((u32*)(o + 16))[i] = (u32)cam;
    func_002ef8d0(o, D_0032b96c);
}

void CameraManager::remove(s32 i) {
    ManagedCamera** s = (ManagedCamera**)(i * 4 + (u32)this + 16);
    if (*s) {
        ((void (*)(ManagedCamera*))(*s)->vt[1])(*s);
        *s = 0;
    }
}

s32 CameraManager::update() {
    s32 found = 0;
    s32 i;
    m_current = 0;
    for (i = 2; i >= 0; i--) {
        ManagedCamera* x = m_cam[i];
        if (!x) continue;
        if (!found) {
            if (x->vt[2](x)) {
                found = 1;
                m_current = m_cam[i];
            } else {
                remove(i);
            }
        } else {
            func_002c65f8(x);
        }
    }
    return found;
}

static void exec(TASK* t) {
    if (!s_instance.update()) {
        func_001024a8(t);
    }
}

}  // namespace worldmap
