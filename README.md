# nRF52832 DK – Testes

Projetos de teste para a placa **nRF52832 DK (PCA10040)** usando nRF Connect SDK v3.0.2 / Zephyr OS.

---

## Projetos

### 1. `blinky-4leds`
Pisca os 4 LEDs da placa simultaneamente a cada 500ms.

**Build e Flash:**
```
west build -b nrf52dk/nrf52832 blinky-4leds --pristine
west flash --runner jlink
```

---

### 2. `vcom-echo`
Teste de VCOM via Segger JLink. Tudo que for digitado no terminal serial é ecoado de volta.

**Build e Flash:**
```
west build -b nrf52dk/nrf52832 vcom-echo --pristine
west flash --runner jlink
```

**Conectar:**
- Cabo USB no conector J2 (DEBUG/JLink)
- Abrir PuTTY: porta COMx (ver Device Manager), 115200 baud, 8N1
- Pressionar RESET na placa, digitar qualquer texto

---

## Requisitos

- nRF Connect SDK v3.0.2
- J-Link drivers instalados (segger.com/downloads/jlink)
- PuTTY ou outro terminal serial (Windows)
