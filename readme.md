# ESP32 Kconfig LED Blink

Ejemplo básico de ESP-IDF que permite configurar el pin de un LED dinámicamente utilizando Kconfig.

## Requisito Previo

Asegúrate de haber creado tu archivo de configuración en la siguiente ruta:
'''bash 
main/Kconfig.projbuild
'''

## Comandos Rápidos

**1. Configurar el Pin del LED:**
Abre el menú interactivo, busca la sección **"Configuración del LED"** y define tu pin.
```bash
idf.py menuconfig
```

## Compila el código, flashea la placa ESP32 y abre el monitor serial en un solo paso.

```Bash
idf.py build flash monitor
```
