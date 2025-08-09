# Keng-cryption & Spinning ASCII Art Shapes

Welcome to **Keng-cryption** — a creative blend of encryption concepts and dynamic **ASCII art animations** rendered directly in the terminal!

This repo includes:
- 🔐 **Keng-cryption**: Experimental encryption tools and C logic
- 🎞️ **Spinning ASCII Art**: Animated shapes like donuts, pyramids, spheres, and lines using classic terminal graphics

---

## 🚀 Features



### assembly code only works on arm64
- coded this on a mac

### 🎞️ ASCII Art Animations
- Rotating 3D donut using ASCII
- Animated line, sphere, and pyramid
- Each shape is rendered frame-by-frame in the terminal
- Symbol-based surface rendering for each side

---

## 🛠️ Tech Stack

- **Language**: C
- **Platform**: macOS Terminal (ZSH)
- **Dependencies**: Standard C libraries (`stdio.h`, `math.h`, `unistd.h`)

---

## link to artical that inspired it

https://www.a1k0n.net/2011/07/20/donut-math.html

## 📂 Directory Structure

```bash
.
├── keng_cryption.c         # Encryption logic
├── spinning_donut.c        # Donut animation
├── spinning_sphere.c       # ASCII sphere animation
├── spinning_pyramid.c      # Pyramid with different characters per side
├── line_spin.c             # Rotating ASCII line
└── README.md               # This file

