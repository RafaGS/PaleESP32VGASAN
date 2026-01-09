# PaleESP32VGASAN
PaleESP32VGA con core de Jose Sanchez adaptadado al ESP32 3.3.0 de Arduino.

Descripción e instalación en: [https://minibots.wordpress.com/2025/10/05/emulador-de-camputers-lynx-96-con-lilygo-ttgo-vga32/]

Más sobre retroinformática aquí: [https://minibots.wordpress.com/retroinformatica/]

Cambios: 
1. PaleESP32VGASAN.ino
- Añadido #include <esp_system.h> y función printResetReason() que imprime la causa del reset.
- Serial.begin(115200) movido/ejecutado más temprano para capturar mensajes de reset.
- Mensaje de boot adicional "== PALE BOOT ==".
- Cambios en pines: pines listados con comentarios y sin cambios funcionales en valores (solo limpieza de comentarios).
- Cambio en vga.init(...) — ahora usa MODE320x240 (antes MODE400x300), y había un comentario de la otra opción.
- Reemplazo de system_get_free_heap_size() por esp_get_free_heap_size().
- Añadido un "HEARTBEAT" en loop() bajo #ifdef DEBUG que imprime memoria libre periódicamente.
- Añadidas comprobaciones NULL para bank2/bank3 antes de leer bytes (previene dereference cuando los bancos no están asignados).
- Ajustes de formato y pequeñas reordenaciones (p.ej. test_sd() llamado dentro de #ifdef con indentación cambiada).

2. paledisk.cpp
- Intento de asignación en PSRAM primero (ps_malloc) y fallback a malloc si falla.
- Mensajes Serial adicionales para fallos de asignación.
- Comprobaciones NULL añadidas antes de lecturas/escrituras sobre disk0, disk_sect_buf, disk_track_buf para evitar accesos inválidos.
- Omisión segura de lecturas/escrituras si buffers son NULL (logs informativos).
- Objetivo: hacerlo más robusto frente a fallos de memoria y evitar crashes por punteros nulos.

3. Z80IO.cpp
- Include modificado de #include "Z80.h" a #include "z80.h" (cambio en mayúsculas/minúsculas del nombre).
- Muchas comprobaciones NULL añadidas alrededor de bank1, bank2, bank3 para lecturas y escrituras: si el banco no existe ahora devuelve 0xff (lectura) o ignora la escritura.
- Objetivo: evitar accesos inválidos si los buffers de memoria no están inicializados.
