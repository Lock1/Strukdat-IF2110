/*
----------------------------------------------
-- Tugas Besar Algoritma dan Struktur Data ---
------------ Kelas 2 - Kelompok 4 ------------
| 13519046    Dwianditya Hanif Raharjanto    |
| 13519110        Mohammad Afif Akromi       |
| 13519146         Fadel Ananda Dotty        |
| 13519206      Muhammad Fawwaz Naabigh      |
| 13519214      Tanur Rizaldi Rahardjo       |
----------------------------------------------
*/

// Dev
// Tags used : TODO, DEBUG, FIXME
// Macro : DEBUG

// Library
#include "engine.h"

int main(void) {
    system(CLSCRN);
    // TODO: Main menu

    // Game loop
    frameSet();
    // mapUpdate();
    forceDraw();
    sleep(1);
    // DEBUG
    long long int fpush = 0;
    // DEBUG STOP
    while (true) {
        sleep(0.9);
        mapUpdate();
        draw();
        dpf("    |||<%lld frames pushed>|||    ",++fpush);
        // dp("DBG");
        // forceDraw();
    }
    return 0;
}
